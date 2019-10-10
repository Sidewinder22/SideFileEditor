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
#include <QString>
#include "IFile.hpp"
#include "IFileManager.hpp"
#include "utils/Logger.hpp"

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
     * @brief Get file name
     * @return String representing file name
     */
    QString fileName() const override;

    /**
     * @brief Read data from file
     * @return Vector contains file's data
     */
    std::vector<QString> read() override;

    /**
     * @brief Write data to file
     * @param text Text to write to file
     * @return True if successful, False otherwise
     */
    bool write(const QString& text) override;

    /**
     * @brief Check if file exists
     * @return True if file exists, False otherwise
     */
    bool exists() override;

    /**
     * @brief Close open file
     */
    void close() override;

    /**
     * @brief Remove file
     */
    void remove() override;

//---------------------------------------------------------
//                  Protected
//---------------------------------------------------------
protected:

//---------------------------------------------------------
//                  Private
//---------------------------------------------------------
private:
    log::Logger log_;                           //!< Logger object
    std::shared_ptr<IFile> file_;               //!< Interface to file object
};

#endif /* SRC_FILE_FILEMANAGER_HPP_ */
