/**
 * @author  {\_Sidewinder22_/}
 * @date    02.10.2019
 *
 * @brief   Set of useful utils
 */

#include "Utils.hpp"

#include <string>
#include <filesystem>   // C++17

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace common
{

QString Utils::extractFileName(QString filePath)
{
    return std::filesystem::path(filePath.toStdString()).filename().c_str();
}

} // ::common

