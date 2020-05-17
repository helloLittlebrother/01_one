#ifndef SUM_01_H
#define SUM_01_H

#include <QWidget>
#include <QApplication>
#include <iostream>
#include <thread>
#include<QThread>

#include<QPushButton>//按钮

#include<QPainter>
#include"QTcpSocket"
class sum_01 : public QWidget
{
    Q_OBJECT
public:
    explicit sum_01(QWidget *parent = nullptr);
private:
    //自己动+画图
    QPainter painter;
    void paintEvent(QPaintEvent *);
    QPainter *paint1;
    QPainter *paint2;
    QPainter *paint3;
    QTcpSocket *tcpSocket;
    //void paintEvent(QPaintEvent *);
signals:
protected:


     //画图的
     void keyPressEvent(QKeyEvent *);
};

#endif // SUM_01_H













