#include "sum_01.h"
//构造函数
#include<QHostAddress>

#include<QDebug>
#include <iostream>
#include <thread>
#include<windows.h>


#include<QPainter>
#include<QThread>

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<QKeyEvent>
int saa=0;
int sbb=50;
int scc=300;
int sdd=50;
int see=250;
int sff=250;
struct locus{
    int bd = 0;
    int cd=0;

    int sa=0;
    int sb=50;
    int sab=50;

    int sc=300;
    int sd=50;
    int scd=45;

    int se=500;
    int sf=500;
    int sef=60;

    int sg=130;
    int sh=90;
    int sgh=35;
}noww;
sum_01::sum_01(QWidget *parent) : QWidget(parent)
{
    int qwe=1111;
    tcpSocket=NULL;
    tcpSocket = new QTcpSocket(this);
    QString aaa="192.168.1.102";
    tcpSocket->connectToHost(QHostAddress(aaa),2222);
    connect(tcpSocket,&QTcpSocket::connected,[=](){
        tcpSocket->write("1111111");
        qDebug() <<qwe;

    });

    connect(tcpSocket,&QTcpSocket::readyRead,
            [=]() mutable
    {
        qDebug() << "2222收到";
        QByteArray array2=tcpSocket->readAll();//取
        locus *now4=(locus*)array2.data();
        qDebug() << "2222原来的数据↓";
        qDebug() << noww.se;
        qDebug() << noww.sf;
        qDebug() << noww.sg;
        qDebug() << noww.sh;
        qDebug() << "2222原来的数据↑";
        qDebug() << "2222收到的数据↓";
        qDebug() << now4->se;
        qDebug() << now4->sf;
        qDebug() << now4->sg;
        qDebug() << now4->sh;
        qDebug() << "2222收到的数据↑";

        noww=*now4;
        qDebug() << "2222改变后的数据↓";
        qDebug() << noww.se;
        qDebug() << noww.sf;
        qDebug() << noww.sg;
        qDebug() << noww.sh;
        qDebug() << "2222改变后的数据↑";
        QWidget::repaint();
    });

}
void sum_01::keyPressEvent(QKeyEvent *e)   //键盘移动
{
    switch(e->key()){
        case Qt::Key_W :noww.sh-=10; tcpSocket->write("11");  break;
        case Qt::Key_S :noww.sh+=10; tcpSocket->write("22");  break;
        case Qt::Key_A :noww.sg-=10; tcpSocket->write("33");  break;
        case Qt::Key_D :noww.sg+=10; tcpSocket->write("44");  break;
    }
    QWidget::repaint();
}
void sum_01::paintEvent(QPaintEvent *)//paintEvent函数由系统自动调用
{
    paint1=new QPainter;
    paint2=new QPainter;
    paint3=new QPainter;
    paint1->begin(this);
    paint1->setPen(QPen(Qt::red,4,Qt::SolidLine)); //设置画笔形式
    paint1->setBrush(QColor(255,0,0));
    paint1->drawEllipse(noww.sa,noww.sb,2*noww.sab,2*noww.sab);
    paint1->setPen(QPen(Qt::red,4,Qt::SolidLine)); //设置画笔形式
    paint1->drawEllipse(noww.sc,noww.sd,2*noww.scd,2*noww.scd);
    paint1->end();
    paint2->begin(this);
    paint2->setPen(QPen(Qt::green,4,Qt::SolidLine)); //设置画笔形式
    paint2->setBrush(QColor(0,255,0));
    paint2->drawEllipse(noww.se,noww.sf,2*noww.sef,2*noww.sef);
    paint2->end();
    paint3->begin(this);
    paint3->setPen(QPen(Qt::blue,4,Qt::SolidLine)); //设置画笔形式
    paint3->setBrush(QColor(0,0,255));
    paint3->drawEllipse(noww.sg,noww.sh,2*noww.sgh,2*noww.sgh);
    paint3->end();
}
