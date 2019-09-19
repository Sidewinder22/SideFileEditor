/**
 * @author Sidewinder22
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
    , toolBSave_(nullptr)
    , toolBClear_(nullptr)
    , toolBClose_(nullptr)
    , toolBTrash_(nullptr)
	, toolBQuit_(nullptr)
    , fileNameLabel_(new QLabel(this))
    , fileDialog_(nullptr)
    , dock_(new QDockWidget(tr("Files"), this))
    //, fileList_(new QListWidget())
{
	fileMenu_ = menuBar()->addMenu("File");
    helpMenu_ = menuBar()->addMenu("Help");
	toolBar_ = addToolBar("Main toolbar");

    // dock
    dock_->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);
    setDockOptions(dockOptions() | QMainWindow::GroupedDragging | QMainWindow::AllowNestedDocks | QMainWindow::AllowTabbedDocks);
    //dock_->setWidget(fileList_);
    addDockWidget(Qt::TopDockWidgetArea, dock_);


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
	toolBClear_ = toolBar_->addAction(QIcon("icons/clear.png"), "Clear Screen");
	toolBClose_ = toolBar_->addAction(QIcon("icons/close.png"), "Close File");
    toolBTrash_ = toolBar_->addAction(QIcon("icons/trash.png"), "Remove File");

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
        tr("Text files (*.txt)"));

    if (!fileName.isEmpty())
    {
        log_ << MY_FUNC << "fileName = " << fileName << log::END;
        if (!fileManager_.openFile(fileName))
        {
            log_ << MY_FUNC << "Cannot open file!!!" << log::END;
            return;
        }
        fillFileNameLabel(fileName);

        //fileList_->addItem(fileName);
        QLabel *label = new QLabel(fileName);
        dock_->setWidget(label);

        auto fileContent = fileManager_.read();
        for (auto&& line : fileContent)
        {
            textEdit_->append(line);
        }

        QMessageBox::information(this, "INFO", "Example of information");
        statusBar()->showMessage("Open file: " + fileName);
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
        tr("Text files (*.txt)"));

    if (!fileName.isEmpty())
    {
        if (!fileManager_.openFile(fileName))
        {
            log_ << MY_FUNC << "Cannot open file!!!" << log::END;
            QMessageBox::information(this, "ERROR", "Can't open file!!!");
            return;
        }
        fillFileNameLabel(fileName);

        log_  << MY_FUNC << "fileName = " << fileName << log::END;
        statusBar()->showMessage("Open file: " + fileName);
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
        statusBar()->showMessage("Cannot save file!");
        QMessageBox::warning(this, "INFO", "Cannot save file!");
    }
}

void Window::closeFile()
{
    log_ << MY_FUNC << log::END;

    textEdit_->clear();
    fileNameLabel_->setText("--------");

    if (fileManager_.exists())
    {
        statusBar()->showMessage("File: " + fileManager_.getFileName() + " closed.");
    }
    else
    {
        statusBar()->clearMessage();
    }

    if (fileManager_.exists())
    {
        fileManager_.close();
    }


    QLabel *emptyLabel = new QLabel("");
    dock_->setWidget(emptyLabel);
}

void Window::removeFile()
{
    log_ << MY_FUNC << log::END;

    textEdit_->clear();
    fileNameLabel_->setText("--------");

    if (fileManager_.exists())
    {
        statusBar()->showMessage("File: " + fileManager_.getFileName() + " removed.");
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

void Window::fillFileNameLabel(QString filePath)
{
    std::string filePathString(filePath.toStdString());

    auto const position = filePathString.find_last_of('/');
    const auto fileName = filePathString.substr(position + 1);

    fileNameLabel_->setText(QString(fileName.c_str()));
}
