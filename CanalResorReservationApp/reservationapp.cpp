#include "reservationapp.h"
#include "ui_reservationapp.h"



#include <QDebug>

//Constructor
ReservationApp::ReservationApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ReservationApp)
{
    ui->setupUi(this);

    netTotal = 0;

    //Setters
    loadLogo();
    AsteriskRed();
    SetRoomTypes();
    SetDate();
    ui->NetTotal->setNum(netTotal);
    ui->NextButton->setEnabled(false);

}

//--------------------------------------------------------------------------------------------
//Load logo
void ReservationApp::loadLogo()
{
    QString logoFileName = ":/ResortLogo.jpg";

    if (imageLogo.load(logoFileName))
    {
        imageLogo = imageLogo.scaled(ui->CanalLogo->size(), Qt::KeepAspectRatioByExpanding);
    }

    ui->CanalLogo->setPixmap(imageLogo);
}

//Set Asterisks red
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

//Set arrival data to default to current date
void ReservationApp::SetDate()
{
    ui->dateEdit->setDate(QDate::currentDate());
}

//Set next button
//Check if user is ready to move to page 2
void ReservationApp::CheckMovePage2()
{
    int i = ui->RoomTypeDropdown->currentIndex();

    // Can only go to next page if name, room type are filled out
    if (!ui->FirstLineEdit->text().isEmpty() && !ui->LastLineEdit->text().isEmpty() && i != 0)
        ui->NextButton->setEnabled(true);
    else
        ui->NextButton->setEnabled(false);
}

//----------------------------------------------------------------------------------------------------------------
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

//--------------------------------------------------------------------------------------------------
//Handles guest number changes
//Change max number of guests depending on room type
//Sets max and min for adults and children based on current number of adults
//Wont let you pass to next page unless you chose an option
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

//Handles room changes
//Change max number of guests depending on room type
//Sets max and min for adults and children based on current number of adults
//Wont let you pass to next page unless you chose an option
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

//Updates running net total based on room type and number of nights
void ReservationApp::on_NightsSpinBox_valueChanged(int numNights)
{
    int i = ui->RoomTypeDropdown->currentIndex();

    if (i == 0)
    {
        netTotal = 0;
    }
    if (i == 1)
    {
        netTotal = standard2Queen * numNights;
    }
    else if (i == 2)
    {
        netTotal = atrium2Queen * numNights;
    }
    else if (i == 3)
    {
        netTotal = standardKing * numNights;
    }
    else if (i == 4)
    {
        netTotal = atriumKing * numNights;
    }

    ui->NetTotal->setNum(netTotal);
    CheckMovePage2();
}

//Updates running net total with parking option
void ReservationApp::on_ParkingCheckBox_stateChanged(int state)
{
    if (ui->ParkingCheckBox->isChecked())
        parking = parkingPerNight * ui->NightsSpinBox->value();
    else if (ui->ParkingCheckBox->isChecked() == false)
        parking = 0;

    //netTotal += parking;
    //ui->NetTotal->setNum(netTotal);
}

//Updates running net cost based on room type
void ReservationApp::on_RoomTypeDropdown_currentIndexChanged(int index)
{
    if (index == 0)
    {
        netTotal = 0;
    }
    if (index == 1)
    {
        netTotal = standard2Queen;
    }
    else if (index == 2)
    {
        netTotal = atrium2Queen;
    }
    else if (index == 3)
    {
        netTotal = standardKing;
    }
    else if (index == 4)
    {
        netTotal = atriumKing;
    }

    CheckMovePage2();
    ui->NetTotal->setNum(netTotal);
}

//Updates enable/disable next button if first name is changed to empty string
void ReservationApp::on_FirstLineEdit_textChanged(const QString &arg1)
{
    CheckMovePage2();
}
//Updates enable/disable next button if last name is changed to empty string
void ReservationApp::on_LastLineEdit_textChanged(const QString &arg1)
{
    CheckMovePage2();
}

//----------------------------------------------------------------------------------------
//Destructor
ReservationApp::~ReservationApp()
{
    delete ui;
}
