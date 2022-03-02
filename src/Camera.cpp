#include "Camera.hpp"
#include "World.hpp"
#include "render.hpp"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL.h>
#include <cmath>
#include <algorithm>


Camera::Camera(World* world) :
    _world(world)
{

}

Camera::~Camera()
{ }


void Camera::render(SDL_Renderer* rnd)
{
    auto screen = get_output_size(rnd);

    SDL_SetRenderDrawColor(rnd, 255, 255, 255, 255);
    render_circle(rnd, {400, 300}, 250);
}


