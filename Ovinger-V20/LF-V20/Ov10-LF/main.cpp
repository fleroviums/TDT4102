#include "MinesweeperWindow.h"

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	Fl::background(200, 200, 200);
	constexpr int width = 10;
	constexpr int height = 10;
	constexpr int mines = 10;

	Point startPoint{ 200, 300 };
	MinesweeperWindow mw{startPoint, width, height, mines, "Minesweeper" };

	return gui_main();
}
