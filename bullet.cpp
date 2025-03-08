#include "bullet.h"

#include <Siv3D.hpp>

void Bullet::draw(const Player player)
{
	if (KeyZ.pressed() && m_stopwatch == 0)
	{
		m_x[m_index] = player.x;
		m_y[m_index] = player.y;

		m_index = (m_index + 1) % 100;
	}

	for (int i = 0; i < 100; ++i)
	{
		if (0 <= m_x[i] && m_x[i] <= WIDTH_X + m_radius)
		{
			Circle(m_x[i], m_y[i], m_radius).draw(Palette::Hotpink);

			m_x[i] += m_speed;
		}
	}

	m_stopwatch = (m_stopwatch + 1) % 10;
}
