#include "Camera.hpp"
#include "World.hpp"
#include "Entity.hpp"
#include "render.hpp"
#include <SDL2/SDL_render.h>


Camera::Camera(World* world) :
    _world(world), _offset({0, 0})
{ }

Camera::~Camera()
{ }


void Camera::render(SDL_Renderer* rnd)
{
    auto screen = get_output_size(rnd);

    SDL_SetRenderDrawColor(rnd, 255, 255, 255, 255);
    for(auto entity : _world->_entities)
        entity->render(rnd, _offset, _zoom);
}


