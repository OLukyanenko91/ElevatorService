#pragma once

#include <QObject>
#include "MAVLinkHandler.hpp"


class Service : public QObject
{
    friend MAVLinkHandler;

    Q_OBJECT

signals:
    void Heartbeat();

public:
    explicit Service(QObject* parent = nullptr);

public:
    void SendCallFromFloorCmd(const uint8_t floor);
    void SendGotoFloorCmd(const uint8_t floor);

private:
    void Run();

    void HeartbeatReceived();

private:
    MAVLinkHandler mMAVHandler;
    std::thread    mProcessingThread;
};
