#include "mythread.h"
#include <QThread>
#include<QDebug>
#include <synchapi.h>
myThread::myThread(QObject *parent) : QThread(parent)
{
 //MyThread::run();
}
void myThread::run()
{

    //很复杂的数据处理
    //需要耗时5秒


    while(1){


        emit bian();

 Sleep(100);

    }

    //emit isDone();  //发送完成信号
}
