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

    double syringeDirection;
    bool syringeShot;
    int fallingRate;

    void keyPressEvent(QKeyEvent *event) override;

    void setupBackground();
    void setupItems();
    void setupState();

private slots:
    void updateScene();


};

#endif // GAMESCENE_H
