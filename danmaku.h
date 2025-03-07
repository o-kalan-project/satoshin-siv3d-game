#ifndef DANMAKU_H_
#define DANMAKU_H_

#include <vector>

#include <Siv3D.hpp>

#include "core.h"

class Danmaku
{
private:
	double m_x = WIDTH_X;													// �R�����g��x���W
	double m_y = Random(GROUND_Y);											// �R�����g��y���W
	double m_speed = 500 / 60.0;											// �R�����g�̃X�s�[�h
	int m_index = 0;														// �R�����g�̃f�[�^�̃C���f�b�N�X;
	int m_num_data;															// �R�����g�̃f�[�^�̐�
	std::vector<DrawableText> m_comment;									// �R�����g�̃f�[�^
	String m_name;															// �R�����g�̖��O
	RectF m_comment_rect;													// �R�����g�̉摜
	const JSON m_json = JSON::Load(U"resources/engine/danmaku_data.json");	// �R�����g�̃f�[�^
	const Font m_font{ FontMethod::SDF, 30, Typeface::Black };				// �R�����g�̃t�H���g

public:
	/// <summary>
	/// �e���R���̏�����
	/// </summary>
	/// <param name="name">�e���̖��O</param>
	void init(const String name);

	/// <summary>
	///	�`��
	/// </summary>
	void draw();
};

#endif // !DANMAKU_H_
