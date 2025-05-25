#include "MainWindow.hpp"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(Service& service,
                       QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mService(service)
{
    ui->setupUi(this);

    connect(ui->floor0CallBtn, &QPushButton::clicked,
            this, [this](){ CallFromFloorBtnClicked(0); });
    connect(ui->floor1CallBtn, &QPushButton::clicked,
            this, [this](){ CallFromFloorBtnClicked(1); });
    connect(ui->floor2CallBtn, &QPushButton::clicked,
            this, [this](){ CallFromFloorBtnClicked(2); });
    connect(ui->floor3CallBtn, &QPushButton::clicked,
            this, [this](){ CallFromFloorBtnClicked(3); });
    connect(ui->floor4CallBtn, &QPushButton::clicked,
            this, [this](){ CallFromFloorBtnClicked(4); });

    connect(ui->gotoFloor0Btn, &QPushButton::clicked,
            this, [this](){ GotoFloorBtnClicked(0); });
    connect(ui->gotoFloor1Btn, &QPushButton::clicked,
            this, [this](){ GotoFloorBtnClicked(1); });
    connect(ui->gotoFloor2Btn, &QPushButton::clicked,
            this, [this](){ GotoFloorBtnClicked(2); });
    connect(ui->gotoFloor3Btn, &QPushButton::clicked,
            this, [this](){ GotoFloorBtnClicked(3); });
    connect(ui->gotoFloor4Btn, &QPushButton::clicked,
            this, [this](){ GotoFloorBtnClicked(4); });

    connect(&service, &Service::Heartbeat, this, &MainWindow::HeartbeatReceived);

    InitNoHeartbeatTimer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CallFromFloorBtnClicked(const quint8 floor)
{
    mService.SendCallFromFloorCmd(floor);
}

void MainWindow::GotoFloorBtnClicked(const quint8 floor)
{
    mService.SendGotoFloorCmd(floor);
}

void MainWindow::InitNoHeartbeatTimer()
{
    mNoHeartbeatTimer.setInterval(5000);
    mNoHeartbeatTimer.setSingleShot(true);

    connect(&mNoHeartbeatTimer, &QTimer::timeout, this, [this](){
        QPalette palette;
        palette.setColor(QPalette::WindowText, Qt::darkRed);

        ui->ConnectionStatusLbl->setPalette(palette);
        ui->ConnectionStatusLbl->setText("NO");

        mNoHeartbeatTimer.stop();
    });

    mNoHeartbeatTimer.start();
}

void MainWindow::HeartbeatReceived()
{
    QPalette palette;
    palette.setColor(QPalette::WindowText, Qt::darkGreen);

    ui->ConnectionStatusLbl->setPalette(palette);
    ui->ConnectionStatusLbl->setText("YES");

    mNoHeartbeatTimer.start();
}
