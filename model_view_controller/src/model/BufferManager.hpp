/**
 * @author  {\_Sidewinder22_/}
 * @date    14.11.2020
 * 
 * @brief   Model manager class.
 */

#ifndef SRC_MODEL_BUFFERMANAGER_HPP_
#define SRC_MODEL_BUFFERMANAGER_HPP_

#include "log/Logger.hpp"

namespace model
{

class BufferManager
{
public:
    BufferManager();

    void create();

private:
    log::Logger log_;
    static int nextBufferNumber_;
};

} // ::model

#endif /* SRC_MODEL_BUFFERMANAGER_HPP_ */
