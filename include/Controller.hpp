#ifndef INCLUDE_CONTROLLER_HPP
#define INCLUDE_CONTROLLER_HPP

#include <cstdint>
class Entity;


class Controller
{
public:
    virtual ~Controller() = default;
    
    virtual void apply(Entity*, uint64_t ms) = 0;

protected:
    Controller() = default;
};

#endif // INCLUDE_CONTROLLER_HPP
