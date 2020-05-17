#ifndef SUBWINDOWS_H
#define SUBWINDOWS_H

#include <QWidget>
#include<QPushButton>
class SubWindows : public QWidget
{
    Q_OBJECT
public:
    explicit SubWindows(QWidget *parent = nullptr);

    void sendSlot();

signals:
    /*
     *信号必须由signals来声明
     *信号没有返回值，但可以有参数
     *信号就是函数的声明，只需声明，无需定义
     *使用： emit xinhao();
     */
    void qiehui();
    void qiehui(int,QString);
    void qiehui(int);
    void qiehui(QString);

private:
    QPushButton b;

};

#endif // SUBWINDOWS_H
