#ifndef INCLUDE_CONTROLLER_HPP
#define INCLUDE_CONTROLLER_HPP

class Entity;


class Controller
{
public:
    virtual ~Controller() = default;
    
    virtual void apply(Entity*, float distance) = 0;

protected:
    Controller() = default;
};

#endif // INCLUDE_CONTROLLER_HPP
