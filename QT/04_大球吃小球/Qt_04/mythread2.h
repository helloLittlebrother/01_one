#ifndef MYTHREAD2_H
#define MYTHREAD2_H

#include <QThread>

class MyThread2 : public QThread
{
    Q_OBJECT
public:
    explicit MyThread2(QObject *parent = nullptr);

protected:
    //QThread的虚函数
    //线程处理函数
    //不能直接调用，通过start()间接调用
    void run();
signals:
    //void isDone();  //处理完成信号
     void bian2(int);
};

#endif // MYTHREAD2_H







