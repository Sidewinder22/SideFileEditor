/**
 * @author  {\_Sidewinder22_/}
 * @date    17.09.2016
 *
 * @brief   Main application file.
 */

#include <iostream>
#include <memory>
#include <QApplication>
#include "window/Window.hpp"
#include "MainController.hpp"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

    app::MainController mainController;
    mainController.start();

    return app.exec();
}
