#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QLCDNumber>
#include <QString>
#include <QMessageBox>
#include <QErrorMessage>


class bmi_Calculator : public QWidget {

Q_OBJECT
//Attributes
    QLineEdit* weightInput;
    QLineEdit* heightInput;
    QLCDNumber* bmiAns;
    QErrorMessage* error_Msg;
public:
    bmi_Calculator();
public slots:
    void bmi_function();
    void clear_function();

};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
