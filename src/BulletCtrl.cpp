#include "BulletCtrl.hpp"
#include "Entity.hpp"
#include <SDL2/SDL_events.h>
#include <cmath>

shared_ptr<BulletCtrl> bullet_ctrl =
    std::make_shared<BulletCtrl>();


void BulletCtrl::apply(Entity* entity, float distance)
{
    
    entity->_pos.x += entity->_direction.x * distance;
    entity->_pos.y += entity->_direction.y * distance;
}
