#include "player.h"

#include <algorithm>

#include <Siv3D.hpp>

#include "core.h"

#define GRAVITY_OPERATE 0 // 重力演算を行うかどうか

void Player::setPos(double x, double y)
{
	m_x = x;
	m_y = y;
}

void Player::move()
{
	m_raw_speed = KeyLShift.pressed() ? m_speed * 0.5 : m_speed;

	if (KeyRight.pressed())
	{
		m_x += m_raw_speed;
	}
	if (KeyLeft.pressed())
	{
		m_x -= m_raw_speed;
	}
	if (KeyUp.pressed())
	{
		m_y -= m_raw_speed;
	}
	if (KeyDown.pressed())
	{
		m_y += m_raw_speed;
	}

#if GRAVITY_OPERATE
	// ジャンプ
	if (KeyUp.down())
	{
		// 押している時間計測開始
		m_push_time.restart();
	}
	
	if (KeyUp.up())
	{
		m_jump_power = std::clamp(m_push_time.sF() * 110, 20.0, MAX_JUMP_POWER);
		m_jumped_y = m_y;
		m_stopwatch.restart();
	}

	// 鉛直投げ上げ運動
	m_y = m_jumped_y - m_jump_power * m_stopwatch.sF() * 10 + GRAVITY_CONST * m_stopwatch.sF() * m_stopwatch.sF() * 0.5 * 100;
#endif

	x = m_x = std::clamp(m_x, 0.0, static_cast<double>(WIDTH_X));
	y = m_y = std::clamp(m_y, static_cast<double>(CEILING_Y + m_radius), static_cast<double>(GROUND_Y - m_radius));

	// プレイヤーの描画
	draw();
}

void Player::draw()
{
	Circle(m_x, m_y, m_radius).draw(Palette::Red);
}
