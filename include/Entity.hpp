#ifndef INCLUDE_ENTITY_HPP
#define INCLUDE_ENTITY_HPP

#include <memory>
using std::shared_ptr;
#include <SDL2/SDL_rect.h>

struct SDL_Renderer;
class Controller;
class World;


class Entity
{
public:
    Entity(World*, SDL_FPoint,
           shared_ptr<Controller> = nullptr);
    ~Entity() = default;

    void render(SDL_Renderer* rnd,
                SDL_FPoint offset,
                float zoom = 1);

    void tick(uint64_t ms);

    SDL_FPoint& pos() { return _pos; }

private:
    World* _world;
    shared_ptr<Controller> _controller;

    SDL_FPoint _pos;
    SDL_Color _color;
    float _size;
};

#endif // INCLUDE_ENTITY_HPP
