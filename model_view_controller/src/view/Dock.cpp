/**
 * @author  {\_Sidewinder22_/}
 * @date    13.11.2020
 * 
 * @brief   Dock for open files.
 */

#include "Dock.hpp"
#include <QEvent>
#include <QMouseEvent>

namespace view
{

Dock::Dock()
    : QDockWidget( "Open files" )
    , log_( "Dock" )
    , names_( new QListWidget( this ) )
{
    setStatusTip( "Open files list" );
    setFloating( false );
    setMaximumHeight( 60 );
    setAllowedAreas( Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea );

    names_->setFlow(QListView::LeftToRight);
    names_->setLayoutMode(QListView::SinglePass);
    names_->setWrapping(true);

    setWidget( names_ );

    connect( names_,
        &QListWidget::currentRowChanged,
        this,
        &Dock::rowChanged );
}

void Dock::addName( const QString& bufferName )
{
    auto item = new QListWidgetItem( bufferName );
    names_->addItem( item );
    names_->setCurrentItem( item );
}

void Dock::setNewName( const QString& newName )
{
	const auto row = names_->currentRow();
	names_->takeItem( row );

	addName( newName );
}

void Dock::removeCurrentFileName()
{
    const auto row = names_->currentRow();
    names_->takeItem( row );
}

QString Dock::getCurrent()
{
    QString fileName;

    if ( names_->currentRow() > -1 )
    {
        fileName = names_->currentItem()->text();
    }

    return fileName;
}
    
void Dock::rowChanged( int row )
{
    log_ << FUNC << "current row: " << row << log::END;
    emit bufferSelectionChangedNotif( getCurrent() );
}

} // ::view
