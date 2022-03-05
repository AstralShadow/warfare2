#include "PlayerCtrl.hpp"
#include "Entity.hpp"
#include <SDL2/SDL_events.h>
#include <cmath>

shared_ptr<PlayerCtrl> player_ctrl = 
    std::make_shared<PlayerCtrl>();


void PlayerCtrl::apply
    (Entity* entity, float distance)
{
    static auto* state = SDL_GetKeyboardState(nullptr);
    
    if(state[SDL_SCANCODE_W] || state[SDL_SCANCODE_UP])
        entity->_pos.y -= distance;
    if(state[SDL_SCANCODE_S] || state[SDL_SCANCODE_DOWN])
        entity->_pos.y += distance;
    if(state[SDL_SCANCODE_A] || state[SDL_SCANCODE_LEFT])
        entity->_pos.x -= distance;
    if(state[SDL_SCANCODE_D] || state[SDL_SCANCODE_RIGHT])
        entity->_pos.x += distance;

    if(_hold_m1)
        entity->shoot();

    auto& pos = entity->_pos;
    float d_x = _mouse_state.x - pos.x;
    float d_y = _mouse_state.y - pos.y;
    float base = hypot(d_x, d_y);
    
    entity->_direction.x = d_x / base;
    entity->_direction.y = d_y / base;

}
