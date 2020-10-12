#ifndef INTROWIDGET_H
#define INTROWIDGET_H

#include <QWidget>
#include <QtWidgets>
#include <QMediaPlayer>

class IntroWidget : public QWidget
{
    Q_OBJECT
public:
    explicit IntroWidget(QWidget *parent = nullptr);

    QLabel* titleLabel;
    QPushButton* playButton;

    QMediaPlayer* musicPlayer;

private:
    void centerWindow();
    void setupBackground();
    void setupWidgets();
    void setupStylesheet();
    void setupLayout();
    void setupConnections();
    void setupMusic();
    void keyPressEvent(QKeyEvent *event);


public slots:
    void clickPlay();

signals:

};

#endif // INTROWIDGET_H
