/**
 * @author  {\_Sidewinder22_/}
 * @date    13.11.2020
 * 
 * @brief   Main controller class.
 */

#include "Controller.hpp"
#include "cmd/CommandFactory.hpp"

#include <ios>

#include <memory>

namespace ctrl
{

Controller::Controller( )
    : log_( "Controller" )
    , commandFactory_( std::make_unique< cmd::CommandFactory > () )
{ }

void Controller::create()
{
    log_ << FUNC << log::END;

    emit createRequest();
}

void Controller::open( const QString& fileName )
{
    log_ << FUNC << ": " << fileName << log::END;

    emit openRequest( fileName );
}

void Controller::save( const QString& bufferName, const QString& text )
{
	emit saveRequest( bufferName, text );
}
	
void Controller::close( const QString& bufferName )
{
    emit closeRequest( bufferName );
}

void Controller::quit()
{
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

void Controller::saved( const QString& bufferName, bool success )
{
    log_ << FUNC << ": " << bufferName << ", success = "
    	<< std::boolalpha << success << log::END;

    emit savedNotif( bufferName, success );
}

void Controller::closed( const QString& bufferName )
{
    emit closedNotif( bufferName );
}

void Controller::read( const QString& text )
{
	log_ << FUNC << "text: " << text << log::END;

    emit loadNotif( text );
}
    
void Controller::textChanged( const QString& bufferName, const QString& text )
{
    log_ << FUNC << log::END;

    emit textChangedNotif( bufferName, text );
}
    
void Controller::bufferSelectionChanged( const QString& bufferName )
{
    log_ << FUNC << bufferName << log::END;

    emit readRequest( bufferName );
}

void Controller::getSavePath( const QString& bufferName )
{
	emit getSavePathRequest( bufferName );
}

void Controller::savePath( const QString& bufferName, const QString& path )
{
	emit savePathNotif( bufferName, path );
}

void Controller::newBufferName( const QString& newBufferName )
{
	emit newBufferNameNotif( newBufferName );
}
    
} // ::ctrl
