#include "gameview.h"

#include <gamescene.h>

GameView::GameView() {
    setFixedSize(1280, 720);
    setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));

    GameScene* scene = new GameScene();
    setScene(scene);

    centerWindow();
}

void GameView::centerWindow() {
    setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
        )
    );
}
