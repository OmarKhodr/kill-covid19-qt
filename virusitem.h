#ifndef VIRUSITEM_H
#define VIRUSITEM_H

#include <QObject>
#include <QtWidgets>

class VirusItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit VirusItem(QObject *parent = nullptr);

signals:

};

#endif // VIRUSITEM_H
