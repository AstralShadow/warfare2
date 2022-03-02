#include "World.hpp"
#include "Entity.hpp"
#include <memory.h>

using std::make_shared;


World::World()
{
    auto entity = make_shared<Entity>(SDL_FPoint{50, 50});
    _entities.push_back(entity);
}
