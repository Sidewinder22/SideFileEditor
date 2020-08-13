#ifndef SRC_APPLICATION_MAINCONTROLLER_HPP_
#define SRC_APPLICATION_MAINCONTROLLER_HPP_
/**
 * @author  {\_Sidewinder22_/}
 * @date    10.10.2019
 *
 * @brief   Main Controller class
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <memory>
#include "content/IContentManager.hpp"
#include "gui/IWindow.hpp"
#include "log/Logger.hpp"
#include "IMainController.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace app
{

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class MainController
	: public IMainController
{
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
    //                  IMainController
    //-----------------------------------------------------
    /**
     * @brief Open file
     * @param fileName path for file
     */
    void open(const QString& fileName) const override;

    /**
     * @brief Read data from file
     * @param fileName file name
     * @return Vector contains file's data
     */
    std::vector<QString> read(const QString& fileName) const override;

    /**
     * @brief Save data to file
     * @param fileName file name
     * @return True if successful, False otherwise
     */
    bool save(const QString &fileName) const override;

    /**
     * @brief Close open file
     * @param fileName file name
     */
    void close(const QString& fileName) const override;

    /**
     * @brief Remove file
     * @param fileName file name
     */
    void remove(const QString& fileName) const override;

    /**
     * @brief Save buffer's content as a new file
     * @param bufferName name of the buffer
     * @param fileName path for file
     * @return True if successful, False otherwise
     */
    bool saveBufferIntoFile(const QString& bufferName,
    	const QString& fileName) const override;

    /**
     * @brief Create new empty buffer
     * @param bufferName name for the buffer
     */
    void createBuffer(const QString& bufferName) const override;

    /**
     * @brief Text changed notification
     * @param fileName fileName
     * @param content content of the buffer
     * @return True if buffer content changed, False otherwise
     */
    bool textChanged(const QString& fileName, const QString &content) const
    	override;

    /**
     * @brief Return the number of the open buffers
     * @return Number of the open buffers
     */
    size_t numberOfBuffers() const override;

    /**
     * @brief Return the number of the unsaved buffers
     * @return NUmber of the unsaved buffers
     */
    size_t numberOfUnsavedBuffers() const override;

    /**
     * @brief Return names of the unsaved buffers
     * @return Vector with the names of the unsaved buffers
     */
    std::vector<QString> namesOfUnsavedBuffers() const override;

    /**
     * @brief Check if buffer is saved
     * @param fileName name of the buffer to check
     * @return True if buffer is saved, False otherwise
     */
    bool isBufferSaved(const QString& fileName) const override;

    /*
     * @brief Check if buffer is empty
     * @param fileName name of the buffer to check
     * @return True if buffer is empty, False otherwise
     */
    bool isBufferEmpty(const QString& fileName) const override;

//---------------------------------------------------------
//                  Private
//---------------------------------------------------------
private:
    log::Logger log_;
    std::unique_ptr<gui::IWindow> window_;
    std::unique_ptr<content::IContentManager> contentManager_;
};

} // ::app

#endif /* SRC_APPLICATION_MAINCONTROLLER_HPP_ */
