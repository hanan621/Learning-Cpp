#include <iostream>
using namespace std;

enum enOperation { Add = '+', Subtract = '-', Multiply = '*', Divide = '/' };

void readnumm(double &num1 , double &num2 , char &opty)
{
    cout << "**************************\n";
    cout << "please enter num1:\n";
    cin >> num1;
    cout << "please enter num2:\n";
    cin >> num2;
    cout << "Enter The operation type: \n";
    cin >> opty;
    cout << "**************************\n";
}   

void calculatnumm(double num1, double num2, char opty)
{
    enOperation readnuumes = (enOperation)opty;
    switch (readnuumes)
    {
    case enOperation::Add:
        cout << num1 + num2;
        break;
    case enOperation::Subtract:
        cout << num1 - num2;
        break;
    case enOperation::Multiply:
        cout << num1 * num2;
        break;
    case enOperation::Divide:
        cout << num1 / num2;
        break;
    default:
        cout << "Wrong Operation Type\n\n";
    }
}

int main()
{
    double nm1, nm2;
    char oop;
    
    readnumm(nm1, nm2, oop);
    calculatnumm(nm1, nm2, oop);
    
    return 0;
}
