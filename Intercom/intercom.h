#ifndef INTERCOM_H
#define INTERCOM_H

#include "Apartments.h"
#include "FrontDoorPanel.h"
#include "IntercomLog.h"

class Intercom : public QObject {
    Q_OBJECT

private:
    int apartPerFloor;
    int floors;
    int correctKey;
    Apartments* intercom;
    FrontDoorPanel* panel;
    IntercomLog* log;

public:
    Intercom(int apf, int f, int key);

};

class IntercomBuilder {
private:
    int aparts;
    int floors;
    int key;

public:
    void setFloors(int num);
    void setAparts(int num);
    void setKey(int num);
    Intercom build();
};


class IntercomConfig {
private:
    QFile* config;
    QTextStream cfg;
    int aparts, floors, key;
    IntercomBuilder builder;

public:
    IntercomConfig();
    Intercom getResult();
};

#endif // INTERCOM_H
