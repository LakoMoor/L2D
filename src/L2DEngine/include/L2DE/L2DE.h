#ifndef L2DE_H
#define L2DE_H

#include <SDL.h>
#include <glad/glad.h>

namespace l2de
{
    class Renderer
    {
    public:
        Renderer();
        
        void createWindow(const char* title, int x, int y, int width, int height, Uint32 flags); // Функция создания окна
        void runGameLoop(bool isRunning);
        void renderImGui();

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
    };
}

#endif  // L2DE_H
