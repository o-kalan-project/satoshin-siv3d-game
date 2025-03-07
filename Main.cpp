# include <Siv3D.hpp>

#include "core.h"
#include "game.h"

void Main()
{
    // Set background color to sky blue
    Scene::SetBackground(ColorF{ 0.8, 0.9, 1.0 });

	Game game;
	int game_state = STAGE_ONE_SCREEN;

	game.init();

    while (System::Update())
    { 
        switch (game_state)
        {
        case STAGE_ONE_SCREEN:
			game_state = game.stageOneScreen();
            break;
        default:
            break;
        }
    }
}
