#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


bmi_Calculator::bmi_Calculator() {

    setWindowTitle("BMI Calculator");
    QGridLayout* layout = new QGridLayout;

    //Weight label/editLine
    QLabel* weightLabel = new QLabel("Enter weight in kilograms ");
    weightInput = new QLineEdit;
    weightInput->setMaxLength(6);
    weightInput->setAlignment(Qt::AlignCenter);

    //Height label/editLine
    QLabel* heightLabel = new QLabel("Enter height in meters ");
    heightInput = new QLineEdit;
    heightInput->setMaxLength(4);
    heightInput->setAlignment(Qt::AlignCenter);

    //BMI
    QLabel* bmiLabel = new QLabel("BMI ");
    bmiAns = new QLCDNumber;
    bmiAns->setSegmentStyle(QLCDNumber::Flat);

    //Buttons
    QPushButton* clear_Button = new QPushButton("Clear All");
    QPushButton* calculate_Button = new QPushButton("Calculate");


    //Grid layout
    layout->addWidget(weightLabel, 0,0);
    layout->addWidget(weightInput, 0,1);

    layout->addWidget(heightLabel, 1,0);
    layout->addWidget(heightInput, 1,1);

    layout->addWidget(calculate_Button, 2,1);
    layout->addWidget(bmiLabel,3,0);
    layout->addWidget(bmiAns,3,1);
    layout->addWidget(clear_Button, 4,1);
    setLayout(layout);


    //connect signals and slots
    connect(calculate_Button, SIGNAL(clicked()), this, SLOT(bmi_function()));         //connects Calculate button to calculate() function.
    connect(clear_Button, SIGNAL(clicked()), this, SLOT(clear_function()));

    //Style Sheet
    calculate_Button->setStyleSheet("background-color: #42a5f5;"
                             "border: none;"
                             "color: white;padding: 1px;"
                             "text-align: center;"
                             "text-decoration: none;"
                             "font-size: 16px;"
                             "border-radius:12px;");
    clear_Button->setStyleSheet("background-color: #42a5f5;"
                             "border: none;"
                             "color: white;padding: 1px;"
                             "text-align: center;"
                             "text-decoration: none;"
                             "font-size: 16px;"
                             "border-radius:12px;");

}
// calculate bmi
void bmi_Calculator::bmi_function() {

    bool valid;
    QString wString = weightInput->text();
    QString hString = heightInput->text();
    error_Msg = new QErrorMessage(this);

    float weight_Value = wString.toFloat(&valid);
    if (!valid) {
        error_Msg->showMessage("Please enter a valid weight in kilograms!");
    }

    float height_Value= hString.toFloat(&valid);
    if (!valid) {
        error_Msg->showMessage("Please enter a valid height in meters!");
    }

    float answer=(weight_Value/(height_Value*height_Value));
    bmiAns->display(answer);


}

//clear widgets
void bmi_Calculator::clear_function(){
    weightInput->clear();
    heightInput->clear();
    bmiAns->display(0.00);
}
