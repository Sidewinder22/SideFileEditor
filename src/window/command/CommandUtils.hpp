/**
 * @author  {\_Sidewinder22_/}
 * @date    25 lip 2020
 * @file    CommandUtils.hpp
 *
 * @brief   Command useful utils
 */
#ifndef SRC_WINDOW_COMMAND_COMMANDUTILS_HPP_
#define SRC_WINDOW_COMMAND_COMMANDUTILS_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QString>
#include "app/IMainController.hpp"
#include "window/OpenFilesDock.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace window
{
namespace command
{
namespace utils
{

QString askUserForFileLocation(QWidget* parent);

bool askForSaveBuffer(const QString& name);

bool saveFile(QWidget* parent,
	app::IMainController* mainController,
	window::OpenFilesDock* openFileDock);

} // :: utils
} // ::command
} // ::window

#endif /* SRC_WINDOW_COMMAND_COMMANDUTILS_HPP_ */
