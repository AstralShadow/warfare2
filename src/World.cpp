#include "World.hpp"
#include "Entity.hpp"
#include "KeyboardController.hpp"
#include <memory.h>

using std::make_shared;


World::World()
{
    auto entity = make_shared<Entity>
        (this, SDL_FPoint{50, 50},
         make_shared<KeyboardController>());
    _entities.push_back(entity);
}

void World::tick(uint64_t ms)
{
    for(auto entity : _entities)
        entity->tick(ms);
}
