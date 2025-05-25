#include <iostream>
#include <unistd.h>
#include <string>
#include "Service.hpp"


Service::Service(QObject* parent)
    : QObject(parent)
    , mMAVHandler(*this)
{
    mProcessingThread = std::thread(&Service::Run, this);
}

void Service::SendCallFromFloorCmd(const uint8_t floor)
{
    mMAVHandler.SendCallFromFloorCmd(floor);
}

void Service::SendGotoFloorCmd(const uint8_t floor)
{
    mMAVHandler.SendGotoFloorCmd(floor);
}

void Service::Run()
{
    mMAVHandler.StartHandling(14550,
                              14550,
                              "192.168.9.247");

    while(true) {
        mMAVHandler.SendHeartbeat();
        sleep(1);
    }
}

void Service::HeartbeatReceived()
{
    emit Heartbeat();
}
