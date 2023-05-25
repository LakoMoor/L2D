#include <L2DE.h>

namespace l2de
{
    Renderer::Renderer()
    {
        SDL_Init(SDL_INIT_VIDEO);
        window = nullptr;
        renderer = nullptr;
    }
    
    void Renderer::createWindow(const char* title, int x, int y, int width, int height, Uint32 flags)
    {
        window = SDL_CreateWindow(title, x, y, width, height, flags);
        
        if (window)
        {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        }
        
    }
    
    void Renderer::runGameLoop(bool isRunning)
    {
        while (isRunning)
        {
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    isRunning = false;
                }
            }
            
            // Game logic and rendering
            
            
            // Clear the renderer
            SDL_RenderClear(renderer);
            
            // Render objects
            // ...
            
            // Update the screen
            SDL_RenderPresent(renderer);
        }
    }
}

