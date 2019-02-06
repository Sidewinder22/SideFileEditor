/**
 * @author Damian Stępień
 * @date 03.10.2016
 *
 * @brief Container for File objects
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <iostream>
#include "FileContainer.hpp"

FileContainer::FileContainer()
    : log_("FileContainer")
{ }

bool FileContainer::addFile(std::shared_ptr<File> file)
{
    container_.push_back(file);

    log_ << MY_FUNC << ": size = " << std::to_string(container_.size()) << log::END;
    return true;
}
