#pragma once
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "../engine/window.h"

namespace Engine {

    class GameGui {
        friend class GameEngine;
    private:
        GameGui() = default;
        void redererRoutine();
    public:
        ~GameGui();
        bool init(Engine::Window* window);
        ImGuiIO* getImGuiIO();
        // Load Fonts
        // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them. 
        // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple. 
        // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
        // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
        // - Read 'misc/fonts/README.txt' for more instructions and details.
        // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
        ImFont* addFont(const std::string& ttfFontPath, float fontSize, const ImWchar* glyphRange, bool bMergeFont = true);
        ImFont* GameGui::addFont(const std::string& ttfFontPath, float fontSize, bool bMergeFont = true);
        void present();

    private:
        ImGuiIO * m_ImGuiIO = nullptr;
        Window * m_window = nullptr;
    };
}