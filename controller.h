#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint64 duration READ duration WRITE setDuration NOTIFY durationChanged FINAL)
    Q_PROPERTY(bool can_clear READ canClear WRITE setCanClear NOTIFY canClearChanged FINAL)
public:
    explicit Controller(QObject *parent = nullptr);
    Q_INVOKABLE void setTimer();
    Q_INVOKABLE void close();
    Q_INVOKABLE void about();
    Q_INVOKABLE void clear();
    qint64 duration() const;
    void setDuration(qint64 newDuration);
    bool canClear() const;
    void setCanClear(bool newCan_clear);
private:
    QDateTime isTimerAlreadyThere();
    void saveTimeStampDateTime();
    QDateTime getTimeStampDateTime()const;
signals:
    void durationChanged(qint64 duration);
    void errorOccured(QString errorString);
    void canClearChanged();

private:
    qint64 m_duration;
    bool m_can_clear;
};

#endif // CONTROLLER_H
