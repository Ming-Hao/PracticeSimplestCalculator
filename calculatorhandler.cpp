#include "calculatorhandler.h"
#include <functional>
CalculatorHandler::CalculatorHandler()
{
    initTable();
}

int CalculatorHandler::operator()(const Calculator::OperationType type, int a, int b)
{
    using namespace Calculator;
    if(operationTable.find(type) != operationTable.end()) {
        auto operation = operationTable[type];
        // return (this->*operation)(a,b);  // if not use bind
        auto operationBindThis = std::bind(operation, this,
                                           std::placeholders::_1, std::placeholders::_2);

        return operationBindThis(a, b);
    }
    return INT_MAX;
}

void CalculatorHandler::initTable()
{
    using namespace Calculator;
    operationTable.insert( {OperationType::ADD, &CalculatorHandler::add} );
    operationTable.insert( {OperationType::SUB, &CalculatorHandler::sub} );
    operationTable.insert( {OperationType::MUL, &CalculatorHandler::mul} );
    operationTable.insert( {OperationType::DIV, &CalculatorHandler::div} );
}

int CalculatorHandler::add(int a, int b)
{
    return a + b;
}

int CalculatorHandler::sub(int a, int b)
{
    return a - b;
}

int CalculatorHandler::mul(int a, int b)
{
    return a * b;
}

int CalculatorHandler::div(int a, int b)
{
    if( b == 0 )
        return INT_MAX;
    return a / b;
}
