/**
 * @author Damian Stępień
 * @date 03.10.2016
 *
 * @brief Class wrapping a file.
 */

#ifndef SRC_FILE_HPP_
#define SRC_FILE_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QFile>
#include <QString>
#include "utils/Logger.hpp"

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class File
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
    QString getFileName();

    /**
     * @brief Read data from file
     * @return Vector contains file's data
     */
    std::vector<QString> read();

    /**
     * @brief Write data to file
     * @param data Vector contains data to write
     * @return True if successfull, False otherwise
     */
    bool write(std::vector<QString>& data);

    /**
     * @brief Write data to file
     * @param text Text to write to file
     */
    void write(const QString& text);

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
};

#endif /* SRC_FILE_HPP_ */
