/**
 * @author  {\_Sidewinder22_/}
 * @date    31.03.2020
 *
 * @brief   Class to buffering text which represent file content.
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include "Buffer.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace file
{

Buffer::Buffer(QString fileName)
    : log_("Buffer")
    , fileName_(fileName)
{ 
    // Empty
}

} // ::file
