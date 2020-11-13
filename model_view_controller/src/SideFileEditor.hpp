/**
 * @author  {\_Sidewinder22_/}
 * @date    12.11.2020
 * 
 * @brief   Side file editor class.
 */

#ifndef SRC_SIDEFILEEDITOR_HPP_
#define SRC_SIDEFILEEDITOR_HPP_

#include <memory>
#include "ctrl/Controller.hpp"

class SideFileEditor
{
public:
    SideFileEditor();
    
private:
    std::unique_ptr< ctrl::Controller > controller_;
};

#endif /* SRC_SIDEFILEEDITOR_HPP_ */