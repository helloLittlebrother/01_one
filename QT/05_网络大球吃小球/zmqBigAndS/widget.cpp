#include "widget.h"
#include "ui_widget.h"
//构造函数

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
}now;

void pan(){
    if(((now.sa+now.sab*2)/2-(now.sc+now.scd*2)/2)*((now.sa+now.sab*2)/2-(now.sc+now.scd*2)/2)+((now.sb+now.sab*2)/2-(now.sd+now.scd*2)/2)*((now.sb+now.sab*2)/2-(now.sd+now.scd*2)/2)<(now.sab+now.scd)*(now.sab+now.scd)-10140){
        if(now.sab>now.scd&&now.scd>10){
            now.sab=now.sab+10;
            now.scd=0;
        }
        if(now.sab<now.scd&&now.sab>10){
            now.sab=0;
            now.scd=now.scd+10;
        }
    }

    if(((now.sa+now.sab*2)/2-(now.se+now.sef*2)/2)*((now.sa+now.sab*2)/2-(now.se+now.sef*2)/2)+((now.sb+now.sab*2)/2-(now.sf+now.sef*2)/2)*((now.sb+now.sab*2)/2-(now.sf+now.sef*2)/2)<(now.sab+now.sef)*(now.sab+now.sef)-10140){
        if(now.sab>now.sef&&now.sef>10){
            now.sab=now.sab+10;
            now.sef=0;
        }
        if(now.sab<now.sef&&now.sab>8){
            now.sab=0;
            now.sef=now.sef+10;
        }
    }

    if(((now.sa+now.sab*2)/2-(now.sg+now.sgh*2)/2)*((now.sa+now.sab*2)/2-(now.sg+now.sgh*2)/2)+((now.sb+now.sab*2)/2-(now.sh+now.sgh*2)/2)*((now.sb+now.sab*2)/2-(now.sh+now.sgh*2)/2)<(now.sab+now.sgh)*(now.sab+now.sgh)-10140){
        if(now.sab>now.sgh&&now.sgh>9){
            now.sab=now.sab+10;
            now.sgh=0;
        }
        if(now.sab<now.sgh&&now.sab>9){
            now.sab=0;
            now.sgh=now.sgh+10;
        }
    }

    if(((now.sc+now.scd*2)/2-(now.se+now.sef*2)/2)*((now.sc+now.scd*2)/2-(now.se+now.sef*2)/2)+((now.sd+now.scd*2)/2-(now.sh+now.sef*2)/2)*((now.sd+now.scd*2)/2-(now.sh+now.sef*2)/2)<(now.scd+now.sef)*(now.scd+now.sef)-10140){
        if(now.scd>now.sef&&now.sef>9){
            now.scd=now.scd+10;
            now.sef=0;
        }
        if(now.scd<now.sef&&now.scd>9){
            now.scd=0;
            now.sef=now.sef+10;
        }
    }

    if(((now.sc+now.scd*2)/2-(now.sg+now.sgh*2)/2)*((now.sc+now.scd*2)/2-(now.sg+now.sgh*2)/2)+((now.sd+now.scd*2)/2-(now.sh+now.sgh*2)/2)*((now.sd+now.scd*2)/2-(now.sh+now.sgh*2)/2)<(now.scd+now.sgh)*(now.scd+now.sgh)-10140){
        if(now.scd>now.sgh&&now.sgh>9){
            now.scd=now.scd+10;
            now.sgh=0;
        }
        if(now.scd<now.sgh&&now.scd>9){
            now.scd=0;
            now.sgh=now.sgh+10;
        }
    }

    if(((now.se+now.sef*2)/2-(now.sg+now.sgh*2)/2)*((now.se+now.sef*2)/2-(now.sg+now.sgh*2)/2)+((now.sf+now.sef*2)/2-(now.sh+now.sgh*2)/2)*((now.sf+now.sef*2)/2-(now.sh+now.sgh*2)/2)<(now.sef+now.sgh)*(now.sef+now.sgh)-10140){
        if(now.sef>now.sgh&&now.sgh>9){
            now.sef=now.sef+10;
            now.sgh=0;
        }
        if(now.sef<now.sgh&&now.sef>9){
            now.sef=0;
            now.sgh=now.sgh+10;
        }
    }


}
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    b1.setParent(this);
    b1.setText("开始");
    b1.move(100,300);
    connect(&b1,&QPushButton::released,this,&Widget::relea);

    //接受线程返回的信号      ++--++
    void (myThread::*cg8)()=&myThread::bian;
    connect(v,cg8,this,&Widget::bianbian);

    tcpServer = new QTcpServer (this);
    tcpServer-> listen (QHostAddress :: Any, 1111);
    tcpServer2 = new QTcpServer (this);
    tcpServer2-> listen (QHostAddress :: Any, 2222);

    connect (tcpServer, & QTcpServer :: newConnection,
        [=] () mutable
        {   now.bd=1;
                tcpSocket = tcpServer-> nextPendingConnection ();

    connect(tcpSocket,&QTcpSocket::readyRead,
            [=]() mutable
    {
        QByteArray array=tcpSocket->readAll();//取
        qDebug() << "服务器成功收到1111";
        if(array.toInt()==11){
            now.sf-=10;
            qDebug() << "1111改变了";
        }
        if(array.toInt()==22){
            now.sf+=10;
             qDebug() << "1111改变了";
        }
        if(array.toInt()==33){
            now.se-=10;
             qDebug() << "1111改变了";
        }
        if(array.toInt()==44){
            now.se+=10;
             qDebug() << "1111改变了";
        }
        QWidget::repaint();

        if(now.cd==1){
            QByteArray wds;
             wds.append((char*)&now,sizeof(locus));
             locus *now2=(locus*)wds.data();
             qDebug() << "向2222发送的数据↓";
             qDebug() <<now.se;
             qDebug() <<now.sf;
             qDebug() <<now.sg;
             qDebug() <<now.sh;
             qDebug() <<now2->se;
             qDebug() <<now2->sf;
             qDebug() <<now2->sg;
             qDebug() <<now2->sh;
             qDebug() << "向2222发送的数据↑";
            tcpSocket2->write(wds);//发
            qDebug() << "向2222转发成功";
        }

    });
        }
        );

    connect (tcpServer2, & QTcpServer :: newConnection,
        [=] () mutable
        {   now.cd=1;

        qDebug() << "hhhhhhwdwa";
        tcpSocket2 = tcpServer2-> nextPendingConnection ();

        connect(tcpSocket2,&QTcpSocket::readyRead,
            [=]() mutable
        {
            QByteArray array2=tcpSocket2->readAll();//取
            qDebug() << "服务器成功收到2222";
            if(array2.toInt()==11){
                now.sh-=10;
            }
            if(array2.toInt()==22){
                now.sh+=10;
            }
            if(array2.toInt()==33){
                now.sg-=10;
            }
        if(array2.toInt()==44){
            now.sg+=10;
        }
        QWidget::repaint();
        qDebug() << array2;
        if(now.bd==1){
            QByteArray wds;
            wds.append((char*)&now,sizeof(locus)+1);
            tcpSocket->write(wds);//发
            qDebug() << "向1111转发成功";
        }

    });
        }
        );
}
void Widget::relea()//触发线程
{
    v->start();
}
void Widget::paintEvent(QPaintEvent *)//paintEvent函数由系统自动调用
{
    paint1=new QPainter;
    paint2=new QPainter;
    paint3=new QPainter;
    paint1->begin(this);
    paint1->setPen(QPen(Qt::red,4,Qt::SolidLine)); //设置画笔形式
    paint1->setBrush(QColor(255,0,0));
    paint1->drawEllipse(now.sa,now.sb,2*now.sab,2*now.sab);
    paint1->setPen(QPen(Qt::red,4,Qt::SolidLine)); //设置画笔形式
    paint1->drawEllipse(now.sc,now.sd,2*now.scd,2*now.scd);
    paint1->end();
    paint2->begin(this);
    paint2->setPen(QPen(Qt::green,4,Qt::SolidLine)); //设置画笔形式
    paint2->setBrush(QColor(0,255,0));
    paint2->drawEllipse(now.se,now.sf,2*now.sef,2*now.sef);
    paint2->end();
    paint3->begin(this);
    paint3->setPen(QPen(Qt::blue,4,Qt::SolidLine)); //设置画笔形式
    paint3->setBrush(QColor(0,0,255));
    paint3->drawEllipse(now.sg,now.sh,2*now.sgh,2*now.sgh);
    paint3->end();
}

