#include "Bullet.hpp"
#include "BulletCtrl.hpp"


Bullet::Bullet(World* world, Entity* soldier) :
    Entity(world, soldier->_pos, bullet_ctrl)
{
    _direction = soldier->_direction;
    _pos.x += _direction.x * soldier->_size;
    _pos.y += _direction.y * soldier->_size;

    _color = {255, 0, 0, 255};
    _size = 4;
    _speed = 2;
}
