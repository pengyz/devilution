#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdio>
#include <string>
#include <iostream>

#include "engine/gameengine.h"
#include "engine/window.h"
#include "gui/gamegui.h"

//#include "restrict.h"
//#include "appfat.h"


int main(int argc, char** argv)
{
    Engine::GameEngine engine(argc, argv);
    auto mainWindow = engine.initGameWindow(u8"你好中国", 100, 100, 1024, 768);
    mainWindow->setResizable(true);
    assert(engine.initOpenGLFunctions());
#if 1
    assert(engine.initWindowGUI());
    assert(engine.initFont("D:/workspace/devilution/extern/DroidSansFallback.ttf", 18));
#endif
    return engine.exec();
}
