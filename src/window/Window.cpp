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
#include <QStatusBar>
#include <QMessageBox>
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
    , openFileDock_(new OpenFilesDock(this, this))
    , utils_(std::make_unique<utils::Utils>())
    , mainController_(mainController)
	, commandFactory_(std::make_shared<command::CommandFactory>(this, textEdit_,
		mainController_, openFileDock_))
{
	menu_ = std::make_unique<Menu>(commandFactory_, menuBar());

	toolBar_ = std::make_unique<ToolBar>(commandFactory_,
		addToolBar("Main toolbar"));

    openFileDock_->createDock();

    setDockOptions(dockOptions() |
    	QMainWindow::GroupedDragging |
		QMainWindow::AllowNestedDocks |
		QMainWindow::AllowTabbedDocks);
    addDockWidget(Qt::TopDockWidgetArea, openFileDock_);

	textEdit_->setStatusTip("Text editor window");
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

	statusBar()->showMessage("Ready!");
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
