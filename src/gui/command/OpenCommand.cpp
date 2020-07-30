/**
 * @author  {\_Sidewinder22_/}
 * @date    25 lip 2020
 * @file    OpenCommand.cpp
 *
 * @brief   Class handles open command
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <string>
#include <QString>
#include <QFileDialog>
#include <QTranslator>
#include "OpenCommand.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace gui
{
namespace command
{

OpenCommand::OpenCommand(QWidget* parent, app::IMainController* mainController,
	gui::OpenFilesDock* openFileDock)
	: log_("OpenCommand")
	, parent_(parent)
	, mainController_(mainController)
	, openFileDock_(openFileDock)
{
	// Nothing
}

void OpenCommand::execute()
{
    log_ << MY_FUNC << log::END;

    auto fileName = askUserForFileName();
    if (!fileName.isEmpty())
    {
		/**
		 * Delete empty startup buffer
		 */
    	auto openBuffers = mainController_->numberOfOpenBuffers();
		auto unsavedBuffers = mainController_->numberOfUnsavedBuffers();
		if (openBuffers == ONE_BUFFER_OPEN &&
			unsavedBuffers == ALL_BUFFERS_SAVED)
		{
			auto bufferName = "Buffer" + std::to_string(ONE_BUFFER_OPEN);
			mainController_->close(QString::fromStdString(bufferName));

			int row = openFileDock_->getCurrentRow();
			openFileDock_->removeFileName(row);
		}

		mainController_->open(fileName);
    }
}

QString OpenCommand::askUserForFileName() const
{
	return QFileDialog::getOpenFileName(
		parent_,
        QObject::tr("Select file to open..."),
        QDir::homePath(),
        QObject::tr("Text files: *.txt *.h *.hpp *.c *.cc *.cpp *.py *.js *.ccs *.json (*.txt *.h *.hpp *.c *.cc *.cpp *.py *.js *.ccs *.json)"));
}

} // ::command
} // ::gui
