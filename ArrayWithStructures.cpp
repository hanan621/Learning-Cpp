#include <iostream>
#include <string>

using namespace std;

struct stcardinfo
{
    string FirstName;
    string LastName;
    int age;
    string phone;
};

void readcardinfo(stcardinfo &readcard)
{
    cout << "********************************\n";
    cout << "Please Enter Your First name: \n";
    cin >> readcard.FirstName;
    cout << "Please Enter Your Last name: \n";
    cin >> readcard.LastName;
    cout << "Please Enter Your Age: \n";
    cin >> readcard.age;
    cout << "Please Enter Your Phone Number: \n";
    cin >> readcard.phone;
}

void printcard1(stcardinfo readcard)
{
    cout << "********************************\n";
    cout << "Your First name:" << readcard.FirstName << endl;
    cout << "Your Last name:" << readcard.LastName << endl;
    cout << "Your Age:" << readcard.age << endl;
    cout << "Your Phone Number:" << readcard.phone << endl;
}

void read(stcardinfo presooons[2])
{
    readcardinfo(presooons[0]);
    readcardinfo(presooons[1]);
}

void printt(stcardinfo presooons[2])
{
    printcard1(presooons[0]);
    printcard1(presooons[1]);
}

int main()
{
    stcardinfo persons[2];
    read(persons);
    printt(persons);

    return 0;
}
