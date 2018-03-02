#include <QFileInfo>
#include "mainpresenter.h"
#include <QDir>

MainModel *gModel;

MainPresenter::MainPresenter(MainView *parent, MainModel *model) : QObject(parent) {
    gModel = model;
}

QString MainPresenter::unzip(QFile *file) {
    qDebug() << "unzipping " << file->fileName();

    int errorCode = 1;
    QFileInfo fileInfo(*file);
    qDebug() << "fileInfo file name = " << fileInfo.fileName();
    auto extractedApkDir = fileInfo.absoluteDir().path() + "/QtAndroidTools/" + fileInfo.fileName();

    auto future = gModel->extractDir(file, extractedApkDir);

    QStringList fileList = future.result();

    for (const QString &s: fileList) {
        qDebug() << "file: " << s;
    }

    return extractedApkDir;
}



