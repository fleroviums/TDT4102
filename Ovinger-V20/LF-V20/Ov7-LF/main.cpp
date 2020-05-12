#include "Simple_window.h"
#include "Emoji.h"

// Window and emoji size
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

// Attach all emojis in a Vector_ref<Emoji> - a vector conceptually holding refs to Emoji
// objects - in Window win.
void draw_emojis(Vector_ref<Emoji>& emojis, Graph_lib::Window& win)
{
	for (int i = 0; i < emojis.size(); ++i)
		emojis[i].attach_to(win);

	// TODO: not part of handout LF.
	// For future reference, so that we can infer the deduced type.

	// for (auto it = es.begin(); it < es.end(); ++it)
	// 	(*it)->attach_to(win);

	// for (auto e : emojis) {
	// 	e->attach_to(win);
	// 	dynamic_cast<Simple_window&>(win).wait_for_button();
	// }
}

int main()
{
	// Graphics library
	using namespace Graph_lib;

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	Simple_window win{tl, xmax, ymax, win_label};

	SmilingFace smiley{
		Point{xmax / 2 - emojiRadius, ymax / 2 - emojiRadius}, emojiRadius};

	SadFace sad{Point{xmax / 2 + emojiRadius, ymax / 2 - emojiRadius}, emojiRadius};

	SurprisedFace surprised{
		Point{xmax / 2 - emojiRadius, ymax / 2 + emojiRadius}, emojiRadius};

	AngryFace angry{
		Point{xmax / 2 + emojiRadius, ymax / 2 + emojiRadius}, emojiRadius};

	NeutralFace neutral{
		Point{xmax / 2 + 3 * emojiRadius, ymax / 2 - emojiRadius}, emojiRadius};

	WinkFace wink{
		Point{xmax / 2 + 3 * emojiRadius, ymax / 2 + emojiRadius}, emojiRadius};

	Vector_ref<Emoji> es;
	es.push_back(smiley);
	es.push_back(sad);
	es.push_back(surprised);
	es.push_back(angry);
	es.push_back(neutral);
	es.push_back(wink);
	draw_emojis(es, win);

	win.wait_for_button();
}
