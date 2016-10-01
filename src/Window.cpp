/**
 * @author Damian Stępień
 * @date 20.09.2016
 */

#include <iostream>
#include <QIcon>
#include <QAction>
#include <QMenuBar>
#include <QStatusBar>
#include <QApplication>
#include <QMessageBox>
#include <QInputDialog>
#include "Window.hpp"

Window::Window(QWidget *parent)
	: QMainWindow(parent)
	, toolBQuit_(nullptr)
	, toolBNew_(nullptr)
{
	menu_ = menuBar()->addMenu("File");
	toolBar_ = addToolBar("Main toolbar");
	textEdit_ = new QTextEdit(this);
}

void Window::init()
{
	buildToolBar();
	connectSignalsToSlots();

	setCentralWidget(textEdit_);

	statusBar()->showMessage("Ready!");
}

void Window::buildToolBar()
{
	toolBNew_ = toolBar_->addAction(QIcon("icons/new.png"), "New File");
	toolBar_->addAction(QIcon("icons/open.png"), "Open File");
	toolBar_->addSeparator();

	toolBQuit_ = toolBar_->addAction(QIcon("icons/quit.png"),
		"Quit Application");
}

void Window::connectSignalsToSlots()
{
	QAction *getFileName = new QAction("&New", this);
	menu_->addAction(getFileName);

	QAction *quit = new QAction("&Quit", this);
	menu_->addAction(quit);

	connect(getFileName, &QAction::triggered, this, &Window::getFileName);
	connect(quit, &QAction::triggered, qApp, QApplication::quit);
	connect(toolBQuit_, &QAction::triggered, qApp, QApplication::quit);
	connect(toolBNew_, &QAction::triggered, this, &Window::getFileName);
}

void Window::getFileName()
{
	std::cout << __FUNCTION__ << std::endl;

	auto fileName = QInputDialog::getText(this, "Type name of a file", "File");
	textEdit_->setText(QString(fileName));

	std::cout << fileName.toStdString() << std::endl;

}
