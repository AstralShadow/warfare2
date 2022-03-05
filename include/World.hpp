#ifndef INCLUDE_WORLD_HPP
#define INCLUDE_WORLD_HPP

#include <vector>
#include <memory>
using std::vector;
using std::shared_ptr;

#include <SDL2/SDL_rect.h>

class Entity;


class World
{
public:
    World();
    ~World() = default;

    vector<shared_ptr<Entity>> _entities;

    void tick(float ms);
    void set_mouse_state(SDL_FPoint state)
        { _mouse_state = state; }

    void remove(Entity*);
    
private:
    SDL_FPoint _mouse_state;
};

#endif // INCLUDE_WORLD_HPP
