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
     * @brief Read data from file
     * @param fileName Filename of open file
     * @return Vector contains file's data
     */
    virtual std::vector<QString> read(const QString& fileName) = 0;

    /**
     * @brief Write data to file
     * @param fileName Filename of open file
     * @param text Text to write to file
     * @return True if successful, False otherwise
     */
    virtual bool write(const QString& fileName, const QString& text) = 0;

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
};

#endif /* SRC_FILE_IFILEMANAGER_HPP_ */
