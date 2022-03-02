#ifndef INCLUDE_ENGINE_HPP
#define INCLUDE_ENGINE_HPP

#include <cstdint>
#define ENGINE_CALCULATE_FPS true

#include "World.hpp"
#include "Camera.hpp"

struct SDL_Window;
struct SDL_Renderer;


class Engine
{
public:
    Engine();
    ~Engine();

    void run();
    int get_fps() const { return _fps; }

private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;

    World _world;
    Camera _camera;

    bool _running;
    int _fps = 0;
    int _tick_delay = 1000 / 60 + 1;

    void poll_events();
    void tick(uint64_t ms);
    void render();
};

#endif // INCLUDE_ENGINE_HPP
