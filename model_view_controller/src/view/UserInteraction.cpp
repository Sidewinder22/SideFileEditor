/**
 * @author  {\_Sidewinder22_/}
 * @date    18.12.2020
 *
 * @brief   User interaction class
 */

#include "UserInteraction.hpp"
#include <QFileDialog>
#include <QMessageBox>
#include <QTranslator>
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

QString UserInteraction::getFileNameForOpen()
{
	return QFileDialog::getOpenFileName(
		parent_,
		QObject::tr( "Select file to open..." ),
		QDir::homePath(),
		QObject::tr( "Text files: *.txt *.h *.hpp *.c *.cc *.cpp *.py"
			"*.js *.ccs *.json (*.txt *.h *.hpp *.c *.cc *.cpp *.py"
			"*.js *.ccs *.json)" ) );
}

}  // ::view
