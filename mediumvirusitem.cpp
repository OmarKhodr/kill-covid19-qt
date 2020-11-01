#include "mediumvirusitem.h"

mediumVirusItem::mediumVirusItem(QObject *parent) : QObject(parent) {
    setPixmap((QPixmap(":/images/mediumVirus.png")).scaled(130, 130));
}
