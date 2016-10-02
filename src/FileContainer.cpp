/**
 * @author Damian Stępień
 * @date 03.10.2016
 */

#include <iostream>
#include "FileContainer.hpp"

FileContainer::FileContainer()
{
    std::cout << "Ctor of FileContainer" << std::endl;
}

bool FileContainer::addFile(std::shared_ptr<File> file)
{
    std::cout << "FileName = " << file->getFileName() << std::endl;

    std::cout << "Size = " << container_.size() << std::endl;

    container_.push_back(file);

    std::cout << "Size = " << container_.size() << std::endl;

    return false;
}
