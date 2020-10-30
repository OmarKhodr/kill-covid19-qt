#include "gamescene.h"
#include <QtMath>

GameScene::GameScene() {

    setupBackground();
    setupItems();
    setupState();

}

void GameScene::setupBackground() {
    setBackgroundBrush(QBrush(QImage(":/images/background.png").scaledToHeight(720).scaledToWidth(1280)));
    setSceneRect(0,0,1280,720);

    setFocus();
}

void GameScene::setupItems() {
    syringe = new SyringeItem();
    syringe->setPos(800, 500);
    addItem(syringe);

    virus = new VirusItem();
    virus->setPos(400, 200);
    addItem(virus);

    smallCounterLabel = new QLabel("Small kills : 0");
    smallCounterLabel->setStyleSheet("font: 27px;");
    QGraphicsProxyWidget * smallItem = addWidget(smallCounterLabel);
    smallItem->setPos(100, 100);

    mediumCounterLabel= new QLabel("Medium kills : 0");
    mediumCounterLabel->setStyleSheet("font: 27px;");
    QGraphicsProxyWidget * medItem = addWidget(mediumCounterLabel);
    medItem->setPos(100, 150);

    largeCounterLabel= new QLabel("Large kills : 0");
    largeCounterLabel->setStyleSheet("font: 27px;");
    QGraphicsProxyWidget * largeItem = addWidget(largeCounterLabel);
    largeItem->setPos(100, 200);

    totalCounterLabel= new QLabel("Total score : 0");
    totalCounterLabel->setStyleSheet("font: 27px;");
    QGraphicsProxyWidget * totalItem = addWidget(totalCounterLabel);
    totalItem->setPos(100, 250);
}

void GameScene::setupState() {
    syringeDirection = 0.5;
    syringeShot = false;

    QTimer* updateTimer = new QTimer();
    QObject::connect(updateTimer, SIGNAL(timeout()), this, SLOT(updateScene()));
    updateTimer->start(10);
}

void GameScene::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        syringeShot = true;
    }
}

void GameScene::updateScene() {
    if (!syringeShot) {
        if (syringe->rotation() == -90 || syringe->rotation() == -20) {
            syringeDirection = - syringeDirection;
        }
        syringe->setRotation(syringe->rotation() + syringeDirection);

    } else {
        syringe->setPos(syringe->x()-7, syringe->y()+qTan(qDegreesToRadians(90-syringe->rotation()))*7);
    }

//    syringe->setPos(syringe->x(), syringe->y()+0.5);
//    virus->setPos(virus->x(), virus->y()+0.5);

}
