/**
 * @author Damian Stępień
 * @date 17.09.2016
 */

#include <iostream>
#include <QApplication>
#include "Window.hpp"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	Window window;
	window.init();

	window.resize(600, 400);
	window.setWindowTitle("MIDI Analyzer");
	window.show();

    return app.exec();
}
