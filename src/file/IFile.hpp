/**
 * @author  {\_Sidewinder22_/}
 * @date    02.10.2019
 *
 * @brief   Interface for class wrapping a file.
 */

#ifndef SRC_FILE_IFILE_HPP_
#define SRC_FILE_IFILE_HPP_

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
class IFile
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
    virtual ~IFile() = default;

    /**
     * @brief Get file name
     * @return String representing file name
     */
    virtual QString fileName() const = 0;

    /**
     * @brief Rename the file
     * @param newFileName New file name
     * @return True if successful, False otherwise
     */
    virtual bool rename(const QString& newFileName) = 0;

    /**
     * @brief Read data from file
     * @return Vector contains file's data
     */
    virtual std::vector<QString> read() = 0;

    /**
     * @brief Write content to file
     * @param content Content to write to file
     */
    virtual void write(const std::vector<QString>& content) = 0;

    /**
     * @brief Remove file from filesystem
     * @return True if successful, False otherwise
     */
    virtual bool remove() = 0;

    /**
     * @brief Check if file is empty
     * @return True if file is empty, False otherwise
     */
    virtual bool isEmpty() = 0;
};

} // ::file

#endif /* SRC_FILE_IFILE_HPP_ */
