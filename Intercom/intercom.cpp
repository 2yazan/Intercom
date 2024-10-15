#include "Intercom.h"

Intercom::Intercom(int apf, int f, int key) : apartPerFloor(apf), floors(f), correctKey(key) {
    intercom = new Apartments(4, 2);
    panel = new FrontDoorPanel(112233);
    log = new IntercomLog();

    QObject::connect(intercom, SIGNAL(openDoor(int)), log, SLOT(recordOpenDoor(int)));
    QObject::connect(intercom, SIGNAL(openConn(int)), log, SLOT(recordConnectOpen(int)));
    QObject::connect(intercom, SIGNAL(closeConn(int)), log, SLOT(recordConnectClose(int)));
    QObject::connect(panel, SIGNAL(recordOpenDoor(int)), log, SLOT(recordOpenWithKey(int)));
    QObject::connect(panel, SIGNAL(recordWrongKey(int)), log, SLOT(recordWrongKey(int)));
    QObject::connect(panel, SIGNAL(bCallClick()), intercom, SLOT(show()));

    panel->show();
    log->show();
}

void IntercomBuilder::setFloors(int num) {
    this->floors = num;
}

void IntercomBuilder::setAparts(int num) {
    this->aparts = num;
}

void IntercomBuilder::setKey(int num) {
    this->key = num;
}

Intercom IntercomBuilder::build() {
    return Intercom(aparts, floors, key);
}

IntercomConfig::IntercomConfig() {
    config = new QFile("config.cfg");
    config->open(QIODevice::ReadOnly);
    cfg.setDevice(config);
    cfg >> aparts >> floors >> key;
    builder.setAparts(aparts);
    builder.setFloors(floors);
    builder.setKey(key);
}

Intercom IntercomConfig::getResult() {
    return builder.build();
}
