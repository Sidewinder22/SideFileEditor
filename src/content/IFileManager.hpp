#ifndef SRC_CONTENT_IFILEMANAGER_HPP_
#define SRC_CONTENT_IFILEMANAGER_HPP_
/**
 * @author  {\_Sidewinder22_/}
 * @date    10.10.2019
 *
 * @brief   File operations interface
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <vector>
#include <QString>

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace content
{

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class IFileManager
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
    virtual ~IFileManager() = default;

    /**
     * @brief Open file
     * @param fileName path for file
     * @return True if successfull, Fale otherwise
     */
    virtual bool openFile(const QString& fileName) = 0;

    /**
     * @brief Save buffer's content as a new file
     * @param bufferName name of the buffer
     * @param fileName path for file
     * @return True if successful, False otherwise
     */
    virtual bool saveBufferIntoFile(const QString& bufferName,
    	const QString& fileName) = 0;

    /**
     * @brief Open buffer for new file
     * @param fileName fileName
     */
    virtual void createBuffer(const QString& fileName) = 0;

    /**
     * @brief Text changed notification
     * @param fileName fileName
     * @param content content of the buffer
     * @return True if buffer content changed, False otherwise
     */
    virtual bool textChanged(const QString &fileName,
    	const QString &content) = 0;

    /**
     * @brief Read data from file
     * @param fileName Filename of open file
     * @return Vector contains file's data
     */
    virtual std::vector<QString> read(const QString& fileName) = 0;

    /**
     * @brief Save data to file
     * @param fileName Filename of open file
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
     * @brief Return the number of the open buffers
     * @return Number of the open buffers
     */
    virtual size_t numberOfOpenBuffers() const = 0;

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

    virtual bool isFileSaved(const QString& fileName) = 0;

    virtual bool isFileEmpty(const QString& fileName) = 0;
};

} // ::content

#endif /* SRC_CONTENT_IFILEMANAGER_HPP_ */
