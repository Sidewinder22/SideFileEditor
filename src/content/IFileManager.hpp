/**
 * @author  {\_Sidewinder22_/}
 * @date    30 lip 2020
 * @file    IFileManager.hpp
 *
 * @brief   Interface for file manager
 */
#ifndef SRC_CONTENT_IFILEMANAGER_HPP_
#define SRC_CONTENT_IFILEMANAGER_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <vector>
#include <QString>

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace content
{

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class IFileManager
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
    virtual ~IFileManager() = default;

    virtual bool open(const QString& fileName) = 0;

    virtual std::vector<QString> read(const QString& fileName) = 0;
};

} // ::content

#endif /* SRC_CONTENT_IFILEMANAGER_HPP_ */
