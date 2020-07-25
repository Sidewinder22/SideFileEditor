/**
 * @author  {\_Sidewinder22_/}
 * @date    25 lip 2020
 * @file    CommandUtils.cpp
 *
 * @brief   
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QFileDialog>
#include "CommandUtils.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace command
{

namespace utils
{

QString askUserForFileLocation(QWidget* parent)
{
	return QFileDialog::getSaveFileName(
		parent,
		QObject::tr("Select location for a file"),
		QDir::homePath(),
		QObject::tr("Text files: *.txt *.h *.hpp *.c *.cc *.cpp *.py *.js *.ccs *.json (*.txt *.h *.hpp *.c *.cc *.cpp *.py *.js *.ccs *.json)"));
}

} // :: utils

} // ::comand


