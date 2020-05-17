#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class myThread : public QThread
{
    Q_OBJECT
public:
    explicit myThread(QObject *parent = nullptr);
protected:
    //QThread的虚函数
    //线程处理函数
    //不能直接调用，通过start()间接调用
    void run();

signals:
    //void isDone();  //处理完成信号
     void bian();
};

#endif // MYTHREAD_H












