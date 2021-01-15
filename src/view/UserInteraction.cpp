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

void UserInteraction::showAboutInfo() const
{
    QString description;
    description.append( APP );
    description.append( BY );
    description.append( AUTHOR );

    QMessageBox::about( parent_, ABOUT, description );
}

void UserInteraction::showSaveWarning() const
{
	QMessageBox::warning( parent_, "WARN", SAVE_WARNING );
}

QString UserInteraction::getFileNameForSave( const QString& bufferName )
{
	QString label = SAVE_QUESTION + bufferName;

	return QFileDialog::getSaveFileName(
		parent_,
		QObject::tr( label.toStdString().c_str() ),
		QDir::homePath(),
		QObject::tr( FILE_TYPES ) );
}

QString UserInteraction::getFileNameForOpen()
{
	return QFileDialog::getOpenFileName(
		parent_,
		QObject::tr( OPEN_QUESTION ),
		QDir::homePath(),
		QObject::tr( FILE_TYPES ) );
}

}  // ::view
