#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QtWidgets>

class GameView : public QGraphicsView
{
    Q_OBJECT
public:
    GameView();

private:
    void centerWindow();
};

#endif // GAMEVIEW_H
