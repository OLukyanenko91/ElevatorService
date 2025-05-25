#include <QApplication>
#include "MainWindow.hpp"
#include "Service/Service.hpp"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Service service;
    MainWindow window(service);

    window.setWindowTitle("Elevator service");
    window.show();

    return app.exec();
}
