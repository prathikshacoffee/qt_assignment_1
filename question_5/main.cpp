#include <QGuiApplication>
#include <QtQuick>
#include <QVariant>


int main(int argc, char *argv[])
{
QGuiApplication app(argc, argv);
const QUrl url(QStringLiteral("qrc:/main.qml"));
QQuickView view(url);

QVariantList list;
list << 10 << QColor(Qt::green) << "bottles";

QVariantMap map;
map.insert("language", "QML");
map.insert("released", QDate(2010, 9, 21));
QFont sansFont("Helvetica [Cronyx]", 12);

//From QT TO QML

QMetaObject::invokeMethod(view.rootObject(), "readValues",
        Q_ARG(QVariant, QVariant::fromValue(list)),
        Q_ARG(QVariant, QVariant::fromValue(map)),
        Q_ARG(QVariant, QVariant::fromValue(QDate(2020,8,24))),
        Q_ARG(QVariant, QVariant::fromValue(QColor(Qt::green))),
        Q_ARG(QVariant, QVariant::fromValue(sansFont)));

// From QML TO QT

QDateTime dateTime = QDateTime::currentDateTime();
QVariant retValue;
QVariant retArray;

QMetaObject::invokeMethod(view.rootObject(), "readDate",
        Q_RETURN_ARG(QVariant, retValue));

QMetaObject::invokeMethod(view.rootObject(), "readArray",
        Q_RETURN_ARG(QVariant, retArray));

//It can be seen that Date() in JS is converted to QDateTime data type.
qDebug() << "Value returned from readDate():" << retValue;

//It can be seen that it is converted from JS to QJSValue data type
qDebug() << "Value returned from readArray():" << retArray;

view.show();
return app.exec();

}
