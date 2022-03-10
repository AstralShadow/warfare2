#include <Area.hpp>

bool Area::overlaps(Area* other) const
{
    using namespace area_t;
    switch(other->type())
    {
        case circle:
            return this->overlaps((Circle*) other);

        case rect:
            return this->overlaps((Rect*) other);
    }
}

bool Area::overlaps(Circle* other) const
{

}

bool Area::overlaps(Rect* other) const
{

}
