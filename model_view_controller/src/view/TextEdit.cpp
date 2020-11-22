/**
 * @author  {\_Sidewinder22_/}
 * @date    13.11.2020
 * 
 * @brief   Text edit class
 */

#include "TextEdit.hpp"

namespace view
{

TextEdit::TextEdit()
{ }
    
QString TextEdit::text()
{
    return toPlainText();
}

} // ::view
