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
        spdlog::info("-----------------------------L2DEngine Loaded-----------------------------\n");
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0)
        {
            spdlog::error("Error:   {}", SDL_GetError());
            exit(0);
        }
        isRunning = false;
        spdlog::info("SDL2 Init");
    }

    Renderer::~Renderer()
    {
        // Clean up OpenGL and SDL2
        isRunning = false;
#ifdef GL
        spdlog::info("Delete OpenGL context");
        SDL_GL_DeleteContext(glContext);
#else
        spdlog::info("Delete SDL Renderer");
        SDL_DestroyRenderer(renderer);
#endif
        spdlog::info("Destroy Window");
        SDL_DestroyWindow(window);

        spdlog::info("Init SDL_Quit");
        SDL_Quit();
    }

    void Renderer::createWindow(const char *title, int x, int y, int width, int height, Uint32 flags)
    {
        window = SDL_CreateWindow(title, x, y, width, height, flags);

#ifdef GL
            glContext = SDL_GL_CreateContext(window);
#else
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
#endif

        if (renderer == NULL)
        {
            SDL_Log("Error creating SDL_Renderer!");
            //Renderer::~Renderer();
        }

        spdlog::info("Window created");
        spdlog::debug("Windows name: {}, Res: {}x{}\n", title, width, height);

        if (window)
        {

        }
#ifdef GL
        SDL_GL_MakeCurrent(window, glContext);
        SDL_GL_SetSwapInterval(1);
        if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
        {
            spdlog::error("Failed to initialize GLAD");
            exit(0);
        }
        else
        {
            spdlog::info("GLAD Init");
        }

        glViewport(0, 0, width, height);

        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        const char *vendorD = reinterpret_cast<const char *>(glGetString(GL_VENDOR));
        const char *rendererD = reinterpret_cast<const char *>(glGetString(GL_RENDERER));
        const char *vglD = reinterpret_cast<const char *>(glGetString(GL_VERSION));
        const char *vglslD = reinterpret_cast<const char *>(glGetString(GL_SHADING_LANGUAGE_VERSION));

#ifdef DEBUG
        spdlog::info("-----------------------------OpenGL Loaded-----------------------------\n");
        spdlog::debug("Vendor:          {}", vendorD);
        spdlog::debug("Renderer:        {}", rendererD);
        spdlog::debug("Version OpenGL:  {}", vglD);
        spdlog::debug("Version GLSL:    {}\n", vglslD);
#endif

#else
        spdlog::info("-----------------------------Console-----------------------------\n");
#endif
        ui.init(window, renderer);
    }

    void Renderer::runEngineLoop()
    {
        isRunning = true;
        while (isRunning)
        {
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                ImGui_ImplSDL2_ProcessEvent(&event);
                switch (event.type)
                {

                case SDL_QUIT:
                    isRunning = false;
                    break;

                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                    case SDLK_ESCAPE:
                        isRunning = false;
                        break;
                    }
                }
            }
#ifdef GL
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            SDL_GL_SwapWindow(window);
#else
            float RGBColor[3];
            SDL_SetRenderDrawColor(renderer, RGBColor[1], RGBColor[2], RGBColor[3], 255);
            ui.create();
            SDL_RenderClear(renderer);

            ImGui::Begin("BK");
            ImGui::ColorEdit3("t", RGBColor);
            ImGui::End();
            ui.render(renderer);

            SDL_RenderPresent(renderer);
#endif
        }
    }
}
