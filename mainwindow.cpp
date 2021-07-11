#include "mainwindow.h"
#include "ui_mainwindow.h"

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
        int result = handler(Calculator::OperationType::ADD,
                             getNumber(ui->lineEditA),
                             getNumber(ui->lineEditB));
        setNumber(ui->lineEditResult, result);
    });

    connect(ui->btnSub, &QAbstractButton::clicked, this, [this](){
        int result = handler(Calculator::OperationType::SUB,
                             getNumber(ui->lineEditA),
                             getNumber(ui->lineEditB));
        setNumber(ui->lineEditResult, result);
    });

    connect(ui->btnMul, &QAbstractButton::clicked, this, [this](){
        int result = handler(Calculator::OperationType::MUL,
                             getNumber(ui->lineEditA),
                             getNumber(ui->lineEditB));
        setNumber(ui->lineEditResult, result);
    });

    connect(ui->btnDiv, &QAbstractButton::clicked, this, [this](){
        int result = handler(Calculator::OperationType::DIV,
                             getNumber(ui->lineEditA),
                             getNumber(ui->lineEditB));
        setNumber(ui->lineEditResult, result);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

