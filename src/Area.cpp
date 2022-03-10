#include "Area.hpp"
#include "Rect.hpp"
#include "Circle.hpp"
#include <cmath>
#include <stdexcept>

using std::hypot;


bool Area::overlaps(const Area* other) const
{
    switch(other->type())
    {
        case area_t::circle:
        {
            auto circle = dynamic_cast
                <const Circle*>(other);
            return this->overlaps(circle);
        }

        case area_t::rect:
        {
            auto rect = static_cast
                <const Rect*>(other);
            return this->overlaps(rect);
        }

        default:
            throw std::runtime_error
                ("Unknown area type");
    }
}


bool Circle::contains(SDL_FPoint const& point) const
{
    return hypot(point.x - _pos.x,
                 point.y - _pos.y) < _size;
}

bool Rect::contains(SDL_FPoint const& point) const
{
    return _area.x <= point.x &&
           _area.y <= point.y &&
           point.x < _area.x + _area.w &&
           point.y < _area.y + _area.h;
}


bool Circle::overlaps(const Circle* other) const
{
    float dist = hypot(other->_pos.x - _pos.x,
                      other->_pos.y - _pos.y);
    return dist < _size + other->_size;
}

bool Rect::overlaps(const Rect* other) const
{
    return _area.x < other->_area.x + other->_area.w &&
           _area.y < other->_area.y + other->_area.h &&
           other->_area.x < _area.x + _area.w &&
           other->_area.y < _area.y + _area.h;
}


bool Rect::overlaps(const Circle* other) const
{
    float x1 = other->_pos.x + other->_size;
    float x2 = other->_pos.x - other->_size;
    float y1 = other->_pos.y + other->_size;
    float y2 = other->_pos.y - other->_size;

    return _area.x < x1 &&
           _area.y < y1 &&
           x2 < _area.x + _area.w &&
           y2 < _area.y + _area.h;
}


bool Circle::overlaps(const Rect* other) const
{
    return other->overlaps(this);
}
