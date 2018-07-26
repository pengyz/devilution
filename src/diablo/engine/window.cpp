#include "Window.h"

#include <cassert>

using namespace Engine;


Window::Window(const std::string& title, int width, int height)
    :m_width(width), m_height(height), m_title(title)
{
    GLFWmonitor* pMonitor = nullptr;
    if (m_fullScreen) {
        pMonitor = glfwGetPrimaryMonitor();
    }
    m_glfwWindow = glfwCreateWindow(m_width, m_height, m_title.c_str(), pMonitor, nullptr);
    assert(m_glfwWindow);
    glfwMakeContextCurrent(m_glfwWindow);
}

Window::~Window()
{
    glfwMakeContextCurrent(nullptr);
    if (m_glfwWindow) {
        glfwDestroyWindow(m_glfwWindow);
        m_glfwWindow = nullptr;
    }
}

void Window::setTitle(const char* title)
{
    glfwSetWindowTitle(m_glfwWindow, title);
}

void Window::setWindowGeometry(int x, int y, int width, int height)
{
    setPosition(x, y);
    setSize(width, height);
}

void Window::setSize(int width, int height)
{
    glfwSetWindowSize(m_glfwWindow, width, height);
}

void Window::setPosition(int x, int y)
{
    glfwSetWindowPos(m_glfwWindow, x, y);
}


void Window::close()
{
    glfwSetWindowShouldClose(m_glfwWindow, GL_TRUE);
}

void Window::setFullScreen(bool fullScreen)
{
    m_fullScreen = fullScreen;
    GLFWmonitor* pMonitor = m_fullScreen ? glfwGetPrimaryMonitor() : nullptr;
    glfwSetWindowMonitor(m_glfwWindow, pMonitor, 0, 0, m_width, m_height, GLFW_DONT_CARE);
}

void Window::toggleFullScreen()
{
    setFullScreen(!m_fullScreen);
}

bool Window::aboutToClose()
{
    if (!m_glfwWindow)
        return true;
    return glfwWindowShouldClose(m_glfwWindow);
}

void Window::setResizable(bool bResize)
{
    assert(m_glfwWindow);
    glfwSetWindowAttrib(m_glfwWindow, GLFW_RESIZABLE, bResize);
}
