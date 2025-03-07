#include "danmaku.h"

#include <Siv3D.hpp>

#include "core.h"

void Danmaku::init(const String name)
{
	m_name = name;						// �g�������R�����g�̖��O��ݒ�
	m_num_data = m_json[name].size();	// �R�����g�̃f�[�^�̐����擾
	m_index = Random(m_num_data - 1);	// �R�����g�̃f�[�^�̃C���f�b�N�X�������_���ɐݒ�
	m_y = Random(GROUND_Y);				// �R�����g��y���W�������_���ɐݒ�

	for (int i = 0; i < m_num_data; ++i)
	{
		m_font.preload(m_json[name][Format(i)].getString().sorted_and_uniqued());

		m_comment.emplace_back(m_font(m_json[name][Format(i)].getString()));
	}
}

void Danmaku::draw()
{
	m_x -= m_speed;

	m_comment_rect = m_comment[m_index].draw(TextStyle::Outline(0.3, {0, 0, 0}), m_x, m_y);

	// �R�����g����ʊO�ɏo����Ĕz�u
	if (m_x < -m_comment_rect.size.x)
	{
		// �R�����g�̃f�[�^�̃C���f�b�N�X���X�V
		m_index = Random(m_num_data - 1);

		// �����_����y���W�ɍĔz�u
		m_y = Random(static_cast<double>(GROUND_Y));

		// x���W��������
		m_x = WIDTH_X;
	}
}
