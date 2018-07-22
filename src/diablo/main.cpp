#include <GL/glew.h>
#include <GLFW/glfw3.h>


int main(int argc, char** argv){
    if(!glfwInit())
        return -1;
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    //to make mac os x happy.
    glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE,GL_TRUE);
    
    bool isFullScreen = false;
    
    GLFWmonitor* pMonitor = isFullScreen ? glfwGetPrimaryMonitor() : nullptr;
    GLFWwindow* window = glfwCreateWindow(1024, 768, "Diablo", pMonitor, nullptr);
    
    if(nullptr == window)
    {
        return -2;
    }
    
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if(GLEW_OK != glewInit())
        return -1;
    
    // game loop 
    while (!glfwWindowShouldClose(window)) 
    {
        // if Esc is pressed, close the window
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        else if(glfwGetKey(window,GLFW_KEY_F11) == GLFW_PRESS){
            isFullScreen = !isFullScreen;
            glfwMakeContextCurrent(nullptr);
            glfwDestroyWindow(window);
            GLFWmonitor* pMonitor = isFullScreen ? glfwGetPrimaryMonitor() : nullptr;
            int width = 1024;
            int height = 768;
            if(pMonitor){
                auto videoMode = glfwGetVideoMode(pMonitor);
                width = videoMode->width;
                height = videoMode->height;
            }
            window = glfwCreateWindow(width,height,"Diablo",pMonitor, nullptr);
            glfwMakeContextCurrent(window);
        }

        // clear the window
        glClear(GL_COLOR_BUFFER_BIT);

        // poll and swap
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // cleanup
    glfwTerminate(); 
    glfwTerminate();
    
    return 0;
}
