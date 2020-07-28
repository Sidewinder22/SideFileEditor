/**
 * @author  {\_Sidewinder22_/}
 * @date    25 lip 2020
 * @file    CommandUtils.hpp
 *
 * @brief   Command useful utils
 */
#ifndef SRC_GUI_COMMAND_COMMANDUTILS_HPP_
#define SRC_GUI_COMMAND_COMMANDUTILS_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QString>
#include "app/IMainController.hpp"
#include "gui/OpenFilesDock.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace gui
{
namespace command
{
namespace utils
{

QString askUserForFileLocation(QWidget* parent);

bool askForSaveBuffer(const QString& name);

bool saveFile(QWidget* parent,
	app::IMainController* mainController,
	gui::OpenFilesDock* openFileDock);

} // :: utils
} // ::command
} // ::gui

#endif /* SRC_GUI_COMMAND_COMMANDUTILS_HPP_ */
