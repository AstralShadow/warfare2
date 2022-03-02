#include "Entity.hpp"
#include "render.hpp"
#include <SDL2/SDL_render.h>


Entity::Entity(SDL_FPoint pos) :
    _pos(pos)
{ }


void Entity::render(SDL_Renderer* rnd,
                    SDL_FPoint offset, float zoom)
{
    SDL_Point pos;
    pos.x = (_pos.x - offset.x) * zoom;
    pos.y = (_pos.y - offset.y) * zoom;

    SDL_SetRenderDrawColor(rnd, 0, 255, 0, 255);
    render_fill_circle(rnd, pos, 30 * zoom);
    SDL_SetRenderDrawColor(rnd, 255, 0, 0, 255);
    
}
