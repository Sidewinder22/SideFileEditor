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
    window_->fileCreated(true, fileName);
}
std::vector<QString> MainController::read(const QString& fileName)
{
    return fileManager_->read(fileName);
}

bool MainController::write(const QString& fileName, const QString& text)
{
    return fileManager_->write(fileName, text);
}

void MainController::textChanged(const QString &fileName, const QString &content)
{
    fileManager_->textChanged(fileName, content);
}

void MainController::close(const QString& fileName)
{
    fileManager_->close(fileName);
}

void MainController::remove(const QString& fileName)
{
    fileManager_->remove(fileName);
}

} // ::app
