/**
 * @author Damian Stępień
 * @date 20.09.2016
 */

#include "Window.hpp"
#include <QMenuBar>
#include <QApplication>

Window::Window(QWidget *parent)
	: QMainWindow(parent)
{
	menu_ = menuBar()->addMenu("File");
}

void Window::init()
{
	connectSignalsToSlots();
}


void Window::connectSignalsToSlots()
{
	QAction *quit = new QAction("&Quit", this);
	menu_->addAction(quit);

	connect(quit, &QAction::triggered, qApp, QApplication::quit);
}

