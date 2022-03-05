#ifndef INCLUDE_BULLET_HPP
#define INCLUDE_BULLET_HPP

#include "Entity.hpp"


class Bullet : public Entity
{
public:
    Bullet(World*, Entity*);
    virtual ~Bullet() = default;

};

#endif // INCLUDE_BULLET_HPP
