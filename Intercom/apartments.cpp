#include "Apartments.h"
#include "ApartmentPanel.h"

Apartments::Apartments(int floors, int apart) : floors(floors), apartPerFloor(apart), QWidget() {
    setWindowTitle(QStringLiteral("Apartments"));
    gridLayout = new QGridLayout();
    QLabel* label = new QLabel("Choose an apartment to  conenct with.");
    mainLayout = new QVBoxLayout();
    mainLayout->addWidget(label);

    for (int i = 0, count = 1; i < floors; ++i) {
        for (int j = 0; j < apartPerFloor; ++j, ++count) {
            QPushButton* button = new QPushButton(QString::number(count));
            apartmentButtons.push_back(button);
            gridLayout->addWidget(apartmentButtons.last(), i, j);
            connect(button, &QPushButton::clicked, [this, count]() { showApartWindow(count); });
        }
    }
//    setStyleSheet("QPushButton {"
//                  "    background-color: #3498db;"
//                  "    border: none;"
//                  "    color: white;"
//                  "    padding: 5px 5px;"
//                  "    text-align: center;"
//                  "    text-decoration: none;"
//                  "    display: inline-block;"
//                  "    font-size: 15px;"
//                  "    margin: 4px 2px;"
//                  "    cursor: pointer;"
//                  "    border-radius: 8px;"
//                  "}");
//    button -> setFixedSize(90,30);
    mainLayout->addLayout(gridLayout);
    setLayout(mainLayout);
}

void Apartments::showApartWindow(int num) {
    ApartmentPanel* window = new ApartmentPanel(num);
    connect(window, &ApartmentPanel::doorOpen, this, &Apartments::apartOpenDoor);
    connect(window, &ApartmentPanel::connectOpen, this, &Apartments::apartOpenConn);
    connect(window, &ApartmentPanel::connectBlock, this, &Apartments::apartCloseConn);
    window->show();
}

void Apartments::apartOpenDoor(int apart) {
    emit openDoor(apart);
}

void Apartments::apartOpenConn(int apart) {
    emit openConn(apart);
}

void Apartments::apartCloseConn(int apart) {
    emit closeConn(apart);
}
