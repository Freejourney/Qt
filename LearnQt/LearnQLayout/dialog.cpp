#include "dialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QFrame>
#include <QGridLayout>
#include <QPixmap>
#include <QHBoxLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("UserInfo"));

    /*****************左侧*******************/
    UserNameLabel = new QLabel(tr("用户名："));
    UserNameLineEdit = new QLineEdit;

    NameLabel = new QLabel(tr("姓名："));
    NameLineEdit = new QLineEdit;

    SexLabel = new QLabel(tr("性别："));
    SexComboBox = new QComboBox;

    SexComboBox->addItem(tr("女"));
    SexComboBox->addItem(tr("男"));

    DepartmentLabel = new QLabel(tr("部门："));
    DepartmentTextEdit = new QTextEdit;

    AgeLabel = new QLabel(tr("年龄："));
    AgeLineEdit = new QLineEdit;

    OtherLabel = new QLabel(tr("备注："));
    OtherLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    LeftLayout = new QGridLayout();

    //向布局中加入需要布局的控件
    LeftLayout->addWidget(UserNameLabel, 0, 0);
    LeftLayout->addWidget(UserNameLineEdit, 0, 1);
    LeftLayout->addWidget(NameLabel, 1, 0);
    LeftLayout->addWidget(NameLineEdit, 1, 1);
    LeftLayout->addWidget(SexLabel, 2, 0);
    LeftLayout->addWidget(SexComboBox, 2, 1);
    LeftLayout->addWidget(DepartmentLabel, 3, 0);
    LeftLayout->addWidget(DepartmentTextEdit, 3, 1);
    LeftLayout->addWidget(AgeLabel, 4, 0);
    LeftLayout->addWidget(AgeLineEdit, 4, 1);
    LeftLayout->addWidget(OtherLabel, 5, 0, 1, 2);
    
    //组合使用，选取第0和1列，设置成1:3比例
    LeftLayout->setColumnStretch(0, 1);
    LeftLayout->setColumnStretch(1, 3);

    /*************右侧*****************/
    HeadLabel = new QLabel(tr("头像："));
    HeadIconLabel = new QLabel;
    QPixmap icon("头像.png.PNG");
    HeadIconLabel->setPixmap(icon);
    HeadIconLabel->resize(icon.width(), icon.height());
    UpdateHeadBtn = new QPushButton(tr("更新"));

    //完成右上侧头像选择区的布局
    TopRightLayout = new QHBoxLayout();
    TopRightLayout->setSpacing(20);
    TopRightLayout->addWidget(HeadLabel);
    TopRightLayout->addWidget(HeadIconLabel);
    TopRightLayout->addWidget(UpdateHeadBtn);
    IntroductionLabel = new QLabel(tr("个人说明："));
    IntroductionTextEdit = new QTextEdit;

    //完成右侧的布局
    RightLayout = new QVBoxLayout();
    RightLayout->setMargin(10);
    RightLayout->addLayout(TopRightLayout);
    RightLayout->addWidget(IntroductionLabel);
    RightLayout->addWidget(IntroductionTextEdit);

    /*----------------------------底部-------------------------------*/
    OkBtn = new QPushButton(tr("确定"));
    CancelBtn = new QPushButton(tr("取消"));

    //完成下方两个按钮的布局
    ButtomLayout = new QHBoxLayout();
    ButtomLayout->addStretch();     //在按钮前加入一个占位符，使两个按钮能够靠右对齐，并且在整个对话框的大小变化时，保证按钮大小不变
    ButtomLayout->addWidget(OkBtn);
    ButtomLayout->addWidget(CancelBtn);

    /*--------------------------------------------------------------*/
    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->setMargin(15);      //设定对话框边距为15
    mainLayout->setSpacing(10);     //设定各个控件间间距为10
    mainLayout->addLayout(LeftLayout, 0, 0);
    mainLayout->addLayout(RightLayout, 0, 1);
    mainLayout->addLayout(ButtomLayout, 1, 0, 1, 2);    //将控件ButtomLayout放在第1行第0列，控件占1行2列
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);   //设定最优显示，并且使用户无法改变对话框的大小
}

Dialog::~Dialog()
{

}
