#include "reservationapp.h"
#include "ui_reservationapp.h"

#include <QDebug>

ReservationApp::ReservationApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ReservationApp)
{
    ui->setupUi(this);
    netTotal = 0;

    ui->NetTotal->setNum(netTotal);
    ui->NextButton->setEnabled(false);

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
    ui->Astreisk_6->setPalette(palette);
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
    ui->RoomTypeDropdown->addItem(""); //No option chosen
    ui->RoomTypeDropdown->addItem("Standard 2-queen room - $284 per night");
    ui->RoomTypeDropdown->addItem("Atrium 2-queen room - $325 per night");
    ui->RoomTypeDropdown->addItem("Standard 1-king room - $290 per night");
    ui->RoomTypeDropdown->addItem("Atrium 1-king room - $350 per night");
}

void ReservationApp::SetDate()
{
    ui->dateEdit->setDate(QDate::currentDate());
}

void ReservationApp::CheckMovePage2()
{
    int i = ui->RoomTypeDropdown->currentIndex();

    // Can only go to next page if name, room type are filled out
    if (!ui->FirstLineEdit->text().isEmpty() && !ui->LastLineEdit->text().isEmpty() && i != 0)
        ui->NextButton->setEnabled(true);
    else
        ui->NextButton->setEnabled(false);
}

//Destructor
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


// Handles guest number changes
// Change max number of guests depending on room type
// Sets max and min for adults and children based on current number of adults
void ReservationApp::on_AdultSpinBox_valueChanged(int arg1)
{
    int i = ui->RoomTypeDropdown->currentIndex();

    if (i == 1 || i == 2)
    {
        ui->AdultSpinBox->setMaximum(4);

        if (ui->AdultSpinBox->value() == 1)
            ui->ChildrenSpinBox->setMaximum(3);

        if (ui->AdultSpinBox->value() == 2)
            ui->ChildrenSpinBox->setMaximum(2);

        if (ui->AdultSpinBox->value() == 3)
            ui->ChildrenSpinBox->setMaximum(1);

        if (ui->AdultSpinBox->value() == 4)
            ui->ChildrenSpinBox->setMaximum(0);
    }

    else if (i == 3 || i == 4)
    {
        ui->AdultSpinBox->setMaximum(3);

        if (ui->AdultSpinBox->value() == 1)
            ui->ChildrenSpinBox->setMaximum(2);

        if (ui->AdultSpinBox->value() == 2)
            ui->ChildrenSpinBox->setMaximum(1);

        if (ui->AdultSpinBox->value() == 3)
            ui->ChildrenSpinBox->setMaximum(0);
    }

    CheckMovePage2();
}

// Handles room changes
// Change max number of guests depending on room type
// Sets max and min for adults and children based on current number of adults
void ReservationApp::on_RoomTypeDropdown_currentIndexChanged(const QString &arg1)
{
    int i = ui->RoomTypeDropdown->currentIndex();

    if (i == 1 || i == 2)
    {
        ui->AdultSpinBox->setMaximum(4);

        if (ui->AdultSpinBox->value() == 1)
            ui->ChildrenSpinBox->setMaximum(3);

        if (ui->AdultSpinBox->value() == 2)
            ui->ChildrenSpinBox->setMaximum(2);

        if (ui->AdultSpinBox->value() == 3)
            ui->ChildrenSpinBox->setMaximum(1);

        if (ui->AdultSpinBox->value() == 4)
            ui->ChildrenSpinBox->setMaximum(0);
    }

    else if (i == 3 || i == 4)
    {
        ui->AdultSpinBox->setMaximum(3);

        if (ui->AdultSpinBox->value() == 1)
            ui->ChildrenSpinBox->setMaximum(2);

        if (ui->AdultSpinBox->value() == 2)
            ui->ChildrenSpinBox->setMaximum(1);

        if (ui->AdultSpinBox->value() == 3)
            ui->ChildrenSpinBox->setMaximum(0);
    }

    CheckMovePage2();
}

// Updates running net total based on room type and number of nights
void ReservationApp::on_NightsSpinBox_valueChanged(int numNights)
{
    int i = ui->RoomTypeDropdown->currentIndex();

    if (i == 0)
    {
        netTotal = 0;
    }
    if (i == 1)
    {
        netTotal = 284 * numNights;
    }
    else if (i == 2)
    {
        netTotal = 325 * numNights;
    }
    else if (i == 3)
    {
        netTotal = 290 * numNights;
    }
    else if (i == 4)
    {
        netTotal = 350 * numNights;
    }

    ui->NetTotal->setNum(netTotal);
    CheckMovePage2();
}

// Updates running net total with parking option
void ReservationApp::on_ParkingCheckBox_stateChanged(int state)
{
    if (ui->ParkingCheckBox->isChecked())
        parking = 12.75 * ui->NightsSpinBox->value();
    else if (ui->ParkingCheckBox->isChecked() == false)
        parking = - parking;

    netTotal += parking;
    ui->NetTotal->setNum(netTotal);
}

// Updates net cost based on room type
void ReservationApp::on_RoomTypeDropdown_currentIndexChanged(int index)
{
    if (index == 0)
    {
        netTotal = 0;
    }
    if (index == 1)
    {
        netTotal = 284;
    }
    else if (index == 2)
    {
        netTotal = 325;
    }
    else if (index == 3)
    {
        netTotal = 290;
    }
    else if (index == 4)
    {
        netTotal = 350;
    }

    CheckMovePage2();
    ui->NetTotal->setNum(netTotal);
}

void ReservationApp::on_FirstLineEdit_textChanged(const QString &arg1)
{
    CheckMovePage2();
}

void ReservationApp::on_LastLineEdit_textChanged(const QString &arg1)
{
    CheckMovePage2();
}
