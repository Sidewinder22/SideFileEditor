/**
 * @author  {\_Sidewinder22_/}
 * @date    30 lip 2020
 * @file    BufferManager.hpp
 *
 * @brief   Buffer manager
 */
#ifndef SRC_CONTENT_BUFFERMANAGER_HPP_
#define SRC_CONTENT_BUFFERMANAGER_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <memory>
#include <vector>
#include "log/Logger.hpp"
#include "IBuffer.hpp"
#include "IBufferManager.hpp"
#include "ContentUtils.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace content
{

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class BufferManager final
	: public IBufferManager
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
	BufferManager();
	virtual ~BufferManager() = default;

    void create(const QString& fileName) override;

    bool write(const QString& fileName, const std::vector<QString> &content);

    std::vector<QString> read(const QString& fileName) override;

    void setSaved(const QString& fileName, bool saved) override;
    bool isSaved(const QString& fileName) override;

//---------------------------------------------------------
//                  Protected
//---------------------------------------------------------
protected:

//---------------------------------------------------------
//                  Private
//---------------------------------------------------------
private:
    std::vector<std::shared_ptr<IBuffer>>::iterator getBufferIterator(
    	const QString& fileName);

	log::Logger log_;
	std::vector<std::shared_ptr<IBuffer>> buffers_;
	std::unique_ptr<ContentUtils> contentUtils_;
};

} // ::content

#endif /* SRC_CONTENT_BUFFERMANAGER_HPP_ */
