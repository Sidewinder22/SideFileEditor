/**
 * @author  {\_Sidewinder22_/}
 * @date    20.09.2016
 *
 * @brief   Main Window class
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
    , toolBSave_(nullptr)
    , toolBClear_(nullptr)
    , toolBClose_(nullptr)
    , toolBTrash_(nullptr)
	, toolBQuit_(nullptr)
    , fileDialog_(nullptr)
    , openFileDock_(new OpenFilesDock(this))
    , utils_(std::make_unique<utils::Utils>())
{

	fileMenu_ = menuBar()->addMenu("File");
    helpMenu_ = menuBar()->addMenu("Help");
	toolBar_ = addToolBar("Main toolbar");

    openFileDock_->createDock();

    setDockOptions(dockOptions() | QMainWindow::GroupedDragging | QMainWindow::AllowNestedDocks | QMainWindow::AllowTabbedDocks);
    addDockWidget(Qt::TopDockWidgetArea, openFileDock_);

	textEdit_ = new QTextEdit(this);

}

void Window::init()
{
	buildToolBar();
	connectSignalsToSlots();

    setCentralWidget(textEdit_);

	statusBar()->showMessage("Ready!");

	setWindowTitle("{\\_Sidewinder_/} File Editor");
    showMaximized();
}

void Window::buildToolBar()
{
	toolBNew_ = toolBar_->addAction(QIcon("../icons/new.png"), "New File");
	toolBOpen_ = toolBar_->addAction(QIcon("../icons/open.png"), "Open File");
	toolBSave_ = toolBar_->addAction(QIcon("../icons/save.png"), "Save File");
	toolBClear_ = toolBar_->addAction(QIcon("../icons/clear.png"), "Clear Screen");
	toolBClose_ = toolBar_->addAction(QIcon("../icons/close.png"), "Close File");
    toolBTrash_ = toolBar_->addAction(QIcon("../icons/trash.png"), "Remove File");

	toolBar_->addSeparator();

	toolBQuit_ = toolBar_->addAction(QIcon("../icons/quit.png"),
		"Quit Application");

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
	QAction *clearScreen = new QAction("&Clear screen", this);
	fileMenu_->addAction(clearScreen);
	QAction *closeFile = new QAction("&Close", this);
	fileMenu_->addAction(closeFile);
	QAction *removeFile = new QAction("&Remove", this);
	fileMenu_->addAction(removeFile);
    fileMenu_->addSeparator();

	QAction *quit = new QAction("&Quit", this);
	fileMenu_->addAction(quit);

    QAction *about = new QAction("&About", this);
    helpMenu_->addAction(about);

	connect(newFile, &QAction::triggered, this, &Window::newFile);
	connect(openFile, &QAction::triggered, this, &Window::openFile);
    connect(saveFile, &QAction::triggered, this, &Window::saveFile);
    connect(clearScreen, &QAction::triggered, this, &Window::clearScreen);
    connect(closeFile, &QAction::triggered, this, &Window::closeFile);
    connect(removeFile, &QAction::triggered, this, &Window::removeFile);
	connect(about, &QAction::triggered, this, &Window::showAboutWindow);
	connect(toolBNew_, &QAction::triggered, this, &Window::newFile);
	connect(toolBOpen_, &QAction::triggered, this, &Window::openFile);
	connect(toolBSave_, &QAction::triggered, this, &Window::saveFile);
	connect(toolBClear_, &QAction::triggered, this, &Window::clearScreen);
	connect(toolBClose_, &QAction::triggered, this, &Window::closeFile);
	connect(toolBTrash_, &QAction::triggered, this, &Window::removeFile);
    connect(toolBQuit_, &QAction::triggered, qApp, QApplication::quit);
	connect(quit, &QAction::triggered, qApp, QApplication::quit);
}

void Window::showAboutWindow()
{
    QString description;
    description.append("       SFileEditor\n");
    description.append("             by\n");
    description.append("{\\_Sidewinder22_/}");

    QMessageBox::information(this, "INFO", description);
}

void Window::openFile()
{
    log_ << MY_FUNC << log::END;

    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("Select file to open..."),
        QDir::homePath(),
        tr("Text files (*.txt *.h *.hpp *.c *.cpp)"));

    if (!fileName.isEmpty())
    {
        log_ << MY_FUNC << "fileName = " << fileName << log::END;
        if (!fileManager_.openFile(fileName))
        {
            log_ << MY_FUNC << "Cannot open file!!!" << log::END;
            return;
        }

        openFileDock_->addFileName(utils_->extractFileName(fileName));

        auto fileContent = fileManager_.read();
        for (auto&& line : fileContent)
        {
            textEdit_->append(line);
        }

        statusBar()->showMessage("Path [open file]: " + fileName);
        setWindowTitle(fileName);
    }
}

void Window::newFile()
{
    log_ << MY_FUNC << log::END;

	QString fileName = QFileDialog::getSaveFileName(
        this,
        tr("Select loction to save a file"),
        QDir::homePath(),
        tr("Text files (*.txt *.h *.hpp *.c *.cpp)"));

    if (!fileName.isEmpty())
    {
        if (!fileManager_.openFile(fileName))
        {
            log_ << MY_FUNC << "Cannot open file!!!" << log::END;
            QMessageBox::information(this, "ERROR", "Can't open file!!!");
            return;
        }

        openFileDock_->addFileName(utils_->extractFileName(fileName));

        log_  << MY_FUNC << "fileName = " << fileName << log::END;
        statusBar()->showMessage("Path [new file]: " + fileName);
        setWindowTitle(fileName);
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
        statusBar()->showMessage("Can't save file!");
        QMessageBox::warning(this, "INFO", "Cannot save file!");
    }
}

void Window::closeFile()
{
    log_ << MY_FUNC << log::END;

    textEdit_->clear();

    int row = 0;
    openFileDock_->removeFileName(row);

    if (fileManager_.exists())
    {
        statusBar()->showMessage("File: " + fileManager_.fileName() + " closed.");
    }
    else
    {
        statusBar()->clearMessage();
    }

    if (fileManager_.exists())
    {
        fileManager_.close();
    }
}

void Window::removeFile()
{
    log_ << MY_FUNC << log::END;

    textEdit_->clear();

    int row = 0;
    openFileDock_->removeFileName(row);

    if (fileManager_.exists())
    {
        statusBar()->showMessage("File: " + fileManager_.fileName() + " removed.");
    }
    else
    {
        statusBar()->clearMessage();
    }

    if (fileManager_.exists())
    {
        fileManager_.remove();
    }
}

void Window::clearScreen()
{
    log_ << MY_FUNC << log::END;

    textEdit_->clear();
}

