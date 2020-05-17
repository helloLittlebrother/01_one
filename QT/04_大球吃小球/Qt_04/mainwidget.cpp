//构造函数
#include "mainwidget.h"
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
int y[4][3]={50,75,50,195,70,45,280,280,30,100,85,35};
void pan(){
    if(((sa+sab*2)/2-(sc+scd*2)/2)*((sa+sab*2)/2-(sc+scd*2)/2)+((sb+sab*2)/2-(sd+scd*2)/2)*((sb+sab*2)/2-(sd+scd*2)/2)<(sab+scd)*(sab+scd)-10140){
        if(sab>scd&scd>10){
            sab=sab+10;
            scd=0;
        }
        if(sab<scd&sab>10){
            sab=0;
            scd=scd+10;
        }
    }

    if(((sa+sab*2)/2-(se+sef*2)/2)*((sa+sab*2)/2-(se+sef*2)/2)+((sb+sab*2)/2-(sf+sef*2)/2)*((sb+sab*2)/2-(sf+sef*2)/2)<(sab+sef)*(sab+sef)-10140){
        if(sab>sef&sef>10){
            sab=sab+10;
            sef=0;
        }
        if(sab<sef&sab>8){
            sab=0;
            sef=sef+10;
        }
    }

    if(((sa+sab*2)/2-(sg+sgh*2)/2)*((sa+sab*2)/2-(sg+sgh*2)/2)+((sb+sab*2)/2-(sh+sgh*2)/2)*((sb+sab*2)/2-(sh+sgh*2)/2)<(sab+sgh)*(sab+sgh)-10140){
        if(sab>sgh&sgh>9){
            sab=sab+10;
            sgh=0;
        }
        if(sab<sgh&sab>9){
            sab=0;
            sgh=sgh+10;
        }
    }

    if(((sc+scd*2)/2-(se+sef*2)/2)*((sc+scd*2)/2-(se+sef*2)/2)+((sd+scd*2)/2-(sh+sef*2)/2)*((sd+scd*2)/2-(sh+sef*2)/2)<(scd+sef)*(scd+sef)-10140){
        if(scd>sef&sef>9){
            scd=scd+10;
            sef=0;
        }
        if(scd<sef&scd>9){
            scd=0;
            sef=sef+10;
        }
    }

    if(((sc+scd*2)/2-(sg+sgh*2)/2)*((sc+scd*2)/2-(sg+sgh*2)/2)+((sd+scd*2)/2-(sh+sgh*2)/2)*((sd+scd*2)/2-(sh+sgh*2)/2)<(scd+sgh)*(scd+sgh)-10140){
        if(scd>sgh&sgh>9){
            scd=scd+10;
            sgh=0;
        }
        if(scd<sgh&scd>9){
            scd=0;
            sgh=sgh+10;
        }
    }

    if(((se+sef*2)/2-(sg+sgh*2)/2)*((se+sef*2)/2-(sg+sgh*2)/2)+((sf+sef*2)/2-(sh+sgh*2)/2)*((sf+sef*2)/2-(sh+sgh*2)/2)<(sef+sgh)*(sef+sgh)-10140){
        if(sef>sgh&sgh>9){
            sef=sef+10;
            sgh=0;
        }
        if(sef<sgh&sef>9){
            sef=0;
            sgh=sgh+10;
        }
    }


}
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{


    //接受线程返回的信号      ++--++
     void (MyThread::*cg8)()=&MyThread::bian;
    connect(v,cg8,this,&MainWidget::bianbian);




    b1.setParent(this);
    b1.setText("b1   关闭");
    b1.move(100,100);

    b2=new QPushButton(this);
    b2->setText("b2");
    b2->move(200,200);
    //                                 影响谁
 //处理信号   谁发               类型 改变 改变谁            具体改变
    connect(&b1,&QPushButton::pressed,this,&MainWidget::close);
    /*
     * &b1    ：信号发出者，指针类型
     * &QPushButton::pressed    ：处理的信号    &发送者的类名：：信号名字
     * this ：信号接收者
     * &MainWidget::close   ：槽函数，信号处理函数    &接收信号的类名：：槽函数名字
     */

    /*
     * 自定义槽函数，普通函数的用法
     *Qt5:任意的成员函数，普通全局函数，静态函数
     *槽函数需要和信号一致（参数、返回值）
     *由于信号都是没有返回值，所以，槽函数一定没有返回值
     */
    connect(b2,&QPushButton::released,this,&MainWidget::mySs);

    setWindowTitle("老大");
    //this->setWindowTitle("老大");
     b3.setParent(this);
     b3.setText("切换到子窗口");
     b3.move(300,300);

     connect(&b3,&QPushButton::released,this,&MainWidget::qie);

     //处理子窗口的信号 稳的一种  无参
      void (SubWindows::*cg1)()=&SubWindows::qiehui;
     connect(&ww,cg1,this,&MainWidget::chulizi);

     b5.setParent(this);
     b5.setText("kaishi");
     b5.move(100,300);
     connect(&b5,&QPushButton::released,this,&MainWidget::relea);




     //有参
      void (SubWindows::*cg2)(int,QString)=&SubWindows::qiehui;
      connect(&ww,cg2,this,&MainWidget::chulizi2);

       //处理子窗口的信号 不稳的一种 但是方便     QT4信号连接   SIGNAL SLOT  将函数名字-》字符串，不进行错误检查
      connect(&ww,SIGNAL(qiehui(int)),this,SLOT(chulizi3(int)));   // 槽函数要用slots修饰
      connect(&ww,SIGNAL(qiehui(QString)),this,SLOT(chulizi4(QString)));




      /*
       * Lambda表达式，匿名函数对象  没名字
       * C++11增加的新特性，项目文件要加上  CONFIG +=C++11
       * Qt配合信号用，非常方便，不用再另写槽函数
       *和函数用法差不多
       */
      //QPushButton *b5=new QPushButton(this);
      b4=new QPushButton(this);
      b4->setText("Lambda表达式");
      b4->move(400,400);
      int aaa=111;
      connect(b4,&QPushButton::released,
              [=]()     //():参数   {} 内容   （）{}和函数的用法一样
        {                //[]必须有  把外部变量传过来，在函数内部能用
                        //[]作用范围  =：把外部所有局部变量、类中的所有成员以值传过来
                        //[]作用范围  &：把外部所有局部变量   引用符号
                        //[]局限：传过来的只读
                        //[]
            b4->setText("我成功改变了");
            qDebug()<< "2222222222";
            qDebug()<<aaa;
      }


      );

    resize(1000,800);

    //设置背景颜色
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, Qt::white);
    this->setPalette(palette);
}


