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
    virtual ~Area() = default;

    virtual area_t::value type() const = 0;


    virtual bool contains(SDL_FPoint const&) const = 0;
    virtual bool intersects(
        float* x1, float* y1,
        float* x2, float* y2
    ) const = 0;
    virtual bool intersects(
        const float* x1, const float* y1,
        const float* x2, const float* y2,
        float* int_x = null, float* int_y = null
    ) const = 0;


    bool overlaps(const Area*) const;

    virtual bool overlaps(const Rect*) const = 0;
    virtual bool overlaps(const Circle*) const = 0;

protected:
    Area() = default;

};


template<class T> class TArea;

#define Gen_TArea(area_type, class_name) \
    template<> \
    struct TArea<class_name> : public Area \
    { \
        virtual area_t::value type() const \
            { return area_type; } \
    };

Gen_TArea(area_t::circle, Circle);
Gen_TArea(area_t::rect, Rect);

#undef Gen_TArea


#endif // INCLUDE_AREA_HPP
