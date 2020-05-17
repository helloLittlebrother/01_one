#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QApplication>
#include <iostream>
#include <thread>
#include<QThread>
#include <QWidget>
#include<QPushButton>//按钮
#include"subwindows.h"//子窗口头文件
#include"mythread.h"
#include<QPainter>
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    void mySs();
    void qie();
    void relea();
    void chulizi();

    //   自己动
    void bianbian();
    void chulizi2(int,QString);

public slots:
    void chulizi3(int);
    void chulizi4(QString);


private:
    QPushButton b1;
    QPushButton *b2;
    QPushButton b3;
    QPushButton *b4;
    QPushButton b5;

    //自己动+画图
    QPainter painter;
    void paintEvent(QPaintEvent *);
    QPainter *paint;
    QPainter *paint1;
    MyThread* v = new MyThread() ;


     SubWindows ww;


protected:
     //自己动线程
     void run();

     //画图的
     void keyPressEvent(QKeyEvent *);

};
#endif // MAINWIDGET_H
