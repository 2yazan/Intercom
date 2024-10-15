#ifndef APARTMENTS_H
#define APARTMENTS_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
//#include <QLabel>

class Apartments : public QWidget {
    Q_OBJECT

private:
    int floors;
    int apartPerFloor;
    QList<QPushButton*> apartmentButtons;
    QGridLayout* gridLayout;
    QVBoxLayout* mainLayout;

public:
    Apartments(int floors, int apart);

public slots:
    void showApartWindow(int num);
    void apartOpenDoor(int apart);
    void apartOpenConn(int apart);
    void apartCloseConn(int apart);

signals:
    void openDoor(int apart);
    void openConn(int apart);
    void closeConn(int apart);
};

#endif // APARTMENTS_H
