#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "calculatorhandler.h"
#include <QIntValidator>

namespace {
    int getNumber(QLineEdit* edit)
    {
        return edit->text().toInt();
    }
    void setNumber(QLineEdit* edit, int num)
    {
        edit->setText(QString::number(num));
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEditA->setValidator( new QIntValidator(0, 100, this) );
    ui->lineEditB->setValidator( new QIntValidator(0, 100, this) );

    connect(ui->btnAdd, &QAbstractButton::clicked, this, [this](){
        using namespace Calculator;
        setNumber(ui->lineEditResult, computeResultByHandler(OperationType::ADD));
    });

    connect(ui->btnSub, &QAbstractButton::clicked, this, [this](){
        using namespace Calculator;
        setNumber(ui->lineEditResult, computeResultByHandler(OperationType::SUB));
    });

    connect(ui->btnMul, &QAbstractButton::clicked, this, [this](){
        using namespace Calculator;
        setNumber(ui->lineEditResult, computeResultByHandler(OperationType::MUL));
    });

    connect(ui->btnDiv, &QAbstractButton::clicked, this, [this](){
        using namespace Calculator;
        setNumber(ui->lineEditResult, computeResultByHandler(OperationType::DIV));
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::computeResultByHandler(Calculator::OperationType type)
{
    return (*handler)(type, getNumber(ui->lineEditA), getNumber(ui->lineEditB));
}

