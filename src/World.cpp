#include "World.hpp"
#include "Entity.hpp"
#include "KeyboardCtrl.hpp"
#include <memory.h>
#include <cmath>
#include <SDL2/SDL_mouse.h>

using std::make_shared;


World::World() :
    _mouse_state{0, 0}
{
    auto entity = make_shared<Entity>
        (this, SDL_FPoint{50, 50},
         make_shared<KeyboardCtrl>());
    _entities.push_back(entity);
}


#include <iostream>
using namespace std;

void World::tick(float ms)
{
    auto& mouse = _mouse_state;
    float outer_range = 100;
    float inner_range = 100;

    for(auto entity : _entities)
    {
        auto& pos = entity->_pos;
        int distance = hypot(mouse.x - pos.x,
                             mouse.y - pos.y);

        float remoteness = max(0.0f, min(1.0f,
            (distance - inner_range) / outer_range));

        entity->tick(ms * (1 - remoteness));
    }
}
