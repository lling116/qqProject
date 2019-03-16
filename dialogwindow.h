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
    explicit dialogWindow(QString titleStr, QWidget *parent = 0);
    ~dialogWindow();

private slots:
    void on_sureBtn_clicked();

    void on_pushButton_3_clicked();

    void on_fontComboBox_currentIndexChanged(const QString &arg1);

    void on_clearBtn_clicked();

    void on_fontComboBox_currentFontChanged(const QFont &f);

    void on_bBtn_clicked();

private:
    Ui::dialogWindow *ui;
};

#endif // DIALOGWINDOW_H
