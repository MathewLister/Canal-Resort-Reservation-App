#include "reservationapp.h"
#include "ui_reservationapp.h"

#include <QDebug>

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

//Set first and last name
void ReservationApp::SetName()
{
    firstName = ui->First->text();
    lastName = ui->Last->text();

    //**TESTING** qDebug() << firstName;
}

ReservationApp::~ReservationApp()
{
    delete ui;
}

//Next and Back Buttons
void ReservationApp::on_NextButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void ReservationApp::on_BackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void ReservationApp::on_NextButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void ReservationApp::on_BackButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
//---------------------------------------------------------
