/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   Model controller class.
 */

#include "ModelController.hpp"

namespace ctrl
{

ModelController::ModelController()
    : log_( "ModelController" )
    , modelManager_( std::make_unique< model::ModelManager >() )
{ }
    
void ModelController::create()
{
    auto bufferName = modelManager_->create();
    emit created( bufferName );
}

void ModelController::textChanged( const QString& bufferName,
    const QString& text )
{
    log_ << MY_FUNC << bufferName <<  ": " << text << log::END;
}

} // ::ctrl
