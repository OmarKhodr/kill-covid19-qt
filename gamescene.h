#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QtWidgets>
#include <syringeitem.h>
#include <virusitem.h>
#include "mediumvirusitem.h"
#include "largevirusitem.h"
#include <stainitem.h>

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GameScene();

    SyringeItem* syringe;
    VirusItem* virus;
    int smallScore;
    int mediumScore;
    int largeScore;
    int totalScore;
    int misses;
    QLabel* missesLabel;
    QLabel* smallCounterLabel;
    QLabel* mediumCounterLabel;
    QLabel* largeCounterLabel;
    QLabel* totalCounterLabel;

    double syringeDirection;
    bool syringeShot;
    bool syringeSide;
    int fallingRate;

    void keyPressEvent(QKeyEvent *event) override;

    void setupBackground();
    void setupItems();
    void setupState();

private slots:
    void updateScene();


};

#endif // GAMESCENE_H
