#include "gui.h"

#include <spdlog/spdlog.h>

namespace GUI
{
    UI::UI()
    {
        spdlog::debug("Setup GUI");

    }

    void UI::init(SDL_Window* window, SDL_Renderer* renderer)
    {
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO();
        io.IniFilename = NULL;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable keyboard controls
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;     // Enable docking
        io.ConfigViewportsNoDecoration = false;

        ImVec4 *colors = ImGui::GetStyle().Colors;

        ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
        ImGui_ImplSDLRenderer_Init(renderer);
        spdlog::info("Init ImGui");

    }

    void UI::demo()
    {
        
        ImGui::ShowDemoWindow();
        
    }

    void UI::create()
    {
        ImGui_ImplSDLRenderer_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();
    }

    void UI::render(SDL_Renderer* renderer)
    {
        ImGui::EndFrame();
        ImGui::Render();
        ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
    }

    UI::~UI()
    {
        ImGui_ImplSDLRenderer_Shutdown();
        ImGui_ImplSDL2_Shutdown();
        ImGui::DestroyContext();
        spdlog::debug("Destroy ImGui");
    }
}