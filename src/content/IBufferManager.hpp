/**
 * @author  {\_Sidewinder22_/}
 * @date    30 lip 2020
 * @file    IBufferManager.hpp
 *
 * @brief   Interface for buffer manager
 */
#ifndef SRC_CONTENT_IBUFFERMANAGER_HPP_
#define SRC_CONTENT_IBUFFERMANAGER_HPP_

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
class IBufferManager
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
    virtual ~IBufferManager() = default;

    virtual void create(const QString& fileName) = 0;

    virtual bool write(const QString& fileName,
    	const std::vector<QString> &content) = 0;

    virtual std::vector<QString> read(const QString& fileName) = 0;

    virtual void setSaved(const QString& fileName, bool saved) = 0;
    virtual bool isSaved(const QString& fileName) = 0;
};

} // ::content

#endif /* SRC_CONTENT_IBUFFERMANAGER_HPP_ */
