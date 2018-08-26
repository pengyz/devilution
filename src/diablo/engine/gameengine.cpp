#include "GameEngine.h"
#include "../gui/gamegui.h"
#include "../renderer/shader.h"
#include "../renderer/stb_image.h"

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

	Shader* shader = nullptr;
	GLuint vao = 0;
	GLuint vbo = 0;
	GLuint ibo = 0;
	GLuint textures[2] = { 0 };

	auto freeGLResources = [&]() {
		glBindVertexArray(0);
		glUseProgram(0);
		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &vbo);
		if (shader)
			shader->unuse();
	};

	//prebuild
	{
		//create shader
		const char* vertSharderSource = R"(
                    #version 330 core
                    layout (location = 0) in vec3 aPos;
					layout (location = 1) in vec2 aTexCoord;
                    
					out vec2 TexCoord;

					uniform mat4 transform;

                    void main()
                    {
                        gl_Position = vec4(aPos, 1.0) * transform;
						TexCoord = aTexCoord;
                    }
                )";
		const char* fragShaderSource = R"(
                    #version 330 core
                    out vec4 FragColor;

					in vec2 TexCoord;

					uniform sampler2D texture1;
					uniform sampler2D texture2;

                    void main()
                    {
						FragColor = mix(texture(texture1, TexCoord),texture(texture2, TexCoord), 0.2);
						//FragColor = texture(texture2, TexCoord);
					}
                )";
		shader = new Shader(vertSharderSource, fragShaderSource);


		float vertices[] = {
			//     ---- 位置 ----     - 纹理坐标 -
				 0.5f,  0.5f, 0.0f,   1.0f, 1.0f,   // 右上
				 0.5f, -0.5f, 0.0f,   1.0f, 0.0f,   // 右下
				-0.5f, -0.5f, 0.0f,   0.0f, 0.0f,   // 左下
				-0.5f,  0.5f, 0.0f,   0.0f, 1.0f    // 左上
		};

		unsigned int indices[] = { // 注意索引从0开始! 
			0, 1, 3, // 第一个三角形
			1, 2, 3  // 第二个三角形
		};

		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glGenBuffers(1, &ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), nullptr);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (const void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		glBindVertexArray(vao);
		glGenTextures(2, textures);
		glBindTexture(GL_TEXTURE_2D, textures[0]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.

		//load and generate texture
		int width, height, nrChannel;
		auto pData = stbi_load("D:\\workspace\\devilution\\extern\\container.jpg", &width, &height, &nrChannel, 0);
		if (pData) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pData);
			glGenerateMipmap(GL_TEXTURE_2D);
		} else {
			std::cout << "Failed to load texture" << std::endl;
		}
		stbi_image_free(pData);

		glBindTexture(GL_TEXTURE_2D, textures[1]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		auto pData2 = stbi_load("D:\\workspace\\devilution\\extern\\awesomeface.png", &width, &height, &nrChannel, 0);
		if (pData2) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pData2);
			glGenerateMipmap(GL_TEXTURE_2D);
		} else {
			std::cout << "Failed to load texture" << std::endl;
		}
		stbi_image_free(pData2);

		shader->use();
		shader->setUniform("texture1", 0);
		shader->setUniform("texture2", 1);
	}

	while (!m_window->aboutToClose()) {
		glfwPollEvents();
		if (m_gameGui)
			m_gameGui->present();
		glfwMakeContextCurrent(m_window->getNativeWindow());
		//this is the test code for OpenGL draw trangle
		{
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, textures[0]);
			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_2D, textures[1]);
			shader->use();
			//rotate 
			{
				glm::mat4 trans = glm::mat4(1.0f);
				trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
				trans = glm::scale(trans, glm::vec3(0.5f, 0.5f, 0.5f));
				shader->setUniform("transform", trans);
			}

			glBindVertexArray(vao);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
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
