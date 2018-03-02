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

signals:


public slots:
    void onApkFileSelected(const QString &msg);
    void onApkExtracted(QStringList &files);
};

#endif // MAINVIEW_H
