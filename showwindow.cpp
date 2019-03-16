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
  //  mDialogWindow = new dialogWindow;
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

void showwindow::DelItemDoubleClicked( QTreeWidgetItem*item, int column)
{
  // qDebug()<<"打开对话框";
  // qDebug()<<item->text(column)QTreeWidgetItem;
   //解决点击分组名称，进入对话框的问题
   if(!item->childCount())
   {
       // mDialogWindow->show();
       //emit sendItemText(item->text(0));
       //为解决内存分配问题，1.可以预先分配一定数目的内存；二是当点击在分配内存如下：
       //qDebug()<<ui->treeWidget->currentColumn()<<ui->treeWidget->currentItem();
      // int i = (int)ui->treeWidget->currentItem();
       //qDebug()<<i;
       bool flag = false;
       for(int i = 0; i <  treeWidgetList.size();i++)
       {
           if(ui->treeWidget->currentItem()==treeWidgetList.at(i))
           {
               dialogWindowList.at(i)->show();
               flag = true;
               break;
           }

        }

       if(!flag)
       {
           treeWidgetList<<ui->treeWidget->currentItem();
           dialogWindow * temp = new dialogWindow(ui->treeWidget->currentItem()->text(0));
           temp->show();
           dialogWindowList<<temp;
       }

   }

   qDebug()<<treeWidgetList.size();
}
