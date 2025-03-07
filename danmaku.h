#ifndef DANMAKU_H_
#define DANMAKU_H_

#include <vector>

#include <Siv3D.hpp>

#include "core.h"

class Danmaku
{
private:
	double m_x = WIDTH_X;													// コメントのx座標
	double m_y = Random(GROUND_Y);											// コメントのy座標
	double m_speed = 500 / 60.0;											// コメントのスピード
	int m_index = 0;														// コメントのデータのインデックス;
	int m_num_data;															// コメントのデータの数
	std::vector<DrawableText> m_comment;									// コメントのデータ
	String m_name;															// コメントの名前
	RectF m_comment_rect;													// コメントの画像
	const JSON m_json = JSON::Load(U"resources/engine/danmaku_data.json");	// コメントのデータ
	const Font m_font{ FontMethod::SDF, 30, Typeface::Black };				// コメントのフォント

public:
	/// <summary>
	/// 弾幕コメの初期化
	/// </summary>
	/// <param name="name">弾幕の名前</param>
	void init(const String name);

	/// <summary>
	///	描画
	/// </summary>
	void draw();
};

#endif // !DANMAKU_H_
