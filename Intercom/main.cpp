#include <QApplication>
#include "Intercom.h"


//THE PASSWORD OF THE DOOR IS 112233
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    IntercomConfig cfg;
    Intercom intercom = cfg.getResult();

    return app.exec();
}
