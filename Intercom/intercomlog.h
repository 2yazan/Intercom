#ifndef INTERCOMLOG_H
#define INTERCOMLOG_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <QHBoxLayout>
//#include <QTime>
#include <QFileDialog>
//#include <QMessageBox>

class IntercomLog : public QWidget {
    Q_OBJECT

private:
    QListWidget* list;
    QPushButton* saveButton;
    QFile* log;
    QTextStream logStream;
    QHBoxLayout* Layout;

public:
    IntercomLog();

public slots:
    void saveLog();
    void recordEvent(const QString& eventType, int param);
    void recordOpenDoor(int apartNum);
    void recordConnectOpen(int apartNum);
    void recordConnectClose(int apartNum);
    void recordOpenWithKey(int key);
    void recordWrongKey(int key);
};

#endif // INTERCOMLOG_H
