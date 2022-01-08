#include "Base/Game.h"

int main()
{
    fw::App* app = new fw::Game();

    app->start();

    delete app;

    return 0; 
}
