#include <L2DE/L2DE.h>

int main(int argv, char** args)
{
    l2de::Renderer renderer;
    #ifdef DEBUG

    renderer.createWindow("(DEBUG) L2D (DEBUG)", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL| SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    renderer.runEngineLoop();

    #endif

    #ifdef RELEASE

    renderer.createWindow("L2D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
    renderer.runEngineLoop();
    
    #endif
    
    return 0;
}