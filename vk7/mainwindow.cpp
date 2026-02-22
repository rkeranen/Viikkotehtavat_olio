#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Numero-napit
    connect(ui->N0, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N1, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N2, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N3, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N4, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N5, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N6, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N7, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N8, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N9, &QPushButton::clicked, this, &MainWindow::numberClickHandler);

    // Operaattorit
    connect(ui->add, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->sub, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->mul, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->div, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);

    // Enter ja Clear
    connect(ui->enter, &QPushButton::clicked, this, &MainWindow::clearAndEnterClickHandler);
    connect(ui->clear, &QPushButton::clicked, this, &MainWindow::clearAndEnterClickHandler);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString value = button->text();

    if (state == 1) {
        number1.append(value);
        ui->num1->setText(number1);
    } else {
        number2.append(value);
        ui->num2->setText(number2);
    }
}

void MainWindow::addSubMulDivClickHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    if (number1.isEmpty()) return;

    QString name = button->objectName();

    if (name == "add") operand = 0;
    else if (name == "sub") operand = 1;
    else if (name == "mul") operand = 2;
    else if (name == "div") operand = 3;

    state = 2;
}

void MainWindow::clearAndEnterClickHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString name = button->objectName();

    if (name == "enter") {

        if (number1.isEmpty() || number2.isEmpty()) return;

        float n1 = number1.toFloat();
        float n2 = number2.toFloat();

        if (operand == 0)
            result = n1 + n2;
        else if (operand == 1)
            result = n1 - n2;
        else if (operand == 2)
            result = n1 * n2;
        else if (operand == 3) {
            if (n2 == 0) {
                ui->result->setText("Virhe");
                return;
            }
            result = n1 / n2;
        }

        ui->result->setText(QString::number(result));
    }
    else if (name == "clear") {
        resetLineEdits();
    }
}

void MainWindow::resetLineEdits()
{
    state = 1;
    number1.clear();
    number2.clear();

    ui->num1->clear();
    ui->num2->clear();
    ui->result->clear();
}
