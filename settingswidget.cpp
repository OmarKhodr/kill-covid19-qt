#include "settingswidget.h"

SettingsWidget::SettingsWidget(QWidget *parent) : QWidget(parent) {

    setupBackground();
    setupWidgets();
    setupStylesheet();
    setupLayout();
    centerWindow();

}

void SettingsWidget::setupBackground() {
    QPixmap bkgnd(":/images/intro-background.jpeg");
//    bkgnd = bkgnd.scaled(QSize(500, 282), Qt::KeepAspectRatio);

    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);

    this->setPalette(palette);
}

void SettingsWidget::setupWidgets() {
    titleLabel = new QLabel("Choose your difficulty");
    titleLabel->setStyleSheet("color: white;"
                              "font: bold 27px;");
    easyButton = new QPushButton("Easy");
    mediumButton = new QPushButton("Medium");
    hardButton = new QPushButton("Hard");
    explainDiffLabel = new QLabel();
}

void SettingsWidget::setupStylesheet() {
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

void SettingsWidget::setupLayout() {
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->addWidget(titleLabel);
    vbox->addWidget(easyButton);
    vbox->addWidget(mediumButton);
    vbox->addWidget(hardButton);
    vbox->addWidget(explainDiffLabel);
}


void SettingsWidget::centerWindow() {
        setGeometry(
            QStyle::alignedRect(
                Qt::LeftToRight,
                Qt::AlignCenter,
                this->size(),
                qApp->desktop()->availableGeometry()
            )
        );
}
