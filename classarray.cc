#include <iostream>
#include <string>
//#include "Person.h"
using namespace std;

int numberOfPeople;

class Person {
 public:
 string lastName;
 string firstName;
 string name();
 string telephoneNumber;
 string streetAddress;
 string email;
};

string Person::name() {
 string name = lastName + ", " + firstName;

 return name;
}

void menu(int &);
void addNewEntry(int &);

void menu(int &numberOfPeople) {
 int choice;
 do {
   cout << "1. Add New Entry" << endl;
   cout << "2. Delete An Entry" << endl;
   cout << "3. Edit An Entry" << endl;
   cout << "4. List All Entries" << endl;
   cout << "5. Search For An Entry" << endl;
   cout << "6. Quit Program" << endl;
   cout << "Enter your choice (1-6): " << endl;
   cin >> choice;

 } while (!(choice > 0 && choice < 7));

 switch (choice) {
   case 1 :  addNewEntry(numberOfPeople);
             break;
   case 2 :  // delete an entry
             break;
   case 3 :  // edit an entry
             break;
   case 4 :  // list all entries
             break;
   case 5 :  // search for an entry
             break;
   case 6 :  exit(0);
 }
}

void addNewEntry(int &numberOfPeople) {
  const int ARRAY_SIZE = 100;
  Person addressBook[ARRAY_SIZE];

  int i;
  if (numberOfPeople == 0)
   i = numberOfPeople;
 else
   i = numberOfPeople + 1;

 cin.ignore();
 cout << "Enter last name : ";
 getline(cin, addressBook[i].lastName);

 cout << "Enter first name: ";
 getline(cin, addressBook[i].firstName);

 cout << "Enter telephone number: ";
 getline(cin, addressBook[i].telephoneNumber);

 cout << "Enter street address: ";
 getline(cin, addressBook[i].streetAddress);

 cout << "Enter email: ";
 getline(cin, addressBook[i].email);
 cout << endl;
 cout << endl;

 numberOfPeople++;
 cout << numberOfPeople << endl;

 menu(numberOfPeople);
}

int main() {
  const int ARRAY_SIZE = 100;
  int numberOfPeople = 0;
  Person addressBook[ARRAY_SIZE];

  addressBook[0].lastName = "Addams";
  addressBook[0].firstName = "Morticia";
  addressBook[0].telephoneNumber = "415-666-1313";
  addressBook[0].streetAddress = "13 Funston Street, San Francisco, CA 94129";
  addressBook[0].email = "morticia@addams.com";
  numberOfPeople++;
  cout << addressBook[0].name() << endl;
  cout << addressBook[0].telephoneNumber << endl;
  cout << addressBook[0].streetAddress << endl;
  cout << addressBook[0].email << endl;
  cout << endl;
  cout << numberOfPeople << endl;

  addressBook[1].lastName = "Bates";
  addressBook[1].firstName = "Norman";
  addressBook[1].telephoneNumber = "323-555-5555";
  addressBook[1].streetAddress = "1070 272nd Street, Aldergrove, BC V4W 2P8, Canada";
  addressBook[1].email = "motherknowsbest@bates.com";
  numberOfPeople++;
  cout << addressBook[1].name() << endl;
  cout << addressBook[1].telephoneNumber << endl;
  cout << addressBook[1].streetAddress << endl;
  cout << addressBook[1].email << endl;
  cout << endl;
  cout << numberOfPeople << endl;


  menu(numberOfPeople);

  return 0;
}
