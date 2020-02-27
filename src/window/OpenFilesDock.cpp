/**
 * @author  {\_Sidewinder22_/}
 * @date    01.10.2019
 *
 * @brief   Dock class for open files
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include <QListWidgetItem>
#include "OpenFilesDock.hpp"

OpenFilesDock::OpenFilesDock(IOpenFilesDockObserver* observer, QWidget *parent)
	: QDockWidget(tr("Open files"), parent)
    , log_("OpenFilesDock")
    , fileList_(new QListWidget())
    , observer_(observer)
{
    connect(fileList_, &QListWidget::currentRowChanged, this, &OpenFilesDock::rowChanged);
}

void OpenFilesDock::createDock()
{
    fileList_->setFlow(QListView::LeftToRight);
    fileList_->setLayoutMode(QListView::SinglePass);
    fileList_->setWrapping(true);

    setMaximumHeight(60);
    setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);

    setWidget(fileList_);
}

void OpenFilesDock::addFileName(QString fileName)
{
    auto item = new QListWidgetItem(fileName);
    fileList_->addItem(item);
    fileList_->setCurrentItem(item);
}

void OpenFilesDock::removeFileName(int row)
{
    // Remove widget from the given row
    fileList_->takeItem(row);
}

QString OpenFilesDock::getCurrentFileName()
{
    QString fileName;

    if (fileList_->currentRow() > -1)
    {
        fileName = fileList_->currentItem()->text();
    }

    return fileName;
}

int OpenFilesDock::getCurrentRow()
{
    return fileList_->currentRow();
}

void OpenFilesDock::rowChanged(int currentRow)
{
    observer_->anotherFileSelected(getCurrentFileName());
}
