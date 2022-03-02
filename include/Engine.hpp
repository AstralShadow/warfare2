#ifndef INCLUDE_ENGINE_HPP
#define INCLUDE_ENGINE_HPP

struct SDL_Window;
struct SDL_Renderer;


class Engine
{
public:
    Engine();
    ~Engine();

    void run();

private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;

    bool _running;


    void poll_events();
};

#endif // INCLUDE_ENGINE_HPP
