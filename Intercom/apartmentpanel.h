#ifndef APARTMENTPANEL_H
#define APARTMENTPANEL_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class ApartmentPanel : public QWidget {
    Q_OBJECT

private:
    int apartNum;
    QPushButton* openButton;
    QPushButton* connectButton;
    QPushButton* closeButton;
    QHBoxLayout* horizontalLayout;
    QVBoxLayout* mainLayout;

public:
    ApartmentPanel(int num);

signals:
    void doorOpen(int apartNum);
    void connectOpen(int apartNum);
    void connectBlock(int apartNum);

private slots:
    void doorButtonClick();
    void connectButtonClick();
    void closeButtonClick();
};

#endif // APARTMENTPANEL_H
