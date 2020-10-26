#include "virusitem.h"

VirusItem::VirusItem(QObject *parent) : QObject(parent) {
    setPixmap((QPixmap(":/images/virus.png")).scaled(100, 100));
}
