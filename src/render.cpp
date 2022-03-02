#include "render.hpp"

void render_circle(SDL_Renderer* rnd,
                   SDL_Point pos, int r)
{
    SDL_Point points[8];
    int x = 0, y = r;
    int e = 3 - 2 * r;

    while(y > x)
    {
        points[0].x = points[2].x = pos.x + x;
        points[1].x = points[3].x = pos.x - x;
        points[0].y = points[1].y = pos.y + y;
        points[2].y = points[3].y = pos.y - y;
        points[4].x = points[6].x = pos.x + y;
        points[5].x = points[7].x = pos.x - y;
        points[4].y = points[5].y = pos.y + x;
        points[6].y = points[7].y = pos.y - x;

        SDL_RenderDrawLines(rnd, &points[0], 2);
        SDL_RenderDrawLines(rnd, &points[2], 2);
        SDL_RenderDrawLines(rnd, &points[4], 2);
        SDL_RenderDrawLines(rnd, &points[6], 2);

        if(e > 0)
        {
            y--;
            e += 2 * (5 - 2*y + 2*x);
        }
        else
        {
            e += 2 * (3 + 2*x);
        }
        x++;
    }
}

