/**
 * @author  {\_Sidewinder22_/}
 * @date    13.11.2020
 * 
 * @brief   Main controller class.
 */

#include "Controller.hpp"
#include "ModelController.hpp"
#include "cmd/CommandFactory.hpp"

#include <memory>

namespace ctrl
{

Controller::Controller( )
    : log_( "Controller" )
    , modelController_( new ModelController( ) )
    , commandFactory_( std::make_unique< cmd::CommandFactory > (
    	modelController_) )
{
    connect( modelController_,
        &ctrl::ModelController::created,
        this,
        &Controller::created );

    connect( modelController_,
        &ctrl::ModelController::opened,
        this,
        &Controller::opened );
}

void Controller::newFile()
{
    log_ << MY_FUNC << log::END;

    commandFactory_->getNewCommandHandler().execute();
}

void Controller::open( const QString& fileName )
{
    log_ << MY_FUNC << ": " << fileName << log::END;

    modelController_->open( fileName );
}

void Controller::save( const QString& fileName )
{
    log_ << MY_FUNC << ": " << fileName << log::END;

}

void Controller::quit()
{
    log_ << MY_FUNC << log::END;

    commandFactory_->getQuitCommandHandler().execute();
}

void Controller::created( const QString& bufferName )
{
	emit createdNotif( bufferName );
}

void Controller::opened( const QString& fileName, const QString& text )
{
	emit openedNotif( fileName, text );
}
    
void Controller::textChanged( const QString& bufferName, const QString& text )
{
    log_ << MY_FUNC << log::END;
    modelController_->textChanged( bufferName, text );
}
    
void Controller::bufferSelectionChanged( const QString& bufferName )
{
    log_ << MY_FUNC << bufferName << log::END;

    auto text = modelController_->read( bufferName );
    emit loadNotif( text );
//    viewController_->load( text );
}
    
} // ::ctrl
