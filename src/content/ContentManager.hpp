/**
 * @author  {\_Sidewinder22_/}
 * @date    30 lip 2020
 * @file    ContentManager.hpp
 *
 * @brief   Manager for buffer and files
 */
#ifndef SRC_CONTENT_CONTENTMANAGER_HPP_
#define SRC_CONTENT_CONTENTMANAGER_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <memory>
#include "log/Logger.hpp"
#include "IBufferManager.hpp"
#include "IContentManager.hpp"
#include "IFileManager.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace content
{

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class ContentManager final
	: public IContentManager
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
	ContentManager();
	virtual ~ContentManager() = default;

	bool open(const QString& fileName) override;

	std::vector<QString> read(const QString& fileName) override;

	bool save(const QString &fileName) override;

	void close(const QString& fileName) override;

    void remove(const QString& fileName) override;

    void createBuffer(const QString& fileName) override;

    bool saveBufferIntoFile(const QString& bufferName,
		const QString& fileName) override;

	size_t numberOfBuffers() const override;
	size_t numberOfUnsavedBuffers() const override;
    std::vector<QString> namesOfUnsavedBuffers() const override;

    bool isBufferSaved(const QString& fileName) const override;
    bool isBufferEmpty(const QString& fileName) const override;

	bool contentChanged(const QString &fileName,
		const QString &content) override;

//---------------------------------------------------------
//                  Protected
//---------------------------------------------------------
protected:

//---------------------------------------------------------
//                  Private
//---------------------------------------------------------
private:
	void loadFileContentIntoBuffer(const QString& fileName);

	log::Logger log_;
	std::unique_ptr<IBufferManager> bufferManager_;
	std::unique_ptr<IFileManager> fileManager_;
};

} // ::content

#endif /* SRC_CONTENT_CONTENTMANAGER_HPP_ */
