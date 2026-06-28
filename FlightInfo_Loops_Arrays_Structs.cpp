#include <iostream>
#include <string>
#include <cmath>
using namespace std;
struct stflightInfo
{
    string flightNumber;
    string fromCity;
    string toCity;

};
void readflightInfo(stflightInfo &readIn)
{
    cout << "**********************************\n";
    cout << "Please Enter The Flight Number: \n";
    cin >> readIn.flightNumber;
    cout << "Please Enter Departure City: \n";
    cin >> readIn.fromCity;
    cout << "Please Enter Destination City: \n";
    cin >> readIn.toCity;
    cout << "**********************************\n";
}
void printFlightInfo(stflightInfo printIn)
{
    cout << "The Flight Number: " << printIn.flightNumber << endl;
    cout << "The Departure City: " << printIn.fromCity << endl;
    cout << "The Destination City: " << printIn.toCity << endl;
    cout << "**********************************\n";
}
void readAllFlights(stflightInfo arr[100] , int &readin)
{
    cout << "How Many flight: \n";
    cin >> readin;
    for (int count = 0 ; count < readin;count ++)
    {
        cout << "Please Enter The Flight Information: \n";

        readflightInfo(arr[count]);
    }
}
void printAllFlights(stflightInfo arr[100], int printin)
{
    for (int count = 0; count < printin; count++)
    {
        printFlightInfo(arr[count]);

    }
}
int main()
{
     
    stflightInfo infooo[100];
    int infoo = 0;

    readAllFlights(infooo,infoo);
    printAllFlights(infooo, infoo);
    

    return 0;
}
