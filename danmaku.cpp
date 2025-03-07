#include "danmaku.h"

#include <Siv3D.hpp>

#include "core.h"

void Danmaku::init(const String name)
{
	m_name = name;						// 使いたいコメントの名前を設定
	m_num_data = m_json[name].size();	// コメントのデータの数を取得
	m_index = Random(m_num_data - 1);	// コメントのデータのインデックスをランダムに設定
	m_y = Random(GROUND_Y);				// コメントのy座標をランダムに設定

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

	// コメントが画面外に出たら再配置
	if (m_x < -m_comment_rect.size.x)
	{
		// コメントのデータのインデックスを更新
		m_index = Random(m_num_data - 1);

		// ランダムなy座標に再配置
		m_y = Random(static_cast<double>(GROUND_Y));

		// x座標を初期化
		m_x = WIDTH_X;
	}
}
