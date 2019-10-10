/**
 * @author Sidewinder22
 * @date   02.10.2019
 *
 * @brief Interface for class wrapping a file.
 */

#ifndef SRC_IFILE_IFILE_HPP_
#define SRC_IFILE_IFILE_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <vector>
#include <QString>
#include "utils/Logger.hpp"

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
     * @brief Write data to file
     * @param text Text to write to file
     */
    virtual void write(const QString& text) = 0;

    /**
     * @brief Remove file from filesystem
     * @return True if successful, False otherwise
     */
    virtual bool remove() = 0;
};

#endif /* SRC_IFILE_IFILE_HPP_ */
