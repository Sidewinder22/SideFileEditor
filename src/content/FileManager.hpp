/**
 * @author  {\_Sidewinder22_/}
 * @date    30 lip 2020
 * @file    FileManager.hpp
 *
 * @brief   File manager
 */
#ifndef SRC_CONTENT_FILEMANAGER_HPP_
#define SRC_CONTENT_FILEMANAGER_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <memory>
#include <vector>
#include "log/Logger.hpp"
#include "ContentUtils.hpp"
#include "IFile.hpp"
#include "IFileManager.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace content
{

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class FileManager final
	: public IFileManager
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
	FileManager();
	virtual ~FileManager() = default;

	bool open(const QString& fileName) override;

	std::vector<QString> read(const QString& fileName) override;

	void save(const QString& fileName,
		const std::vector<QString>& content) override;

	void close(const QString& fileName) override;

	void remove(const QString& fileName) override;

    bool isOpen(const QString& fileName) override;

//---------------------------------------------------------
//                  Protected
//---------------------------------------------------------
protected:

//---------------------------------------------------------
//                  Private
//---------------------------------------------------------
private:
	std::shared_ptr<IFile> create(const QString& fileName);

    std::vector<std::shared_ptr<IFile>>::iterator
		getIterator(const QString& fileName);

	log::Logger log_;
	std::vector<std::shared_ptr<IFile>> files_;
	std::unique_ptr<ContentUtils> contentUtils_;
};

} // ::content



#endif /* SRC_CONTENT_FILEMANAGER_HPP_ */
