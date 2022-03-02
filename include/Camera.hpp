#ifndef INCLUDE_CAMERA_HPP
#define INCLUDE_CAMERA_HPP

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
};

#endif // INCLUDE_CAMERA_HPP
