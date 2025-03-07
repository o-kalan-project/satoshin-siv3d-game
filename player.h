#ifndef PLAYER_H_
#define PLAYER_H_

#include <Siv3D.hpp>

#include "core.h"

class Player
{
private:
	double m_x = 100;
	double m_y = GROUND_Y;
	double m_jumped_y = GROUND_Y;
	const double m_speed = 3;
	double m_raw_speed;
	double m_jump_power = 50;
	const double m_radius = 10;
	Stopwatch m_stopwatch{ StartImmediately::No };
	Stopwatch m_push_time{ StartImmediately::No };

public:
	double x;
	double y;

	/// <summary>
	/// 場所の設定
	/// </summary>
	/// <param name="x">x座標</param>
	/// <param name="y">y座標</param>
	void setPos(double x, double y);

	/// <summary>
	/// 自機を動かす
	/// </summary>
	void move();

	/// <summary>
	///	描画
	/// </summary>
	void draw();
};

#endif // !PLAYER_H_
