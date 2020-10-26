#include "gamescene.h"

GameScene::GameScene() {
    setBackgroundBrush(QBrush(QImage(":/images/background.png").scaledToHeight(720).scaledToWidth(1280)));
    setSceneRect(0,0,1280,720);

    syringe = new SyringeItem();
    syringe->setFlag(QGraphicsItem::ItemIsFocusable);
    syringe->setFocus();
    syringe->setPos(730, 500);
    syringe->setRotation(syringe->rotation() + 45);
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
