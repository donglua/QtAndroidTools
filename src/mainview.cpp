#include "mainview.h"
#include "mainpresenter.h"

#include <QDebug>
#include <QFile>

MainPresenter* presenter;

MainView::MainView(QQmlApplicationEngine *engine) : QObject(engine)
{
    auto rootObj = engine->rootObjects()[0];
    engine->connect(rootObj,
                   SIGNAL(fileSelected(QString)),
                   this,
                   SLOT(onApkFileSelected(QString)));

    presenter = new MainPresenter();
}

void MainView::onApkFileSelected(const QString &msg) {
    QUrl url(msg, QUrl::TolerantMode);
    qDebug() << "file path = " << url.toLocalFile();

    QFile file(url.toLocalFile());

    if (!file.open(QFile::ReadOnly)) {
        qDebug() << file.errorString();
        return;
    }

    if (!file.exists()) {
        qDebug() << "文件不存在~";
        return;
    }

    qDebug() << "file size = "<< file.size();

    presenter->unzip(&file);
}