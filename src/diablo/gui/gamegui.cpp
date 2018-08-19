#include "gamegui.h"
#include "../engine/window.h"

using namespace Engine;

GameGui::~GameGui()
{
    if (m_ImGuiIO) {
        m_ImGuiIO = nullptr;
    }
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

bool GameGui::init(Engine::Window* window)
{
    bool bRet = false;
    m_window = window;
    // Setup Dear ImGui binding
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    m_ImGuiIO = &ImGui::GetIO();
    m_ImGuiIO->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls
    m_ImGuiIO->ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;   // Enable Gamepad Controls

    bRet = ImGui_ImplGlfw_InitForOpenGL(m_window->getNativeWindow(), true);
    if (!bRet) {
        return false;
    }
    bRet = ImGui_ImplOpenGL3_Init();
    if (!bRet) {
        return false;
    }

    // Setup style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();
    return bRet;
}

ImGuiIO* GameGui::getImGuiIO()
{
    return m_ImGuiIO;
}

void GameGui::redererRoutine()
{
    static bool show_demo_window;
    static bool show_another_window;
    static float f = 0.0f;

    static int counter = 0;
    static bool bOpen = true;

    IMGUI_CHECKVERSION();

    if (bOpen) {
        ImGui::Begin("你好中国!", &bOpen);                          // Create a window called "Hello, world!" and append into it.

        ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
        ImGui::Checkbox("关闭", &show_demo_window);      // Edit bools storing our window open/close state
        ImGui::Checkbox("Another Window", &show_another_window);

        ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f    

        if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
            counter++;
        ImGui::SameLine();
        ImGui::Text("counter = %d", counter);

        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

        ImGuiID id = ImGui::GetID("demo_id");
        ImGui::BeginChild(id, ImVec2(100, 200));
        ImGui::Text("This is child text");
        ImGui::EndChild();

        ImGui::End();
    }
    ImGui::PushStyleVar(ImGuiStyleVar_WindowTitleAlign, ImVec2(0.5, 0.5));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
    ImGui::PushStyleColor(ImGuiCol_TitleBg, ImVec4(1, 1, 1, 0));
    ImGui::PushStyleColor(ImGuiCol_TitleBgActive, ImVec4(1, 1, 1, 0));
    ImGui::Begin("背包", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoCollapse);
    ImGui::Text("This is user bag");
    ImGui::End();
    ImGui::PopStyleVar(2);
    ImGui::PopStyleColor(2);
}

void GameGui::present()
{
    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    //call renderer function
    redererRoutine();
    // Rendering
    ImGui::Render();
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f, 0.0f, 0.8f, 1.f);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

ImFont* GameGui::addFont(const std::string& ttfFontPath, float fontSize, const ImWchar* glyphRange, bool bMergeFont)
{
    ImFontConfig config;
    config.MergeMode = bMergeFont;
    ImFont* chFont = m_ImGuiIO->Fonts->AddFontFromFileTTF(ttfFontPath.c_str(), fontSize, &config, glyphRange);
    return chFont;
}

ImFont* GameGui::addFont(const std::string& ttfFontPath, float fontSize, bool bMergeFont)
{
    ImFontConfig config;
    config.MergeMode = bMergeFont;
    ImFont* chFont = m_ImGuiIO->Fonts->AddFontFromFileTTF(ttfFontPath.c_str(), fontSize, &config, NULL);
    return chFont;
}
