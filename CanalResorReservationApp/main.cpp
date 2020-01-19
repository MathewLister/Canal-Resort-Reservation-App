#include "reservationapp.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ReservationApp w;
    w.show();
    return a.exec();
}
