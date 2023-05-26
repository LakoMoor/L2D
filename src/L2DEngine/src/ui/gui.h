#ifndef GUI_H
#define GUI_H

#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer.h>
#include <imgui_internal.h>
#include <iostream>
#include <SDL.h>
#include <glad/glad.h>

namespace GUI
{
    class UI
    {
    public:
        UI();
        ~UI();
        void init(SDL_Window* window, SDL_Renderer* renderer);
        void demo();
        void create();
        void render(SDL_Renderer* renderer);
    private:
    };
}

#endif  // GUI_H