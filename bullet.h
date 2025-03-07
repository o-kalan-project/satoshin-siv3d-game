#ifndef BULLET_H_
#define BULLET_H_

#include <vector>

#include "core.h"
#include "player.h"

class Bullet
{
private:
	int m_index = 0;
	const double m_radius = 5;
	const double m_speed = 3;
	std::vector<double> m_x = std::vector<double>(100, -m_radius);
	std::vector<double> m_y = std::vector<double>(100, 0);

public:
	void draw(const Player player);
};

#endif // !BULLET_H_
