#ifndef RESERVATIONAPP_H
#define RESERVATIONAPP_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ReservationApp; }
QT_END_NAMESPACE

class ReservationApp : public QMainWindow
{
    Q_OBJECT

public:
    ReservationApp(QWidget *parent = nullptr);
    ~ReservationApp();

    QString firstName;
    QString lastName;

    //before taxes for room per night
    double netTotal;
    //after taxes grand total
    double grossTotal;
    //charges per night
    double parking = 0;
    double fee = 15;
    double taxes;
    int numberOfNights = 1;

    static const int standard2Queen = 284;
    static const int atrium2Queen = 325;
    static const int standardKing = 290;
    static const int atriumKing = 350;
    static const int resortFee = 15;
    const double parkingPerNight = 12.75;
    const double taxRate = .15;



private slots:
    void on_NextButton_clicked();

    void on_BackButton_clicked();

    void on_NextButton_2_clicked();

    void on_BackButton_2_clicked();

    void on_AdultSpinBox_valueChanged(int arg1);

    void on_RoomTypeDropdown_currentIndexChanged(const QString &arg1);

    void on_NightsSpinBox_valueChanged(int arg1);

    void on_ParkingCheckBox_stateChanged(int arg1);

    void on_RoomTypeDropdown_currentIndexChanged(int index);

    void on_FirstLineEdit_textChanged(const QString &arg1);

    void on_LastLineEdit_textChanged(const QString &arg1);

    void on_AmericanExpress_clicked();

    void on_Visa_clicked();

    void on_Mastercard_clicked();

    void on_Discover_clicked();

    void on_CardNumberEntry_textChanged(const QString &arg1);

    void on_FinsihButton_clicked();

private:
    Ui::ReservationApp *ui;

    QPixmap imageLogo;
    QPixmap AmericanExpress;
    QPixmap Visa;
    QPixmap Mastercard;
    QPixmap Discover;

    void loadLogo();

    //Setters
    void SetName();
    void SetRoomTypes();
    void SetDate();

    void CheckMovePage2();
    void CheckMovePage3();

};
#endif // RESERVATIONAPP_H
