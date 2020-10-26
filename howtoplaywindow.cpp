#include "howtoplaywindow.h"

howToPlayWindow::howToPlayWindow(QWidget *parent) : QWidget(parent)
{
    setFixedSize(500, 282);
    centerWindow();
    setupBackground();
    setupWidgets();
    setupLayout();


}

void howToPlayWindow::setupBackground() {
    QPixmap bkgnd(":/images/intro-background.jpeg");
    bkgnd = bkgnd.scaled(QSize(500, 282), Qt::KeepAspectRatio);

    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);

    this->setPalette(palette);
}

void howToPlayWindow::centerWindow() {
        setGeometry(
            QStyle::alignedRect(
                Qt::LeftToRight,
                Qt::AlignCenter,
                this->size(),
                qApp->desktop()->availableGeometry()
            )
        );
}



void howToPlayWindow::setupWidgets(){
    titleLabel = new QLabel("How To Play");
    titleLabel->setStyleSheet("color: white;"
                              "font: bold 27px;");
    titleLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    explainLabel = new QLabel(" - Press ENTER to shoot the syringe");
    explainLabel->setStyleSheet("color: white;"
                              "font: 15px;");
    titleLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}



void howToPlayWindow::setupLayout(){
    verticalLayout = new QVBoxLayout(this);
    verticalLayout->addWidget(titleLabel);
    verticalLayout->addWidget(explainLabel);

    verticalLayout->setAlignment(titleLabel, Qt::AlignHCenter);
    verticalLayout->setAlignment(explainLabel, Qt::AlignHCenter);
}
