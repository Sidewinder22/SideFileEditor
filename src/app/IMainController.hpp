#ifndef SRC_APP_IMAINCONTROLLER_HPP_
#define SRC_APP_IMAINCONTROLLER_HPP_
/**
 * @author  {\_Sidewinder22_/}
 * @date    11.10.2019
 *
 * @brief   Main controller interface
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <vector>
#include <QString>

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace app
{

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class IMainController
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
	virtual ~IMainController() = default;

    /**
     * @brief Open file
     * @param fileName path for file
     */
    virtual void open(const QString& fileName) const = 0;

    /**
     * @brief Read data from file
     * @param fileName file name
     * @return Vector contains file's data
     */
    virtual std::vector<QString> read(const QString& fileName) const = 0;

    /**
     * @brief Save data to file
     * @param fileName file name
     * @return True if successful, False otherwise
     */
    virtual bool save(const QString &fileName) const = 0;

    /**
     * @brief Close open file
     * @param fileName file name
     */
    virtual void close(const QString& fileName) const = 0;

    /**
     * @brief Remove file
     * @param fileName file name
     */
    virtual void remove(const QString& fileName) const = 0;

    /**
     * @brief Create new empty buffer
     * @param bufferName name for the buffer
     */
    virtual void createBuffer(const QString& bufferName) const = 0;

    /**
     * @brief Save buffer's content as a new file
     * @param bufferName name of the buffer
     * @param fileName path for file
     * @return True if successful, False otherwise
     */
    virtual bool saveBufferIntoFile(const QString& bufferName,
    	const QString& fileName) const = 0;

    /**
     * @brief Text changed notification
     * @param fileName fileName
     * @param content content of the buffer
     * @return True if buffer content changed, False otherwise
     */
    virtual bool textChanged(const QString& fileName,
    	const QString &content) const = 0;

    /**
     * @brief Return the number of the open buffers
     * @return Number of the open buffers
     */
    virtual size_t numberOfBuffers() const = 0;

     /**
     * @brief Return the number of the unsaved buffers
     * @return NUmber of the unsaved buffers
     */
    virtual size_t numberOfUnsavedBuffers() const = 0;

    /**
     * @brief Return names of the unsaved buffers
     * @return Vector with the names of the unsaved buffers
     */
    virtual std::vector<QString> unsavedBufferNames() const = 0;

    /**
     * @brief Check if file is saved
     * @param fileName name of the file to check
     * @return True if file is saved, False otherwise
     */
    virtual bool isFileSaved(const QString& fileName) const = 0;

    /*
     * @brief Check if file is empty
     * @param fileName name of the file to check
     * @return True if file is empty, False otherwise
     */
    virtual bool isFileEmpty(const QString& fileName) const = 0;
};

} // ::app

#endif /* SRC_APP_IMAINCONTROLLER_HPP_ */
