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


signals:

public slots:
    void quitWindow();
    //正则表达式
    void regExpCount();

private:
    QGridLayout* gridLayout;
    QLabel *countLabel;
    QLabel *pwdLabel;
    QLabel *pwdAgainLabel;
    QLineEdit *countLineEdit;
    QLineEdit *pwdLineEdit;
    QLineEdit *pwdAgainLineEdit;
    QPushButton *okBtn;
    QPushButton *quitBtn;
    QHBoxLayout  *hLayout;


};

#endif // REGISTERWINDOW_H
