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
	, modelManager_( new model::ModelManager( ) )
    , controller_( new ctrl::Controller( ) )
{
	/*****************************
	 * ViewManager -> Controller
	******************************/
    connect( viewManager_,
        &view::ViewManager::createNotif,
        controller_,
        &ctrl::Controller::create );

    connect( viewManager_,
        &view::ViewManager::openNotif,
        controller_,
        &ctrl::Controller::open );

    connect( viewManager_,
        &view::ViewManager::saveNotif,
        controller_,
        &ctrl::Controller::save );

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


	/*****************************
	 * ModelManager -> Controller
	******************************/
    connect( modelManager_,
        &model::ModelManager::createdNotif,
		controller_,
        &ctrl::Controller::created );

    connect( modelManager_,
        &model::ModelManager::openedNotif,
		controller_,
        &ctrl::Controller::opened );

    connect( modelManager_,
        &model::ModelManager::readNotif,
		controller_,
        &ctrl::Controller::read );


	/*****************************
	 * Controller -> ViewManager
	******************************/
    connect( controller_,
        &ctrl::Controller::createdNotif,
		viewManager_,
        &view::ViewManager::created );

    connect( controller_,
        &ctrl::Controller::openedNotif,
		viewManager_,
        &view::ViewManager::opened );

    connect( controller_,
        &ctrl::Controller::loadNotif,
		viewManager_,
        &view::ViewManager::load );


	/*****************************
	 * Controller -> ModelManager
	******************************/
    connect( controller_,
        &ctrl::Controller::createRequest,
		modelManager_,
        &model::ModelManager::create );

    connect( controller_,
        &ctrl::Controller::openRequest,
		modelManager_,
        &model::ModelManager::open );

    connect( controller_,
        &ctrl::Controller::readRequest,
		modelManager_,
        &model::ModelManager::read );

    connect( controller_,
        &ctrl::Controller::textChangedNotif,
		modelManager_,
        &model::ModelManager::textChanged );
}
