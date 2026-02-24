#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void timeout();

private:
    Ui::MainWindow *ui;

    short player1Time;
    short player2Time;
    short currentPlayer;
    short gameTime;
    QTimer *pQTimer;

    void updateProgressBar();
    void setGameInfoText(QString text, short fontSize);
};

#endif
