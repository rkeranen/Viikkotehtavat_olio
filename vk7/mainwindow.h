#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QString number1;
    QString number2;
    int state = 1;
    float result = 0;
    short operand = 0;

private slots:
    void numberClickHandler();
    void clearAndEnterClickHandler();
    void addSubMulDivClickHandler();

private:
    void resetLineEdits();
};

#endif
