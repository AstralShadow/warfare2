#ifndef INCLUDE_BULLET_HPP
#define INCLUDE_BULLET_HPP

#include "Entity.hpp"


class Bullet : public Entity
{
public:
    Bullet(World*, Entity*);
    virtual ~Bullet() = default;

    virtual void render(SDL_Renderer* rnd, Camera*);
};

#endif // INCLUDE_BULLET_HPP
