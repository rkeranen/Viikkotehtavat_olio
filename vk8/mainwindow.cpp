#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    {
    ui->setupUi(this);
    pQTimer = new QTimer(this);
      
    // Timeout-signaali timeout-slottiin
    connect(pQTimer, &QTimer::timeout, this, &MainWindow::timeout);

    // Alustetaan käyttöliittymä
    setGameInfoText("Select playtime and press START GAME", 12);
    ui->progressBar1->setValue(0);
    ui->progressBar2->setValue(0);

    // Ajanvalinta
    connect(ui->sec120, &QPushButton::clicked, [this]() {
        gameTime = 120;
        player1Time = gameTime;
        player2Time = gameTime;
        updateProgressBar();
        setGameInfoText("Ready to play", 14);
    });

    connect(ui->min5, &QPushButton::clicked, [this]() {
        gameTime = 300;
        player1Time = gameTime;
        player2Time = gameTime;
        updateProgressBar();
        setGameInfoText("Ready to play", 14);
    });

    // Pelin hallinta
    connect(ui->STARTGAME, &QPushButton::clicked, [this]() {
        if (gameTime > 0) {
            currentPlayer = 1;
            pQTimer->start(1000);
            setGameInfoText("Game ongoing", 14);
        }
    });

    connect(ui->STOPGAME, &QPushButton::clicked, [this]() {
        pQTimer->stop();
        gameTime = 0;
        setGameInfoText("Select playtime and press start game!", 12);
    });

    // Vuoron vaihto
    connect(ui->Sp1, &QPushButton::clicked, [this]() { currentPlayer = 2; });
    connect(ui->Sp2, &QPushButton::clicked, [this]() { currentPlayer = 1; });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeout()
{
    // Vähennetään aikaa siltä pelaajalta, jonka vuoro on
    if (currentPlayer == 1) {
        player1Time--;
    } else {
        player2Time--;
    }

    updateProgressBar();

    // Tarkistus loppuiko aika
    if (player1Time <= 0) {
        pQTimer->stop();
        setGameInfoText("Player 2 WON!!", 16);
    } else if (player2Time <= 0) {
        pQTimer->stop();
        setGameInfoText("Player 1 WON!!", 16);
    }
}

void MainWindow::updateProgressBar()
{
    // Lasketaan prosentit ja päivitetään palkit
    if (gameTime > 0) {
        ui->progressBar1->setValue((player1Time * 100) / gameTime);
        ui->progressBar2->setValue((player2Time * 100) / gameTime);
    }
}

void MainWindow::setGameInfoText(QString text, short fontSize)
{
    // Ohjetekstin ja sen fonttikoon päivitys
    ui->label->setText(text);
    QFont font = ui->label->font();
    font.setPointSize(fontSize);
    ui->label->setFont(font);
}
