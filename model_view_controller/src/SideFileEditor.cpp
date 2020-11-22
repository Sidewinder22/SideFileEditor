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
    , modelController_( new ctrl::ModelController() )
    , viewController_( new ctrl::ViewController( viewManager_ ) )
    , controller_( new ctrl::Controller( modelController_, viewController_ ) )
{
    connect( commandHandler_,
        &view::CommandHandler::newFileRequest, 
        controller_,
        &ctrl::Controller::newFile );

    connect( commandHandler_,
        &view::CommandHandler::quitRequest, 
        controller_,
        &ctrl::Controller::quit );

    connect( modelController_,
        &ctrl::ModelController::created,
        viewManager_,
        &view::ViewManager::created );

    connect( viewManager_,
        &view::ViewManager::textChangedNotif,
        modelController_,
        &ctrl::ModelController::textChanged );
}
