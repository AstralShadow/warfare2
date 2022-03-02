#include "Engine.hpp"
#include <SDL2/SDL.h>
#include <stdexcept>

using std::runtime_error;

static const char* TITLE = "Slow Motion Warfare 2.0";
static const int WIDTH = 800, HEIGHT = 600;


Engine::Engine()
{
    if(SDL_Init(SDL_INIT_VIDEO))
        throw runtime_error("Could not init SDL2.");

    _window = SDL_CreateWindow(
        TITLE, 
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WIDTH, HEIGHT,
        0
    );
    if(!_window)
    {
        throw runtime_error(
            std::string("Could not create window. ")
            + SDL_GetError());
    }

    _renderer = SDL_CreateRenderer(_window, -1, 0);
    if(!_renderer)
    {
        throw runtime_error(
            std::string("Could not create renderer.")
            + SDL_GetError());
    }
}

Engine::~Engine()
{
    if(_renderer)
        SDL_DestroyRenderer(_renderer);
    if(_window)
        SDL_DestroyWindow(_window);
    SDL_Quit();
}


void Engine::run()
{

}

