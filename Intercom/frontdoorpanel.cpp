#include "FrontDoorPanel.h"


FrontDoorPanel::FrontDoorPanel(int key) : QWidget(), correctKey(key) {
    setWindowTitle(QStringLiteral("Intercom"));

//    gridLayout = new QGridLayout();
//    QLabel* label = new QLabel("Выберите номер квартиры для связи.");
//    mainLayout = new QVBoxLayout();
//    mainLayout->addWidget(label);

    mainLayout = new QHBoxLayout();
    keyOpen = new QPushButton("Open with password");
    callOpen = new QPushButton("Call an apartment");
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
//    keyOpen -> setFixedSize(180,60);
//    callOpen -> setFixedSize(180,60);


    mainLayout->addWidget(keyOpen);
    mainLayout->addWidget(callOpen);
    setLayout(mainLayout);
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
    connect(keyOpen, SIGNAL(clicked()), this, SLOT(bKeySlot()));
    connect(callOpen, SIGNAL(clicked()), this, SLOT(bCallSlot()));
}

void FrontDoorPanel::bKeySlot() {
    QString inputKey = QInputDialog::getText(this, tr("Password"), tr("Enter the password:"), QLineEdit::Password);
    int parsedKey = inputKey.toInt();

    if (parsedKey == correctKey) {
        emit recordOpenDoor(correctKey);
    } else {
        QMessageBox msgBox;
        msgBox.setText("Incorrect password");
        msgBox.exec();
        emit recordWrongKey(parsedKey);
    }
}

void FrontDoorPanel::bCallSlot() {
    emit bCallClick();
}
