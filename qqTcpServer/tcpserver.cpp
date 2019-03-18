#include "tcpserver.h"
#include<QDebug>
#include<QJsonDocument>
#include<QJsonParseError>
#include<QJsonObject>
#include<QJsonValue>
#include <QSqlQuery>
#include<QSqlDatabase>
#include<QMessageBox>
#include <QSqlError>
#include<QDebug>

TcpServer::TcpServer(QWidget *parent)
    : QWidget(parent)
{
    tcpServer = new QTcpServer(this);
    tcpServer->listen(QHostAddress::Any,8888);
    setWindowTitle("服务器: 8888");
    initDataBase();
    connect(tcpServer,&QTcpServer::newConnection,
            this,&TcpServer::delNewConnection);
}

TcpServer::~TcpServer()
{

}

void TcpServer::initDataBase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../info.db");
    if(!db.open())
    {
         QMessageBox::warning(this, "错误", db.lastError().text());
         return;
    }
    qDebug()<<"数据库打开成功";
    QSqlQuery query;
    query.exec("create table if not exists userTable( account varchar(16), password varchar(32));");
}

void TcpServer::passwordTrue()
{
     if(NULL == tcpSocket)
      {
          return;
      }

     QJsonObject regJson;
     QByteArray byteArray;
     regJson.insert("loginPassword","true");
     QJsonDocument regJsonDoc;
     regJsonDoc.setObject(regJson);
     byteArray = regJsonDoc.toJson(QJsonDocument::Compact);
     //发送数据
     tcpSocket->write(byteArray.data());
}

void TcpServer::passwordFault()
{
    if(NULL == tcpSocket)
     {
         return;
     }

    QJsonObject regJson;
    QByteArray byteArray;
    regJson.insert("loginPassword","fault");
    QJsonDocument regJsonDoc;
    regJsonDoc.setObject(regJson);
    byteArray = regJsonDoc.toJson(QJsonDocument::Compact);
    //发送数据
    tcpSocket->write(byteArray.data());
}

void TcpServer::delNewConnection()
{
    qDebug()<<"客户端已经连接";
    //取出建立好连接的套接字
    tcpSocket = tcpServer->nextPendingConnection();
    connect(tcpSocket,&QTcpSocket::readyRead,this,&TcpServer::delreadyRead);
}

void TcpServer::delreadyRead()
{
    QJsonParseError jsonError;
    QString strPassword ;
    QString strAccount;
    QSqlQuery query;

    qDebug()<<"数据传过来";
    array = tcpSocket->readAll();
    qDebug()<<array.data();
    //转换为json文档
    QJsonDocument doucment = QJsonDocument::fromJson(array, &jsonError);
    if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError))
    {
        if (doucment.isObject()) //JSON 为文档对象
        {
           QJsonObject object = doucment.object();  // 转化为对象
           if(object.contains("password")&&object.contains("account"))
            {
                QJsonValue value = object.value("password");  // 获取指定 key 对应的 value
                 if (value.isString())
                 {
                     // 判断 value 是否为字符串
                      strPassword = value.toString();  // 将 value 转化为字符串
                      qDebug() << "strPassword : " << strPassword;
                 }

                 value = object.value("account");
                 if (value.isString())
                 {
                     // 判断 value 是否为字符串
                      strAccount= value.toString();  // 将 value 转化为字符串
                      qDebug() << "strAccount : " << strAccount;
                 }

                 query.exec("select * from userTable");
                  while(query.next())
                  {
                      if(query.value(0).toString()==strAccount)
                      {
                          qDebug()<<"账号重复！";
                          return;
                      }

                  }
                 query.prepare("insert into userTable(account,password) values(?,?) ");
                 query.addBindValue(strAccount);
                 query.addBindValue(strPassword);
                 query.exec();
                 qDebug()<<"数据库插入数据";

            }

           if(object.contains("loginAccount")&&object.contains("loginPassword"))
           {

               qDebug()<<"登陆请求";
               QJsonValue valueAccount = object.value("loginAccount");  // 获取指定 key 对应的 value
               query.exec("select * from userTable");
                while(query.next())
                {
                    if(query.value(0).toString()==valueAccount.toString())
                    {
                        QJsonValue valuePassword = object.value("loginPassword");
                        if(query.value(1).toString()==valuePassword.toString())
                        {
                              qDebug()<<"密码正确";
                              passwordTrue();
                        }
                        else
                        {
                            qDebug()<<"密码错误";
                            passwordFault();
                        }
                       return ;
                    }

                }
           }
        }


    }

}
