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
#include "file/FileContainer.hpp"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	auto fileContainer = std::make_shared<FileContainer>();

	Window window(fileContainer);
	window.init();

	window.resize(1000, 600);
	window.setWindowTitle("MIDI Analyzer");
	window.show();

    return app.exec();
}
