#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QObject>
#include <QDebug>
#include <QQmlApplicationEngine>

class MainView : public QObject
{
    Q_OBJECT
public:
    explicit MainView(QQmlApplicationEngine *engine = nullptr);

public slots:
    void onApkFileSelected(const QString &msg);
};

#endif // MAINVIEW_H
