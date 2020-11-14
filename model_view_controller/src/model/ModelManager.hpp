/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   Model manager class.
 */

#ifndef SRC_MODEL_MODELMANAGER_HPP_
#define SRC_MODEL_MODELMANAGER_HPP_

#include <memory>
#include "log/Logger.hpp"
#include "BufferManager.hpp"

namespace model
{

class ModelManager
{
public:
    ModelManager();

    void create();

private:
    log::Logger log_;
    std::unique_ptr< BufferManager > bufferManager_;
};

} // ::model

#endif /* SRC_MODEL_MODELMANAGER_HPP_ */
