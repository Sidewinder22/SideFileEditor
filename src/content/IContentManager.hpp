/**
 * @author  {\_Sidewinder22_/}
 * @date    30 lip 2020
 * @file    IContentManager.hpp
 *
 * @brief   Interface for content manager class
 */
#ifndef SRC_CONTENT_ICONTENTMANAGER_HPP_
#define SRC_CONTENT_ICONTENTMANAGER_HPP_

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
class IContentManager
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
    virtual ~IContentManager() = default;

    virtual bool open(const QString& fileName) = 0;

    virtual std::vector<QString> read(const QString& fileName) = 0;

};

} // ::content

#endif /* SRC_CONTENT_ICONTENTMANAGER_HPP_ */
