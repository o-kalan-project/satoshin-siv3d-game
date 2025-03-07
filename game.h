#ifndef GAME_H_
#define GAME_H_

#include <Siv3D.hpp>

#include "core.h"
#include "player.h"
#include "danmaku.h"
#include "bullet.h"

class Game
{
private:
	Player m_player;
	Danmaku m_danmaku[5];
	const Font m_font{ 30, Typeface::Bold };
	Bullet m_bullet;

	/// <summary>
	/// �n�ʂ̕\��
	/// </summary>
	void drawGround();

public:
	void init();

	/// <summary>
	/// ���X�e�[�W
	/// </summary>
	/// <returns>�Q�[�����</returns>
	int stageOneScreen();
};


#endif // !GAME_H_
