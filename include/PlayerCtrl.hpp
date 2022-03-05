#ifndef INCLUDE_PLAYERCTRL_HPP
#define INCLUDE_PLAYERCTRL_HPP

#include "Controller.hpp"
#include <memory>
using std::shared_ptr;

#include <SDL2/SDL_rect.h>

class PlayerCtrl;
extern shared_ptr<PlayerCtrl> player_ctrl;


class PlayerCtrl : public Controller
{
public:
    PlayerCtrl() = default;
    virtual ~PlayerCtrl() = default;

    void set_mouse_state(SDL_FPoint state)
        { _mouse_state = state; }
    void set_hold_m1(bool pressed)
        { _hold_m1 = pressed; }
    
    void apply(Entity*, float distance);

private:
    bool _hold_m1 = false;
    SDL_FPoint _mouse_state{0, 0};
};

#endif // INCLUDE_PLAYERCTRL_HPP
