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
	if (KeyRight.pressed())
	{
		m_x += m_speed;
	}
	if (KeyLeft.pressed())
	{
		m_x -= m_speed;
	}

	// ジャンプ
	if (m_y == GROUND_Y && KeyUp.down())
	{
		// 押している時間計測開始
		m_push_time.restart();
	}
	if (m_y == GROUND_Y && KeyUp.up())
	{
		m_jump_power = std::clamp(m_push_time.sF() * 110, 20.0, 110.0);

		m_stopwatch.restart();
	}

	m_y = GROUND_Y - m_jump_power * m_stopwatch.sF() * 10 + GRAVITY_CONST * m_stopwatch.sF() * m_stopwatch.sF() * 0.5 * 100;
	
	m_x = std::clamp(m_x, 0.0, static_cast<double>(WIDTH_X));
	m_y = std::clamp(m_y, 0.0, static_cast<double>(GROUND_Y));

	draw();
}

void Player::draw()
{
	Circle(m_x, m_y, 10).draw(Palette::Red);
}
