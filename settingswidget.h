#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QWidget>
#include <QtWidgets>

class SettingsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SettingsWidget(QWidget *parent = nullptr);

    bool readyButtonAvailable;
    QLabel* titleLabel;
    QPushButton* easyButton;
    QPushButton* mediumButton;
    QPushButton* hardButton;
    QPushButton* readyButton;
    QLabel* explainDiffLabel;
    QString difficultyChosen;
    QVBoxLayout* vbox;

private:
    void setupBackground();
    void setupWidgets();
    void setupStylesheet();
    void setupLayout();
    void centerWindow();
    void setupConnections();
    void showReadyButton();


private slots:
    void clickEasy();
    void clickMedium();
    void clickHard();
    void clickReady();


signals:

};

#endif // SETTINGSWIDGET_H
