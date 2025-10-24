#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//初始化qt实例
    MainWindow w;//创建主窗口对象
    w.show();//显示
    return a.exec();//进入qt循环，保存程序运行
}
