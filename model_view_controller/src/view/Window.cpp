/**
 * @author  {\_Sidewinder22_/}
 * @date    13.11.2020
 * 
 * @brief   Main window class.
 */

#include <QScreen>
#include <QGuiApplication>
#include "Window.hpp"

namespace view
{

Window::Window()
    : QMainWindow()
{
    // Display center window
	QScreen *screen = QGuiApplication::primaryScreen();
	move(screen->geometry().center() - frameGeometry().center());

    resize(900, 600);
    show();
}

} // ::view