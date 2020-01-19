#include "reservationapp.h"
#include "ui_reservationapp.h"

#include <QDebug>

ReservationApp::ReservationApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ReservationApp)
{
    ui->setupUi(this);
    //Setters
    AsteriskRed();
    SetRoomTypes();
    SetDate();

}

//Make Asterisks red
void ReservationApp::AsteriskRed()
{
    QPalette palette = ui->Astreisk->palette();
    palette.setColor(QPalette::WindowText, Qt::red);

    ui->Astreisk->setPalette(palette);
    ui->Astreisk_3->setPalette(palette);
    ui->Astreisk_4->setPalette(palette);
    ui->Astreisk_5->setPalette(palette);
}

//Set first and last name
void ReservationApp::SetName()
{
    firstName = ui->First->text();
    lastName = ui->Last->text();

    //**TESTING** qDebug() << firstName;
}

//Set room and view type combo box
void ReservationApp::SetRoomTypes()
{
    ui->RoomTypeDropdown->addItem("Standard 2-queen room - $284 per night");
    ui->RoomTypeDropdown->addItem("Atrium 2-queen room - $325 per night");
    ui->RoomTypeDropdown->addItem("Standard 1-king room - $290 per night");
    ui->RoomTypeDropdown->addItem("Atrium 1-king room - $350 per night");
}

void ReservationApp::SetDate()
{
    ui->dateEdit->setDate(QDate::currentDate());
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
