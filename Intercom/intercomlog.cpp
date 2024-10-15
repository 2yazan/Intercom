#include "IntercomLog.h"

const QString tempFilename = "temp.log";

IntercomLog::IntercomLog() : QWidget() {
    setWindowTitle(QString("Intercom log"));
    list = new QListWidget();
    saveButton = new QPushButton("Save the log");
    log = new QFile(tempFilename);
    log->remove();
    log->open(QIODevice::WriteOnly);
    logStream.setDevice(log);
    Layout = new QHBoxLayout(this);
    Layout->addWidget(list);
    Layout->addWidget(saveButton);
    connect(saveButton, SIGNAL(clicked()), this, SLOT(saveLog()));
    connect(saveButton, SIGNAL(clicked()), list, SLOT(clear()));
}
void IntercomLog::recordEvent(const QString& eventType, int param) {
    QString timeStr = QTime::currentTime().toString();
    QString resultStr = "[" + timeStr + "]. " + eventType + ": " + QString::number(param);
    list->addItem(resultStr);
    logStream << resultStr << "\n";
}

void IntercomLog::recordOpenDoor(int apartNum) {
    recordEvent("Door open", apartNum);
}

void IntercomLog::recordConnectOpen(int apartNum) {
    recordEvent("The doorbell rings", apartNum);
}

void IntercomLog::recordConnectClose(int apartNum) {
    recordEvent("The call was dropped", apartNum);
}

void IntercomLog::recordOpenWithKey(int key) {
    recordEvent("The door opened by password", key);
}

void IntercomLog::recordWrongKey(int key) {
    recordEvent("Trying to open the door, the password is incorrect", key);
}

void IntercomLog::saveLog() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save the log"), "/home", tr("Text files (*.txt);;All files (*)"));
    log->rename(fileName);
    log->close();
    log->setFileName(tempFilename);
    log->open(QIODevice::WriteOnly);
}
