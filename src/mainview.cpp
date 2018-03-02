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

    MainModel *mainModel = new MainModel();
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

    qDebug() << "file size = "<< file.size();

    auto path = presenter->unzip(&file);
}