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

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace command
{
namespace utils
{

QString askUserForFileLocation(QWidget* parent);

} // :: utils
} // ::comand

#endif /* SRC_WINDOW_COMMAND_COMMANDUTILS_HPP_ */
