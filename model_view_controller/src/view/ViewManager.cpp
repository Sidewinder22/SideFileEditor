/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   View manager class.
 */

#include "ViewManager.hpp"

namespace view
{
    
ViewManager::ViewManager( std::shared_ptr< view::CommandHandler > commandHandler )
    : log_( "ViewManager" )
    , window_( std::make_unique< view::Window >( commandHandler ) )
{ }
    
void ViewManager::bufferCreated( const QString& bufferName )
{
    log_ << MY_FUNC << ": " << bufferName << log::END;
}

} // ::view
