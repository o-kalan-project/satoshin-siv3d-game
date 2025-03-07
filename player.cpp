#include "player.h"

#include <algorithm>

#include <Siv3D.hpp>

#include "core.h"

void Player::setPos(double x, double y)
{
	m_x = x;
	m_y = y;
}

void Player::move()
{
	// �����ړ�
	if (KeyRight.pressed())
	{
		m_x += m_speed;
	}
	if (KeyLeft.pressed())
	{
		m_x -= m_speed;
	}

	// �W�����v
	if (KeyUp.down())
	{
		// �����Ă��鎞�Ԍv���J�n
		m_push_time.restart();
	}
	
	if (KeyUp.up())
	{
		m_jump_power = std::clamp(m_push_time.sF() * 110, 20.0, 110.0);
		m_jumped_y = m_y;
		m_stopwatch.restart();
	}

	// ���������グ�^��
	m_y = m_jumped_y - m_jump_power * m_stopwatch.sF() * 10 + GRAVITY_CONST * m_stopwatch.sF() * m_stopwatch.sF() * 0.5 * 100;
	
	x = m_x = std::clamp(m_x, 0.0, static_cast<double>(WIDTH_X));
	y = m_y = std::clamp(m_y, 0.0, static_cast<double>(GROUND_Y - m_radius));

	// �v���C���[�̕`��
	draw();
}

void Player::draw()
{
	Circle(m_x, m_y, m_radius).draw(Palette::Red);
}
