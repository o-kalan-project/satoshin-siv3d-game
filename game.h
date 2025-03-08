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
	Danmaku m_danmaku[MAX_COMMENT_NUM];
	const Font m_font{ FontMethod::SDF, 30, Typeface::Bold };
	Bullet m_bullet;

	/// <summary>
	/// �n�ʂ̕\��
	/// </summary>
	void drawGroundAndCeiling();

public:
	/// <summary>
	/// ������
	/// </summary>
	/// <param name="name">�R�����g�̖��O</param>
	void init(const String name);

	int titleScreen();

	/// <summary>
	/// ���X�e�[�W
	/// </summary>
	/// <returns>�Q�[�����</returns>
	int stageOneScreen();
};


#endif // !GAME_H_
