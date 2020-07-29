/**
 * @author  {\_Sidewinder22_/}
 * @date    30 lip 2020
 * @file    Utils.hpp
 *
 * @brief   Content utils
 */
#ifndef SRC_CONTENT_CONTENTUTILS_HPP_
#define SRC_CONTENT_CONTENTUTILS_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <memory>
#include <QString>
#include "common/CommonUtils.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace content
{

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class ContentUtils final
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
	ContentUtils();

    template<typename T>
    auto getVectorIterator(
        const QString& fileName,
        std::vector<std::shared_ptr<T>>::iterator begin,
        std::vector<std::shared_ptr<T>>::iterator end)
    {
        return std::find_if(
            begin,
            end,
            [&fileName, this](auto element) {
                return utils_->extractFileName(element->fileName()) == fileName;
            });
    }

//---------------------------------------------------------
//                  Protected
//---------------------------------------------------------
protected:

//---------------------------------------------------------
//                  Private
//---------------------------------------------------------
private:
    std::unique_ptr<::common::CommonUtils> utils_;
};

} // ::content

#endif /* SRC_CONTENT_CONTENTUTILS_HPP_ */
