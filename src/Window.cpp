/**
 * @author Damian Stępień
 * @date 20.09.2016
 */

#include <iostream>
#include <QMenuBar>
#include <QApplication>
#include <QMessageBox>
#include <QInputDialog>
#include "Window.hpp"

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
	QAction *getFileName = new QAction("&Open", this);
	menu_->addAction(getFileName);

	QAction *quit = new QAction("&Quit", this);
	menu_->addAction(quit);



	connect(getFileName, &QAction::triggered, this, &Window::getFileName);
	connect(quit, &QAction::triggered, qApp, QApplication::quit);
}

void Window::getFileName()
{
	std::cout << __FUNCTION__ << std::endl;

	auto fileName = QInputDialog::getText(this, "Type name of a file", "File");

	std::cout << fileName.toStdString() << std::endl;

}
