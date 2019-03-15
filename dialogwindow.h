#ifndef DIALOGWINDOW_H
#define DIALOGWINDOW_H

#include <QWidget>

namespace Ui {
class dialogWindow;
}

class dialogWindow : public QWidget
{
    Q_OBJECT

public:
    explicit dialogWindow(QWidget *parent = 0);
    ~dialogWindow();

private slots:
    void on_sureBtn_clicked();

private:
    Ui::dialogWindow *ui;
};

#endif // DIALOGWINDOW_H
