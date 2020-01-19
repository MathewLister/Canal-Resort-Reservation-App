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

    //before taxes
    double netTotal;
    //after taxes
    double grossTotal;
    double parking;

    double taxes;

    static const int standard2Queen = 284;
    static const int atrium2Queen = 325;
    static const int standardKing = 290;
    static const int atriumKing = 350;
    const double parkingPerNight = 12.75;


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

private:
    Ui::ReservationApp *ui;

    //Setters
    void AsteriskRed();
    void SetName();
    void SetRoomTypes();
    void SetDate();

    void CheckMovePage2();

};
#endif // RESERVATIONAPP_H
