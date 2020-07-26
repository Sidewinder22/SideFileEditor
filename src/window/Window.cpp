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
#include <QMessageBox>
#include <QGuiApplication>
#include "Window.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace window
{

Window::Window(app::IMainController* mainController, QWidget *parent)
	: QMainWindow(parent)
    , log_("Window")
	, toolBNew_(nullptr)
	, toolBOpen_(nullptr)
    , toolBSave_(nullptr)
    , toolBClear_(nullptr)
    , toolBClose_(nullptr)
	, toolBQuit_(nullptr)
	, textEdit_(new QTextEdit(this))
    , openFileDock_(new OpenFilesDock(this, this))
    , utils_(std::make_unique<utils::Utils>())
    , mainController_(mainController)
	, commandFactory_(std::make_shared<command::CommandFactory>(this, textEdit_,
		mainController_, openFileDock_))
{
	menu_ = std::make_unique<Menu>(commandFactory_,  menuBar());

	toolBar_ = addToolBar("Main toolbar");

    openFileDock_->createDock();

    setDockOptions(dockOptions() |
    	QMainWindow::GroupedDragging |
		QMainWindow::AllowNestedDocks |
		QMainWindow::AllowTabbedDocks);
    addDockWidget(Qt::TopDockWidgetArea, openFileDock_);

	textEdit_->setStatusTip("Text editor window");
}

void Window::init()
{
	menu_->init();

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

	newFile();
}

void Window::prepareToolBar()
{
	toolBNew_ = toolBar_->addAction(QIcon("icons/new.png"), "New File");
	toolBOpen_ = toolBar_->addAction(QIcon("icons/open.png"), "Open File");
	toolBSave_ = toolBar_->addAction(QIcon("icons/save.png"), "Save File");
	toolBClear_ = toolBar_->addAction(QIcon("icons/clear.png"), "Clear Screen");
	toolBClose_ = toolBar_->addAction(QIcon("icons/close.png"), "Close File");

	toolBNew_->setStatusTip("New File");
	toolBOpen_->setStatusTip("Open File");
	toolBSave_->setStatusTip("Save File");
	toolBClear_->setStatusTip("Clear Screen");
	toolBClose_->setStatusTip("Close File");

	toolBar_->addSeparator();

	toolBQuit_ = toolBar_->addAction(QIcon("icons/quit.png"),
		"Quit Application");

	toolBar_->addSeparator();
}

void Window::connectSignalsToSlots()
{
	connect(toolBNew_, &QAction::triggered, this, &Window::newFile);
	connect(toolBOpen_, &QAction::triggered, this, &Window::openFile);
	connect(toolBSave_, &QAction::triggered, this, &Window::saveFile);
	connect(toolBClear_, &QAction::triggered, this, &Window::clearScreen);
	connect(toolBClose_, &QAction::triggered, this, &Window::closeFile);
    connect(textEdit_, &QTextEdit::textChanged, this, &Window::textChanged);
	connect(toolBQuit_, &QAction::triggered, this, &Window::quitApplication);
}

void Window::openFile()
{
	commandFactory_->getOpenCommand().execute();
}

void Window::newFile()
{
	commandFactory_->getNewCommand().execute();
}

void Window::saveFile()
{
	commandFactory_->getSaveCommand().execute();
}

void Window::closeFile()
{
	commandFactory_->getCloseCommand().execute();
}

void Window::removeFile()
{
	commandFactory_->getRemoveCommand().execute();
}

void Window::clearScreen()
{
	commandFactory_->getClearCommand().execute();
}

void Window::quitApplication()
{
	commandFactory_->getQuitCommand().execute();
}

void Window::opened(bool status, const QString& filePath)
{
    log_ << MY_FUNC << log::END;

    if (!filePath.isEmpty())
    {
        if (status)
        {
            auto fileName = utils_->extractFileName(filePath);
            openFileDock_->addFileName(fileName);

            textEdit_->clear();

            auto fileContent = mainController_->read(fileName);
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

void Window::created(const QString& filePath)
{
    log_ << MY_FUNC << log::END;

	openFileDock_->addFileName(utils_->extractFileName(filePath));

	statusBar()->showMessage("[New]: " + filePath);
	setWindowTitle(filePath);
}

void Window::anotherFileSelected(const QString& fileName)
{
    log_ << MY_FUNC << log::END;

	statusBar()->showMessage("[Current file]: " + fileName);
	setWindowTitle(fileName);

	textEdit_->clear();

	auto fileContent = mainController_->read(utils_->extractFileName(fileName));
	for (auto&& line : fileContent)
	{
		textEdit_->append(line);
	}
}

void Window::textChanged()
{
    auto fileName = openFileDock_->getCurrentFileName();
    if (!fileName.isEmpty())
    {
		auto text = textEdit_->toPlainText();
		bool fileContentChanged = false;

		if (!text.isEmpty())
		{
			fileContentChanged = mainController_->textChanged(fileName, text);
		}

		if (fileContentChanged)
		{
			openFileDock_->markCurrentFileAsUnsaved();
		}
    }
}

} // ::window
