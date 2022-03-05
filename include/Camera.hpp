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

    World* _world;
    SDL_FPoint _offset;
    float _zoom = 1.0f;

    void render(SDL_Renderer*);

    void tick(float ms);
    SDL_FPoint mouse_state() const;

private:
    void render_mouse(SDL_Renderer*);

};

#endif // INCLUDE_CAMERA_HPP
