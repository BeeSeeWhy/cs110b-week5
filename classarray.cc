#include <iomanip>
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

//protoypes since they call each other
void menu(Person array[], int &);
void addNewEntry(Person array[], int &);
void search(Person array[], int);

void sortArray(Person persons[], int length) {
    int i, j;
    for(i = 0; i < length - 1; i++) {
        int minValue = i;
        for(j = i + 1; j < length; j++) {
            if(persons[j].name() < persons[minValue].name())
                minValue = j;
        }

        Person temp;
        temp = persons[i];
        persons[i] = persons[minValue];
        persons[minValue] = temp;
    }
}

void printAddressBook(Person persons[], int numberOfPeople) {
  //sort before print
  sortArray(persons, numberOfPeople);

  //test to make sure working
  for(int i = 0; i < numberOfPeople; i++) {
    cout << setw(5) << left << i + 1;
    cout << persons[i].name() << endl;
    cout << setw(5) << " " << persons[i].telephoneNumber << endl;
    cout << setw(5) << " " << persons[i].streetAddress << endl;
    cout << setw(5) << " " << persons[i].email << endl;
    cout << endl;
  }

  menu(persons, numberOfPeople);
}

void hardCodePeople(Person persons[], int &numberOfPeople) {
  persons[0].lastName = "Sioux";
  persons[0].firstName = "Siouxsie";
  persons[0].telephoneNumber = "702-555-5555";
  persons[0].streetAddress = "3570 S Las Vegas Blvd, Las Vegas, NV 89109";
  persons[0].email = "siouxsie@sioux.com";
  numberOfPeople++;

  persons[1].lastName = "Addams";
  persons[1].firstName = "Morticia";
  persons[1].telephoneNumber = "415-666-1313";
  persons[1].streetAddress = "13 Funston Street, San Francisco, CA 94129";
  persons[1].email = "morticia@addams.com";
  numberOfPeople++;

  persons[2].lastName = "Bates";
  persons[2].firstName = "Norman";
  persons[2].telephoneNumber = "323-555-5555";
  persons[2].streetAddress = "1070 272nd Street, Aldergrove, BC V4W 2P8, Canada";
  persons[2].email = "motherknowsbest@bates.com";
  numberOfPeople++;
}

//Searching the address book
void search(Person persons[], int numberOfPeople) {
	int userSearch;
	//persons[numberOfPeople];
	string fname;
	string lname;

	cout << endl;
	cout << "1. Search First Name" << endl;
	cout << "2. Search Last Name" << endl;
	cout << "Enter your choice (1-2): ";
	cin >> userSearch;

	switch (userSearch) {
	case 1:
		cout << "First Name: ";
		cin >> fname;
		cout << endl;

		for (int i = 0; i < numberOfPeople; i++) {
			if (fname.compare(persons[i].firstName) == 0) {
				cout << persons[i].name() << endl;
				cout << persons[i].telephoneNumber << endl;
				cout << persons[i].streetAddress << endl;
				cout << persons[i].email << endl;
			}
		}
		cout << endl;
		cin.ignore();
		break;
	case 2:
		cout << "Last Name: ";
		cin >> lname;

		for (int i = 0; i < numberOfPeople; i++) {
			if (lname.compare(persons[i].lastName) == 0) {
				cout << persons[i].name() << endl;
				cout << persons[i].telephoneNumber << endl;
				cout << persons[i].streetAddress << endl;
				cout << persons[i].email << endl;
			}
		}
		cout << endl;
		cin.ignore();
		break;
	default:
		cout << "Not a valid option" << endl;
		break;
	}
	menu(persons, numberOfPeople);
}

//adding an entry
void addNewEntry(Person persons[], int &numberOfPeople) {
  int i = numberOfPeople;

  cin.ignore();
  cout << "Enter last name : ";
  getline(cin, persons[i].lastName, '\n');

  cout << "Enter first name: ";
  getline(cin, persons[i].firstName, '\n');

  cout << "Enter telephone number: ";
  getline(cin, persons[i].telephoneNumber, '\n');

  cout << "Enter street address: ";
  getline(cin, persons[i].streetAddress, '\n');

  cout << "Enter email: ";
  getline(cin, persons[i].email, '\n');

  cout << endl;
  cout << endl;

  //increment so we know how many elements
  //are used in array
  numberOfPeople++;
  cout << numberOfPeople << endl; //test to make sure increment

  printAddressBook(persons, numberOfPeople);
  menu(persons, numberOfPeople);
}

//menu and user choice
void menu(Person persons[], int &numberOfPeople) {
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
   case 1 :  addNewEntry(persons, numberOfPeople);
             break;
   case 2 :  // delete an entry
             break;
   case 3 :  // edit an entry
             break;
   case 4 :  printAddressBook(persons, numberOfPeople);
             break;
   case 5 :  search(persons, numberOfPeople);
             break;
   case 6 :  exit(0);
 }
}


int main() {
  const int ARRAY_SIZE = 100;
  int numberOfPeople = 0;
  Person addressBook[ARRAY_SIZE];

  //hard code people in address book
  hardCodePeople(addressBook, numberOfPeople);

  //call menu
  menu(addressBook, numberOfPeople);

  return 0;
}
