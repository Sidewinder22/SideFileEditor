/**
 * @author Damian Stępień
 * @date 20.09.2016
 *
 * @brief Main Window class
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QIcon>
#include <QAction>
#include <QMenuBar>
#include <QStatusBar>
#include <QIODevice>
#include <QApplication>
#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>
#include <QTextStream>
#include "Window.hpp"

Window::Window(std::shared_ptr<FileContainer> fileContainger, QWidget *parent)
	: QMainWindow(parent)
    , log_("Window")
	, toolBNew_(nullptr)
	, toolBOpen_(nullptr)
	, toolBQuit_(nullptr)
    , fileDialog_(nullptr)
    , fileContainer_(fileContainger)
    , fileName_("")
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
	toolBSave_ = toolBar_->addAction(QIcon("icons/save.png"), "Save File");
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
	QAction *saveFile = new QAction("&Save", this);
	menu_->addAction(saveFile);
    menu_->addSeparator();

	QAction *quit = new QAction("&Quit", this);
	menu_->addAction(quit);

	connect(newFile, &QAction::triggered, this, &Window::selectFileName);
	connect(openFile, &QAction::triggered, this, &Window::openFile);
    connect(saveFile, &QAction::triggered, this, &Window::saveFile);
	connect(quit, &QAction::triggered, qApp, QApplication::quit);
	connect(toolBNew_, &QAction::triggered, this, &Window::selectFileName);
	connect(toolBOpen_, &QAction::triggered, this, &Window::openFile);
	connect(toolBSave_, &QAction::triggered, this, &Window::saveFile);
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
        log_ << MY_FUNC << ": fileName = " << fileName.toStdString() << log::END;
        fileContainer_->addFile(std::make_shared<File>(fileName.toStdString()));

        /**
         * @brief Reading from file
         */
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            log_ << MY_FUNC << "Cannot open file or file isn't text type!" << log::END;
            return;
        }

        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            textEdit_->append(line);
        }
        /*******/

        QMessageBox::information(this, "INFO", "Example of information");

        statusBar()->showMessage("Open file: " + fileName);
    }
}

void Window::selectFileName()
{
    log_ << MY_FUNC << log::END;

	QString fileName = QFileDialog::getSaveFileName(
        this,
        tr("Select loction to save a file"),
        QDir::homePath(),
        tr("Text files (*.txt)"));

    fileName_ = fileName;

    if (!fileName.isEmpty())
    {
        log_  << MY_FUNC << ": fileName = " << fileName.toStdString() << log::END;
        statusBar()->showMessage("Open file: " + fileName);
    }
}

void Window::saveFile()
{
    log_ << MY_FUNC << log::END;


    if (!fileName_.isEmpty())
    {
        QFile file(fileName_);
        if(!file.open(QFile::WriteOnly | QFile::Text))
        {
            log_ << " Could not open file for writing" << MY_FUNC << log::END;
            return;
        }

        // To write text, we use operator<<(),
        // which is overloaded to take
        // a QTextStream on the left
        // and data types (including QString) on the right

        auto text = textEdit_->toPlainText();

        QTextStream out(&file);
        out << text << "\n";
        file.flush();
        file.close();
    }

    statusBar()->showMessage("File saved");
    QMessageBox::information(this, "INFO", "File saved!");
}

