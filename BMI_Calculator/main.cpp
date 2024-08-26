#include "mainwindow.h"
#include <QColor>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    QPalette pal = a.palette();
    pal.setColor(QPalette::Window,QColor(227, 242, 253));
    a.setPalette(pal);


    bmi_Calculator calculator;
    calculator.show();
    return a.exec();
}
