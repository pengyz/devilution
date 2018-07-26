#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <string>
#include "window.h"
#include "globalUtils.h"
#include "../gui/gamegui.h"

namespace Engine {

    class GameEngine {
    public:
        GameEngine(int argc, char** argv);
        ~GameEngine();

    public:
        int exec();
        Window* initGameWindow(const std::string& title, int x, int y, int width, int height);
        bool initWindowGUI();
        bool initOpenGLFunctions();
        ImFont* initFont(const std::string& fontPath, float fontSize);

    private:
        bool init();
        static void glfwErrorCallback(int error, const char* description);

    private:
        std::vector<std::string> m_params;
        std::string m_appFileName;
        std::string m_appPath;
        Window* m_window = nullptr;
        GameGui* m_gameGui = nullptr;
        ImFont* m_chineseFont = nullptr;
    };
}