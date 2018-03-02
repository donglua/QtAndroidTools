#include <QFileInfo>
#include "mainpresenter.h"
#include <QDir>

MainModel *gModel;

MainPresenter::MainPresenter(MainView *parent, MainModel *model) : QObject(parent) {
    gModel = model;

    QObject::connect(this, &MainPresenter::ApkExtracted,
                     parent, &MainView::onApkExtracted);
}

QString MainPresenter::unzip(QFile *file) {
    qDebug() << "unzipping " << file->fileName();

    int errorCode = 1;
    QFileInfo fileInfo(*file);

    qDebug() << "fileInfo file name = " << fileInfo.fileName();

    auto extractedApkDir = fileInfo.absoluteDir().path() + "/QtAndroidTools/" + fileInfo.fileName();

    auto future = gModel->extractDir(file, extractedApkDir);

    auto result = future.result();
    emit MainPresenter::ApkExtracted(result);

    return extractedApkDir;
}




