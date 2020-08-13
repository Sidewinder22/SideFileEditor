/**
 * @author  {\_Sidewinder22_/}
 * @date    03.10.2016
 *
 * @brief   Class wrapping a file.
 */
#ifndef SRC_CONTENT_FILE_HPP_
#define SRC_CONTENT_FILE_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QFile>
#include <QString>
#include "log/Logger.hpp"
#include "IFile.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace content
{

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class File
    : public IFile
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
    File(QString fileName);
    virtual ~File();

    /**
     * @brief Get file name
     * @return String representing file name
     */
    QString fileName() const override;

    /**
     * @brief Rename the file
     * @param newFileName New file name
     * @return True if successful, False otherwise
     */
    bool rename(const QString& newFileName) override;

    /**
     * @brief Read data from file
     * @return Vector contains file's data
     */
    std::vector<QString> read() override;

    /**
     * @brief Write data to file
     * @param content Content to write to file
     */
    void write(const std::vector<QString>& content) override;

    /**
     * @brief Remove file from filesystem
     * @return True if successful, False otherwise
     */
    bool remove() override;

    /**
     * @brief Check if file is empty
     * @return True if file is empty, False otherwise
     */
    bool isEmpty() override;

//---------------------------------------------------------
//                  Protected
//---------------------------------------------------------
protected:

//---------------------------------------------------------
//                  Private
//---------------------------------------------------------
private:
    log::Logger log_;                       //!< Logger object
    QFile file_;                            //!< QFile object
    bool isEmpty_;                          //!< Is file empty (new file created)
};

} // ::content

#endif /* SRC_CONTENT_FILE_HPP_ */
