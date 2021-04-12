#ifndef INTERACT_METHODS_H
#define INTERACT_METHODS_H

#include <QObject>

class interact_methods : public QObject
{
    Q_OBJECT
public:
    explicit interact_methods(QObject *parent = nullptr);
    Q_INVOKABLE void slot_q_invokable_time(QString button_time_q, int emit_flag);
    Q_INVOKABLE QString get_time_var();

signals:
    void timeQiVarChanged();
    void timeSlotVarChanged();

public slots:
    void slot_time(QString button_time, int emit_flag);

private:
    QString m_time_ret;
};

#endif // INTERACT_METHODS_H
