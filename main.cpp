#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include"controller.h"
#include<QQmlContext>
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    Controller controller(&app);
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("controller",&controller);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Ss", "Main");
    return app.exec();
}
