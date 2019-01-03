/**
 * @author Damian Stępień
 * @date 20.09.2016
 *
 * @brief Main Window class
 */

#include <QIcon>
#include <QAction>
#include <QMenuBar>
#include <QStatusBar>
#include <QApplication>
#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>
#include "Window.hpp"

Window::Window(std::shared_ptr<FileContainer> fileContainger, QWidget *parent)
	: QMainWindow(parent)
    , log_("Window")
	, toolBNew_(nullptr)
	, toolBOpen_(nullptr)
	, toolBQuit_(nullptr)
    , fileDialog_(nullptr)
    , fileContainer_(fileContainger)
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
    log_ << MY_FUNC << log::END;

    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("Select file to open..."),
        QDir::homePath(),
        tr("Text files (*.txt)"));

    if (!fileName.isEmpty())
    {
        fileContainer_->addFile(std::make_shared<File>(fileName.toStdString()));
        std::string log;
        log += __FUNCTION__;
        log += ", fileName = ";
        log += fileName.toStdString();

        log_  << MY_FUNC << ": fileName = " << fileName.toStdString() << log::END;
    }
}

void Window::selectFileName()
{
    log_ << MY_FUNC << log::END;

	QString fileName = QFileDialog::getSaveFileName(
        this,
        tr("Save File"),
        QDir::homePath(),
        tr("MIDI Files (*.mid, *.kar)"));

    if (!fileName.isEmpty())
    {
        log_  << MY_FUNC << ": fileName = " << fileName.toStdString() << log::END;
    }
}
