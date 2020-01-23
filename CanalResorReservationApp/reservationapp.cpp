#include "reservationapp.h"
#include "ui_reservationapp.h"
#include <QMessageBox>
#include <string>

//Constructor
ReservationApp::ReservationApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ReservationApp)
{
    ui->setupUi(this);

    netTotal = 0;

    //Setters
    loadLogo();
    SetRoomTypes();
    SetDate();
    ui->NetTotal->setNum(netTotal);
    ui->NextButton->setEnabled(false);
    ui->NextButton_2->setEnabled(false);

}

//--------------------------------------------------------------------------------------------
//Load logo
void ReservationApp::loadLogo()
{
    QString logoFileName = ":/ResortLogo.jpg";
    QString AmericaFileName = ":/AmericaExpress.png";
    QString VisaFileName = ":/VISA.png";
    QString MasterFileName = ":/MasterCard.png";
    QString DiscoverFileName = ":/Discover.png";

    if (imageLogo.load(logoFileName))
    {
        imageLogo = imageLogo.scaled(ui->CanalLogo->size(), Qt::KeepAspectRatioByExpanding);
    }

    ui->CanalLogo->setPixmap(imageLogo);
    ui->CanalLogo_2->setPixmap(imageLogo);
    ui->CanalLogo_3->setPixmap(imageLogo);

    if (AmericanExpress.load(AmericaFileName) && Visa.load(VisaFileName) && Mastercard.load(MasterFileName) && Discover.load(DiscoverFileName))
    {
        AmericanExpress = AmericanExpress.scaled(ui->AmericanLogo->size(), Qt::KeepAspectRatioByExpanding);
        Visa = Visa.scaled(ui->VisaLogo->size(), Qt::KeepAspectRatioByExpanding);
        Mastercard = Mastercard.scaled(ui->MasterLogo->size(), Qt::KeepAspectRatioByExpanding);
        Discover = Discover.scaled(ui->DiscoverLogo->size(), Qt::KeepAspectRatioByExpanding);
    }

    ui->AmericanLogo->setPixmap(AmericanExpress);
    ui->VisaLogo->setPixmap(Visa);
    ui->MasterLogo->setPixmap(Mastercard);
    ui->DiscoverLogo->setPixmap(Discover);

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
    ui->ExpDateEntry->setDate(QDate::currentDate());
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

//Set pay button
//Check if user chose a card type and entered correct ammount of numbers before moving on
void ReservationApp::CheckMovePage3()
{
    if (ui->AmericanExpress->isChecked() && ui->CardNumberEntry->text().length() == 21)
        ui->NextButton_2->setEnabled(true);
    else if (ui->Visa->isChecked() && ui->CardNumberEntry->text().length() == 25)
        ui->NextButton_2->setEnabled(true);
    else if (ui->Mastercard->isChecked() && ui->CardNumberEntry->text().length() == 25)
        ui->NextButton_2->setEnabled(true);
    else if (ui->Discover->isChecked() && ui->CardNumberEntry->text().length() == 25)
        ui->NextButton_2->setEnabled(true);
}

//----------------------------------------------------------------------------------------------------------------
//Next and Back Buttons

//Moves user to page 2
// Calculates payment info based on inputs from page 1
void ReservationApp::on_NextButton_clicked()
{
    QDate temp = ui->dateEdit->date();
    arrivalDate = temp.toString();
    numAdults = ui->AdultSpinBox->value();
    numChildren = ui->ChildrenSpinBox->value();
    taxes = taxRate * netTotal;
    fee = resortFee * numberOfNights;
    grossTotal = netTotal + taxes + fee + parking;

    ui->stackedWidget->setCurrentIndex(1);
    ui->RoomLabel->setNum(netTotal);
    ui->TaxLabel->setNum(taxes);
    ui->ParkingLabel->setNum(parking);
    ui->ResortFeeLabel->setNum(fee);
    ui->TotalDueLabel->setNum(grossTotal);
}

void ReservationApp::on_BackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void ReservationApp::on_NextButton_2_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("The transaction was successfully processed.");
    msgBox.setWindowTitle("Thank you!");
    msgBox.exec();
    QString temp = ui->CardNumberEntry->text();
    lastFour = temp.right(4);
    SetPage3();
    ui->stackedWidget->setCurrentIndex(2);
}

void ReservationApp::on_BackButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

//Closes the app
void ReservationApp::on_FinsihButton_clicked()
{
    close();
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
    numberOfNights = numNights;

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

    //Updates parking if number of nights gets changed
    if (ui->ParkingCheckBox->isChecked())
        parking = parkingPerNight * numNights;
    else if (ui->ParkingCheckBox->isChecked() == false)
        parking = 0;

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
        roomType = 1;
    }
    else if (index == 2)
    {
        netTotal = atrium2Queen;
        roomType = 2;
    }
    else if (index == 3)
    {
        netTotal = standardKing;
        roomType = 3;
    }
    else if (index == 4)
    {
        netTotal = atriumKing;
        roomType = 4;
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

//Handlers for card type choice
void ReservationApp::on_AmericanExpress_clicked()
{
    ui->NextButton_2->setEnabled(false);
    ui->CardNumberEntry->setInputMask("3999 - 999999 - 99999;0");
    ui->CardNumberEntry->clear();
}

void ReservationApp::on_Visa_clicked()
{
    ui->NextButton_2->setEnabled(false);
    ui->CardNumberEntry->setInputMask("4999 - 9999 - 9999 - 9999;0");
    ui->CardNumberEntry->clear();
}

void ReservationApp::on_Mastercard_clicked()
{
    ui->NextButton_2->setEnabled(false);
    ui->CardNumberEntry->setInputMask("5999 - 9999 - 9999 - 9999;0");
    ui->CardNumberEntry->clear();
}

void ReservationApp::on_Discover_clicked()
{
    ui->NextButton_2->setEnabled(false);
    ui->CardNumberEntry->setInputMask("6999 - 9999 - 9999 - 9999;0");
    ui->CardNumberEntry->clear();
}

void ReservationApp::on_CardNumberEntry_textChanged(const QString &arg1)
{
    CheckMovePage3();
}


void ReservationApp::SetPage3()
{
    ui->ConfArrival->setText(ui->ConfArrival->text() + arrivalDate);
    ui->ConfNumNightsNum->setNum(numberOfNights);
    if (roomType == 1)
        ui->ConfRoom->setText(ui->ConfRoom->text() + "Standard 2-Queen room");
    else if (roomType ==2)
        ui->ConfRoom->setText(ui->ConfRoom->text() + "Atrium 2-Queen room");
    else if (roomType == 3)
        ui->ConfRoom->setText(ui->ConfRoom->text() + "Standard 1-King room");
    else if (roomType == 4)
        ui->ConfRoom->setText(ui->ConfRoom->text() + "Atrium 1-King room");

    if (parking == 0)
        ui->ConfParking->setText(ui->ConfParking->text() + "No");
    else
        ui->ConfParking->setText(ui->ConfParking->text() + "Yes");

    ui->ConfNumAdultsNum->setNum(numAdults);
    ui->ConfNumkidsNum->setNum(numChildren);
    ui->ConfTotalNum->setNum(grossTotal);
    ui->ConfCard->setText(ui->ConfCard->text() + lastFour);


}

