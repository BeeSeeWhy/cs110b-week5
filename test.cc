#include <iostream>
#include <string>
using namespace std;

//global variable so we can access by reference
//use this variable to assess elements that have
//data in them for sorting
int numberOfPeople;

//our class object
class Person {
 public:
 string lastName;
 string firstName;
 string name();
 string telephoneNumber;
 string streetAddress;
 string email;
};

//this concatenates so we can use
// addressBook[i].name() for sorting
string Person::name() {
 string name = lastName + ", " + firstName;

 return name;
}

void testPrint (Person persons[], int &numberOfPeople) {
  //test to make sure working
  cout << persons[0].name() << endl;
  cout << persons[0].telephoneNumber << endl;
  cout << persons[0].streetAddress << endl;
  cout << persons[0].email << endl;
  cout << endl;
  cout << numberOfPeople << endl;

  //test to make sure working
  cout << persons[1].name() << endl;
  cout << persons[1].telephoneNumber << endl;
  cout << persons[1].streetAddress << endl;
  cout << persons[1].email << endl;
  cout << endl;
  cout << numberOfPeople << endl;

  //test to make sure working
  cout << persons[2].name() << endl;
  cout << persons[2].telephoneNumber << endl;
  cout << persons[2].streetAddress << endl;
  cout << persons[2].email << endl;
  cout << endl;
  cout << numberOfPeople << endl;
}


void sortArray(Person persons[], int length) {
    int i, j;
    for(i = 0; i < length - 1; i++) {
        int minValue = i;
        for(j = i + 1; j < length; j++) {
            cout << i << " " << j << endl;
            if(persons[j].name() < persons[minValue].name())
                minValue = j;
        }
        cout << "break" << endl;
        Person temp;
        temp = persons[i];
        persons[i] = persons[minValue];
        persons[minValue] = temp;

    }
}


int main() {
  const int ARRAY_SIZE = 4;
  int numberOfPeople = 0;
  Person addressBook[ARRAY_SIZE];
  //hard coding a couple entries
  addressBook[0].lastName = "Sioux";
  addressBook[0].firstName = "Siouxsie";
  addressBook[0].telephoneNumber = "702-555-5555";
  addressBook[0].streetAddress = "3570 S Las Vegas Blvd, Las Vegas, NV 89109";
  addressBook[0].email = "siouxsie@sioux.com";
  numberOfPeople++;

  //test to make sure working
  /*cout << addressBook[0].name() << endl;
  cout << addressBook[0].telephoneNumber << endl;
  cout << addressBook[0].streetAddress << endl;
  cout << addressBook[0].email << endl;
  cout << endl;
  cout << numberOfPeople << endl;*/

  //hard coding a couple entries
  addressBook[1].lastName = "Addams";
  addressBook[1].firstName = "Morticia";
  addressBook[1].telephoneNumber = "415-666-1313";
  addressBook[1].streetAddress = "13 Funston Street, San Francisco, CA 94129";
  addressBook[1].email = "morticia@addams.com";
  numberOfPeople++;

  //test to make sure working
  /*cout << addressBook[1].name() << endl;
  cout << addressBook[1].telephoneNumber << endl;
  cout << addressBook[1].streetAddress << endl;
  cout << addressBook[1].email << endl;
  cout << endl;
  cout << numberOfPeople << endl;*/

  //hardcoding entry
  addressBook[2].lastName = "Bates";
  addressBook[2].firstName = "Norman";
  addressBook[2].telephoneNumber = "323-555-5555";
  addressBook[2].streetAddress = "1070 272nd Street, Aldergrove, BC V4W 2P8, Canada";
  addressBook[2].email = "motherknowsbest@bates.com";
  numberOfPeople++;

  //test to make sure working
  /*cout << addressBook[2].name() << endl;
  cout << addressBook[2].telephoneNumber << endl;
  cout << addressBook[2].streetAddress << endl;
  cout << addressBook[2].email << endl;
  cout << endl;
  cout << numberOfPeople << endl;*/

  cout << "entering testPrint" << endl;
  testPrint(addressBook, numberOfPeople);

  cout << "entering sortArray" << endl;
  sortArray(addressBook, numberOfPeople);

  testPrint(addressBook, numberOfPeople);
  return 0;
}
