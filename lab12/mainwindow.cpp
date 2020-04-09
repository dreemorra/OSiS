#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <unistd.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sc = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(sc);

    color1 = new colorThread(0);
    color2 = new colorThread(1);
    color3 = new colorThread(2);

    color1->moveToThread(thread1);
    color2->moveToThread(thread2);
    color3->moveToThread(thread3);

    connect(thread1, SIGNAL(started()), color1, SLOT(changeColor()));
    connect(thread2, SIGNAL(started()), color2, SLOT(changeColor()));
    connect(thread3, SIGNAL(started()), color3, SLOT(changeColor()));

    connect(color1, SIGNAL(send(int)), this, SLOT(updateCol(int)));
    connect(color2, SIGNAL(send(int)), this, SLOT(updateCol(int)));
    connect(color3, SIGNAL(send(int)), this, SLOT(updateCol(int)));

    thread1->start();
    thread2->start();
    thread3->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateCol(int color) {
    mutex.lock();
    qDebug() << "repaint";
    if (color == 0) sc->setBackgroundBrush(QBrush(Qt::red));
    else if (color == 1) sc->setBackgroundBrush(QBrush(Qt::blue));
    else sc->setBackgroundBrush(QBrush(Qt::green));
    repaint();
    mutex.unlock();
}
