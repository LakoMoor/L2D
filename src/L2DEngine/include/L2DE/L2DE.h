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

        void createWindow(const char *title, int x, int y, int width, int height, Uint32 flags); // Функция создания окна
        void runEngineLoop();

    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
#ifdef GL
        SDL_GLContext glContext;
#endif
        GLuint textureID;

        bool isRunning;
        GUI::UI ui;
    };
}

#endif // L2DE_H
