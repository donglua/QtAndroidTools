#ifndef MAINPRESENTER_H
#define MAINPRESENTER_H

#include <QObject>
#include <QFile>

class MainPresenter : public QObject
{
    Q_OBJECT
public:
    explicit MainPresenter(QObject *parent = nullptr);
    void unzip(QFile *file);

signals:

public slots:
};

#endif // MAINPRESENTER_H
