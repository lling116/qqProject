#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H
#include<QGridLayout>

#include <QWidget>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>

class registerWindow : public QWidget
{
    Q_OBJECT
public:
    explicit registerWindow(QWidget *parent = 0);
    QString getPassword();
    QString getAccount();

public slots:
    void quitWindow();
    //正则表达式
    void regExpCount();

signals:
    void SureRegister();
private:
    QGridLayout* gridLayout;
    QLabel *countLabel;
    QLabel *pwdLabel;
    QLabel *pwdAgainLabel;
    QLineEdit *countLineEdit;
    QLineEdit *pwdLineEdit;
    QLineEdit *pwdAgainLineEdit;
    QPushButton *quitBtn;
    QHBoxLayout  *hLayout;
    QPushButton *okBtn;

};

#endif // REGISTERWINDOW_H
