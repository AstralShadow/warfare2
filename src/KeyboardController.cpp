#include "KeyboardController.hpp"
#include "Entity.hpp"
#include <SDL2/SDL_events.h>


void KeyboardController::apply
    (Entity* entity, float ms)
{
    static auto* state = SDL_GetKeyboardState(nullptr);
    
    if(state[SDL_SCANCODE_W] || state[SDL_SCANCODE_UP])
        entity->pos().y -= ms;
    if(state[SDL_SCANCODE_S] || state[SDL_SCANCODE_DOWN])
        entity->pos().y += ms;
    if(state[SDL_SCANCODE_A] || state[SDL_SCANCODE_LEFT])
        entity->pos().x -= ms;
    if(state[SDL_SCANCODE_D] || state[SDL_SCANCODE_RIGHT])
        entity->pos().x += ms;


}
