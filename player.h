#ifndef PLAYER_H_
#define PLAYER_H_

#include <Siv3D.hpp>

#include "core.h"

class Player
{
private:
	double m_x = 100;
	double m_y = GROUND_Y;
	double m_speed = 3;
	double m_jump_power = 50;
	Stopwatch m_stopwatch{ StartImmediately::No };
	Stopwatch m_push_time{ StartImmediately::No };

public:
	/// <summary>
	/// êŠ‚Ìİ’è
	/// </summary>
	/// <param name="x">xÀ•W</param>
	/// <param name="y">yÀ•W</param>
	void setPos(double x, double y);

	/// <summary>
	/// ©‹@‚ğ“®‚©‚·
	/// </summary>
	void move();

	/// <summary>
	///	•`‰æ
	/// </summary>
	void draw();
};

#endif // !PLAYER_H_
