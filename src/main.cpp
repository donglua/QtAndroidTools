#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <src/mainview.h>

int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQuickStyle::setStyle("Material");

    QQmlApplicationEngine engine;

    engine.load(QUrl("qrc:/main.qml"));

    auto mainView = new MainView(&engine);

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
