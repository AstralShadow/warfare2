#include "World.hpp"
#include "Entity.hpp"
#include "PlayerCtrl.hpp"
#include <memory.h>
#include <cmath>
#include <SDL2/SDL_mouse.h>

using std::make_shared;


World::World() :
    _mouse_state{0, 0}
{
    auto entity = make_shared<Entity>
        (this, SDL_FPoint{50, 50}, player_ctrl);
    _entities.push_back(entity);

    entity = make_shared<Entity>
        (this, SDL_FPoint{750, 550}, player_ctrl);
    _entities.push_back(entity);
}


#include <iostream>
using namespace std;

void World::tick(float ms)
{
    auto& mouse = _mouse_state;
    float inner_range = 100;
    float outer_range = 150;

    for(auto entity : _entities)
    {
        if(!entity) continue;
        SDL_FPoint& pos = entity->_pos;
        float distance = hypot(mouse.x - pos.x,
                               mouse.y - pos.y);

        float remoteness = max(0.0f, min(1.0f,
            (distance - inner_range) / outer_range));

        entity->tick(ms * (1 - remoteness));
    }
}

void World::remove(Entity* entity)
{
    auto itr = _entities.begin();
    while(itr != _entities.end() && itr->get() != entity)
        itr++;

    if(itr == _entities.end())
        return;
    
    std::swap(*itr, _entities.back());
    _entities.pop_back();
}
