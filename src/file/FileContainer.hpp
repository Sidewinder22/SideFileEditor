/**
 * @author Damian Stępień
 * @date 03.10.2016
 *
 * @brief Container for File objects
 */

#ifndef SRC_FILECONTAINER_HPP_
#define SRC_FILECONTAINER_HPP_

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <vector>
#include <memory>
#include "File.hpp"
#include "utils/Logger.hpp"

//---------------------------------------------------------
//                  Class declaration
//---------------------------------------------------------
class FileContainer
{
//---------------------------------------------------------
//                  Public
//---------------------------------------------------------
public:
    FileContainer();
    virtual ~FileContainer() = default;

    /**
     * @brief Add file to the container
     * @param file Shared pointer to file
     * @return True if success, False otherwise
     */
    bool addFile(std::shared_ptr<File> file);

//---------------------------------------------------------
//                  Protected
//---------------------------------------------------------
protected:

//---------------------------------------------------------
//                  Private
//---------------------------------------------------------
private:
    log::Logger log_;                               //!< Logger object
    std::vector<std::shared_ptr<File>> container_;  //!< Temporary container of File objects
};

#endif /* SRC_FILECONTAINER_HPP_ */
