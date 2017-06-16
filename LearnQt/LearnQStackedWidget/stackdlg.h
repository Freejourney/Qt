//新建 Qt Widget Application
//项目名称  "StackedWidget"
//基类  "QDialog"
//类名  "StackDlg"
//取消"创建界面"复选框的选中状态

#ifndef STACKDLG_H
#define STACKDLG_H

#include <QDialog>
#include <QStackedWidget>
#include <QListWidget>
#include <QLabel>

class StackDlg : public QDialog
{
    Q_OBJECT

public:
    StackDlg(QWidget *parent = 0);
    ~StackDlg();
private:
    QListWidget *list;
    QStackedWidget *stack;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
};

#endif // STACKDLG_H
