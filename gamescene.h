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
    stainItem* stain;
    int smallScore;
    int mediumScore;
    int largeScore;
    int totalScore;
    int winningScore;
    int misses;
    int maxMisses;
    QLabel* missesLabel;
    QLabel* smallCounterLabel;
    QLabel* mediumCounterLabel;
    QLabel* largeCounterLabel;
    QLabel* totalCounterLabel;
    QVector<QPair<int, int>*>* viruses;

    QGraphicsProxyWidget* popupItem;

    double syringeDirection;
    bool syringeShot;
    bool syringeSide;
    bool hitVirus;
    double fallingRate;
    int virusType;
    int waiting;
    int killedViruses;
    int virusCounter;

    QTimer* updateTimer;

    void keyPressEvent(QKeyEvent *event) override;

    void setupBackground();
    void setupConfig();
    void setupState();
    void setupItems();
    void startTimer();

private slots:
    void updateScene();


};

#endif // GAMESCENE_H
