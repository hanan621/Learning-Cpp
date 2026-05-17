#include <iostream>
#include <string>
using namespace std;
enum enStatus { Single, Married };
enum enGender { Male, Female };

struct staddress
{
    
    string Country;
    string City;
    string Region;
    string Streetname;
    string name;
    int age;
};


struct stcontact
{
    string Email;
    string Number;
    string PostalCode;
    staddress address;
    
};

struct stcardinfo
{
    string Bankname;
    string CardNumber;
    double Balance; 
    enStatus Status;
    enGender Gender;
    stcontact contact;
   
};



int main()
{
    stcardinfo allinfo;
   
    allinfo.contact.address.name = "Hanane Hamid";
    allinfo.contact.address.age = 89;
    allinfo.Gender = enGender::Female;
    allinfo.Status = enStatus::Single;
    allinfo.contact.address.Country = "Tch";
    allinfo.contact.address.City = "N'Dj";
    allinfo.contact.address.Region = "Moursal";
    allinfo.contact.address.Streetname = "Rue de Bordeaux";
    allinfo.contact.Email = "moreaz@gmail.com";
    allinfo.contact.Number = "0378923589";
    allinfo.contact.PostalCode = "4326";
    allinfo.Bankname = "Tcbank";
    allinfo.CardNumber = "98756543456776";
    allinfo.Balance = 25000;

    cout <<"Name :" <<allinfo.contact.address.name << endl;
    cout <<"Age: " <<allinfo.contact.address.age << endl;
    cout << "Gender: "<< allinfo.Gender << endl;
    cout <<"Status: " << allinfo.Status << endl;
    cout << "**************************************\n";
    cout <<"Country: " << allinfo.contact.address.Country << endl;
    cout <<"City: " << allinfo.contact.address.City << endl;
    cout <<"Region: " << allinfo.contact.address.Region << endl;
    cout <<"Streetname: " << allinfo.contact.address.Streetname << endl;
    cout << "**************************************\n";
    cout <<"Email: " << allinfo.contact.Email << endl;
    cout <<"Number: " << allinfo.contact.Number << endl;
    cout <<"Postal Cod: " << allinfo.contact.PostalCode << endl;
    cout <<"Bank name: " << allinfo.Bankname << endl;
    cout <<"Card Number: " << allinfo.CardNumber << endl;
    cout <<"Balance: " << allinfo.Balance << endl;
    cout << "**************************************\n";






    return 0;

}

 
