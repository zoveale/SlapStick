#include <iostream>
#include "../inculde/Window.h"

int main(int argc, char* argv[])
{
	Window window;
	window.Initialize();
	window.Draw();
	std::cout << "Stuff\n";
	return 0;
}