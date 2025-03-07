#include "game.h"

#include "core.h"
#include <Siv3D.hpp>

void Game::init(const String name)
{
	// �R�����g�̏�����
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

int Game::stageOneScreen()
{
	drawGroundAndCeiling();

	m_font(U"FPS: {}"_fmt(Format(Profiler::FPS()))).draw(WIDTH_X - 170, WIDTH_Y - 100, Palette::White);

	// �R�����g�̕`��
	for (int i = 0; i < MAX_COMMENT_NUM; ++i)
	{
		m_danmaku[i].draw();
	}

	// �e�̕`��
	m_bullet.draw(m_player);

	// �v���C���[�̈ړ�
	m_player.move();

	return STAGE_ONE_SCREEN;
}
