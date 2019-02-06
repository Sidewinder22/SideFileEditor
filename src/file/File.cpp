/**
 * @author Damian Stępień
 * @date 03.10.2016
 *
 * @brief Class wrapping a file.
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include "File.hpp"

File::File(std::string fileName)
    : fileName_(fileName)
{ }

std::string File::getFileName()
{
    return fileName_;
}
