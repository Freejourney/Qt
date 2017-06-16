//新建Qt Widgets Application
//项目名称 "Splitter"
//基类选择 "QMainWindow"
//取消“创建界面”复选框选中状态

#include "mainwindow.h"
#include <QApplication>
#include <QSplitter>
#include <QTextEdit>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //调整字体
    QFont font("ZYSong18030", 12);
    a.setFont(font);
    //主分割窗口
    QSplitter * splitterMain = new QSplitter(Qt::Horizontal, 0);    //水平分割(将整个窗口分为左右连个部分)

    QTextEdit * textLeft = new QTextEdit(QObject::tr("Left  Widget"), splitterMain);    //新建文本框,字符串“Left  Widget",填充splitterMain
    textLeft->setAlignment(Qt::AlignCenter);        //文字居中
    //右部分分割窗口
    QSplitter * splitterRight = new QSplitter(Qt::Vertical, splitterMain);  //垂直分割(将右边窗口分为上下两个部分)

    splitterRight->setOpaqueResize(false);  //分割窗口的分割条在拖拽时不实时更新显示


    //文本框根据文本框个数从上往下等分填充(水平分割时从左往右)
    QTextEdit * textUp = new QTextEdit(QObject::tr("Top  Widget"), splitterRight);  //新建文本框,字符串“Top  Widget”,填充splitterRight
    textUp->setAlignment(Qt::AlignCenter);        //文字居中
    QTextEdit * textMiddle = new QTextEdit(QObject::tr("Middle Widget"), splitterRight);    //新建文本框,字符串“Middle  Widget”,填充splitterRight
    textMiddle->setAlignment(Qt::AlignCenter);        //文字居中
    QTextEdit * textBottom = new QTextEdit(QObject::tr("Bottom Widget"), splitterRight);    //新建文本框,字符串“Bottom  Widget”,填充splitterRight
    textBottom->setAlignment(Qt::AlignCenter);        //文字居中

    //调整可伸缩控件，第一个参数代表指定控件的序号，按插入顺序从0开始编号，第二个参数代表是否可以伸缩，大于0时表示可以伸缩
    splitterMain->setStretchFactor(1,1);
    
    //调整窗口标题
    splitterMain->setWindowTitle(QObject::tr("Splitter"));
    
    splitterMain->show();
//    MainWindow w;
//    w.show();

    return a.exec();
}
