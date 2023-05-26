#ifndef L2DE_H
#define L2DE_H

#include <SDL.h>
#include <glad/glad.h>
#include "../../src/ui/gui.h"

namespace l2de
{
    class Renderer
    {
    public:
        Renderer();
        ~Renderer();
        
        void createWindow(const char* title, int x, int y, int width, int height, Uint32 flags); // Функция создания окна
        void runGameLoop();
        void renderImGui();

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_GLContext glContext;
        GLuint textureID;

        bool isRunning;
        GUI::UI ui;
    };
}

#endif  // L2DE_H
