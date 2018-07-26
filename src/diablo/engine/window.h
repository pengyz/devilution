#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include "globalUtils.h"


namespace Engine {

    class Window {
        friend class GameEngine;
    public:
        ~Window();
    private:
        Window(const std::string& title, int width, int height);

    private:
        GLFWwindow * m_glfwWindow = nullptr;
        int m_width = 0;
        int m_height = 0;
        std::string m_title;
        bool m_fullScreen = false;


    public:
        int getWidth()
        {
            return m_width;
        }
        void setWidth(int width)
        {
            m_width = width;
            glfwSetWindowSize(m_glfwWindow, m_width, m_height);
        }

        int getHeight()
        {
            return m_height;
        }

        GLFWwindow* getNativeWindow() const
        {
            return m_glfwWindow;
        }

        void setHeight(int height)
        {
            m_height = height;
            glfwSetWindowSize(m_glfwWindow, m_width, m_height);
        }

        std::string getTitle()
        {
            return m_title;
        }

        void setTitle(const std::string& title)
        {
            m_title = title;
            glfwSetWindowTitle(m_glfwWindow, title.c_str());
        }

        void setTitle(const char* title);
        void setWindowGeometry(int x, int y, int width, int height);
        void setSize(int width, int height);
        void setPosition(int x, int y);
        void close();
        void setFullScreen(bool fullScreen);
        void toggleFullScreen();
        bool aboutToClose();
        void setResizable(bool bResize);
    };

}
