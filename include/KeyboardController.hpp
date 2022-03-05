#ifndef INCLUDE_KEYBOARDCONTROLLER_HPP
#define INCLUDE_KEYBOARDCONTROLLER_HPP

#include "Controller.hpp"


class KeyboardController : public Controller
{
public:
    KeyboardController() = default;
    virtual ~KeyboardController() = default;
    
    void apply(Entity*, float ms);

};

#endif // INCLUDE_KEYBOARDCONTROLLER_HPP
