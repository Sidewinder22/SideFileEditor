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
    : viewManager_( new view::ViewManager( ) )
    , controller_( new ctrl::Controller( viewManager_ ) )
{
    connect( viewManager_,
        &view::ViewManager::newFileNotif,
        controller_,
        &ctrl::Controller::newFile );

    connect( viewManager_,
        &view::ViewManager::openNotif,
        controller_,
        &ctrl::Controller::open );

    connect( viewManager_,
        &view::ViewManager::aboutNotif,
        controller_,
        &ctrl::Controller::about );

    connect( viewManager_,
        &view::ViewManager::quitNotif,
        controller_,
        &ctrl::Controller::quit );

    connect( viewManager_,
        &view::ViewManager::textChangedNotif,
        controller_,
        &ctrl::Controller::textChanged );

    connect( viewManager_,
        &view::ViewManager::bufferSelectionChangedNotif,
        controller_,
        &ctrl::Controller::bufferSelectionChanged );
}
