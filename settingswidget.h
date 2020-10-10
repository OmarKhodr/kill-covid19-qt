#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QWidget>
#include <QtWidgets>

class SettingsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SettingsWidget(QWidget *parent = nullptr);

    QLabel* titleLabel;
    QPushButton* easyButton;
    QPushButton* mediumButton;
    QPushButton* hardButton;
    QLabel* explainDiffLabel;
    QString difficultyChosen;

private:
    void setupBackground();
    void setupWidgets();
    void setupStylesheet();
    void setupLayout();
    void centerWindow();
    void setupConnections();

signals:

};

#endif // SETTINGSWIDGET_H
