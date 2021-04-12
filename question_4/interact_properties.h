#ifndef INTERACT_PROPERTIES_H
#define INTERACT_PROPERTIES_H

#include <QObject>

class interact_properties : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString read_property READ read_property WRITE set_property_time NOTIFY notify_proptery_time)
public:
    explicit interact_properties(QObject *parent = nullptr);
    QString read_property();

signals:
    void notify_proptery_time();

public slots:
    void set_property_time(QString);
    void set_emit_flag(int flag);
private:
    QString time_var, button_time;
    int emit_flag;


};

#endif // INTERACT_PROPERTIES_H
