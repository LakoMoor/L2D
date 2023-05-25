#include <L2DE/L2DE.h>

int main()
{
    l2de::Renderer renderer;
    #ifdef DEBUG
    renderer.createWindow("My Window DEBUG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
    renderer.runGameLoop(true);
    #endif
    #ifdef RELEASE
    renderer.createWindow("My Window RELEASE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
    renderer.runGameLoop(true);
    #endif
    
    return 0;
}
