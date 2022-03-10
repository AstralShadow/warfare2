#ifndef INCLUDE_CIRCLE_HPP
#define INCLUDE_CIRCLE_HPP

#include "Area.hpp"
#include "SDL2/SDL_rect.h"


class Circle : public TArea<Circle>
{
public:
    Circle() = default;
    Circle(SDL_FPoint pos, float radius);
    Circle(SDL_Point pos, float radius);

    virtual ~Circle() = default;


    SDL_FPoint _pos = {0, 0};
    float _size = 0;

    bool contains(SDL_FPoint const&) const;

    bool overlaps(const Rect*) const;
    bool overlaps(const Circle*) const;

};

#endif // INCLUDE_CIRCLE_HPP
