#include "sum_02.h"
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
int a2=0;
int b2=50;
int c2=300;
int d2=50;
int ee2=250;
int f2=250;
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
}nowww;
sum_02::sum_02(QWidget *parent) : QWidget(parent)
{
    int qwe=1111;
    tcpSocket=NULL;
    tcpSocket = new QTcpSocket(this);
    QString asa="192.168.1.102";
    tcpSocket->connectToHost(QHostAddress(asa),1111);
    connect(tcpSocket,&QTcpSocket::connected,[=](){
        tcpSocket->write("1111111");
        qDebug() <<qwe;

    });

    connect(tcpSocket,&QTcpSocket::readyRead,
            [=]() mutable
    {
         qDebug() << "1111收到";
        QByteArray array2=tcpSocket->readAll();//取
        //QByteArray &str;
        //str=&array2;
        locus *now2=(locus*)array2.data();

        nowww=*now2;

         QWidget::repaint();
    });

}
void sum_02::keyPressEvent(QKeyEvent *e)   //键盘移动
{
    switch(e->key()){
        case Qt::Key_W :nowww.sf-=10; tcpSocket->write("11");  break;
        case Qt::Key_S :nowww.sf+=10; tcpSocket->write("22");  break;
        case Qt::Key_A :nowww.se-=10; tcpSocket->write("33");  break;
        case Qt::Key_D :nowww.se+=10; tcpSocket->write("44");  break;
    }
    QWidget::repaint();
}
void sum_02::paintEvent(QPaintEvent *)//paintEvent函数由系统自动调用
{
    paint1=new QPainter;
    paint2=new QPainter;
    paint3=new QPainter;
    paint1->begin(this);
    paint1->setPen(QPen(Qt::red,4,Qt::SolidLine)); //设置画笔形式
    paint1->setBrush(QColor(255,0,0));
    paint1->drawEllipse(nowww.sa,nowww.sb,2*nowww.sab,2*nowww.sab);
    paint1->setPen(QPen(Qt::red,4,Qt::SolidLine)); //设置画笔形式
    paint1->drawEllipse(nowww.sc,nowww.sd,2*nowww.scd,2*nowww.scd);
    paint1->end();
    paint2->begin(this);
    paint2->setPen(QPen(Qt::green,4,Qt::SolidLine)); //设置画笔形式
    paint2->setBrush(QColor(0,255,0));
    paint2->drawEllipse(nowww.se,nowww.sf,2*nowww.sef,2*nowww.sef);
    paint2->end();
    paint3->begin(this);
    paint3->setPen(QPen(Qt::blue,4,Qt::SolidLine)); //设置画笔形式
    paint3->setBrush(QColor(0,0,255));
    paint3->drawEllipse(nowww.sg,nowww.sh,2*nowww.sgh,2*nowww.sgh);
    paint3->end();
}
