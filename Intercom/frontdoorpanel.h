#ifndef FRONTDOORPANEL_H
#define FRONTDOORPANEL_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QInputDialog>
#include <QMessageBox>
#include<QLabel>

class FrontDoorPanel : public QWidget {
    Q_OBJECT

private:
    int correctKey;
    QHBoxLayout* mainLayout;
    QPushButton* keyOpen;
    QPushButton* callOpen;

public:
    FrontDoorPanel(int key);

signals:
    void bKeyClick();
    void bCallClick();
    void recordOpenDoor(int key);
    void recordWrongKey(int key);

private slots:
    void bKeySlot();
    void bCallSlot();
};

#endif // FRONTDOORPANEL_H
