#include "stainitem.h"

stainItem::stainItem(QObject *parent) : QObject(parent){

    setPixmap((QPixmap(":/images/stain.png")).scaled(160, 160));
}
