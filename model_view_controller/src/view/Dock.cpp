/**
 * @author  {\_Sidewinder22_/}
 * @date    13.11.2020
 * 
 * @brief   Dock for open files.
 */

#include "Dock.hpp"

namespace view
{

Dock::Dock()
    : QDockWidget( "Open files" )
    , log_( "Dock" )
    , names_( new QListWidget( this ) )
{
    setStatusTip( "Open files list" );
    setFloating( false );
    setMaximumHeight(60);
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
    
void Dock::rowChanged( int currentRow )
{
    log_ << MY_FUNC << "current row: " << currentRow << log::END;
}

} // ::view
