#ifndef INCLUDE_HITBOX_HPP
#define INCLUDE_HITBOX_HPP

#include <cstdint>
#include <SDL2/SDL_rect.h>


namespace hitbox_t
{
    enum value : uint8_t
    {
        wall,
        circle,
        rect 
    };
}

class Wall;
class Circle;
class Rect;


class Hitbox
{
public:
    virtual ~Hitbox() = 0;

    virtual hitbox_t::value type() = 0;

    virtual bool contains(SDL_Point const&) = 0; 

    bool overlaps(Hitbox*) const;
    bool overlaps(Wall*) const;
    bool overlaps(Circle*) const;
    bool overlaps(Rect*) const;

protected:
    Hitbox() = default;
};

#endif // INCLUDE_HITBOX_HPP
