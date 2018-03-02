#include "mainview.h"
#include "mainpresenter.h"

#include <QDir>

MainPresenter* presenter;

MainView::MainView(QQmlApplicationEngine *engine) : QObject(engine)
{
    auto rootObj = engine->rootObjects()[0];
    engine->connect(rootObj,
                   SIGNAL(fileSelected(QString)),
                   this,
                   SLOT(onApkFileSelected(QString)));

    auto *mainModel = new MainModel();
    presenter = new MainPresenter(this, mainModel);
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

    auto path = presenter->unzip(&file);
}

void MainView::onApkExtracted(QStringList &files) {
    for (const QString &s: files) {
        qDebug() << "file: " << s;
    }
}

