#include "Entity.hpp"
#include "World.hpp"
#include "Controller.hpp"
#include "Bullet.hpp"
#include "Camera.hpp"
#include "render.hpp"
#include <SDL2/SDL_render.h>
#include <algorithm>


Entity::Entity(World* world, SDL_FPoint pos,
               shared_ptr<Controller> ctrl) :
    _world(world),
    _controller(ctrl),
    _pos(pos),
    _last_pos(pos),
    _direction{1, 0},
    _color{0, 127, 0, 255},
    _size(16),
    _speed(0.3)
{ }


void Entity::render(SDL_Renderer* rnd, Camera* cam)
{
    SDL_Point pos;
    pos.x = (_pos.x - cam->_offset.x) * cam->_zoom;
    pos.y = (_pos.y - cam->_offset.y) * cam->_zoom;

    SDL_SetRenderDrawColor(rnd, _color.r, _color.g,
                                _color.b, _color.a);
    render_fill_circle(rnd, pos, _size * cam->_zoom);
}

void Entity::tick(float ms)
{
    _shoot_timeout -= ms;
    _last_pos = _pos;
    if(_controller)
        _controller->apply(this, ms * _speed);
}

void Entity::shoot()
{
    if(_shoot_timeout > 0)
        return;
    _shoot_timeout = 200;
    auto bullet = std::make_shared<Bullet>(_world, this);
    _world->_entities.push_back(bullet);
}

void Entity::remove()
{
    _world->remove(this);
}
