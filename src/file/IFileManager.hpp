/**
 * @author  {\_Sidewinder22_/}
 * @date    10.10.2019
 *
 * @brief   File operations interface
 */

#ifndef SRC_FILE_IFILEMANAGER_HPP_
#define SRC_FILE_IFILEMANAGER_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <vector>
#include <QString>

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
     * @brief Get file name
     * @return String representing file name
     */
    virtual QString fileName() const = 0;

    /**
     * @brief Read data from file
     * @return Vector contains file's data
     */
    virtual std::vector<QString> read() = 0;

    /**
     * @brief Write data to file
     * @param text Text to write to file
     * @return True if successful, False otherwise
     */
    virtual bool write(const QString& text) = 0;

    /**
     * @brief Check if file exists
     * @return True if file exists, False otherwise
     */
    virtual bool exists() = 0;

    /**
     * @brief Close open file
     */
    virtual void close() = 0;

    /**
     * @brief Remove file
     */
    virtual void remove() = 0;
};

#endif /* SRC_FILE_IFILEMANAGER_HPP_ */
