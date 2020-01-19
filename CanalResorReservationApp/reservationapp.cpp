#include "reservationapp.h"
#include "ui_reservationapp.h"

ReservationApp::ReservationApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ReservationApp)
{
    ui->setupUi(this);
    AsteriskRed();
}

//Make Asterisk red
void ReservationApp::AsteriskRed()
{
    QPalette palette = ui->Astreisk->palette();
    palette.setColor(QPalette::WindowText, Qt::red);
    ui->Astreisk->setPalette(palette);
}

ReservationApp::~ReservationApp()
{
    delete ui;
}

