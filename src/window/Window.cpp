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
#include <QScreen>
#include <QMenuBar>
#include <QStatusBar>
#include <QIODevice>
#include <QApplication>
#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>
#include <QTextStream>
#include <QDesktopWidget>
#include "Window.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace window
{

int Window::bufferNumber_ = 1;

Window::Window(IWindowObserver* observer, QWidget *parent)
	: QMainWindow(parent)
    , log_("Window")
	, toolBNew_(nullptr)
	, toolBOpen_(nullptr)
    , toolBSave_(nullptr)
    , toolBClear_(nullptr)
    , toolBClose_(nullptr)
    , toolBTrash_(nullptr)
	, toolBQuit_(nullptr)
	, menuNewFile_(new QAction("&New", this))
	, menuOpenFile_(new QAction("&Open", this))
	, menuSaveFile_(new QAction("&Save", this))
	, menuClearScreen_(new QAction("&Clear screen", this))
	, menuCloseFile_(new QAction("&Close", this))
	, menuRemoveFile_(new QAction("&Remove", this))
	, menuQuit_(new QAction("&Quit", this))
    , menuAbout_(new QAction("&About", this))
    , fileDialog_(nullptr)
    , openFileDock_(new OpenFilesDock(this, this))
    , utils_(std::make_unique<utils::Utils>())
    , observer_(observer)
{
	fileMenu_ = menuBar()->addMenu("File");
    helpMenu_ = menuBar()->addMenu("Help");
	toolBar_ = addToolBar("Main toolbar");

    openFileDock_->createDock();

    setDockOptions(dockOptions() | QMainWindow::GroupedDragging | QMainWindow::AllowNestedDocks | QMainWindow::AllowTabbedDocks);
    addDockWidget(Qt::TopDockWidgetArea, openFileDock_);

	textEdit_ = new QTextEdit(this);
	textEdit_->setStatusTip("Text editor window");
}

void Window::init()
{
	prepareMenu();
	prepareToolBar();
	connectSignalsToSlots();

    setCentralWidget(textEdit_);

	statusBar()->showMessage("Ready!");

	setWindowTitle("{\\_SideFileEditor_/} ");

	resize(900, 600);
	show();

	// Display center window
	QScreen *screen = QGuiApplication::primaryScreen();
	move(screen->geometry().center() - frameGeometry().center());
}

void Window::prepareMenu()
{
	fileMenu_->addAction(menuNewFile_);
	fileMenu_->addAction(menuOpenFile_);
	fileMenu_->addAction(menuSaveFile_);
	fileMenu_->addAction(menuClearScreen_);
	fileMenu_->addAction(menuCloseFile_);
	fileMenu_->addAction(menuRemoveFile_);
    fileMenu_->addSeparator();
	fileMenu_->addAction(menuQuit_);
    helpMenu_->addAction(menuAbout_);

    QKeySequence newShortcut("Ctrl+N");
    QKeySequence openShortcut("Ctrl+O");
    QKeySequence saveShortcut("Ctrl+S");
    QKeySequence clearScreenShortcut("Ctrl+L");
    QKeySequence closeShortcut("Ctrl+W");
    QKeySequence removeShortcut("Ctrl+R");
    QKeySequence quitShortcut("Ctrl+Q");

    menuNewFile_->setShortcut(newShortcut);
    menuOpenFile_->setShortcut(openShortcut);
    menuSaveFile_->setShortcut(saveShortcut);
    menuClearScreen_->setShortcut(clearScreenShortcut);
    menuCloseFile_->setShortcut(closeShortcut);
    menuRemoveFile_->setShortcut(removeShortcut);
    menuQuit_->setShortcut(quitShortcut);
}

void Window::prepareToolBar()
{
	toolBNew_ = toolBar_->addAction(QIcon("../icons/new.png"), "New File");
	toolBOpen_ = toolBar_->addAction(QIcon("../icons/open.png"), "Open File");
	toolBSave_ = toolBar_->addAction(QIcon("../icons/save.png"), "Save File");
	toolBClear_ = toolBar_->addAction(QIcon("../icons/clear.png"), "Clear Screen");
	toolBClose_ = toolBar_->addAction(QIcon("../icons/close.png"), "Close File");
    toolBTrash_ = toolBar_->addAction(QIcon("../icons/trash.png"), "Remove File");

	toolBNew_->setStatusTip("New File");
	toolBOpen_->setStatusTip("Open File");
	toolBSave_->setStatusTip("Save File");
	toolBClear_->setStatusTip("Clear Screen");
	toolBClose_->setStatusTip("Close File");
	toolBTrash_->setStatusTip("Remove File");

	toolBar_->addSeparator();

	toolBQuit_ = toolBar_->addAction(QIcon("../icons/quit.png"),
		"Quit Application");

	toolBar_->addSeparator();
}

void Window::connectSignalsToSlots()
{
	connect(menuNewFile_, &QAction::triggered, this, &Window::newFile);
	connect(menuOpenFile_, &QAction::triggered, this, &Window::openFile);
    connect(menuSaveFile_, &QAction::triggered, this, &Window::saveFile);
    connect(menuClearScreen_, &QAction::triggered, this, &Window::clearScreen);
    connect(menuCloseFile_, &QAction::triggered, this, &Window::closeFile);
    connect(menuRemoveFile_, &QAction::triggered, this, &Window::removeFile);
	connect(menuAbout_, &QAction::triggered, this, &Window::showAboutWindow);
	connect(menuQuit_, &QAction::triggered, qApp, QApplication::quit);

	connect(toolBNew_, &QAction::triggered, this, &Window::newFile);
	connect(toolBOpen_, &QAction::triggered, this, &Window::openFile);
	connect(toolBSave_, &QAction::triggered, this, &Window::saveFile);
	connect(toolBClear_, &QAction::triggered, this, &Window::clearScreen);
	connect(toolBClose_, &QAction::triggered, this, &Window::closeFile);
	connect(toolBTrash_, &QAction::triggered, this, &Window::removeFile);
    connect(toolBQuit_, &QAction::triggered, qApp, QApplication::quit);
    connect(textEdit_, &QTextEdit::textChanged, this, &Window::textChanged);
}

void Window::showAboutWindow()
{
    QString description;
    description.append("     SideFileEditor\n");
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
        tr("Text files: *.txt *.h *.hpp *.c *.cc *.cpp *.py *.js *.ccs *.json (*.txt *.h *.hpp *.c *.cc *.cpp *.py *.js *.ccs *.json)"));

    observer_->openFile(fileName);
}

