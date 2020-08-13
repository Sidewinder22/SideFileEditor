/**
 * @author  {\_Sidewinder22_/}
 * @date    10.10.2019
 *
 * @brief   Main Controller class
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include "gui/Window.hpp"
#include "content/ContentManager.hpp"
#include "MainController.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace app
{

//---------------------------------------------------------./
//                  Class implementation
//---------------------------------------------------------
MainController::MainController()
    : log_("MainController")
    , window_(std::make_unique<gui::Window>(this))
	, contentManager_(std::make_unique<content::ContentManager>())
{
    // Nothing
}

void MainController::start()
{
	window_->init();
}

//-----------------------------------------------------
//                  IWindowObserver
//-----------------------------------------------------
void MainController::open(const QString& fileName) const
{
    bool status = contentManager_->open(fileName);
    window_->opened(status, fileName);
}

std::vector<QString> MainController::read(const QString& fileName) const
{
    return contentManager_->read(fileName);
}

bool MainController::save(const QString &fileName) const
{
    return contentManager_->save(fileName);
}

void MainController::close(const QString& fileName) const
{
    contentManager_->close(fileName);
}

void MainController::remove(const QString& fileName) const
{
    contentManager_->remove(fileName);
}

bool MainController::saveBufferIntoFile(const QString& bufferName,
	const QString& fileName) const
{
	bool status = contentManager_->saveBufferIntoFile(bufferName, fileName);
	window_->created(fileName);

	return status;
}

void MainController::createBuffer(const QString& bufferName) const
{
    contentManager_->createBuffer(bufferName);
    window_->created(bufferName);
}

bool MainController::textChanged(const QString &fileName,
	const QString &content) const
{
    return contentManager_->contentChanged(fileName, content);
}

size_t MainController::numberOfBuffers() const
{
	return contentManager_->numberOfBuffers();
}

size_t MainController::numberOfUnsavedBuffers() const
{
	return contentManager_->numberOfUnsavedBuffers();
}

std::vector<QString> MainController::namesOfUnsavedBuffers() const
{
	return contentManager_->namesOfUnsavedBuffers();
}

bool MainController::isBufferSaved(const QString& fileName) const
{
	return contentManager_->isBufferSaved(fileName);
}

bool MainController::isBufferEmpty(const QString& fileName) const
{
	return contentManager_->isBufferEmpty(fileName);
}

} // ::app
