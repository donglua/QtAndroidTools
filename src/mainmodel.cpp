//
// Created by 鲁大师 on 2018/3/1.
//

#include "mainmodel.h"
#include "lib/quazip/JlCompress.h"
#include <QtConcurrent>

MainModel::MainModel(QObject *parent) : QObject(parent) {
}


QFuture<QStringList> MainModel::extractDir(QFile *file, QString &extractedApkDir) {
    QFuture<QStringList> future = QtConcurrent::run(MainModel::extract, file->fileName(), extractedApkDir);
    return future;
}

QStringList MainModel::extract(QString &fileName, QString &extractedApkDir) {
    return JlCompress::extractDir(fileName, extractedApkDir);
}


