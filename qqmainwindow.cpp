#include "qqmainwindow.h"
#include "ui_qqmainwindow.h"
#include<QDebug>
#include<QDesktopServices>
#include<QUrl>
#include<QPropertyAnimation>
#include<QList>

QQMainWindow::QQMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QQMainWindow)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()&~Qt::WindowMinimizeButtonHint
                   &~Qt::WindowMaximizeButtonHint);
    setFixedSize(420,300);
    regWindow= new registerWindow;
    m_showwindow = new showwindow;

    countAction = new QAction(this);
    countAction->setIcon(QIcon(":/login/image/inputBox-more.svg"));
    ui->userNamelineEdit->addAction(countAction,QLineEdit::TrailingPosition);

    pwdAction = new QAction(this);
    pwdAction->setIcon(QIcon(":/login/image/soft-keyboard.svg"));
    ui->pwdlineEdi->addAction(pwdAction,QLineEdit::TrailingPosition);
    loginFlag=0;
    //定时器
    m_Timer = new QTimer(this);
    //信号和槽
    connect(pwdAction,SIGNAL(triggered(bool)),this,SLOT(keyBoardTriggered()));
    connect(m_Timer,&QTimer::timeout,this,&QQMainWindow::updateTimer);
}

QQMainWindow::~QQMainWindow()
{
    delete ui;
}

//使用错误的信号和槽了
/*void QQMainWindow::on_label_2_linkActivated(const QString &link)
{
    qDebug()<<link;
}*/

//注册按钮
void QQMainWindow::on_pushButton_clicked()
{   
      regWindow->show();
      //通过打开网页来注册
      // QDesktopServices::openUrl(QUrl("https://ssl.zc.qq.com/v3/index-chs.html"));
}

void QQMainWindow::keyBoardTriggered()
{
    qDebug()<<"键盘按下";
}

void QQMainWindow::on_loginBtn_clicked()
{
     if(loginFlag==0)
     {
       picLabelPos= ui->picturelabel->pos();
        ui->loginBtn->setText("取消");
        ui->userNamelineEdit->hide();
        ui->pwdlineEdi->hide();
        ui->loginradioButton->hide();
        ui->radioButton_2->hide();
        ui->label_3->hide();
       // qDebug()<<ui->picturelabel->pos();
        // qDebug()<<ui->picturelabel->size();

        //移动图标
        ui->picturelabel->move(180,130);
        loginFlag=1;
        m_Timer->start(1000);
        m_showwindow->show();
    }

     else{
         //停止定时器
         m_Timer->stop();
         ui->loginBtn->setText("登陆");
         ui->userNamelineEdit->show();
         ui->pwdlineEdi->show();
         ui->loginradioButton->show();
         ui->radioButton_2->show();
         ui->label_3->show();
        // qDebug()<<ui->picturelabel->pos();
         // qDebug()<<ui->picturelabel->size();

         //移动图标
         ui->picturelabel->move(picLabelPos);
         loginFlag = 0;
     }
}

void QQMainWindow::updateTimer()
{
  // qDebug()<<"时间到";
    static unsigned int countTimer = 0;
    QList<QString>list;
    list<<"取消."<<"取消.."<<"取消...";
    ui->loginBtn->setText(list.at(countTimer));
    countTimer++;
    countTimer=(countTimer==3)?0:countTimer;

}
