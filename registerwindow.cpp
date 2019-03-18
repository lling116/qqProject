#include "registerwindow.h"
#include<QDebug>
#include<QRegExp>
#include<QMessageBox>

registerWindow::registerWindow(QWidget *parent) : QWidget(parent)
{
    setWindowIconText("注册账号");
    //setFixedSize(420,300);
    countLabel = new QLabel(QObject::tr("账号："),this);
    countLineEdit = new QLineEdit(this);
    countLineEdit->setMaxLength(9);
    countLineEdit->setPlaceholderText(tr("请输非0开头的九位数"));
    pwdLineEdit = new QLineEdit(this);
    pwdLabel = new QLabel(QObject::tr("密码："),this);

    pwdAgainLineEdit = new QLineEdit(this);
    pwdAgainLabel = new QLabel(QObject::tr("确认密码："),this);
    okBtn = new QPushButton(QObject::tr("确认"),this);
    quitBtn = new QPushButton(QObject::tr("取消"),this);
    //网格布局
    gridLayout = new QGridLayout(this);
    gridLayout->addWidget(countLabel,0,0);
    gridLayout->addWidget(countLineEdit,0,1);
    gridLayout->addWidget(pwdLabel,1,0);
    gridLayout->addWidget(pwdLineEdit,1,1);
    gridLayout->addWidget(pwdAgainLabel,2,0);
    gridLayout->addWidget(pwdAgainLineEdit,2,1);
    //水平布局
    hLayout = new QHBoxLayout(this);
    hLayout->addWidget(okBtn);
    hLayout->addWidget(quitBtn);
    gridLayout->addLayout(hLayout,3,0,1,2);
     //设置对话框大小无法改变
     gridLayout->setSizeConstraint(QLayout::SetFixedSize);
     //设置外边框的距离和控件的间隔
     gridLayout->setMargin(15);
     gridLayout->setSpacing(10);

     connect(quitBtn,SIGNAL(clicked()),this,SLOT(quitWindow()));
     connect(okBtn,SIGNAL(clicked()),this,SLOT(regExpCount()));
}

QString registerWindow::getPassword()
{
    return pwdLineEdit->text();
}

QString registerWindow::getAccount()
{
    return countLineEdit->text();
}

void registerWindow::regExpCount()
{
    QRegExp mRegExp(tr("[1-9]{1}[0-9]{8}"));
    if(!mRegExp.exactMatch(this->countLineEdit->text()))
    {
        QMessageBox::information(this,"错误提示！","请输入非0开头的九位数字！",
                                 QMessageBox::Ok);
        return;
    }
    if(pwdLineEdit->text()!=pwdAgainLineEdit->text())
    {
        QMessageBox::information(this,"密码错误","两次输入的密码不一致！",
                                 QMessageBox::Ok);
        return;
    }
   emit SureRegister();
}

//退出
void registerWindow::quitWindow()
{
    this->close();

}



