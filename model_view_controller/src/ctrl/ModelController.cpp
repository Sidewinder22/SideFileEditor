/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   Model controller class.
 */

#include "ModelController.hpp"

namespace ctrl
{

ModelController::ModelController()
    : modelManager_( std::make_unique< model::ModelManager >() )
{ }
    
void ModelController::create()
{
    modelManager_->create();
}

} // ::ctrl
