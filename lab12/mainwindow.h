#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMutex>
#include <QThread>
#include <colorthread.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void updateCol(int color);
signals:
    void updateScene();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *sc;
    QThread *thread1= new QThread;
    QThread *thread2= new QThread;
    QThread *thread3= new QThread;
    QMutex mutex;

    colorThread *color1;
    colorThread *color2;
    colorThread *color3;


};
#endif // MAINWINDOW_H
