#include "GameEngine.h"
#include "../gui/gamegui.h"
#include "../renderer/shader.h"

#include <cassert>
#include <filesystem>
#include <iostream>
#include <vector>
#include <string>


using namespace Engine;

GameEngine::GameEngine(int argc, char** argv)
{
    for (int i = 0; i < argc; ++i) {
        m_params.emplace_back(argv[i]);
    }
    assert(init());

    m_appPath = argv[0];
    std::filesystem::path currPath(m_appPath);
    m_appFileName = currPath.filename().generic_u8string();
}

GameEngine::~GameEngine()
{
    if (m_window) {
        delete m_window;
        m_window = nullptr;
    }
    if (m_gameGui) {
        delete m_gameGui;
        m_gameGui = nullptr;
    }

    glfwTerminate();
}

bool GameEngine::initOpenGLFunctions()
{
    glewExperimental = GL_TRUE;
    return GLEW_OK == glewInit();
}

Window* GameEngine::initGameWindow(const std::string& title, int x, int y, int width, int height)
{
    assert(!m_window);
    m_window = new Window(title, width, height);
    m_window->setPosition(x, y);
    return m_window;
}


void GameEngine::glfwErrorCallback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}


bool GameEngine::init()
{
    if (!glfwInit())
        return false;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    //to make mac os x happy.
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GL_TRUE);
#endif
    glfwSetErrorCallback(glfwErrorCallback);
    return true;
}

bool GameEngine::initWindowGUI()
{
    assert(m_window);
    assert(!m_gameGui);
    m_gameGui = new GameGui();
    return m_gameGui->init(m_window);
}

int GameEngine::exec()
{
    assert(m_window);

    //GLuint g_programId = 0;
    Shader* g_shader = nullptr;
    GLuint g_vao = 0;
    GLuint g_vbo = 0;
    GLuint g_ibo = 0;

    auto freeGLResources = [&]() {
        glBindVertexArray(0);
        glUseProgram(0);
        glDeleteVertexArrays(1, &g_vao);
        glDeleteBuffers(1, &g_vbo);
        if (g_shader)
            g_shader->unuse();
    };

    while (!m_window->aboutToClose()) {
        glfwPollEvents();
        m_gameGui->present();
        glfwMakeContextCurrent(m_window->getNativeWindow());
        //this is the test code for OpenGL draw trangle
        {
            if (!g_shader) {
                const char* vertSharderSource = R"(
                    #version 330 core
                    layout (location = 0) in vec3 aPos;
                    layout (location = 1) in vec3 aColor;
                    out vec3 ourColor;

                    void main()
                    {
                        gl_Position = vec4(aPos, 1.0);
                        ourColor = aColor;
                    }
                )";
                const char* fragShaderSource = R"(
                    #version 330 core
                    out vec4 FragColor;
                    in vec3 ourColor;

                    void main()
                    {
                        FragColor = vec4(ourColor,1.0);
                    }
                )";
                g_shader = new Shader(vertSharderSource, fragShaderSource);
            }
            if (!g_vao) {

                float vertices[] = {
                    // 位置              // 颜色
                     0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // 右下
                    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // 左下
                     0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // 顶部
                };

                //unsigned int indices[] = { // 注意索引从0开始! 
                //    0, 1, 3, // 第一个三角形
                //    1, 2, 3  // 第二个三角形
                //};

                glGenVertexArrays(1, &g_vao);
                glBindVertexArray(g_vao);

                glGenBuffers(1, &g_vbo);
                glBindBuffer(GL_ARRAY_BUFFER, g_vbo);
                glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                /*glGenBuffers(1, &g_ibo);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, g_ibo);
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);*/


                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
                glEnableVertexAttribArray(0);

                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (const void*)(3 * sizeof(float)));
                glEnableVertexAttribArray(1);

                //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            }

            ////set uniform color value
            //float timeValue = glfwGetTime();
            //float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
            //int vertexColorLocation = glGetUniformLocation(g_programId, "ourColor");
            //draw call
            //glUseProgram(g_programId);
            g_shader->use();
            //glUniform4f(vertexColorLocation, 0.4f, greenValue, 0.1f, 1.0f);
            glBindVertexArray(g_vao);
            glDrawArrays(GL_TRIANGLES, 0, 3);
            //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
            glBindVertexArray(0);
        }
        glfwSwapBuffers(m_window->getNativeWindow());
    }
    freeGLResources();
    return 0;
}

ImFont* GameEngine::initFont(const std::string& fontPath, float fontSize)
{
    auto& io = ImGui::GetIO();
    assert(m_gameGui);
    io.Fonts->AddFontDefault();
    m_chineseFont = m_gameGui->addFont(fontPath, fontSize,
        io.Fonts->GetGlyphRangesChineseSimplifiedCommon(), true);
    return m_chineseFont;
}
