#include "game.h"

#include "core.h"
#include <Siv3D.hpp>

void Game::init()
{
	// コメントの初期化
	for (int i = 0; i < 5; ++i)
	{
		m_danmaku[i].init(U"gochiusa");
	}
}

void Game::drawGround()
{
	Rect(0, GROUND_Y, WIDTH_X, WIDTH_Y).draw(Palette::Black);
}

int Game::stageOneScreen()
{
	drawGround();

	m_font(Format(Profiler::FPS())).draw(WIDTH_X - 100, WIDTH_Y - 100, Palette::White);

	// コメントの描画
	for (int i = 0; i < 5; ++i)
	{
		m_danmaku[i].draw();
	}

	// 弾の描画
	m_bullet.draw(m_player);

	// プレイヤーの移動
	m_player.move();

	return STAGE_ONE_SCREEN;
}
