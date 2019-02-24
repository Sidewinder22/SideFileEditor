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

Window::Window(QWidget *parent)
	: QMainWindow(parent)
    , log_("Window")
	, toolBNew_(nullptr)
	, toolBOpen_(nullptr)
	, toolBQuit_(nullptr)
    , fileNameLabel_(new QLabel(this))
    , fileDialog_(nullptr)
{
	fileMenu_ = menuBar()->addMenu("File");
    helpMenu_ = menuBar()->addMenu("Help");
	toolBar_ = addToolBar("Main toolbar");
	textEdit_ = new QTextEdit(this);

    fileNameLabel_->setText("--------");
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
	toolBar_->addSeparator();

    QLabel* fileNameDescription(new QLabel(this));
    fileNameDescription->setText("FileName: ");
    toolBar_->addWidget(fileNameDescription);
    toolBar_->addWidget(fileNameLabel_);
	toolBar_->addSeparator();
}

void Window::connectSignalsToSlots()
{
	QAction *newFile = new QAction("&New", this);
	fileMenu_->addAction(newFile);
	QAction *openFile = new QAction("&Open", this);
	fileMenu_->addAction(openFile);
	QAction *saveFile = new QAction("&Save", this);
	fileMenu_->addAction(saveFile);
    fileMenu_->addSeparator();

	QAction *quit = new QAction("&Quit", this);
	fileMenu_->addAction(quit);

    QAction *about = new QAction("&About", this);
    helpMenu_->addAction(about);

	connect(newFile, &QAction::triggered, this, &Window::newFile);
	connect(openFile, &QAction::triggered, this, &Window::openFile);
    connect(saveFile, &QAction::triggered, this, &Window::saveFile);
	connect(about, &QAction::triggered, this, &Window::showAboutWindow);
	connect(toolBNew_, &QAction::triggered, this, &Window::newFile);
	connect(toolBOpen_, &QAction::triggered, this, &Window::openFile);
	connect(toolBSave_, &QAction::triggered, this, &Window::saveFile);
	connect(quit, &QAction::triggered, qApp, QApplication::quit);
    connect(toolBQuit_, &QAction::triggered, qApp, QApplication::quit);
}

void Window::showAboutWindow()
{
    QString description;
    description.append("##################################\n");
    description.append("SFileEditor by {\\_Sidewinder22_/}");
    description.append("##################################");
    QMessageBox::information(this, "INFO", description);
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
        log_ << MY_FUNC << "fileName = " << fileName.toStdString() << log::END;
        if (!fileManager_.openFile(fileName))
        {
            log_ << MY_FUNC << "Cannot open file!!!" << log::END;
            return;
        }
        fillFileNameLabel(fileName);

        auto fileContent = fileManager_.read();
        for (auto&& line : fileContent)
        {
            textEdit_->append(line);
        }

        QMessageBox::information(this, "INFO", "Example of information");
        statusBar()->showMessage("Open file: " + fileName);
    }
}

void Window::newFile()
{
    log_ << MY_FUNC << log::END;

	QString fileName = QFileDialog::getSaveFileName(
        this,
        tr("Select loction to save a file"),
        QDir::homePath(),
        tr("Text files (*.txt)"));

    if (!fileName.isEmpty())
    {
        if (!fileManager_.openFile(fileName))
        {
            log_ << MY_FUNC << "Cannot open file!!!" << log::END;
        }
        fillFileNameLabel(fileName);

        log_  << MY_FUNC << "fileName = " << fileName.toStdString() << log::END;
        statusBar()->showMessage("Open file: " + fileName);
    }
}

void Window::saveFile()
{
    log_ << MY_FUNC << log::END;

    auto text = textEdit_->toPlainText();
    if (fileManager_.write(text))
    {
        statusBar()->showMessage("File saved");
        QMessageBox::information(this, "INFO", "File saved!");
    }
    else
    {
        statusBar()->showMessage("Cannot save file!");
        QMessageBox::warning(this, "INFO", "Cannot save file!");
    }
}

void Window::fillFileNameLabel(QString filePath)
{
    std::string filePathString(filePath.toStdString());

    auto const position = filePathString.find_last_of('/');
    const auto fileName = filePathString.substr(position + 1);

    fileNameLabel_->setText(QString(fileName.c_str()));
}
