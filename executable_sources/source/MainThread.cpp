#include "lib/MainWindowHeader.hpp"

#ifdef __linux__
#include <X11/Xlib.h>
#endif

int main()
{

#ifdef __linux__
	XInitThreads();
#endif

	MatthewsNamespace::MainWindowClass* MyMainWindow;
	MyMainWindow = new MatthewsNamespace::MainWindowClass("MainWindow", 1000, 500);

	MatthewsNamespace::MainWindowClass* MyMainWindow1;
	MyMainWindow1 = new MatthewsNamespace::MainWindowClass("MainWindow1", 1000, 500);
	
	MatthewsNamespace::MainWindowClass* MyMainWindow2;
	MyMainWindow2 = new MatthewsNamespace::MainWindowClass("MainWindow2", 1000, 500);
	
	MatthewsNamespace::MainWindowClass* MyMainWindow3;
	MyMainWindow3 = new MatthewsNamespace::MainWindowClass("MainWindow3", 1000, 500);


	std::cin.get();
	return 0;
}
