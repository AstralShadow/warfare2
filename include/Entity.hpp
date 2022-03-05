#ifndef INCLUDE_ENTITY_HPP
#define INCLUDE_ENTITY_HPP

#include <memory>
using std::shared_ptr;
#include <SDL2/SDL_rect.h>

struct SDL_Renderer;
class Controller;
class World;
class Camera;


class Entity
{
public:
    Entity(World*, SDL_FPoint,
           shared_ptr<Controller> = nullptr);
    virtual ~Entity() = default;

    World* _world;
    shared_ptr<Controller> _controller;

    SDL_FPoint _pos;
    SDL_FPoint _last_pos;
    SDL_FPoint _direction;
    SDL_Color _color;
    float _size;
    float _speed;


    virtual void render(SDL_Renderer*, Camera*);

    void tick(float ms);

    void shoot();

    void remove();

private:
    float _shoot_timeout = 0;

};

#endif // INCLUDE_ENTITY_HPP
