/**
 * @author  {\_Sidewinder22_/}
 * @date    12.11.2020
 * 
 * @brief   Side file editor class.
 */

#ifndef SRC_SIDEFILEEDITOR_HPP_
#define SRC_SIDEFILEEDITOR_HPP_

#include <memory>
#include "view/Window.hpp"

class SideFileEditor
{
public:
    SideFileEditor();
    
private:
    std::unique_ptr< view::Window > window_;
};

#endif /* SRC_SIDEFILEEDITOR_HPP_ */