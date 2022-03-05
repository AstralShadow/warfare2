#include "Entity.hpp"
#include "render.hpp"
#include "Controller.hpp"
#include <SDL2/SDL_render.h>


Entity::Entity(World* world, SDL_FPoint pos,
               shared_ptr<Controller> ctrl) :
    _world(world),
    _controller(ctrl),
    _pos(pos),
    _direction{0, 0},
    _color{0, 127, 0, 255},
    _size(16),
    _speed(0.3)
{ }


void Entity::render(SDL_Renderer* rnd,
                    SDL_FPoint offset, float zoom)
{
    SDL_Point pos;
    pos.x = (_pos.x - offset.x) * zoom;
    pos.y = (_pos.y - offset.y) * zoom;

    SDL_SetRenderDrawColor(rnd, _color.r, _color.g,
                                _color.b, _color.a);
    render_fill_circle(rnd, pos, _size * zoom);
}

void Entity::tick(float milliseconds)
{
    if(_controller)
        _controller->apply(this, milliseconds * _speed);
}
