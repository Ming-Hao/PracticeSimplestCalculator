#ifndef CALCULATORHANDLER_H
#define CALCULATORHANDLER_H

#include "calculatorenum.h"
#include "unordered_map"

class CalculatorHandler
{
public:
    CalculatorHandler();
    using OperationPtr = int(CalculatorHandler::*)(int,int);
    std::unordered_map<Calculator::OperationType, OperationPtr> operationTable;

    int operator()(const Calculator::OperationType type, int a, int b);
private:
    void initTable();
    int add(int a, int b);
    int sub(int a, int b);
    int mul(int a, int b);
    int div(int a, int b);
};

#endif // CALCULATORHANDLER_H
