#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "interact_properties.h"
#include "interact_methods.h"
#include "interact_signals.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qmlRegisterType<interact_properties>("interact_time", 1, 0, "InteractProperties");
    qmlRegisterType<interact_methods>("interact_time", 1, 0, "InteractMethods");
    qmlRegisterType<interact_signals>("interact_time", 1, 0, "InteractSignals");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
