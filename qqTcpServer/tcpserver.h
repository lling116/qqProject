#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QWidget>
#include<QTcpServer>
#include<QTcpSocket>

class TcpServer : public QWidget
{
    Q_OBJECT

public:
    TcpServer(QWidget *parent = 0);
    ~TcpServer();
    void initDataBase();
    void passwordTrue();
    void passwordFault();
public slots:
    void delNewConnection();
    void delreadyRead();
private:
    QTcpServer *tcpServer; //监听套接字
    QTcpSocket *tcpSocket; //通信套接字
    QByteArray array ;

};

#endif // TCPSERVER_H
