#include "controller.h"
#include<QCoreApplication>
#include<QProcess>
#include<QTimer>
#include<QFile>
#include<QDir>
#if defined(Q_OS_WIN)
#include<windows.h>
#endif
Controller::Controller(QObject *parent)
    : QObject{parent}
{
    ScheduleType type;
    auto boot_time=getBootDateTime();
    auto saved_scheduled_time=getTimeStampDateTime(type);
    if(boot_time.isValid()&&saved_scheduled_time.isValid()&&saved_scheduled_time>boot_time){
        setCanClear(true);
        switch (type) {
        case ScheduleType::REBOOT:
            setMsg("Reboot Timer Scheduled for "+saved_scheduled_time.toString());
            break;
        case ScheduleType::SHUTDOWN:
            setMsg("Shutdown Timer Scheduled for "+saved_scheduled_time.toString());
            break;
    }
    }else{
        setCanClear(false);
        qDebug()<<"Noope";
        setMsg("Copyright© 2025 Vishal Ahirwar.All rights reserved.");
    }
    setDuration(45);
}

void Controller::shutdown()
{
    if (m_duration < 15) {
        setMsg("Warning: Timer is set for less than 15 minutes");
    }

    QTimer::singleShot(500, [this]() {
        auto* process = new QProcess(this); // Prevent premature destruction

#ifdef Q_OS_WIN
        process->start("shutdown", QStringList() << "/s" << "/t" << QString::number(m_duration * 60));
#elif defined(Q_OS_LINUX) || defined(Q_OS_UNIX)
        process->start("shutdown", QStringList() << "-h" << "+" << QString::number(m_duration));
#elif defined(Q_OS_MAC)
        process->start("sudo", QStringList() << "shutdown" << "-h" << "+" << QString::number(m_duration));
#endif

        if (!process->waitForFinished()) {
            qDebug() << process->exitCode() << "Failed to set shutdown timer";
        } else {
            qDebug() << process->exitCode() << "Shutdown timer set successfully";
            setCanClear(!m_can_clear);
            saveTimeStampDateTime(ScheduleType::SHUTDOWN);
        }
        process->deleteLater(); // Clean up the process
    });
}


void Controller::close()
{
    qDebug()<<"close clicked!";
    QCoreApplication::quit();
}

void Controller::about()
{
    //TODO
}

void Controller::clear()
{
    QProcess *process = new QProcess(this);

#ifdef Q_OS_WIN
    process->start("shutdown", QStringList() << "/a");
#elif defined(Q_OS_LINUX) || defined(Q_OS_UNIX) || defined(Q_OS_MAC)
    process->start("shutdown", QStringList() << "-c");
#endif

    if (!process->waitForFinished()) {
        qDebug() << process->exitCode() << "Failed to cancel shutdown";
    } else {
        qDebug() << process->exitCode() << "Shutdown canceled successfully";
        setCanClear(!m_can_clear);

    }
    process->deleteLater(); // Cleanup
}

void Controller::reboot()
{
    if (m_duration < 15) {
        setMsg("Warning: Timer is set for less than 15 minutes");
    }

    QTimer::singleShot(500, [this]() {
        auto* process = new QProcess(this); // Prevent premature destruction

#ifdef Q_OS_WIN
        process->start("shutdown", QStringList() << "/r" << "/t" << QString::number(m_duration * 60));
#elif defined(Q_OS_LINUX) || defined(Q_OS_UNIX)
        process->start("shutdown", QStringList() << "-r" << "+" << QString::number(m_duration));
#elif defined(Q_OS_MAC)
        process->start("sudo", QStringList() << "shutdown" << "-r" << "+" << QString::number(m_duration));
#endif

        if (!process->waitForFinished()) {
            qDebug() << process->exitCode() << "Failed to set reboot timer";
        } else {
            qDebug() << process->exitCode() << "Reboot timer set successfully";
            setCanClear(!m_can_clear);
            saveTimeStampDateTime(ScheduleType::REBOOT);
        }
        process->deleteLater(); // Clean up the process
    });
}

qint64 Controller::duration() const
{
    return m_duration;
}

void Controller::setDuration(qint64 newDuration)
{
    if (m_duration == newDuration)
        return;
    m_duration = newDuration;
    emit durationChanged(m_duration);
}

bool Controller::canClear() const
{
    return m_can_clear;
}

void Controller::setCanClear(bool newCan_clear)
{
    if (m_can_clear == newCan_clear)
        return;
    m_can_clear = newCan_clear;
    if(!m_can_clear){
        qDebug()<<"Noope";
        setMsg("Copyright© 2025 Vishal Ahirwar.All rights reserved.");
        auto file=QFile("timer.txt");
        if(file.exists())file.remove();
        qDebug()<<"removing from "<<__func__;
    }
    emit canClearChanged();
}

QDateTime Controller::getBootDateTime()
{
    qint64 bootTimeStamp = 0;

#ifdef Q_OS_WIN
    bootTimeStamp = QDateTime::currentSecsSinceEpoch() - (GetTickCount64() / 1000);
#elif defined(Q_OS_LINUX)
    QFile file("/proc/uptime");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        qint64 uptimeSeconds = in.readLine().split(" ").first().toDouble();
        file.close();
        bootTimeStamp = QDateTime::currentSecsSinceEpoch() - uptimeSeconds;
    }
#elif defined(Q_OS_MAC)
    QProcess process;
    process.start("sysctl", QStringList() << "-n" << "kern.boottime");
    if (process.waitForFinished()) {
        QString output = process.readAllStandardOutput();
        QRegExp regex("\\{ sec = (\\d+),");
        if (regex.indexIn(output) != -1) {
            bootTimeStamp = regex.cap(1).toLongLong();
        }
    }
#endif

    if (bootTimeStamp > 0) {
        return QDateTime::fromSecsSinceEpoch(bootTimeStamp);
    }
    return QDateTime();
}

void Controller::saveTimeStampDateTime(ScheduleType type)
{
    QFile file("timer.txt");
    if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
        QString scheduledDateTime = QDateTime::currentDateTime().addSecs(duration()*60).toString("yyyy-MM-dd HH:mm:ss");
        switch(type){
        case ScheduleType::SHUTDOWN:{
            scheduledDateTime= "Shutdown Scheduled for="+scheduledDateTime;
            break;
        };
        case ScheduleType::REBOOT:{
            scheduledDateTime= "Reboot Scheduled for="+scheduledDateTime;
            break;
        };
        }
        setMsg(scheduledDateTime);
        QTextStream out(&file);
        out<<scheduledDateTime;
        file.close();
        qDebug()<<scheduledDateTime;

    }

}

QDateTime Controller::getTimeStampDateTime(ScheduleType&type) const
{
    QFile file("timer.txt");
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        auto data= file.readAll();
        auto save_string=data.split('=');
        if(save_string.first().split(' ').first().compare("reboot",Qt::CaseInsensitive)==0)type=ScheduleType::REBOOT;
        else type=ScheduleType::SHUTDOWN;
        return QDateTime::fromString(save_string.last().trimmed(),"yyyy-MM-dd HH:mm:ss");
    }
    return QDateTime();
}

QString Controller::msg() const
{
    return m_msg;
}

void Controller::setMsg(const QString &newMsg)
{
    if (m_msg == newMsg)
        return;
    m_msg = newMsg;
    emit msgChanged();
}
