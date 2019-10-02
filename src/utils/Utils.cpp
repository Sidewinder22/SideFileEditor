/**
 * @author  Sidewinder22
 * @date    02.10.2019
 *
 * @brief   Set of useful utils
 */

#include <string>
#include "Utils.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace utils
{

QString Utils::extractFileNameFromPath(QString path)
{
    std::string filePathString(path.toStdString());

    auto const position = filePathString.find_last_of('/');
    const auto fileName = filePathString.substr(position + 1);

    return fileName.c_str();
}

} // ::utils

