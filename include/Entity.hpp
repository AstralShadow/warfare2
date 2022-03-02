#ifndef INCLUDE_ENTITY_HPP
#define INCLUDE_ENTITY_HPP

#include <SDL2/SDL_rect.h>

struct SDL_Renderer;


class Entity
{
public:
    Entity(SDL_FPoint);
    ~Entity() = default;

    void render(SDL_Renderer* rnd,
                SDL_FPoint offset,
                float zoom = 1);

    SDL_FPoint& pos() { return _pos; }

private:
    SDL_FPoint _pos;
};

#endif // INCLUDE_ENTITY_HPP
