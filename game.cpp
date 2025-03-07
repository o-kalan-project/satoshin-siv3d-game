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

	// �R�����g�̕`��
	for (int i = 0; i < 5; ++i)
	{
		m_danmaku[i].draw();
	}

	// �v���C���[�̈ړ�
	m_player.move();

	return STAGE_ONE_SCREEN;
}
