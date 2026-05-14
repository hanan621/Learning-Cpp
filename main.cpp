تفضلي الكود جاهز ونظيف تماماً للرفع (بدون ملاحظات):

```cpp
#include <iostream>
#include <string>

using namespace std;

struct car
{
    string name; 
    string color;
    int  model;
    int price;
    bool isAutomatic;
    string plateNumber;
};

struct carowner
{
    string name;
    int age;
    string city;
    string phone;
};

int main()
{
    car carinfo;
    
    cout << "-------------------------the car information------------------\n";
    cout << "Please enter the name of the car? \n";
    getline(cin, carinfo.name);
    
    cout << "Please enter the color of the car? \n";
    cin >> carinfo.color;
    
    cout << "Please enter the model of the car? \n";
    cin >> carinfo.model; 
    
    cout << "Please enter the price of the car? \n";
    cin >> carinfo.price;
    
    cout << "is it Automatic 1 = yes, 0 = no \n";
    cin >> carinfo.isAutomatic;
    
    cin.ignore();
    cout << "Please enter the plate Number of the car? \n";
    getline(cin, carinfo.plateNumber);

    cout << "\n--- Car Summary ---\n";
    cout << "The name: " << carinfo.name << endl; 
    cout << "The Color: " << carinfo.color << endl; 
    cout << "The Model: " << carinfo.model << endl;
    cout << "The Price: " << carinfo.price << endl;
    cout << "is it Automatic: " << carinfo.isAutomatic << endl;
    cout << "The plate Number: " << carinfo.plateNumber << endl;
    
    cout << "\n-------------------------the owner information------------------\n";
    
    carowner owner;
    
    cout << "Please enter your full name?\n";
    getline(cin, owner.name);
    
    cout << "Please enter your Age?\n";
    cin >> owner.age;
    
    cin.ignore();
    cout << "Please enter your City?\n";
    getline(cin, owner.city);
    
    cout << "Please enter your phone number?\n";
    cin >> owner.phone;

    cout << "\n--- Owner Summary ---\n";
    cout << "The name: " << owner.name << endl;
    cout << "The age: " << owner.age << endl; 
    cout << "The city: " << owner.city << endl;
    cout << "The phone number: " << owner.phone << endl;

    return 0;
}

```
