#ifndef SRC_FILE_IFILEMANAGER_HPP_
#define SRC_FILE_IFILEMANAGER_HPP_
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
namespace file
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
     * @brief Open buffer for new file
     * @param fileName fileName
     */
    virtual void createBuffer(const QString& fileName) = 0;

    /**
     * @brief Text changed notification
     * @param fileName fileName
     * @param content content of the buffer
     */
    virtual void textChanged(const QString &fileName, const QString &content) = 0;

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

} // ::file

#endif /* SRC_FILE_IFILEMANAGER_HPP_ */
