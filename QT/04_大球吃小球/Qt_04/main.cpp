#include "mainwidget.h"
#include <iostream>
// 必须的头文件
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5
#include <QApplication>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h >
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    MainWidget w;   //执行mainWidget的构造函数

    w.show();
    return a.exec();
}
