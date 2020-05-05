#include "my_ui.h"
#include "ui_my_ui.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QDateTime>
#include <QDebug>

My_Ui::My_Ui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::My_Ui)
{
    ui->setupUi(this);

    QDateTime time = QDateTime::currentDateTime(); //获取系统现在的时间
    //DateEdit 设置下拉日历,XXXX年XX月XX日
    ui->dateEdit_birthday->setCalendarPopup(true);
    ui->dateEdit_birthday->setDisplayFormat("yyyy-MM-dd");
    ui->dateEdit_birthday->setDateTime(time);//显示当前日期

    //设置学制去掉后面两个上下调节按钮,且不能从键盘上获取值
    ui->spinBox_year->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->spinBox_year->setFocusPolicy(Qt::NoFocus);
}

My_Ui::~My_Ui()
{
    delete ui;
}

void My_Ui::on_pushButton_photo_clicked()
{
    QString fileName =
            QFileDialog::getOpenFileName(this,"打开文件","","图片文件(*.png *.jpg)");
    QImage * img=new QImage;
    if(fileName != ""){
        if(img->load(fileName)){
            //图片缩放以适应Label大小
            img->scaled(ui->label_picture->size(),Qt::KeepAspectRatio);
            ui->label_picture->setScaledContents(true);
            //显示图片在Label中
            ui->label_picture->setPixmap(QPixmap::fromImage(*img));
        }
    }
}

void My_Ui::on_radioButton_3_toggled(bool checked)
{
    ui->spinBox_year->setMinimum(2);
    ui->spinBox_year->setMaximum(3);
    ui->Slider->setMinimum(2);
    ui->Slider->setMaximum(3);
}

void My_Ui::on_radioButton_4_toggled(bool checked)
{
    ui->spinBox_year->setMinimum(4);
    ui->spinBox_year->setMaximum(5);
    ui->Slider->setMinimum(4);
    ui->Slider->setMaximum(5);
}

void My_Ui::on_checkBox_all_stateChanged(int arg1)
{
    if(ui->checkBox_all->isChecked()){
        ui->checkBox_all->setText("清除");
        ui->checkBox_ball->setCheckState(Qt::Checked);
        ui->checkBox_book->setCheckState(Qt::Checked);
        ui->checkBox_film->setCheckState(Qt::Checked);
        ui->checkBox_game->setCheckState(Qt::Checked);
        ui->checkBox_photo->setCheckState(Qt::Checked);
        ui->checkBox_travel->setCheckState(Qt::Checked);
        ui->checkBox_cartoon->setCheckState(Qt::Checked);
        ui->checkBox_painting->setCheckState(Qt::Checked);
    }
    else {
        ui->checkBox_all->setText("全选");
        ui->checkBox_ball->setCheckState(Qt::Unchecked);
        ui->checkBox_book->setCheckState(Qt::Unchecked);
        ui->checkBox_film->setCheckState(Qt::Unchecked);
        ui->checkBox_game->setCheckState(Qt::Unchecked);
        ui->checkBox_photo->setCheckState(Qt::Unchecked);
        ui->checkBox_travel->setCheckState(Qt::Unchecked);
        ui->checkBox_cartoon->setCheckState(Qt::Unchecked);
        ui->checkBox_painting->setCheckState(Qt::Unchecked);
    }
}

void My_Ui::on_pushButton_clicked()
{
    QString str;
    if(ui->radioButton_3->isChecked()){
        str = "专科";
    }
    if(ui->radioButton_4->isChecked()){
        str = "本科";
    }
    qDebug().noquote()<<"1.基本信息："<<endl
           <<ui->label_name->text()<<":"<<ui->lineEdit_name->text()<<" "
          <<ui->label_number->text()<<":"<<ui->lineEdit_number->text()<<" "
         <<ui->label_gender->text()<<":"<<ui->comboBox_gender->currentText()<<" "
        <<ui->label_birthday->text()<<":"<<ui->dateEdit_birthday->text()<<endl
       <<"2.学习情况："<<endl
      <<ui->label->text()<<":"<<ui->lineEdit_major->text()<<" "
     <<ui->label_2->text()<<":"<<ui->lineEdit_time->text()<<" "
    <<ui->label_3->text()<<":"<<str<<" "
    <<ui->label_4->text()<<":"<<ui->spinBox_year->value()<<endl
    <<"3.兴趣爱好："<<endl;
    if(ui->checkBox_ball->isChecked()){
        qDebug().noquote()<<ui->checkBox_ball->text()<<" ";
    }
    if(ui->checkBox_book->isChecked()){
        qDebug().noquote()<<ui->checkBox_book->text()<<" ";
    }
    if(ui->checkBox_film->isChecked()){
        qDebug().noquote()<<ui->checkBox_film->text()<<" ";
    }
    if(ui->checkBox_game->isChecked()){
        qDebug().noquote()<<ui->checkBox_game->text()<<" ";
    }
    if(ui->checkBox_photo->isChecked()){
        qDebug().noquote()<<ui->checkBox_photo->text()<<" ";
    }
    if(ui->checkBox_travel->isChecked()){
        qDebug().noquote()<<ui->checkBox_travel->text()<<" ";
    }
    if(ui->checkBox_cartoon->isChecked()){
        qDebug().noquote()<<ui->checkBox_cartoon->text()<<" ";
    }
    if(ui->checkBox_painting->isChecked()){
        qDebug().noquote()<<ui->checkBox_painting->text()<<" ";
    }
    qDebug().noquote()<<endl
           <<"4.联系方式："<<endl
          <<ui->label_5->text()<<":"<<ui->lineEdit_email<<" "
         <<ui->label_6->text()<<":"<<ui->lineEdit_phone<<endl;
}
