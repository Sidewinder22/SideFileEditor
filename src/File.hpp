/**
 * @author Damian Stępień
 * @date 03.10.2016
 */

#ifndef SRC_FILE_HPP_
#define SRC_FILE_HPP_

#include <string>

class File
{
public:
    File(std::string fileName);
    std::string getFileName();

private:
    std::string fileName_;
};

#endif /* SRC_FILE_HPP_ */
