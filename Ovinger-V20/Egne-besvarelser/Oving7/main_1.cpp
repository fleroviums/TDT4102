#include "Simple_window.h"
#include "Emoji.h"

// Size of window and emoji radius
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

int main()
{
	using namespace Graph_lib;

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	Simple_window win{tl, xmax, ymax, win_label};

	/* TODO:
	 *  - initialize emojis
	 *  - connect emojis to window
	 **/

	win.wait_for_button();
}
