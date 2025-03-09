#include "game.h"

#include "core.h"
#include <Siv3D.hpp>

void Game::init(const String name)
{
	// プレイヤーの初期化
	m_player.setPos(100, WIDTH_Y_HALF);

	// コメントの初期化
	for (Danmaku& danmaku : m_danmaku)
	{
		danmaku.init(name);
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
	for (Danmaku& danmaku : m_danmaku)
	{
		danmaku.draw();
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
	for (Danmaku& danmaku : m_danmaku)
	{
		danmaku.draw();

		if (danmaku.isHit(m_player))
		{
			init(U"other");
			return TITLE_SCREEN;
		}
	}

	return STAGE_ONE_SCREEN;
}
