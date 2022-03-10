#ifndef INCLUDE_RECT_HPP
#define INCLUDE_RECT_HPP

#include "Area.hpp"
#include "SDL2/SDL_rect.h"


class Rect : public TArea<Rect>
{
public:
    Rect() = default;
    Rect(SDL_FRect area, float rotation = 0);
    Rect(SDL_Rect area, float rotation = 0);

    virtual ~Rect() = default;


    SDL_FRect _area = {0, 0, 0, 0};
    float _rotation = 0;


    bool contains(SDL_FPoint const&) const;

    bool overlaps(const Rect*) const;
    bool overlaps(const Circle*) const;

};

#endif // INCLUDE_RECT_HPP
