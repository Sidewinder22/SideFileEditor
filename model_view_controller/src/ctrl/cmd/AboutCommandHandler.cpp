/*
 * @author	{\_Sidewinder22_/}
 * @date	25 lis 2020
 * 
 * @brief   New command handler.
 */

#include <QMessageBox>
#include <QString>
#include "AboutCommandHandler.hpp"

namespace ctrl
{
namespace cmd
{
AboutCommandHandler::AboutCommandHandler( QWidget* parent )
    : parent_( parent )
{ }

void AboutCommandHandler::execute()
{
    QString description;
    description.append(APP);
    description.append(BY);
    description.append(AUTHOR);

    QMessageBox::about(parent_, ABOUT, description);
}

} // ::cmd
} // ::ctrl


