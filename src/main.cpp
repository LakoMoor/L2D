#include <L2DE/L2DE.h>
#include <imgui.h>

int main(int argv, char** args)
{
    l2de::Renderer renderer;
    #ifdef DEBUG

    renderer.createWindow("My Window DEBUG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL| SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    
    while(renderer.isRunning){
        ImGui::ShowDemoWindow();
    }
    #endif

    #ifdef RELEASE

    renderer.createWindow("My Window RELEASE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
    renderer.runGameLoop();
    
    #endif
    
    return 0;
}