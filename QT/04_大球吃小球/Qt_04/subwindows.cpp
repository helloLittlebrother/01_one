#include "subwindows.h"

SubWindows::SubWindows(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("小弟");
    //this->setWindowTitle("老大");
     b.setParent(this);
     b.setText("切换到主窗口");
     connect(&b,&QPushButton::clicked,this,&SubWindows::sendSlot);
     resize(800,600);
}

void SubWindows::sendSlot()
{
    emit qiehui();
    emit qiehui(250,"欢迎光临");
    emit qiehui(666);
    emit qiehui("你好");
}
