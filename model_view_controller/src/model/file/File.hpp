/**
 * @author  {\_Sidewinder22_/}
 * @date    19.12.2020
 *
 * @brief   File class
 */

#ifndef SRC_MODEL_FILE_FILE_HPP_
#define SRC_MODEL_FILE_FILE_HPP_

#include "IFile.hpp"
#include <QFile>

namespace model
{
namespace file
{

class File
	: public IFile
{
public:
	explicit File( const QString& fileName );
	~File() override;

    /**********************************************
     *              	IFile
    **********************************************/
    QString name() override;
    QString read() override;
    void write( const QString& text ) override;

private:
    QFile file_;
};

}  // ::file
}  // ::model

#endif /* SRC_MODEL_FILE_FILE_HPP_ */
