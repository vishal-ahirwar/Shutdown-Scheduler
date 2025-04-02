#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
enum class ScheduleType{
    SHUTDOWN,
    REBOOT
};

class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint64 duration READ duration WRITE setDuration NOTIFY durationChanged FINAL)
    Q_PROPERTY(bool can_clear READ canClear WRITE setCanClear NOTIFY canClearChanged FINAL)
    Q_PROPERTY(QString msg READ msg WRITE setMsg NOTIFY msgChanged FINAL)
public:
    explicit Controller(QObject *parent = nullptr);
    Q_INVOKABLE void shutdown();
    Q_INVOKABLE void close();
    Q_INVOKABLE void about();
    Q_INVOKABLE void clear();
    Q_INVOKABLE void reboot();
    qint64 duration() const;
    void setDuration(qint64 newDuration);
    bool canClear() const;
    void setCanClear(bool newCan_clear);
    QString msg() const;
    void setMsg(const QString &newMsg);

private:
    QDateTime getBootDateTime();
    void saveTimeStampDateTime(ScheduleType type);
    QDateTime getTimeStampDateTime(ScheduleType&type)const;
signals:
    void durationChanged(qint64 duration);
    void canClearChanged();
    void msgChanged();

private:
    qint64 m_duration;
    bool m_can_clear;
    QString m_msg;
};

#endif // CONTROLLER_H
