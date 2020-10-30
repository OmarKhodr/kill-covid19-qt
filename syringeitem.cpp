#include "syringeitem.h"
#include <QTimer>

SyringeItem::SyringeItem(QObject *parent) : QObject(parent) {
    setPixmap((QPixmap(":/images/syringe.png")).scaled(120, 142));

    setTransformOriginPoint(pixmap().width()/2, pixmap().height()/2);
    setRotation(rotation()-45);
}
