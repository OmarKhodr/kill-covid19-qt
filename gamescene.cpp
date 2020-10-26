#include "gamescene.h"

GameScene::GameScene() {
    setBackgroundBrush(QBrush(QImage(":/images/background.png").scaledToHeight(720).scaledToWidth(1280)));
    setSceneRect(0,0,1280,720);

    syringe = new SyringeItem();
    syringe->setPos(730, 500);
    syringe->setRotation(syringe->rotation() - 45);
    syringe->setFlag(QGraphicsItem::ItemIsFocusable);
    syringe->setFocus();
    addItem(syringe);

    virus = new VirusItem();
    virus->setPos(400, 200);
    addItem(virus);


}
