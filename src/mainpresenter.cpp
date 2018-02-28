#include "mainpresenter.h"
#include <QDebug>
#include "lib/quazip/JlCompress.h"

MainPresenter::MainPresenter(QObject *parent) : QObject(parent)
{

}

void MainPresenter::unzip(QFile *file)
{
    qDebug() << "unzipping " << file->fileName();

    int errorCode = 1;

    JlCompress::extractDir(file->fileName(), "unzip");
}


