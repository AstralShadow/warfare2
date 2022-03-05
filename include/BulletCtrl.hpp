#ifndef INCLUDE_BULLETCTRL_HPP
#define INCLUDE_BULLETCTRL_HPP

#include "Controller.hpp"
#include "Bullet.hpp"
#include <SDL2/SDL_rect.h>
#include <memory>
using std::shared_ptr;

class BulletCtrl;
extern shared_ptr<BulletCtrl> bullet_ctrl;


class BulletCtrl : public Controller
{
public:
    BulletCtrl() = default;
    virtual ~BulletCtrl() = default;
    
    void apply(Entity*, float distance);

private:
    SDL_FPoint _direction;
};

#endif // INCLUDE_BULLETCTRL_HPP
