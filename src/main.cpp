#include "Engine.hpp"

static Engine* game = nullptr;

int main(int, char**)
{
    game = new Engine();

    game->run();

    delete game;
    return 0;
}
