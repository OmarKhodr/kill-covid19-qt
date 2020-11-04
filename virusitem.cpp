#include "virusitem.h"

VirusItem::VirusItem(QObject *parent, int type) : QObject(parent) {
    QString imageStr;
    if (type == 0) {
        imageStr = ":/images/virus.png";
    } else if (type == 1) {
        imageStr = ":/images/mediumVirus.png";
    } else {
        imageStr = ":/images/largeVirus.png";
    }
    setPixmap((QPixmap(imageStr)).scaled(100+type*10, 100+type*10));
}
