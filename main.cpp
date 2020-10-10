#include <QApplication>
#include <QGraphicsView>
#include "mainmenu.h"
#include "difficultywindow.h"
#include "introwidget.h"

int main(int argc,char** argv){
    QApplication app(argc, argv);

//    QGraphicsView* view= new QGraphicsView();

//    Mainmenu *scene1 = new Mainmenu();
//    view->setScene(scene1);
//    view->setFixedSize(500, 282);
//    view->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
//    view->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
//    view->show();

    IntroWidget* intro = new IntroWidget();
    intro->setWindowTitle("Kill COVID-19");
    intro->show();

    return app.exec();
}

