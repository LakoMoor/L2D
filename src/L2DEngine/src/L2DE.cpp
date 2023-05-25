#include <L2DE.h>

#include <spdlog/spdlog.h>

#include <iostream>

namespace l2de
{
    Renderer::Renderer()
    {
        #ifdef DEBUG

        spdlog::set_level(spdlog::level::debug);

        #endif

        if(SDL_Init(SDL_INIT_VIDEO) != 0)
        {
            spdlog::error("s\n",SDL_GetError());
            exit(0);
        }

        spdlog::info("SDL2 Init");
    }
    
    void Renderer::createWindow(const char* title, int x, int y, int width, int height, Uint32 flags)
    {
        window = SDL_CreateWindow(title, x, y, width, height, flags);

        spdlog::info("Window created");
        spdlog::debug("Windows name: {}, Res: {}x{}\n", title, width, height);

        
        if (window)
        {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        }
        
        glContext = SDL_GL_CreateContext(window);
        
        if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
        {
            spdlog::error("Failed to initialize GLAD");
            exit(0);
        }

        glViewport(0, 0, width, height);
        
        const char* vendorD = reinterpret_cast<const char*>(glGetString(GL_VENDOR));
        const char* rendererD = reinterpret_cast<const char*>(glGetString(GL_RENDERER));
        const char* vglD = reinterpret_cast<const char*>(glGetString(GL_VERSION));
        const char* vglslD = reinterpret_cast<const char*>(glGetString(GL_SHADING_LANGUAGE_VERSION));

        #ifdef DEBUG
        spdlog::info("OpenGL Loaded\n");
        spdlog::debug("Vendor:          {}", vendorD);
        spdlog::debug("Renderer:        {}", rendererD);
        spdlog::debug("Version OpenGL:  {}", vglD);
        spdlog::debug("Version GLSL:    {}", vglslD);
        #endif
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
                    #ifdef DEBUG
                    #endif
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

