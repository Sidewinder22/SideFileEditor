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

    connect( viewManager_,
        &view::ViewManager::savePathNotif,
        controller_,
        &ctrl::Controller::savePath );


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

    connect( modelManager_,
        &model::ModelManager::savedNotif,
		controller_,
        &ctrl::Controller::saved );

    connect( modelManager_,
        &model::ModelManager::getSavePathRequest,
		controller_,
        &ctrl::Controller::getSavePath );

    connect( modelManager_,
        &model::ModelManager::newBufferNameNotif,
		controller_,
        &ctrl::Controller::newBufferName );


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
        &ctrl::Controller::savedNotif,
		viewManager_,
        &view::ViewManager::saved );

    connect( controller_,
        &ctrl::Controller::loadNotif,
		viewManager_,
        &view::ViewManager::load );

    connect( controller_,
        &ctrl::Controller::getSavePathRequest,
		viewManager_,
        &view::ViewManager::getSavePath );

    connect( controller_,
        &ctrl::Controller::newBufferNameNotif,
		viewManager_,
        &view::ViewManager::newBufferName );


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
        &ctrl::Controller::saveRequest,
		modelManager_,
        &model::ModelManager::save );

    connect( controller_,
        &ctrl::Controller::textChangedNotif,
		modelManager_,
        &model::ModelManager::textChanged );

    connect( controller_,
        &ctrl::Controller::savePathNotif,
		modelManager_,
        &model::ModelManager::savePath );
}
