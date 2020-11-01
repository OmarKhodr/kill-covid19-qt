#include "gamescene.h"
#include <QtMath>

GameScene::GameScene() {

    misses = 0;
    smallScore = 0;
    mediumScore = 0;
    largeScore = 0;
    totalScore = 0;
    syringeSide = 1;     // starts at the right side
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

    missesLabel = new QLabel("Misses : "+ QString::number(misses));
    missesLabel->setStyleSheet("font: 27px;");
    QGraphicsProxyWidget * missesItem = addWidget(missesLabel);
    missesItem->setPos(100, 50);

    smallCounterLabel = new QLabel("Small kills : "+ QString::number(smallScore));
    smallCounterLabel->setStyleSheet("font: 27px;");
    QGraphicsProxyWidget * smallItem = addWidget(smallCounterLabel);
    smallItem->setPos(100, 100);

    mediumCounterLabel= new QLabel("Medium kills : "+ QString::number(mediumScore));
    mediumCounterLabel->setStyleSheet("font: 27px;");
    QGraphicsProxyWidget * medItem = addWidget(mediumCounterLabel);
    medItem->setPos(100, 150);

    largeCounterLabel= new QLabel("Large kills : "+ QString::number(largeScore));
    largeCounterLabel->setStyleSheet("font: 27px;");
    QGraphicsProxyWidget * largeItem = addWidget(largeCounterLabel);
    largeItem->setPos(100, 200);

    totalCounterLabel= new QLabel("Total score : "+ QString::number(totalScore));
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

    } else if(syringeShot and syringeSide==true) {
        syringe->setPos(syringe->x()-7, syringe->y()+qTan(qDegreesToRadians(90-syringe->rotation()))*7);
        if (syringe->x()<=400){
            QList<QGraphicsItem*> list1 = syringe->collidingItems();
            bool collided = 0;
            for(int i = 0; i<list1.size() ; i++) {
                // if collides with small virus
                if( typeid(*(list1[i]) ) == typeid(VirusItem)){
                    smallScore ++;
                    collided = true;
                    stainItem * stain = new stainItem();
                    stain->setPos(virus->x(), virus->y() );
                    delete list1[i];
                    addItem(stain);
                }
                // if collides with medium virus
                if( typeid(*(list1[i]) ) == typeid(mediumVirusItem)){
                    mediumScore ++;
                    collided = true;
                    stainItem * stain = new stainItem();
                    stain->setPos(virus->x(), virus->y() );
                    delete list1[i];
                    addItem(stain);
                }
                // if collides with large virus
                if( typeid(*(list1[i]) ) == typeid(largeVirusItem)){
                    largeScore ++;
                    collided = true;
                    stainItem * stain = new stainItem();
                    stain->setPos(virus->x(), virus->y() );
                    delete list1[i];
                    addItem(stain);
                }
            }
            if (collided==false){
                misses ++;
            }
            syringeSide = 0;
            removeItem(syringe);
        }
    } else if(syringeShot and syringeSide==false) {
        syringe->setPos(syringe->x()-7, syringe->y()+qTan(qDegreesToRadians(90+syringe->rotation()))*7);
        if (syringe->x()>=800){
            QList<QGraphicsItem*> list1 = syringe->collidingItems();
            bool collided = 0;
            for(int i = 0; i<list1.size() ; i++) {
                // if collided with small virus
                if( typeid(*(list1[i]) ) == typeid(VirusItem)){
                    smallScore ++;
                    collided = true;
                    stainItem * stain = new stainItem();
                    stain->setPos(virus->x(), virus->y() );
                    delete list1[i];
                    addItem(stain);
                }
                // if collides with medium virus
                if( typeid(*(list1[i]) ) == typeid(mediumVirusItem)){
                    mediumScore ++;
                    collided = true;
                    stainItem * stain = new stainItem();
                    stain->setPos(virus->x(), virus->y() );
                    delete list1[i];
                    addItem(stain);
                }
                // if collides with large virus
                if( typeid(*(list1[i]) ) == typeid(largeVirusItem)){
                    largeScore ++;
                    collided = true;
                    stainItem * stain = new stainItem();
                    stain->setPos(virus->x(), virus->y() );
                    delete list1[i];
                    addItem(stain);
                }
            }
            if (collided==false){
                misses ++;
            }
            syringeSide = 1;
            removeItem(syringe);
        }
    }

    // updates score
    totalScore = smallScore*3 + mediumScore*5 + largeScore*7;
    smallCounterLabel->setText("Small kills : "+ QString::number(smallScore));
    mediumCounterLabel->setText("Medium kills : "+ QString::number(mediumScore));
    largeCounterLabel->setText("Large kills : "+ QString::number(largeScore));
    totalCounterLabel->setText("Total score : "+ QString::number(totalScore));
    missesLabel->setText("Misses : " + QString::number(misses));

//    syringe->setPos(syringe->x(), syringe->y()+0.5);
//    virus->setPos(virus->x(), virus->y()+0.5);

}
