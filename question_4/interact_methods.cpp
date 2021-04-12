#include "interact_methods.h"
#include <QDateTime>
#include <QDebug>

interact_methods::interact_methods(QObject *parent) : QObject(parent), m_time_ret("0")
{

}

void interact_methods::slot_q_invokable_time(QString button_time_q, int emit_flag){
    m_time_ret = QString::number(QDateTime::currentMSecsSinceEpoch()-button_time_q.toLongLong());
    if(emit_flag){
        emit timeQiVarChanged();
    }
}

void interact_methods::slot_time(QString button_time, int emit_flag){
    m_time_ret = QString::number(QDateTime::currentMSecsSinceEpoch()-button_time.toLongLong());
    if(emit_flag){
        emit timeSlotVarChanged();
    }
}

QString interact_methods::get_time_var(){
    return m_time_ret;
}
