#pragma once

#include <QMainWindow>
#include <QTimer>
#include "Service/Service.hpp"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Service& service,
               QWidget* parent = nullptr);
    ~MainWindow();

private:
    void CallFromFloorBtnClicked(const quint8 floor);
    void GotoFloorBtnClicked(const quint8 floor);

    void InitNoHeartbeatTimer();
    void HeartbeatReceived();

private:
    Ui::MainWindow* ui;

    Service& mService;
    QTimer   mNoHeartbeatTimer;
};
