#include "introwidget.h"

#include <QStyle>
#include <QMediaPlaylist>

#include<settingswidget.h>

IntroWidget::IntroWidget(QWidget *parent) : QWidget(parent) {

    setFixedSize(500, 282);

    setupBackground();
    setupWidgets();
    setupStylesheet();
    setupLayout();
    centerWindow();
    setupConnections();
    setupMusic();

}


void IntroWidget::setupBackground() {
    QPixmap bkgnd(":/images/intro-background.jpeg");
    bkgnd = bkgnd.scaled(QSize(500, 282), Qt::KeepAspectRatio);

    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);

    this->setPalette(palette);
}


void IntroWidget::setupWidgets() {
    titleLabel = new QLabel("Kill COVID-19");
    titleLabel->setStyleSheet("color: white;"
                              "font: bold 27px;");
    titleLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    playButton = new QPushButton("Play (or Press F1)");
    playButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

void IntroWidget::setupStylesheet() {
    setStyleSheet("QPushButton {"
                    "background-color: #FFFFFF;"
                    "color: #000000;"
                    "border-radius: 3px;"
                    "min-width: 11em;"
                    "padding: 6px;"
                  "}"
                  "QPushButton:pressed {"
                    "background-color: #C4C4C4;"
                  "}");
}


void IntroWidget::setupLayout() {
    QVBoxLayout* innervbox = new QVBoxLayout();
    innervbox->addWidget(titleLabel, 1, Qt::AlignRight);
    innervbox->addWidget(playButton, 0, Qt::AlignRight);

    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->addStretch(1);
    vbox->addLayout(innervbox);
    vbox->addStretch(1);
}


void IntroWidget::centerWindow() {
        setGeometry(
            QStyle::alignedRect(
                Qt::LeftToRight,
                Qt::AlignCenter,
                this->size(),
                qApp->desktop()->availableGeometry()
            )
        );
}

void IntroWidget::setupConnections() {
    QObject::connect(playButton, SIGNAL(clicked(bool)), this, SLOT(clickPlay()));
}

void IntroWidget::clickPlay() {
    SettingsWidget* settings = new SettingsWidget();
    settings->show();
    this->close();
}

void IntroWidget::setupMusic() {
    QMediaPlaylist* playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/intro-music.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    musicPlayer = new QMediaPlayer();
    musicPlayer->setPlaylist(playlist);
    musicPlayer->play();
}