void Widget::bianbian()  //轨迹变化的规律
{
    srand(time(0));
    if(now.sa<1000){
        if(rand()%3){
            srand(time(0));
            now.sa+=rand()%10;
            srand(time(0));
            now.sb+=rand()%10;
        }else{
            srand(time(0));
            now.sa-=rand()%10;
            srand(time(0));
            now.sb-=rand()%10;
        }
    }else{
        if(rand()%3){
            srand(time(0));
            now.sa-=rand()%10;
            srand(time(0));
            now.sb-=rand()%10;
        }else{
            srand(time(0));
            now.sa+=rand()%10;
            srand(time(0));
            now.sb+=rand()%10;
        }
    }
    if(now.sc<1000){
        if(rand()%3){
            srand(time(0));
            now.sc+=rand()%10;
            srand(time(0));
            now.sd+=rand()%10;
        }else{
            srand(time(0));
            now.sc-=rand()%10;
            srand(time(0));
            now.sd-=rand()%10;
        }
    }else{
        if(rand()%3){
            srand(time(0));
            now.sc-=rand()%10;
            srand(time(0));
            now.sd-=rand()%10;
        }else{
            srand(time(0));
            now.sc+=rand()%10;
            srand(time(0));
            now.sd+=rand()%10;
        }
    }

    pan();
    QByteArray wds;
    wds.append((char*)&now,sizeof(locus));

    tcpSocket->write(wds);
    tcpSocket2->write(wds);
    QWidget::repaint();

}
void Widget::keyPressEvent(QKeyEvent *e)   //键盘移动
{/*
    switch(e->key()){
        case Qt::Key_W :now.sf-=10;break;
        case Qt::Key_S :now.sf+=10;break;
        case Qt::Key_A :now.se-=10;break;
        case Qt::Key_D :now.se+=10;break;
    }
    pan();
    QWidget::repaint();
    */
}

void Widget::bianbian1 (QByteArray array){
int a=19;
}
Widget::~Widget()
{
    delete ui;
}

