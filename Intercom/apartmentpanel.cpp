#include "ApartmentPanel.h"

ApartmentPanel::ApartmentPanel(int num) : QWidget(), apartNum(num) {
    setWindowTitle(QStringLiteral("Apartment № %1").arg(apartNum));
    QLabel* label = new QLabel(QStringLiteral("Apartment № %1 Panel").arg(apartNum));
    label->setAlignment(Qt::AlignCenter);

    horizontalLayout = new QHBoxLayout();
    mainLayout = new QVBoxLayout();

    openButton = new QPushButton("Open");
    openButton->setEnabled(false);
    closeButton = new QPushButton("Block");
    closeButton->setEnabled(false);
    connectButton = new QPushButton("Connect");
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
//    openButton -> setFixedSize(135,45);
//    closeButton -> setFixedSize(135,45);
//    connectButton -> setFixedSize(135,45);

    connect(openButton, &QPushButton::clicked, this, &ApartmentPanel::doorButtonClick);
    connect(connectButton, &QPushButton::clicked, this, &ApartmentPanel::connectButtonClick);
    connect(closeButton, &QPushButton::clicked, this, &ApartmentPanel::closeButtonClick);

    horizontalLayout->addWidget(connectButton);
    horizontalLayout->addWidget(openButton);
    horizontalLayout->addWidget(closeButton);

    mainLayout->addWidget(label);
    mainLayout->addLayout(horizontalLayout);

    setLayout(mainLayout);
}

void ApartmentPanel::doorButtonClick() {
    emit doorOpen(apartNum);
    close();
}

void ApartmentPanel::connectButtonClick() {
    emit connectOpen(apartNum);
    connectButton->setEnabled(false);
    openButton->setEnabled(true);
    closeButton->setEnabled(true);
}

void ApartmentPanel::closeButtonClick() {
    emit connectBlock(apartNum);
    close();
}
