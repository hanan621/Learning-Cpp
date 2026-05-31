#include <iostream>
#include <string>
using namespace std;


void SwapNumbers(int &num1, int &num2)
{
   
    int temp;
    temp = num1;
    num1 = num2;
     num2 = temp;
    cout <<"after temp\n"<<num1 << endl <<num2 << endl;

  
}
int main()
{
    int number1,number2 ;
    cout <<"Enter number1 \n ";
    cin >> number1;
    cout <<"Enter number2 \n ";
    cin >> number2;
    cout <<"you enter \n"<<number1<< endl<<number2 <<endl;
    SwapNumbers(number1,number2);




    return 0;
}
