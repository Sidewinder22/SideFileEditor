/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   Model manager class.
 */

#include "ModelManager.hpp"

namespace model
{

ModelManager::ModelManager()
    : log_( "ModelManager" )
{
    log_ << MY_FUNC << "Created." << log::END;
}

} // ::model
