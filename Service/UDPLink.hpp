#pragma once

#include <cstdint>
#include <functional>
#include <thread>
#include <arpa/inet.h>
#include <atomic>


class UDPLink
{
    using DataHandlerCb = std::function<void(const uint8_t* buffer,
                                             const uint16_t size)>;
    using aBool         = std::atomic<bool>;

public:
    UDPLink();

public:
    bool Connect(const uint16_t localPort,
                 const uint16_t remotePort,
                 const std::string remoteHost);
    void StartReading(DataHandlerCb callback);
    void SendData(const uint8_t* buffer,
                  const uint16_t size);

private:
    void ReadData(DataHandlerCb callback);

private:
    int32_t     mSocket;
    sockaddr_in mTargetAddress;
    std::thread mReadingThread;

    bool  mConnected {false};
    aBool mReading   {false};
};
