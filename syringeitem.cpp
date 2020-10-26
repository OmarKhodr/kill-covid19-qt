#include "syringeitem.h"

SyringeItem::SyringeItem(QObject *parent) : QObject(parent) {
    setPixmap((QPixmap(":/images/syringe.png")).scaled(120, 142));
}
