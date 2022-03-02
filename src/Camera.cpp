#include "Camera.hpp"
#include "World.hpp"
#include <SDL2/SDL_render.h>


Camera::Camera(World* world) :
    _world(world)
{

}

Camera::~Camera()
{ }


static SDL_Point get_output_size(SDL_Renderer* rnd)
{
    SDL_Point size;
    SDL_GetRendererOutputSize(rnd, &size.x, &size.y);
    return size;
}

void Camera::render(SDL_Renderer* rnd)
{
    auto screen = get_output_size(rnd);
    SDL_FPoint points[2] = {{5, 5}, {20, 20}};
    SDL_SetRenderDrawColor(rnd, 255, 255, 255, 255);
    SDL_RenderDrawLinesF(rnd, points, 2);
}
