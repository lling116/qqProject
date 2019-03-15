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
public slots:
    void DelItemDoubleClicked(QTreeWidgetItem * item, int column);

private:
    Ui::showwindow *ui;
    dialogWindow* mDialogWindow;
};

#endif // SHOWWINDOW_H
