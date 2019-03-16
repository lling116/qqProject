#include "dialogwindow.h"
#include "ui_dialogwindow.h"
#include<QPixmap>
#include<QDebug>

dialogWindow::dialogWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dialogWindow)
{
    ui->setupUi(this);
    setFixedSize(791,462);

}

dialogWindow::~dialogWindow()
{
    delete ui;
}

void dialogWindow::on_sureBtn_clicked()
{
    //判断是否为空
    if(!ui->textEdit->toPlainText().isEmpty())
    {
        //QString str="程涛：\n";
       // ui->textBrowser->append(str+ui->textEdit->toPlainText());
      //  ui->textBrowser->insertHtml("<div style=\"float:right; color:red;\">你好</div>");
        QString content=ui->textEdit->toPlainText();
        qDebug()<<content.length();
        if(content.length()>=23){
            qDebug()<<"进入了这个";
            QString s1="<img width='30' height='30' src=':/login/image/avatar.svg' style='float:right;margin-left:15px;margin-right:15px;'><div style='background:rgb(205,215,226);padding-top:8px;float:right;margin-top:10px;margin-right:45px;padding:10px;margin-left:60px;'><span style='font-size:15px;font-family:'Microsoft YaHei';margin-top:2px;'>"+content+"</span></div><br><br><br>";
           ui->textBrowser->insertHtml(s1);
        }
        else{
            int flag=60+(24-content.length())*15;
            QString myflag=QString::number(flag, 10);;
            qDebug()<<myflag;
            QString s1="<img width='30' height='30' src=':/login/image/avatar.svg' style='float:right;margin-left:15px;margin-right:15px;'>"
                       "<div style='background:rgb(205,215,226);padding-top:8px;float:right;margin-top:10px;margin-right:45px;padding:10px;margin-left:"+myflag+"px;'>";
            s1+="<span style='font-size:15px;font-family:'Microsoft YaHei';margin-top:2px;'>"+content+"</span></div><br><br><br>";
            qDebug()<<s1;
           ui->textBrowser->insertHtml(s1);
        }

        ui->textEdit->clear();
    }

}
