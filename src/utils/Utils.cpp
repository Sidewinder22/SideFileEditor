/**
 * @author  Sidewinder22
 * @date    02.10.2019
 *
 * @brief   Set of useful utils
 */

#include <string>
#include <filesystem>
#include "Utils.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace utils
{

QString Utils::extractFileName(QString filePath)
{
    return std::filesystem::path(filePath.toStdString()).filename().c_str();
}

} // ::utils

