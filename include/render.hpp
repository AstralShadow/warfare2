#ifndef INCLUDE_RENDER_HPP
#define INCLUDE_RENDER_HPP

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_rect.h>

void render_circle(SDL_Renderer*, SDL_Point pos, int r);

inline SDL_Point get_output_size(SDL_Renderer* rnd)
{
    SDL_Point size;
    SDL_GetRendererOutputSize(rnd, &size.x, &size.y);
    return size;
}

#endif // INCLUDE_RENDER_HPP
