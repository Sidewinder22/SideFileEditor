/**
 * @author  {\_Sidewinder22_/}
 * @date    25 lip 2020
 * @file    AboutCommand.cpp
 *
 * @brief   Class handles about command
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include "AboutCommand.hpp"
#include <QString>
#include <QMessageBox>

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace gui
{
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
} // ::gui
