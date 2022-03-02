#ifndef INCLUDE_CAMERA_HPP
#define INCLUDE_CAMERA_HPP

#include <SDL2/SDL_rect.h>

class World;
struct SDL_Renderer;


class Camera
{
public:
    Camera(World*);
    ~Camera();

    void render(SDL_Renderer*);

private:
    World* _world;
    SDL_FPoint _offset;
    float _zoom = 1;
};

#endif // INCLUDE_CAMERA_HPP
