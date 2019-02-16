/**
 * @author Damian Stępień
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
    , good_(false)
    , file_(fileName)
{
    if (file_.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        good_ = true;
    }
    else
    {
        log_ << MY_FUNC << "Cannot open file or file isn't text type!" << log::END;
    }
}

QString File::getFileName()
{
    QString fileName;

    if (good_)
    {
        fileName = file_.fileName();
    }

    return fileName;
}

std::vector<QString> File::read()
{
    std::vector<QString> fileContent;

    if (good_)
    {
        QTextStream in(&file_);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            fileContent.push_back(line);
        }
    }

    return std::move(fileContent);
}

