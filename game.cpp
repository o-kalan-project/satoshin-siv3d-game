#include "game.h"

#include "core.h"
#include <Siv3D.hpp>

void Game::init(const String name)
{
	// コメントの初期化
	for (int i = 0; i < MAX_COMMENT_NUM; ++i)
	{
		m_danmaku[i].init(name);
	}
}

void Game::drawGroundAndCeiling()
{
	Rect(0, 0, WIDTH_X, CEILING_Y).draw(Palette::Black);
	Rect(0, GROUND_Y, WIDTH_X, WIDTH_Y).draw(Palette::Black);
}

int Game::titleScreen()
{
	drawGroundAndCeiling();

	// コメントの描画
	for (int i = 0; i < MAX_COMMENT_NUM; ++i)
	{
		m_danmaku[i].draw();
	}

	m_font(U"Press Space Key to Start").drawAt(TextStyle::Outline(0.3, Palette::Red), WIDTH_X_HALF, WIDTH_Y_HALF, Palette::White);

	if (KeySpace.down())
	{
		init(U"gochiusa");
		return STAGE_ONE_SCREEN;
	}
	return TITLE_SCREEN;
}

int Game::stageOneScreen()
{
	drawGroundAndCeiling();

	m_font(U"FPS: {}"_fmt(Format(Profiler::FPS()))).draw(WIDTH_X - 170, WIDTH_Y - 100, Palette::White);

	// 弾の描画
	m_bullet.draw(m_player);

	// プレイヤーの移動
	m_player.move();

	// コメントの描画
	for (int i = 0; i < MAX_COMMENT_NUM; ++i)
	{
		m_danmaku[i].draw();

		if (m_danmaku[i].isHit(m_player))
		{
			init(U"other");
			return TITLE_SCREEN;
		}
	}

	return STAGE_ONE_SCREEN;
}
