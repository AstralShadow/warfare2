#ifndef INCLUDE_WORLD_HPP
#define INCLUDE_WORLD_HPP

#include <vector>
#include <memory>
using std::vector;
using std::shared_ptr;

class Entity;


class World
{
public:
    World();
    ~World() = default;

    vector<shared_ptr<Entity>> _entities;

    void tick(float ms);
    
};

#endif // INCLUDE_WORLD_HPP
