/**
 * @author  {\_Sidewinder22_/}
 * @date    10.10.2019
 *
 * @brief   Main Controller class
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include "content/FileManager.hpp"
#include "gui/Window.hpp"
#include "MainController.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace app
{

//---------------------------------------------------------
//                  Class implementation
//---------------------------------------------------------
MainController::MainController()
    : log_("MainController")
    , window_(std::make_shared<gui::Window>(this))
    , fileManager_(std::make_shared<content::FileManager>())
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
void MainController::openFile(const QString& fileName) const
{
    bool status = fileManager_->openFile(fileName);
    window_->opened(status, fileName);
}

bool MainController::saveBufferIntoFile(const QString& bufferName,
	const QString& fileName) const
{
	bool status = fileManager_->saveBufferIntoFile(bufferName, fileName);
	window_->created(bufferName);

	return status;
}

void MainController::createBuffer(const QString& bufferName) const
{
    fileManager_->createBuffer(bufferName);
    window_->created(bufferName);
}

std::vector<QString> MainController::read(const QString& fileName) const
{
    return fileManager_->read(fileName);
}

bool MainController::save(const QString &fileName) const
{
    return fileManager_->save(fileName);
}

bool MainController::textChanged(const QString &fileName,
	const QString &content) const
{
    return fileManager_->textChanged(fileName, content);
}

void MainController::close(const QString& fileName) const
{
    fileManager_->close(fileName);
}

void MainController::remove(const QString& fileName) const
{
    fileManager_->remove(fileName);
}

size_t MainController::numberOfOpenBuffers() const
{
	return fileManager_->numberOfOpenBuffers();
}

size_t MainController::numberOfUnsavedBuffers() const
{
	return fileManager_->numberOfUnsavedBuffers();
}

std::vector<QString> MainController::unsavedBufferNames() const
{
	return fileManager_->unsavedBufferNames();
}

bool MainController::isFileSaved(const QString& fileName) const
{
	return fileManager_->isFileSaved(fileName);
}

bool MainController::isFileEmpty(const QString& fileName) const
{
	return fileManager_->isFileEmpty(fileName);
}

} // ::app
