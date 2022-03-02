#include "Engine.hpp"
#include <SDL2/SDL.h>
#include <stdexcept>
#include <queue>

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


#include <iostream>
using namespace std;

void Engine::run()
{
    static uint64_t min_sleep_delay = [](){
        auto test_start = SDL_GetTicks64();
        SDL_Delay(1);
        auto test_end = SDL_GetTicks64();
        return test_end - test_start;
    }();

    auto last_t = SDL_GetTicks64();

#ifdef ENGINE_CALCULATE_FPS
    std::queue<uint64_t> frames;
#endif

    _running = true;
    while(_running)
    {
        auto start_t = SDL_GetTicks64();
        auto progress = start_t - last_t;
        last_t = start_t;

        poll_events();
        tick(progress);
        render();

        #ifdef ENGINE_CALCULATE_FPS
            auto now = SDL_GetTicks64();
            frames.push(now);
            while(frames.front() + 1000 < now)
                frames.pop();
            _fps = frames.size();
        #endif

        auto end_t = SDL_GetTicks64();
        auto tick_t = end_t - start_t;
        auto sleep_t = _tick_delay - tick_t;
        
        if(sleep_t <= min_sleep_delay)
            while(SDL_GetTicks64() < start_t + sleep_t);
        else SDL_Delay(sleep_t);
    }
}


void Engine::poll_events()
{
    SDL_Event ev;
    while(SDL_PollEvent(&ev))
    {
        switch(ev.type)
        {

            case SDL_QUIT:
            {
                _running = false;
                break;
            }

        }
    }
}

void Engine::render()
{

}

void Engine::tick(uint64_t ms)
{

}
