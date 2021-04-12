#ifndef INTERACT_SIGNALS_H
#define INTERACT_SIGNALS_H

#include <QObject>

class interact_signals : public QObject
{
    Q_OBJECT
public:
    explicit interact_signals(QObject *parent = nullptr);
    Q_INVOKABLE QString get_time_var();

signals:
    void signalTime();
public slots:
    void emit_signal(QString button_time);
private:
    QString m_time_ret;
};

#endif // INTERACT_SIGNALS_H
