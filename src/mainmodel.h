//
// Created by 鲁大师 on 2018/3/1.
//

#ifndef QTANDROIDTOOLS_MAINMODEL_H
#define QTANDROIDTOOLS_MAINMODEL_H

#include <QObject>
#include <QFile>
#include <QFuture>

class MainModel : public QObject
{
    Q_OBJECT
public:
    explicit MainModel(QObject *parent = nullptr);
    QFuture<QStringList> extractDir(QFile *file, QString &extractedApkDir);

public slots:

protected:
    static QStringList extract(QString &fileName, QString &extractedApkDir);
};

#endif //QTANDROIDTOOLS_MAINMODEL_H
