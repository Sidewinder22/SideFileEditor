/**
 * @author  {\_Sidewinder22_/}
 * @date    23.11.2020
 * 
 * @brief   Model's utils.
 */

#ifndef SRC_MODEL_UTILS_HPP_
#define SRC_MODEL_UTILS_HPP_

#include <algorithm>
#include <memory>
#include <vector>
#include <QString>

namespace model
{
namespace utils
{

template<typename T>
auto getVectorIterator( const QString& name, auto begin, auto end )
{
    return std::find_if(
        begin,
        end,
        [&name](auto element) {
            return element->name() == name;
        });
}

} // ::utils
} // ::model

#endif /* SRC_MODEL_UTILS_HPP_ */
