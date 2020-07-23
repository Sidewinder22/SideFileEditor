/**
 * @author  {\_Sidewinder22_/}
 * @date    10.10.2019
 *
 * @brief   Main Controller class
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include "file/FileManager.hpp"
#include "window/Window.hpp"
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
    , window_(std::make_shared<window::Window>(this))
    , fileManager_(std::make_shared<file::FileManager>())
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
void MainController::openFile(const QString& fileName)
{
    bool status = fileManager_->openFile(fileName);
    window_->fileOpened(status, fileName);
}

void MainController::createFile(const QString& fileName)
{
    fileManager_->createBuffer(fileName);
    window_->fileCreated(fileName);
}

void MainController::saveBufferIntoFile(const QString& bufferName,
	const QString& fileName)
{
	fileManager_->saveBufferIntoFile(bufferName, fileName);
	window_->fileCreated(fileName);
}

void MainController::createBuffer(const QString& bufferName)
{
    fileManager_->createBuffer(bufferName);
    window_->bufferCreated(bufferName);
}

std::vector<QString> MainController::read(const QString& fileName)
{
    return fileManager_->read(fileName);
}

bool MainController::save(const QString &fileName)
{
    return fileManager_->save(fileName);
}

bool MainController::textChanged(const QString &fileName,
	const QString &content)
{
    return fileManager_->textChanged(fileName, content);
}

void MainController::close(const QString& fileName)
{
    fileManager_->close(fileName);
}

void MainController::remove(const QString& fileName)
{
    fileManager_->remove(fileName);
}

void MainController::clear(const QString& fileName)
{
    fileManager_->clear(fileName);
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

} // ::app
