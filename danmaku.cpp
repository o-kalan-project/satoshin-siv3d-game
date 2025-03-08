#include "danmaku.h"

#include <Siv3D.hpp>

#include "core.h"

ColorF Danmaku::setColor(const int color) const
{
	switch (color)
	{
	case 0:
		return Palette::White;
	case 1:
		return Palette::Red;
	case 2:
		return Palette::Pink;
	case 3:
		return Palette::Orange;
	case 4:
		return Palette::Yellow;
	case 5:
		return Palette::Green;
	case 6:
		return Palette::Cyan;
	case 7:
		return Palette::Blue;
	case 8:
		return Palette::Purple;
	case 9:
		return Palette::Black;
	default:
		return Palette::White;
	}
}

void Danmaku::init(const String name)
{
	m_name = name;																	// �g�������R�����g�̖��O��ݒ�
	m_num_data = m_json[name].size();												// �R�����g�̃f�[�^�̐����擾
	m_index = Random(m_num_data - 1);												// �R�����g�̃f�[�^�̃C���f�b�N�X�������_���ɐݒ�
	m_x = WIDTH_X;																	// �R�����g��x���W��������
	m_y = Random(static_cast<double>(CEILING_Y), static_cast<double>(GROUND_Y));	// �R�����g��y���W�������_���ɐݒ�
	m_color = setColor(Random(0, 20));												// �R�����g�̐F��ݒ�

	m_comment.resize(0);
	for (int i = 0; i < m_num_data; ++i)
	{
		m_font.preload(m_json[name][Format(i)].getString().sorted_and_uniqued());

		m_comment.emplace_back(m_font(m_json[name][Format(i)].getString()));
	}
}

void Danmaku::draw()
{
	m_x -= m_speed;
	
	m_comment_rect = m_comment[m_index].draw(TextStyle::Outline(0.3, Palette::Black), m_x, m_y, m_color);

	// �R�����g����ʊO�ɏo����Ĕz�u
	if (m_x < -m_comment_rect.size.x)
	{
		// �R�����g�̃f�[�^�̃C���f�b�N�X���X�V
		m_index = Random(m_num_data - 1);

		// �����_����y���W�ɍĔz�u
		m_y = Random(static_cast<double>(CEILING_Y), static_cast<double>(GROUND_Y));

		// �����_���ȐF�ɍĐݒ�
		m_color = setColor(Random(0, 20));

		// x���W��������
		m_x = WIDTH_X;
	}
}

bool Danmaku::isHit(const Player player) const
{
	if (player.x < m_comment_rect.pos.x)
	{
		return false;
	}
	if (player.x > m_comment_rect.pos.x + m_comment_rect.size.x)
	{
		return false;
	}
	if (player.y < m_comment_rect.pos.y)
	{
		return false;
	}
	if (player.y > m_comment_rect.pos.y + m_comment_rect.size.y)
	{
		return false;
	}
	return true;
	// return m_comment_rect.intersects(player.hittable_circle);
}
