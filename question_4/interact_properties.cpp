#include "interact_properties.h"
#include <QDateTime>
#include <QDebug>

interact_properties::interact_properties(QObject *parent) : QObject(parent)
  , time_var("0"), button_time("0"), emit_flag(0)
{

}

QString interact_properties::read_property()
{


    if(button_time.toLongLong()==0)
        return QString::number(0);
    return QString::number(QDateTime::currentMSecsSinceEpoch()-button_time.toLongLong());
}

void interact_properties::set_property_time(QString time_from_button){
    button_time = time_from_button;
    if(emit_flag){
        emit notify_proptery_time();
        emit_flag=0;
    }
}

void interact_properties::set_emit_flag(int flag){
    emit_flag=flag;
}
