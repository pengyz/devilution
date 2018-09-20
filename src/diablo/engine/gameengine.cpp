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


	while (!m_window->aboutToClose()) {
		glfwPollEvents();
		m_gameGui->present();
		glfwMakeContextCurrent(m_window->getNativeWindow());
	}
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
