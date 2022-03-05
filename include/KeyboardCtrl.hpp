#ifndef INCLUDE_KEYBOARDCTRL_HPP
#define INCLUDE_KEYBOARDCTRL_HPP

#include "Controller.hpp"


class KeyboardCtrl : public Controller
{
public:
    KeyboardCtrl() = default;
    virtual ~KeyboardCtrl() = default;
    
    void apply(Entity*, float distance);

};

#endif // INCLUDE_KEYBOARDCTRL_HPP