void Window::newFile()
{
    log_ << MY_FUNC << log::END;

    auto bufferName = "Buffer" + std::to_string(bufferNumber_++);
    observer_->createBuffer(QString(bufferName.c_str()));

//QString fileName = QFileDialog::getSaveFileName(
//        this,
//        tr("Select loction to save a file"),
//        QDir::homePath(),
//        tr("Text files: *.txt *.h *.hpp *.c *.cc *.cpp *.py *.js *.ccs *.json (*.txt *.h *.hpp *.c *.cc *.cpp *.py *.js *.ccs *.json)"));
//
//    observer_->createFile(fileName);
}

void Window::saveFile()
{
    log_ << MY_FUNC << log::END;

    auto fileName = openFileDock_->getCurrentFileName();

    if (observer_->save(fileName))
    {
        statusBar()->showMessage("[File saved]: " + fileName);
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

    int row = openFileDock_->getCurrentRow();
    auto fileName = openFileDock_->getCurrentFileName();

    openFileDock_->removeFileName(row);
    if (!fileName.isEmpty())
    {
        statusBar()->showMessage("File: " + fileName + " closed.");
        observer_->close(fileName);
    }
    else
    {
        statusBar()->clearMessage();
    }
}

void Window::removeFile()
{
    log_ << MY_FUNC << log::END;

    textEdit_->clear();

    int row = openFileDock_->getCurrentRow();
    auto fileName = openFileDock_->getCurrentFileName();

    openFileDock_->removeFileName(row);

    if (!fileName.isEmpty())
    {
        statusBar()->showMessage("File: " + fileName + " removed.");
        observer_->remove(fileName);
    }
    else
    {
        statusBar()->clearMessage();
    }
}

void Window::clearScreen()
{
    log_ << MY_FUNC << log::END;

    textEdit_->clear();

    auto fileName = openFileDock_->getCurrentFileName();
    observer_->clear(fileName);
}

void Window::fileOpened(bool status, const QString& filePath)
{
    log_ << MY_FUNC << log::END;

    if (!filePath.isEmpty())
    {
        if (status)
        {
            auto fileName = utils_->extractFileName(filePath);
            openFileDock_->addFileName(fileName);

            textEdit_->clear();

            auto fileContent = observer_->read(fileName);
            for (auto&& line : fileContent)
            {
                textEdit_->append(line);
            }

            statusBar()->showMessage("[Open file]: " + filePath);
            setWindowTitle(fileName);

        }
        else
        {
            log_ << MY_FUNC << "Cannot open file!!!" << log::END;

            QMessageBox::information(this, "ERROR", "Can't open file!!!");
            statusBar()->showMessage("Cannot open file!!!" + filePath);
        }
    }
}

void Window::fileCreated(const QString& filePath)
{
    log_ << MY_FUNC << log::END;

	openFileDock_->addFileName(utils_->extractFileName(filePath));

	statusBar()->showMessage("[New file]: " + filePath);
	setWindowTitle(filePath);
}

void Window::bufferCreated(const QString& bufferName)
{
    log_ << MY_FUNC << log::END;

	openFileDock_->addFileName(bufferName);

	statusBar()->showMessage("[New buffer]: " + bufferName);
	setWindowTitle(bufferName);
}

void Window::anotherFileSelected(const QString& fileName)
{
    log_ << MY_FUNC << log::END;

    statusBar()->showMessage("[Current file]: " + fileName);
    setWindowTitle(fileName);

    textEdit_->clear();

    auto fileContent = observer_->read(utils_->extractFileName(fileName));
    for (auto&& line : fileContent)
    {
        textEdit_->append(line);
    }
}

void Window::textChanged()
{
    auto filename = openFileDock_->getCurrentFileName();
    auto text = textEdit_->toPlainText();

    if (!text.isEmpty())
    {
        observer_->textChanged(filename, text);
    }
}

} // ::window
