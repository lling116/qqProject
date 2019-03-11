#ifndef QQMAINWINDOW_H
#define QQMAINWINDOW_H

#include <QMainWindow>
#include<QAction>
#include"registerwindow.h"
#include<QTimer>

namespace Ui {
class QQMainWindow;
}

class QQMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QQMainWindow(QWidget *parent = 0);
    ~QQMainWindow();

private slots:
    void on_label_2_linkActivated(const QString &link);

    void on_pushButton_clicked();
    void keyBoardTriggered();

    void on_loginBtn_clicked();
    void updateTimer();

private:
    Ui::QQMainWindow *ui;
    registerWindow* regWindow;
    QAction *countAction;
    QAction *pwdAction;
    bool loginFlag;
    //保存没移动之前的pso
    QPoint picLabelPos;
    QTimer *m_Timer;
};

#endif // QQMAINWINDOW_H
