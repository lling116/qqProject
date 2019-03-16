#ifndef SHOWWINDOW_H
#define SHOWWINDOW_H

#include <QWidget>
#include<QTreeWidgetItem>
#include "dialogwindow.h"

namespace Ui {
class showwindow;
}

class showwindow : public QWidget
{
    Q_OBJECT

public:
    explicit showwindow(QWidget *parent = 0);
    ~showwindow();
    void initTreeWidget();
signals:
    //void sendItemText(QString str);

public slots:
    void DelItemDoubleClicked(QTreeWidgetItem * item, int column);
   // void openDialog(QString  str);

private:
    Ui::showwindow *ui;
   // dialogWindow* mDialogWindow;
    QList<dialogWindow*>dialogWindowList;
    QList<QTreeWidgetItem*> treeWidgetList;
    QString titleStr;

};

#endif // SHOWWINDOW_H
