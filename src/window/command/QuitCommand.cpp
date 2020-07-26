/**
 * @author  {\_Sidewinder22_/}
 * @date    26 lip 2020
 * @file    QuitCommand.cpp
 *
 * @brief   Class handles quit command
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QApplication>
#include "CommandUtils.hpp"
#include "QuitCommand.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace window
{
namespace command
{

QuitCommand::QuitCommand(QWidget* parent, app::IMainController* mainController)
	: log_("QuitCommand")
	, parent_(parent)
	, mainController_(mainController)
	, commonUtils_(std::make_unique<::utils::Utils>())
{
	// Nothing
}

void QuitCommand::execute()
{
    log_ << MY_FUNC << log::END;

    auto numberOfUnsavedBuffers = mainController_->numberOfUnsavedBuffers();

    log_ << MY_FUNC << ", open files = "
    	<< std::to_string(numberOfUnsavedBuffers)
    	<< log::END;

    if (numberOfUnsavedBuffers > 0)
    {
    	verifyUnsavedBuffers();
    }

    QApplication::quit();
}

void QuitCommand::verifyUnsavedBuffers()
{
    log_ << MY_FUNC << log::END;

    auto unsavedBufferNames = mainController_->unsavedBufferNames();

    for (auto && bufferName : unsavedBufferNames)
   {
		if (utils::askForSaveBuffer(bufferName))
		{
			if (bufferName.contains('/'))
			{
				mainController_->save(
					commonUtils_->extractFileName(bufferName));
			}
			else
			{
				auto fileName = utils::askUserForFileLocation(parent_);
				if (!fileName.isEmpty())
				{
					mainController_->saveBufferIntoFile(bufferName, fileName);
				}
			}
		}
    }
}

} // ::command
} // ::window
