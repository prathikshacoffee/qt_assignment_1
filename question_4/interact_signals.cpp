#include "interact_signals.h"
#include <QDateTime>
#include <QDebug>

interact_signals::interact_signals(QObject *parent) : QObject(parent), m_time_ret("0")
{

}


void interact_signals::emit_signal(QString button_time){
    m_time_ret = QString::number(QDateTime::currentMSecsSinceEpoch()-button_time.toLongLong());
    emit signalTime();
}

QString interact_signals::get_time_var(){
    return m_time_ret;
}
