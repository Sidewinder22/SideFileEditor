/**
 * @author Sidewinder22
 * @date   01.10.2019
 *
 * @brief Dock class for open files
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include "OpenFilesDock.hpp"

OpenFilesDock::OpenFilesDock(QWidget *parent)
	: QDockWidget(tr("Open files"), parent)
    , log_("OpenFilesDock")
    , fileList_(new QListWidget())
{
    // Nothing
}

void OpenFilesDock::createDock()
{
    log_ << MY_FUNC << log::END;

    fileList_->setFlow(QListView::LeftToRight);
    fileList_->setLayoutMode(QListView::SinglePass);
    fileList_->setWrapping(true);

    setMaximumHeight(60);
    setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);

    setWidget(fileList_);
}

void OpenFilesDock::addFileName(QString fileName)
{
    log_ << MY_FUNC << log::END;

    fileList_->addItem(fileName);
}

void OpenFilesDock::removeFileName(int row)
{
    log_ << MY_FUNC << log::END;

    fileList_->takeItem(row);     // Remove widget from the given row
}

