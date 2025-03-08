# include <Siv3D.hpp>

#include "core.h"
#include "game.h"

void Main()
{
    // Set background color to sky blue
    Scene::SetBackground(ColorF{ 0.8, 0.9, 1.0 });

	Game game;
	int game_state = TITLE_SCREEN;

	game.init(U"other");

    while (System::Update())
    { 
        switch (game_state)
        {
		case TITLE_SCREEN:
			game_state = game.titleScreen();
			break;

        // ステージ１（ごちうさ）
        case STAGE_ONE_SCREEN:
			game_state = game.stageOneScreen();
            break;
        }
    }
}
