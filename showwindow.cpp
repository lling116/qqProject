#include "showwindow.h"
#include "ui_showwindow.h"
#include<QDebug>

showwindow::showwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showwindow)
{
    ui->setupUi(this);
    ui->treeWidget->setHeaderLabel("我的好友");
    setFixedSize(289,478);
    //初始化好友列表
    initTreeWidget();
    mDialogWindow = new dialogWindow;
   connect(ui->treeWidget,&QTreeWidget::itemDoubleClicked,this,&showwindow::DelItemDoubleClicked);
}

showwindow::~showwindow()
{
    delete ui;
}

void showwindow::initTreeWidget()
{
    QTreeWidgetItem *myFriends = new QTreeWidgetItem(ui->treeWidget);
    myFriends->setText(0,"好友");
    QTreeWidgetItem *friendOne = new QTreeWidgetItem(myFriends);
    friendOne->setText(0,"徐统");
    friendOne->setIcon(0,QIcon(":/show/image/Cherry.png"));
    QTreeWidgetItem *friendTwo = new QTreeWidgetItem(myFriends);
    friendTwo->setText(0,"程涛");
    friendTwo->setIcon(0,QIcon(":/show/image/dr.png"));

    QTreeWidgetItem *myColleagues = new QTreeWidgetItem(ui->treeWidget);
    myColleagues->setText(0,tr("同事"));
    QTreeWidgetItem *colleaguesOne = new QTreeWidgetItem(myColleagues);
    colleaguesOne->setText(0,"王瑞生");
    colleaguesOne->setIcon(0,QIcon(":/show/image/ymrl.png"));
    QTreeWidgetItem *colleaguesOneTwo = new QTreeWidgetItem(myColleagues);
    colleaguesOneTwo->setIcon(0,QIcon(":/show/image/qmnn.png"));
    colleaguesOneTwo->setText(0,tr("高工"));
}

void showwindow::DelItemDoubleClicked(QTreeWidgetItem *item, int column)
{
   qDebug()<<"打开对话框";
   qDebug()<<item->text(column);
   //解决点击分组名称，进入对话框的问题
   if(!item->childCount())
   {
       mDialogWindow->show();
   }

}
