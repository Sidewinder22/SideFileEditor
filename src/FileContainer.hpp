/**
 * @author Damian Stępień
 * @date 03.10.2016
 */

#ifndef SRC_FILECONTAINER_HPP_
#define SRC_FILECONTAINER_HPP_

#include <vector>
#include <memory>
#include "File.hpp"
#include "utils/Logger.hpp"

class FileContainer
{
public:
    FileContainer();
    bool addFile(std::shared_ptr<File> file);

private:
    log::Logger log_;
    std::vector<std::shared_ptr<File>> container_;  //!< Temporary container of File objects
};

#endif /* SRC_FILECONTAINER_HPP_ */
