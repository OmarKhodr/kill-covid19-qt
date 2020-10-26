#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QtWidgets>
#include <syringeitem.h>
#include <virusitem.h>

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GameScene();

    SyringeItem* syringe;
    VirusItem* virus;
    QLabel* smallCounterLabel;
    QLabel* mediumCounterLabel;
    QLabel* largeCounterLabel;
    QLabel* totalCounterLabel;

};

#endif // GAMESCENE_H
