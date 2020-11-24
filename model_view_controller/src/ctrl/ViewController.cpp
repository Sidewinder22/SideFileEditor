/**
 * @author  {\_Sidewinder22_/}
 * @date    20.11.2020
 * 
 * @brief   View controller class.
 */

#include "ViewController.hpp"

namespace ctrl
{

ViewController::ViewController( view::ViewManager* viewManager )
    : viewManager_( viewManager )
{ }
    
void ViewController::created( const QString& bufferName )
{
    viewManager_->created( bufferName );
}

void ViewController::load( const QString& text )
{
    viewManager_->load( text );
}

};
