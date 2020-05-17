
#ifndef SUM_02_H
#define SUM_02_H


#include <QWidget>
#include <QApplication>
#include <iostream>
#include <thread>
#include<QThread>

#include<QPushButton>//按钮

#include<QPainter>
#include"QTcpSocket"

class sum_02 : public QWidget
{
    Q_OBJECT
public:
    explicit sum_02(QWidget *parent = nullptr);
private:
    //自己动+画图
    QPainter painter;
    void paintEvent(QPaintEvent *);
    QPainter *paint1;
    QPainter *paint2;
    QPainter *paint3;
    QTcpSocket *tcpSocket;
    //void paintEvent(QPaintEvent *);
protected:


     //画图的
     void keyPressEvent(QKeyEvent *);

};

#endif // WW001_H
