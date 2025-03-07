#include "game.h"

#include "core.h"
#include <Siv3D.hpp>

void Game::init()
{
	// �R�����g�̏�����
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

	// �R�����g�̕`��
	for (int i = 0; i < 5; ++i)
	{
		m_danmaku[i].draw();
	}

	// �e�̕`��
	m_bullet.draw(m_player);

	// �v���C���[�̈ړ�
	m_player.move();

	return STAGE_ONE_SCREEN;
}
