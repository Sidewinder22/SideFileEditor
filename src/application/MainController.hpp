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
#include "utils/Logger.hpp"
#include "window/IWindow.hpp"
#include "window/IWindowObserver.hpp"

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class MainController
    : public QObject
    , public IWindowObserver
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
     * @brief Read data from file
     * @param fileName file name
     * @return Vector contains file's data
     */
    std::vector<QString> read(const QString& fileName) override;

    /**
     * @brief Write data to file
     * @param fileName file name
     * @param text Text to write to file
     * @return True if successful, False otherwise
     */
    bool write(const QString& fileName, const QString& text) override;

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
    log::Logger log_;                                   //!< Logger object
    std::shared_ptr<IWindow> window_;                   //!< Window unique pointer
    std::shared_ptr<IFileManager> fileManager_;         //!< File manager unique pointer

};

#endif /* SRC_APPLICATION_MAINCONTROLLER_HPP_ */
