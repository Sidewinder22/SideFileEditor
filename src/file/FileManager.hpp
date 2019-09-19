/**
 * @author Sidewinder22
 * @date 11.02.2019
 *
 * @brief FileManager Manager class
 */

#ifndef SRC_FILEMANAGER_FILEMANAGER_HPP_
#define SRC_FILEMANAGER_FILEMANAGER_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <memory>
#include <QString>
#include "File.hpp"
#include "utils/Logger.hpp"

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class FileManager
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
    bool openFile(const QString& fileName);

    /**
     * @brief Get file name
     * @return String representing file name
     */
    QString getFileName();

    /**
     * @brief Read data from file
     * @return Vector contains file's data
     */
    std::vector<QString> read();

    /**
     * @brief Write data to file
     * @param text Text to write to file
     * @return True if successful, False otherwise
     */
    bool write(const QString& text);

    /**
     * @brief Check if file exists
     * @return True if file exists, False otherwise
     */
    bool exists();

    /**
     * @brief Close open file
     */
    void close();

    /**
     * @brief Remove file
     */
    void remove();

//---------------------------------------------------------
//                  Protected
//---------------------------------------------------------
protected:

//---------------------------------------------------------
//                  Private
//---------------------------------------------------------
private:
    log::Logger log_;                       //!< Logger object
    std::shared_ptr<File> file_;             //!< File object
};

#endif /* SRC_FILEMANAGER_FILEMANAGER_HPP_ */
