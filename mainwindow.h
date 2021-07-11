#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "calculatorenum.h"

class CalculatorHandler;

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
    int computeResultByHandler(Calculator::OperationType type);

private:
    Ui::MainWindow *ui;
    CalculatorHandler* handler;
};
#endif // MAINWINDOW_H
