//新建  Qt Widgets Application
//项目名称  "UserInfo"
//基类  "QDialog"
//取消  "创建界面"  复选框的选中状态

#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QGridLayout>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
private:
    //左侧
    QLabel *UserNameLabel;
    QLabel *NameLabel;
    QLabel *SexLabel;
    QLabel *DepartmentLabel;
    QLabel *AgeLabel;
    QLabel *OtherLabel;

    QLineEdit *UserNameLineEdit;
    QLineEdit *NameLineEdit;
    QLineEdit *AgeLineEdit;

    QComboBox *SexComboBox;

    QTextEdit *DepartmentTextEdit;

    QGridLayout *LeftLayout;        //网格排列布局
    //右侧
    QLabel *HeadLabel;
    QLabel *HeadIconLabel;
    QPushButton *UpdateHeadBtn;
    QHBoxLayout *TopRightLayout;    //水平排列布局

    QLabel *IntroductionLabel;
    QTextEdit *IntroductionTextEdit;
    QVBoxLayout *RightLayout;       //垂直排列布局
    //底部
    QPushButton *OkBtn;
    QPushButton *CancelBtn;
    QHBoxLayout *ButtomLayout;      //水平排列布局
};

#endif // DIALOG_H
