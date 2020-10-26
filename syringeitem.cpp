#include "syringeitem.h"
#include <QTimer>

SyringeItem::SyringeItem(QObject *parent) : QObject(parent) {
    side = true; // syringe is on the right
    angle  = 1;
    goingDown = false;
    setPixmap((QPixmap(":/images/syringe.png")).scaled(120, 142));

    QTimer* rotationTimer = new QTimer();
    QObject::connect( rotationTimer, SIGNAL(timeout()), this, SLOT(timeoutRotate()));
    rotationTimer->start(90);
}

void SyringeItem::keyPressEvent(QKeyEvent *event){
    //Shoots syringe when we press ENTER
    if (event->key()==Qt::Key_Enter){
        moveSyringe(side);
    }
    // Now we change the side that we are on and also the syringe rotation
    if(side){
        setRotation(0);
        side = false;
    } else{
        setRotation(0);
        side = true;
    }
}

void SyringeItem::moveSyringe(bool side){
    // Base case 1: syringe cant go beyond x=400
    if (x()<400){
        return ;
    }
    // Base case 2: syringe cant go beyond x=730
    else if (x()>730){
        return;
    }
    else{
        // if side is True then we are on the right and need to go left
        if (side){
            setPos(x()-20, y()+10);
            moveSyringe(side);
        }
        else{
            setPos(x()+20, y()+10);
            moveSyringe(side);
        }
    }
}


void SyringeItem::timeoutRotate(){
    // rotation if it is on the right side
    if (side){
        if(angle>=90 and goingDown==false){
            goingDown = true;
            angle = angle - 3;
            setRotation(-angle);
        }
        if (angle<90 and goingDown==false){
            angle = angle + 3;
            setRotation( -angle);
        }
        if (angle<90 and angle>0 and goingDown==true){
            angle = angle - 3;
            setRotation(-angle);
        }
        if (angle<=0){
            goingDown = false;
        }

    }
    // rotation if on left side
    else{

    }

}
