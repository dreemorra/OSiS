#include "colorthread.h"
#include <unistd.h>
#include <QDebug>

colorThread::colorThread(int color)
{
    this->color = color;
}

void colorThread::changeColor() {
    forever {
        emit send(color);
        qDebug() << "send";
        usleep(1e6);
    }
}
