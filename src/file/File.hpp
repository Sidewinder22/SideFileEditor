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
#include <string>

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class File
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
    File(std::string fileName);

    /**
     * @brief Get file name
     * @return String representing file name
     */
    std::string getFileName();

//---------------------------------------------------------
//                  Protected
//---------------------------------------------------------
protected:

//---------------------------------------------------------
//                  Private
//---------------------------------------------------------
private:
    std::string fileName_;          //!< File name
};

#endif /* SRC_FILE_HPP_ */
