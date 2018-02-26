#include "mainview.h"

#include <QDebug>

MainView::MainView(QQmlApplicationEngine *engine) : QObject(engine)
{
    auto rootObj = engine->rootObjects()[0];
    engine->connect(rootObj,
                   SIGNAL(fileSelected(QString)),
                   this,
                   SLOT(onApkFileSelected(QString)));
}

void MainView::onApkFileSelected(const QString &msg) {
    qDebug() << "file path = " << msg;


}