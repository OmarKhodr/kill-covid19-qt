#include "largevirusitem.h"

largeVirusItem::largeVirusItem(QObject *parent) : QObject(parent) {
    setPixmap((QPixmap(":/images/largeVirus.png")).scaled(160, 160));
}

