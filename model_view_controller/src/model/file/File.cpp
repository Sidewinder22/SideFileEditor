/**
 * @author  {\_Sidewinder22_/}
 * @date    19.12.2020
 *
 * @brief   File class
 */

#include "File.hpp"
#include <QTextStream>
#include <stdexcept>

namespace model
{
namespace file
{

File::File( const QString& fileName )
	: file_( fileName )
{
    if (!file_.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        throw std::runtime_error("Cannot open file or file isn't text type!");
    }
}

File::~File()
{
	file_.close();
}

QString File::name()
{
	return file_.fileName();
}

QString File::read()
{
	QString text;
	QTextStream in( &file_ );

    while (!in.atEnd())
    {
        text.append( in.readLine() );
    }

    // Set file ptr to the beginning of the file for the future readings
    file_.seek(0);

    return text;
}

void File::save( const QString& text )
{
	QTextStream out( &file_ );
	out << text;

	file_.flush();
}

}  // ::file
}  // ::model
