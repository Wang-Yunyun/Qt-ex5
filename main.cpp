#include "my_ui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    My_Ui w;
    w.setWindowTitle("用户信息");
    w.show();

    return a.exec();
}
