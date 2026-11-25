#include "Game/Game.h"
#include <ctime>
#include <cstdlib>

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));
    DontCrashMyCar::Game game = DontCrashMyCar::Game();
    game.run();
}