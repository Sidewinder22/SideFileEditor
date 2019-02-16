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
    virtual ~File() = default;

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

//---------------------------------------------------------
//                  Protected
//---------------------------------------------------------
protected:

//---------------------------------------------------------
//                  Private
//---------------------------------------------------------
private:
    log::Logger log_;                       //!< Logger object
    bool good_;                             //!< File open successfull
    QFile file_;                            //!< QFile object

};

#endif /* SRC_FILE_HPP_ */
