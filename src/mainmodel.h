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

public slots:
    QFuture<QStringList> extractDir(const QFile *file, const QString &extractedApkDir);

protected:
    static QStringList extract(const QString &fileName, const QString &extractedApkDir);
};

#endif //QTANDROIDTOOLS_MAINMODEL_H
