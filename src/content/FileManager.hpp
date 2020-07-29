#ifndef SRC_CONTENT_FILEMANAGER_HPP_
#define SRC_CONTENT_FILEMANAGER_HPP_
/**
 * @author  {\_Sidewinder22_/}
 * @date    11.02.2019
 *
 * @brief   FileManager Manager class
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <memory>
#include <vector>
#include <QString>
#include "common/CommonUtils.hpp"
#include "ContentUtils.hpp"
#include "log/Logger.hpp"
#include "IBuffer.hpp"
#include "IFile.hpp"
#include "IFileManager.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace content
{

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
// TODO: Change the name of this class to the ContentManager
class FileManager
    : public IFileManager
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
    FileManager();
    virtual ~FileManager() = default;

    /**
     * @brief Open file
     * @param fileName path for file
     * @return True if successfull, Fale otherwise
     */
    bool openFile(const QString& fileName) override;

    /**
     * @brief Save buffer's content as a new file
     * @param bufferName name of the buffer
     * @param fileName path for file
     * @return True if successful, False otherwise
     */
    bool saveBufferIntoFile(const QString& bufferName,
    	const QString& fileName) override;

    /**
     * @brief Open buffer for new file
     * @param fileName fileName
     */
    void createBuffer(const QString& fileName) override;

    /**
     * @brief Text changed notification
     * @param fileName fileName
     * @param content content of the buffer
     * @return True if buffer content changed, False otherwise
     */
    bool textChanged(const QString &fileName, const QString &content) override;

    /**
     * @brief Read data from file
     * @param fileName Filename of open file
     * @return Vector contains file's data
     */
    std::vector<QString> read(const QString& fileName) override;

    /**
     * @brief Save data to file
     * @param fileName Filename of open file
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

    /**
     * @brief Return the number of the open buffers
     * @return Number of the open buffers
     */
    size_t numberOfOpenBuffers() const override;

    /**
     * @brief Return the number of the unsaved buffers
     * @return Number of the unsaved buffers
     */
    size_t numberOfUnsavedBuffers() const override;

    /**
     * @brief Return names of the unsaved buffers
     * @return Vector with the names of the unsaved buffers
     */
    std::vector<QString> unsavedBufferNames() const override;

    bool isFileSaved(const QString& fileName) override;

    bool isFileEmpty(const QString& fileName) override;

//---------------------------------------------------------
//                  Protected
//---------------------------------------------------------
protected:

//---------------------------------------------------------
//                  Private
//---------------------------------------------------------
private:
    std::vector<std::shared_ptr<IFile>>::iterator
		getFileIterator(const QString& fileName);
    std::vector<std::shared_ptr<IBuffer>>::iterator
		getBufferIterator(const QString& fileName);
    void loadFileContentToNewBuffer(std::shared_ptr<IFile> file);
    std::shared_ptr<IFile> createFile(const QString& fileName);
    void closeBuffer(const QString& fileName);
    void saveFile(std::vector<std::shared_ptr<IFile>>::iterator fileIt,
        std::vector<std::shared_ptr<IBuffer>>::iterator buffIt);

    log::Logger log_;
    std::unique_ptr<common::CommonUtils> commonUtils_;
    std::unique_ptr<ContentUtils> utils_;
    std::vector<std::shared_ptr<IFile>> openFiles_;
    std::vector<std::shared_ptr<IBuffer>> openBuffers_;
};

} // ::content

#endif /* SRC_CONTENT_FILEMANAGER_HPP_ */
