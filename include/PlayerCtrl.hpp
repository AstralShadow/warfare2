#ifndef INCLUDE_PLAYERCTRL_HPP
#define INCLUDE_PLAYERCTRL_HPP

#include "Controller.hpp"
#include <memory>
using std::shared_ptr;

class PlayerCtrl;
extern shared_ptr<PlayerCtrl> player_ctrl;


class PlayerCtrl : public Controller
{
public:
    PlayerCtrl() = default;
    virtual ~PlayerCtrl() = default;
    
    void apply(Entity*, float distance);

};

#endif // INCLUDE_PLAYERCTRL_HPP
