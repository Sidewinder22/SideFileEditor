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
        &view::CommandHandler::newFileRequested, 
        controller_,
        &ctrl::Controller::newFile );

    connect( controller_,
        &ctrl::Controller::created,
        viewManager_,
        &view::ViewManager::bufferCreated );

}
