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

private slots:
    void on_NextButton_clicked();

    void on_BackButton_clicked();

    void on_NextButton_2_clicked();

    void on_BackButton_2_clicked();

    void on_AdultSpinBox_valueChanged(int arg1);

    void on_RoomTypeDropdown_currentIndexChanged(const QString &arg1);

private:
    Ui::ReservationApp *ui;

    //Setters
    void AsteriskRed();
    void SetName();
    void SetRoomTypes();
    void SetDate();


};
#endif // RESERVATIONAPP_H
