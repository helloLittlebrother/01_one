#ifndef WIDGET_H
#define WIDGET_H


#include<QTcpServer>//监听套接字
#include<QTcpSocket>//通信套接字


#include <QWidget>
//#include "sum_01.h"
#include"mythread.h"
#include <QApplication>
#include <iostream>
#include <thread>
#include<QThread>
#include<QPushButton>//按钮
#include<QPainter>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void relea();
    void bianbian();
   void bianbian1(QByteArray);
private:
   QTcpServer *tcpServer;//监听套接字
   QTcpServer *tcpServer2;//监听套接字
   QTcpSocket *tcpSocket;//通信套接字
   QTcpSocket *tcpSocket2;//通信套接字
    myThread* v = new myThread() ;
    QPushButton b1;
    Ui::Widget *ui;
    QPainter painter;
    void paintEvent(QPaintEvent *);
    QPainter *paint1;
    QPainter *paint2;
    QPainter *paint3;
    //sum_01* vv = new sum_01() ;

protected:
     //自己动线程
     void run();

     //画图的
     void keyPressEvent(QKeyEvent *);

};
#endif // WIDGET_H
