/**
 * @author Sidewinder22
 * @date 03.10.2016
 *
 * @brief Class wrapping a file.
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <memory>
#include <vector>
#include <QTextStream>
#include "File.hpp"

File::File(QString fileName)
    : log_("File")
    , file_(fileName)
{
    if (!file_.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        throw std::runtime_error("Cannot open file or file isn't text type!");
    }

    log_ << MY_FUNC << "File opened succesfully." << log::END;
}

File::~File()
{
    file_.close();
}

QString File::getFileName()
{
    return file_.fileName();
}

bool File::rename(const QString& newFileName)
{
    return file_.rename(newFileName);
}

std::vector<QString> File::read()
{
    std::vector<QString> fileContent;

    QTextStream in(&file_);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        fileContent.push_back(line);
    }

    return std::move(fileContent);
}

void File::write(const QString& text)
{
    QTextStream out(&file_);
    out << text << "\n";

    file_.flush();
}

bool File::remove()
{
    return file_.remove();
}
