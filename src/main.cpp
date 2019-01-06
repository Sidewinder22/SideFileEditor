/**
 * @author Damian Stępień
 * @date 17.09.2016
 */

#include <iostream>
#include <memory>
#include <QApplication>
#include "Window.hpp"
#include "FileContainer.hpp"

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