void MainWidget::relea()//触发线程
{
    v->start();
}

void MainWidget::bianbian()  //轨迹变化的规律
{
    srand(time(0));
    if(sa<1000){
        if(rand()%3){
            srand(time(0));
            sa+=rand()%10;
            srand(time(0));
            sb+=rand()%10;
        }else{
            srand(time(0));
            sa-=rand()%10;
            srand(time(0));
            sb-=rand()%10;
        }
    }else{
        if(rand()%3){
            srand(time(0));
            sa-=rand()%10;
            srand(time(0));
            sb-=rand()%10;
        }else{
            srand(time(0));
            sa+=rand()%10;
            srand(time(0));
            sb+=rand()%10;
        }
    }
    if(sc<1000){
        if(rand()%3){
            srand(time(0));
            sc+=rand()%10;
            srand(time(0));
            sd+=rand()%10;
        }else{
            srand(time(0));
            sc-=rand()%10;
            srand(time(0));
            sd-=rand()%10;
        }
    }else{
        if(rand()%3){
            srand(time(0));
            sc-=rand()%10;
            srand(time(0));
            sd-=rand()%10;
        }else{
            srand(time(0));
            sc+=rand()%10;
            srand(time(0));
            sd+=rand()%10;
        }
    }

    pan();
    QWidget::repaint();
}

void MainWidget::keyPressEvent(QKeyEvent *e)   //键盘移动
{
    switch(e->key()){
        case Qt::Key_W :sf-=10;break;
        case Qt::Key_S :sf+=10;break;
        case Qt::Key_A :se-=10;break;
        case Qt::Key_D :se+=10;break;
    }
    pan();
    QWidget::repaint();
}




void MainWidget::paintEvent(QPaintEvent *)//paintEvent函数由系统自动调用
{
    paint=new QPainter;
    paint->begin(this);
    paint->setPen(QPen(Qt::blue,4,Qt::SolidLine)); //设置画笔形式
    paint->drawEllipse(sa,sb,2*sab,2*sab);
    paint->setPen(QPen(Qt::blue,4,Qt::SolidLine)); //设置画笔形式
    paint->drawEllipse(sc,sd,2*scd,2*scd);
    paint->setPen(QPen(Qt::red,4,Qt::SolidLine)); //设置画笔形式
    paint->drawEllipse(se,sf,2*sef,2*sef);

    paint->setPen(QPen(Qt::red,4,Qt::SolidLine)); //设置画笔形式
    paint->drawEllipse(sg,sh,2*sgh,2*sgh);
    paint->end();
}

void MainWidget::chulizi2(int a,QString str)
{
    //                 .toUtf8().data()   编码
    //str.Utf8()     ->字节数组QByteArray
    //.data()         QByteArray->char *
    qDebug() <<a <<str.toUtf8().data();

}

void MainWidget::chulizi3(int a)
{
    //                 .toUtf8().data()   编码
    //str.Utf8()     ->字节数组QByteArray
    //.data()         QByteArray->char *
    qDebug() <<a;
}

void MainWidget::chulizi4(QString str)
{
    //                 .toUtf8().data()   编码
    //str.Utf8()     ->字节数组QByteArray
    //.data()         QByteArray->char *
    qDebug() <<str.toUtf8().data();
}

void MainWidget::mySs()
{
    b2->setText("b2222222222222");
}

void MainWidget::qie()
{
    //子窗口显示
   ww.show();
    //父窗口隐藏
   this->hide();
}



void MainWidget::chulizi()
{
    this->show();
    ww.hide();
}



MainWidget::~MainWidget()
{

}

