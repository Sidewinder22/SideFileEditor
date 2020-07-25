/**
 * @author  {\_Sidewinder22_/}
 * @date    25 lip 2020
 * @file    AboutCommand.cpp
 *
 * @brief   
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QString>
#include <QMessageBox>
#include "AboutCommand.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace command
{

AboutCommand::AboutCommand(QWidget* parent)
	: log_("AboutCommand")
	, parent_(parent)
{
	// Nothing
}

void AboutCommand::execute()
{
    QString description;
    description.append(APP);
    description.append(BY);
    description.append(AUTHOR);

    QMessageBox::about(parent_, ABOUT, description);
}

} // ::command
