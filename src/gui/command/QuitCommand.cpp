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
#include "QuitCommand.hpp"
#include "CommandUtils.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace gui
{
namespace command
{

QuitCommand::QuitCommand(QWidget* parent, app::IMainController* mainController)
	: log_("QuitCommand")
	, parent_(parent)
	, mainController_(mainController)
	, commonUtils_(std::make_unique<::common::CommonUtils>())
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

    for (auto && bufferName : mainController_->namesOfUnsavedBuffers())
    {
		if (utils::askForSaveBuffer(bufferName))
		{
			if (bufferName.contains('/'))
			{
				mainController_->save(bufferName);
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
} // ::gui
