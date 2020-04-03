/**
 * @author  {\_Sidewinder22_/}
 * @date    11.02.2019
 *
 * @brief   FileManager Manager class
 */

#ifndef SRC_FILE_FILEMANAGER_HPP_
#define SRC_FILE_FILEMANAGER_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <memory>
#include <vector>
#include <QString>
#include "log/Logger.hpp"
#include "utils/Utils.hpp"
#include "IBuffer.hpp"
#include "IFile.hpp"
#include "IFileManager.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace file
{

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
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
     * @brief Open buffer for new file
     * @param fileName fileName
     */
    void createBuffer(const QString& fileName) override;

    /**
     * @brief Text changed notification
     * @param fileName fileName
     * @param content content of the buffer
     */
    void textChanged(const QString &fileName, const QString &content) override;

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

//---------------------------------------------------------
//                  Protected
//---------------------------------------------------------
protected:

//---------------------------------------------------------
//                  Private
//---------------------------------------------------------
private:
    std::vector<std::shared_ptr<IFile>>::iterator getCurrentFile(const QString& fileName);
    std::vector<std::shared_ptr<IBuffer>>::iterator getCurrentBuffer(const QString& fileName);
    void loadFileContentToNewBuffer(std::shared_ptr<IFile> file);

    log::Logger log_;                                       //!< Logger object
    std::unique_ptr<utils::Utils> utils_;                   //!< Pointer to utils object
    std::vector<std::shared_ptr<IFile>> openFiles_;         //!< Vector for open files
    std::vector<std::shared_ptr<IBuffer>> openBuffers_;     //!< Vector for open buffers
};

} // ::file

#endif /* SRC_FILE_FILEMANAGER_HPP_ */
