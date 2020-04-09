#ifndef COLORTHREAD_H
#define COLORTHREAD_H

#include <QMainWindow>
#include <QGraphicsScene>

class colorThread : public QObject
{
Q_OBJECT
public:
    colorThread(int color);
    int color;
public slots:
    void changeColor();
signals:
    void send(int color);
};

#endif // COLORTHREAD_H
