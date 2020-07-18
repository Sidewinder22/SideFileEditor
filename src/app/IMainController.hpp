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
    virtual void openFile(const QString& fileName) = 0;

    /**
     * @brief Create new file
     * @param fileName path for file
     */
    virtual void createFile(const QString& fileName) = 0;

    /**
     * @brief Create new empty buffer
     * @param bufferName name for the buffer
     */
    virtual void createBuffer(const QString& bufferName) = 0;

    /**
     * @brief Create new file
     * @param bufferName name of the buffer
     * @param fileName path for file
     */
    virtual void createFileFromBuffer(const QString& bufferName,
    	const QString& fileName) = 0;

    /**
     * @brief Text changed notification
     * @param fileName fileName
     * @param content content of the buffer
     */
    virtual void textChanged(const QString& fileName, const QString &content) = 0;

    /**
     * @brief Read data from file
     * @param fileName file name
     * @return Vector contains file's data
     */
    virtual std::vector<QString> read(const QString& fileName) = 0;

    /**
     * @brief Save data to file
     * @param fileName file name
     * @return True if successful, False otherwise
     */
    virtual bool save(const QString &fileName) = 0;

    /**
     * @brief Close open file
     * @param fileName file name
     */
    virtual void close(const QString& fileName) = 0;

    /**
     * @brief Remove file
     * @param fileName file name
     */
    virtual void remove(const QString& fileName) = 0;

    /**
     * @brief Clear buffer content
     * @param fileName file name
     */
    virtual void clear(const QString& fileName) = 0;

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
};

} // ::app

#endif /* SRC_APP_IMAINCONTROLLER_HPP_ */
