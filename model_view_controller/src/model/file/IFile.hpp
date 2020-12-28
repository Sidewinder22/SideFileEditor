/**
 * @author  {\_Sidewinder22_/}
 * @date    19.12.2020
 *
 * @brief   File interface
 */

#ifndef SRC_MODEL_FILE_IFILE_HPP_
#define SRC_MODEL_FILE_IFILE_HPP_

#include <QString>

namespace model
{
namespace file
{

class IFile
{
public:
	virtual ~IFile() = default;

    virtual QString name() = 0;
    virtual QString read() = 0;
    virtual void write( const QString& text ) = 0;
};

}  // ::file
}  // ::model

#endif /* SRC_MODEL_FILE_IFILE_HPP_ */
