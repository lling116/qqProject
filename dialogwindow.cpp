#include "dialogwindow.h"
#include "ui_dialogwindow.h"
#include<QPixmap>

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
    {   QString str="程涛：\n";
        ui->textBrowser->append(str+ui->textEdit->toPlainText());
       ui->textBrowser->insertHtml("<div style=\"float:right; color:red;\">你好</div>");
        ui->textEdit->clear();
    }

}
