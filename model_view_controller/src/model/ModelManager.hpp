/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   Model manager class.
 */

#ifndef SRC_MODEL_MODELMANAGER_HPP_
#define SRC_MODEL_MODELMANAGER_HPP_

#include "log/Logger.hpp"

namespace model
{

class ModelManager
{
public:
    ModelManager();

private:
    log::Logger log_;
};

} // ::model

#endif /* SRC_MODEL_MODELMANAGER_HPP_ */
