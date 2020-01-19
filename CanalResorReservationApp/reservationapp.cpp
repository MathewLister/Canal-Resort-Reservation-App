#include "reservationapp.h"
#include "ui_reservationapp.h"

ReservationApp::ReservationApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ReservationApp)
{
    ui->setupUi(this);
}

ReservationApp::~ReservationApp()
{
    delete ui;
}

