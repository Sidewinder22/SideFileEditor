/**
 * @author  {\_Sidewinder22_/}
 * @date    12.11.2020
 * 
 * @brief   Side file editor class.
 */

#include <QScreen>
#include <QGuiApplication>
#include "SideFileEditor.hpp"

SideFileEditor::SideFileEditor()
    : controller_( std::make_unique< ctrl::Controller >() )
    , commandHandler_( std::make_shared< view::CommandHandler >() )
    , viewManager_( std::make_unique< view::ViewManager >( commandHandler_ ) )
{
    connect( commandHandler_.get(),
        &view::CommandHandler::newFileRequested, 
        controller_.get(),
        &ctrl::Controller::newFile );

    connect( controller_.get(),
        &ctrl::Controller::created,
        viewManager_.get(),
        &view::ViewManager::bufferCreated );

}
