#include <iostream>
#include <string>

#include "Base/Game.h"

int main()
{
    fw::App* app = new fw::Game();

    app->start();

    return 0; 
}
