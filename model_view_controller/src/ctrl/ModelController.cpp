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

void ModelController::open( const QString& fileName )
{
	const QString exampleResponse( "Example text ;)" );
    emit opened( fileName, exampleResponse );
}

void ModelController::textChanged( const QString& bufferName,
    const QString& text )
{
    modelManager_->textChanged( bufferName, text );
}

QString ModelController::read( const QString& bufferName )
{
    return modelManager_->read( bufferName );
}

} // ::ctrl
