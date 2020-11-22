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
    : commandHandler_( new view::CommandHandler() )
    , viewManager_( new view::ViewManager( commandHandler_ ) )
    , controller_( new ctrl::Controller( viewManager_ ) )
{
    connect( commandHandler_,
        &view::CommandHandler::newFileRequest, 
        controller_,
        &ctrl::Controller::newFile );

    connect( commandHandler_,
        &view::CommandHandler::quitRequest, 
        controller_,
        &ctrl::Controller::quit );

    connect( controller_,
        &ctrl::Controller::created,
        viewManager_,
        &view::ViewManager::bufferCreated );

    connect( viewManager_,
        &view::ViewManager::textChangedNotif,
        controller_,
        &ctrl::Controller::textChanged );
}
