/**
 * @author  {\_Sidewinder22_/}
 * @date    10.10.2019
 *
 * @brief   Main Controller class
 */

#ifndef SRC_APPLICATION_MAINCONTROLLER_HPP_
#define SRC_APPLICATION_MAINCONTROLLER_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <memory>
#include <QObject>
#include "file/IFileManager.hpp"
#include "log/Logger.hpp"
#include "window/IWindow.hpp"
#include "window/IWindowObserver.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace app
{

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class MainController
    : public QObject
    , public window::IWindowObserver
{
	Q_OBJECT

//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
    MainController();

    /**
     * @brief Start app
     */
    void start();

//---------------------------------------------------------
//                  Protected
//---------------------------------------------------------
protected:
    //-----------------------------------------------------
    //                  IWindowObserver
    //-----------------------------------------------------
    /**
     * @brief Open file
     * @param fileName path for file
     */
    void openFile(const QString& fileName) override;

    /**
     * @brief Create new file
     * @param fileName path for file
     */
    void createFile(const QString& fileName) override;

    /**
     * @brief Text changed notification
     * @param fileName fileName
     * @param content content of the buffer
     */
    void textChanged(const QString& fileName, const QString &content) override;

    /**
     * @brief Read data from file
     * @param fileName file name
     * @return Vector contains file's data
     */
    std::vector<QString> read(const QString& fileName) override;

    /**
     * @brief Save data to file
     * @param fileName file name
     * @return True if successful, False otherwise
     */
    bool save(const QString &fileName) override;

    /**
     * @brief Close open file
     * @param fileName file name
     */
    void close(const QString& fileName) override;

    /**
     * @brief Remove file
     * @param fileName file name
     */
    void remove(const QString& fileName) override;

//---------------------------------------------------------
//                  Private
//---------------------------------------------------------
private:
    log::Logger log_;                                       //!< Logger object
    std::shared_ptr<window::IWindow> window_;               //!< Window unique pointer
    std::shared_ptr<file::IFileManager> fileManager_;       //!< File manager unique pointer
};

} // ::app

#endif /* SRC_APPLICATION_MAINCONTROLLER_HPP_ */
