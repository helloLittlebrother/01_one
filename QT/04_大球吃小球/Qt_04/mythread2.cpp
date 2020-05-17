#include "mythread2.h"
#include <QThread>
#include<QDebug>
#include <synchapi.h>
MyThread2::MyThread2(QObject *parent) : QThread(parent)
{

}
void MyThread2::run()
{



    while(1){
        int a;
        char s;
        qDebug() << "23232323232323232" << endl;

        scanf("%s",&s);
         qDebug() << "12121212" << endl;
          qDebug() <<s;
        if(s=='w'){
            emit bian2(1);
        }
        if(s=='s'){
            emit bian2(2);
        }
        if(s=='a'){
            emit bian2(3);
        }
        if(s=='d'){
            emit bian2(4);
        }


 Sleep(100);

    }
}
