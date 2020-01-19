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

private:
    Ui::ReservationApp *ui;
};
#endif // RESERVATIONAPP_H
