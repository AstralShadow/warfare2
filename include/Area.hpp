#ifndef INCLUDE_AREA_HPP
#define INCLUDE_AREA_HPP

#include <cstdint>
#include <SDL2/SDL_rect.h>


namespace area_t
{
    enum value : uint8_t
    {
        circle,
        rect 
    };
}

class Circle;
class Rect;


class Area
{
public:
    virtual ~Area() = 0;

    virtual area_t::value type() = 0;

    virtual bool contains(SDL_Point const&) = 0; 

    bool overlaps(Area*) const;

    bool overlaps(Circle*) const;
    bool overlaps(Rect*) const;

protected:
    Area() = default;
};

#endif // INCLUDE_AREA_HPP
