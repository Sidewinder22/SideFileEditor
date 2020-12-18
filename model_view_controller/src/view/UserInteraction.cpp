/**
 * @author  {\_Sidewinder22_/}
 * @date    18.12.2020
 *
 * @brief   User interaction class
 */

#include "UserInteraction.hpp"
#include <QMessageBox>
#include <QString>

namespace view
{

UserInteraction::UserInteraction( QWidget* parent )
	: parent_( parent )
{ }

void UserInteraction::showAboutInfo()
{
    QString description;
    description.append(APP);
    description.append(BY);
    description.append(AUTHOR);

    QMessageBox::about(parent_, ABOUT, description);
}

}  // ::view
