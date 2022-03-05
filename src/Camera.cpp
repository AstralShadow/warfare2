#include "Camera.hpp"
#include "World.hpp"
#include "Entity.hpp"
#include "render.hpp"
#include "PlayerCtrl.hpp"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_mouse.h>


Camera::Camera(World* world) :
    _world(world), _offset({0, 0})
{ }

Camera::~Camera()
{ }


void Camera::render(SDL_Renderer* rnd)
{
    auto screen = get_output_size(rnd);

    for(auto entity : _world->_entities)
        entity->render(rnd, _offset, _zoom);

    render_mouse(rnd);
}

void Camera::render_mouse(SDL_Renderer* rnd)
{
    int x, y;
    SDL_GetMouseState(&x, &y);

    float inner_range = 100;
    float outer_range = 100;
    
    SDL_SetRenderDrawColor(rnd, 255, 255, 255, 255);
    render_draw_circle(rnd, {x, y}, inner_range * _zoom);
    render_draw_circle(rnd, {x, y},
        (inner_range + outer_range) * _zoom);
}

void Camera::tick(float)
{
    _world->set_mouse_state(this->mouse_state());
    player_ctrl->set_mouse_state(this->mouse_state());
}

SDL_FPoint Camera::mouse_state() const
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    return {
        x / _zoom + _offset.x,
        y / _zoom + _offset.y
    };
}

