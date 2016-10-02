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
#include <QFileDialog>
#include "Window.hpp"

Window::Window(QWidget *parent)
	: QMainWindow(parent)
	, toolBNew_(nullptr)
	, toolBOpen_(nullptr)
	, toolBQuit_(nullptr)
    , fileDialog_(nullptr)
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
	toolBOpen_ = toolBar_->addAction(QIcon("icons/open.png"), "Open File");
	toolBar_->addSeparator();

	toolBQuit_ = toolBar_->addAction(QIcon("icons/quit.png"),
		"Quit Application");
}

void Window::connectSignalsToSlots()
{
	QAction *newFile = new QAction("&New", this);
	menu_->addAction(newFile);
	QAction *openFile = new QAction("&Open", this);
	menu_->addAction(openFile);
	QAction *quit = new QAction("&Quit", this);
	menu_->addAction(quit);

	connect(newFile, &QAction::triggered, this, &Window::selectFileName);
	connect(openFile, &QAction::triggered, this, &Window::openFile);
	connect(quit, &QAction::triggered, qApp, QApplication::quit);
	connect(toolBNew_, &QAction::triggered, this, &Window::selectFileName);
	connect(toolBOpen_, &QAction::triggered, this, &Window::openFile);
	connect(toolBQuit_, &QAction::triggered, qApp, QApplication::quit);
}

void Window::openFile()
{
	std::cout << __FUNCTION__ << std::endl;

	QString filter = "File Description (*.mid)";
	fileDialog_ = new QFileDialog(
        this,
        "Select a file to open...",
        QDir::homePath(),
        filter);

	auto fileName = fileDialog_->getOpenFileName();

	std::cout << "FileName = " << fileName.toStdString() << std::endl;
}

void Window::selectFileName()
{
	std::cout << __FUNCTION__ << std::endl;

	QString fileName = QFileDialog::getSaveFileName(
	        this,
	        tr("Save File"),
            QDir::homePath(),
            tr("MIDI Files (*.mid, *.kar)"));

	std::cout << "FileName = " << fileName.toStdString() << std::endl;
}
