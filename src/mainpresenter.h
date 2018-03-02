#ifndef MAINPRESENTER_H
#define MAINPRESENTER_H

#include "mainview.h"

#include <QObject>
#include <QFile>
#include "mainmodel.h"

class MainPresenter : public QObject
{
    Q_OBJECT
public:
    explicit MainPresenter(MainView *parent, MainModel *model);
    QString unzip(QFile *file);

signals:

public slots:

};

#endif // MAINPRESENTER_H
