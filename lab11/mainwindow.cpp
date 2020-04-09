#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_pushButton_clicked() {
    scene1 = new QGraphicsScene(ui->graphicsView);
    scene2 = new QGraphicsScene(ui->graphicsView_2);
    scene3 = new QGraphicsScene(ui->graphicsView_3);
    scene4 = new QGraphicsScene(ui->graphicsView_4);

    ui->graphicsView->setScene(scene1);
    ui->graphicsView_2->setScene(scene2);
    ui->graphicsView_3->setScene(scene3);
    ui->graphicsView_4->setScene(scene4);

    QThread *thread = new QThread;
    MyClass *my_class = new MyClass(scene1, 1000);
    QThread *thread2 = new QThread;
    QThread *thread3 = new QThread;
    QThread *thread4 = new QThread;
    MyClass *my_class2 = new MyClass(scene2, 500);
    MyClass *my_class3 = new MyClass(scene3, 700);
    MyClass *my_class4 = new MyClass(scene4, 300);

    my_class->moveToThread(thread);
    my_class2->moveToThread(thread2);
    my_class3->moveToThread(thread3);
    my_class4->moveToThread(thread4);

    connect(thread, SIGNAL(started()), my_class, SLOT(doWork())); connect(my_class, SIGNAL(send(int)), this, SLOT(update(int)));
    connect(thread2, SIGNAL(started()), my_class2, SLOT(doWork())); connect(my_class2, SIGNAL(send(int)), this, SLOT(update(int)));
    connect(thread3, SIGNAL(started()), my_class3, SLOT(doWork())); connect(my_class3, SIGNAL(send(int)), this, SLOT(update(int)));
    connect(thread4, SIGNAL(started()), my_class4, SLOT(doWork())); connect(my_class4, SIGNAL(send(int)), this, SLOT(update(int)));

    thread->start();
    thread2->start();
    thread3->start();
    thread4->start();

    ui->pushButton->setEnabled(false);
}


void MainWindow::update (int i) {
    repaint();
    qDebug() << i;
}
