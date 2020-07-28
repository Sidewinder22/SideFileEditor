/**
 * @author  {\_Sidewinder22_/}
 * @date    20.09.2016
 *
 * @brief   Main Window class
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QScreen>
#include <QGuiApplication>
#include "command/CommandFactory.hpp"
#include "Window.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace window
{

Window::Window(app::IMainController* mainController, QWidget *parent)
	: QMainWindow(parent)
    , log_("Window")
	, textEdit_(new QTextEdit(this))
	, statusBar_(statusBar())
    , openFileDock_(new OpenFilesDock(this, this))
    , mainController_(mainController)
	, commandFactory_(std::make_shared<command::CommandFactory>(this, textEdit_,
		statusBar_, mainController_, openFileDock_))
{
	menu_ = std::make_unique<Menu>(commandFactory_, menuBar());
	toolBar_ = std::make_unique<ToolBar>(commandFactory_,
		addToolBar("Main toolbar"));

	notificationHandler_ = std::make_unique<window::NotificationHandler>(this,
		textEdit_, statusBar_, mainController_, openFileDock_);

    openFileDock_->createDock();

    setDockOptions(dockOptions() |
    	QMainWindow::GroupedDragging |
		QMainWindow::AllowNestedDocks |
		QMainWindow::AllowTabbedDocks);
    addDockWidget(Qt::TopDockWidgetArea, openFileDock_);

    connect(textEdit_, &QTextEdit::textChanged, this, &Window::textChanged);
}

void Window::init()
{
	menu_->init();
	toolBar_->init();

    setCentralWidget(textEdit_);
	setWindowTitle("{\\_SideFileEditor_/} ");

	resize(900, 600);
	show();

	// Display center window
	QScreen *screen = QGuiApplication::primaryScreen();
	move(screen->geometry().center() - frameGeometry().center());

    // Create empty buffer during startup
    commandFactory_->getNewCommand().execute();

    statusBar_->showMessage("Ready!");
}

void Window::opened(bool status, const QString& filePath)
{
	auto windowTitle = notificationHandler_->opened(status, filePath);

	if (!windowTitle.isEmpty())
	{
		setWindowTitle(windowTitle);
	}
}

void Window::created(const QString& filePath)
{
	auto windowTitle = notificationHandler_->created(filePath);
	setWindowTitle(windowTitle);
}

void Window::anotherFileSelected(const QString& fileName)
{
	auto windowTitle = notificationHandler_->anotherFileSelected(fileName);
	setWindowTitle(windowTitle);
}

void Window::textChanged()
{
	notificationHandler_->textChanged();
}

} // ::window
