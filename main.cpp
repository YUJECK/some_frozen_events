#include <SFML/Graphics.hpp>
#include "apMoon/Game.h"
#include "Player.h"
#include "content/IntroLevel.h"

int main()
{
    srand(time(NULL));

    IntroLevel * intro = new IntroLevel;
    Game::get_instance()->load_scene(intro);

    Game::get_instance()->start_game_loop();

    return 0;
}