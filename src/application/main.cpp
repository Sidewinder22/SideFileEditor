/**
 * @author Damian Stępień
 * @date 17.09.2016
 *
 * @brief Main application file.
 */

#include <iostream>
#include <memory>
#include <QApplication>
#include "window/Window.hpp"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	Window window;
	window.init();

	window.resize(1000, 600);
	window.setWindowTitle("{\\_Sidewinder_/} File Editor");
	window.show();

    return app.exec();
}
