#include "widget.h"

#include <QApplication>


#include "sum_01.h"
#include "sum_02.h"
#include <iostream>
// 必须的头文件
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h >
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    sum_01 w1;
    w1.show();
    sum_02 w2;
    w2.show();
    return a.exec();
}
