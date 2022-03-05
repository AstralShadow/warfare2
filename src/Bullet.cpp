#include "Bullet.hpp"
#include "BulletCtrl.hpp"
#include "Camera.hpp"
#include "render.hpp"


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


void Bullet::render(SDL_Renderer* rnd, Camera* cam)
{
    SDL_Point pos, pos2;
    pos.x = (_pos.x - cam->_offset.x) * cam->_zoom;
    pos.y = (_pos.y - cam->_offset.y) * cam->_zoom;
    pos2.x = (_last_pos.x - cam->_offset.x) * cam->_zoom;
    pos2.y = (_last_pos.y - cam->_offset.y) * cam->_zoom;

    SDL_SetRenderDrawColor(rnd, _color.r, _color.g,
                                _color.b, _color.a);
    render_draw_circle(rnd, pos, _size * cam->_zoom);
    SDL_RenderDrawLine(rnd, pos.x, pos.y, pos2.x, pos2.y);
}
