/**
 * @author  {\_Sidewinder22_/}
 * @date    25 lip 2020
 * @file    NewCommand.cpp
 *
 * @brief   Class handles new command
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QString>
#include "NewCommand.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace gui
{
namespace command
{

int NewCommand::bufferNumber_ = 1;

NewCommand::NewCommand(app::IMainController* mainController)
	: log_("NewCommand")
	, mainController_(mainController)
{
	// Nothing
}

void NewCommand::execute()
{
    log_ << MY_FUNC << log::END;

	auto bufferName = "Buffer" + std::to_string(bufferNumber_++);
	mainController_->createBuffer(QString::fromStdString(bufferName.c_str()));
}

} // ::command
} // ::gui
