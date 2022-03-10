#include <Hitbox.hpp>

bool Hitbox::overlaps(Hitbox* other) const
{
    using namespace hitbox_t;
    switch(other->type())
    {
        case wall:
            return this->overlaps((Wall*) other);

        case circle:
            return this->overlaps((Circle*) other);

        case rect:
            return this->overlaps((Rect*) other);
    }
}

bool Hitbox::overlaps(Wall* other) const
{

}

bool Hitbox::overlaps(Circle* other) const
{

}

bool Hitbox::overlaps(Rect* other) const
{

}
