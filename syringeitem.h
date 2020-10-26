#ifndef SYRINGEITEM_H
#define SYRINGEITEM_H

#include <QObject>
#include <QtWidgets>

class SyringeItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit SyringeItem(QObject *parent = nullptr);

private:
    void keyPressEvent(QKeyEvent *event);
    void moveSyringe(bool side);
    bool side;
    int angle;
    bool goingDown;

private slots:
    void timeoutRotate();

signals:

};

#endif // SYRINGEITEM_H
