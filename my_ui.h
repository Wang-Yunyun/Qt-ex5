#ifndef MY_UI_H
#define MY_UI_H

#include <QDialog>

namespace Ui {
class My_Ui;
}

class My_Ui : public QDialog
{
    Q_OBJECT

public:
    explicit My_Ui(QWidget *parent = nullptr);
    ~My_Ui();

private slots:
    void on_pushButton_photo_clicked();

    void on_radioButton_3_toggled(bool checked);

    void on_radioButton_4_toggled(bool checked);

    void on_checkBox_all_stateChanged(int arg1);

    void on_pushButton_clicked();

private:
    Ui::My_Ui *ui;
};

#endif // MY_UI_H
