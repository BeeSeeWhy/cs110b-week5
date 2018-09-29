#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
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
void addNewEntry(Person[], int &);
void hardCodePeople(Person[], int &);
void menu(Person[], int &);
void printAddressBook(Person[], int);
void search(Person[], int &);
void sortArray(Person[], int);

int main() {
	const int ARRAY_SIZE = 100;
	int numberOfPeople = 0;
	Person addressBook[ARRAY_SIZE];
	string goBack;
	bool open = true;

	//hard code people in address book
	hardCodePeople(addressBook, numberOfPeople);

	//call menu
	menu(addressBook, numberOfPeople);

	return 0;

}
//adding an entry
void addNewEntry(Person persons[], int &numberOfPeople) {
	cout << endl;
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

//menu and user choice
void menu(Person persons[], int &numberOfPeople) {
	int choice;
	do {
		cout << "1. Add New Entry" << endl;
		cout << "2. List All Entries" << endl;
		cout << "3. Search For An Entry" << endl;
		cout << "4. Quit Program" << endl;
		cout << "Enter your choice (1-4): ";
		cin >> choice;

	} while (!(choice > 0 && choice < 7));
	switch (choice) {
	case 1:  addNewEntry(persons, numberOfPeople);
		break;
	case 2:  printAddressBook(persons, numberOfPeople);
		break;
	case 3:  search(persons, numberOfPeople);
		break;
	case 4:  exit(0);
	}
}

void printAddressBook(Person persons[], int numberOfPeople) {
	//sort before print
	sortArray(persons, numberOfPeople);

	//test to make sure working
	for (int i = 0; i < numberOfPeople; i++) {
		cout << setw(5) << left << i + 1;
		cout << persons[i].name() << endl;
		cout << setw(5) << ' ' << persons[i].telephoneNumber << endl;
		cout << setw(5) << ' ' << persons[i].streetAddress << endl;
		cout << setw(5) << ' ' << persons[i].email << endl;
		cout << endl;
		}
	menu(persons, numberOfPeople);
}

//Searching the address book
void search(Person persons[], int &numberOfPeople) {
	int userSearch;
	string fname;
	string lname;
	char deleteChoice;
	Person newAddressBook[100];

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
				cout << endl;

				//Edit Delete Menu
				int choice;
				cout << "1. Edit Entry" << endl;
				cout << "2. Delete Entry" << endl;
				cout << "3. Return to Main Menu" << endl;
				cout << "Enter your choice (1-3): ";
				cin >> choice;

				switch (choice) {
				case 1:
					cout << "Are you sure that you want to edit this entry? Y/N" << endl;
					cout << persons[i].name() << endl;
					cin >> deleteChoice;
					if (deleteChoice == 'Y' || 'y') {
						cin.ignore();
						cout << "Enter last name : ";
						getline(cin, persons[i].lastName);
						cout << "Enter first name: ";
						getline(cin, persons[i].firstName);
						cout << "Enter telephone number: ";
						getline(cin, persons[i].telephoneNumber);
						cout << "Enter street address: ";
						getline(cin, persons[i].streetAddress);
						cout << "Enter email: ";
						getline(cin, persons[i].email);
						cout << endl;
					}
					else {
						cout << "Start over from the main menu" << endl;
			  	}
					break;
				case 2: // Delete
					cout << "Are you sure that you want to edit this entry? Y/N" << endl;
					cout << persons[i].name() << endl;
					cin >> deleteChoice;
					if (deleteChoice == 'Y' || 'y') {
						cin.ignore();

						for (int j = i; j < (numberOfPeople - i); j++) {
							persons[j] = persons[j + 1];
						}

						persons[numberOfPeople].firstName = "";
						persons[numberOfPeople].lastName = "";
						persons[numberOfPeople].telephoneNumber = "";
						persons[numberOfPeople].streetAddress = "";
						persons[numberOfPeople].email = "";

						numberOfPeople -= 1;
						cout << "The entry has been deleted " << endl;
						cout << endl;
					}
					else {
						cout << "Start over from the main menu" << endl;
					}
					cin.ignore();
					break;
				case 3: menu(persons, numberOfPeople);
					break;
				default: cout << "Not a valid entry" << endl;
					break;
				}
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
				cout << endl;

				//Edit Delete Menu
				int choice;
				cout << "1. Edit Entry" << endl;
				cout << "2. Delete Entry" << endl;
				cout << "3. Return to Main Menu" << endl;
				cout << "Enter your choice (1-3): ";
				cin >> choice;

				switch (choice) {
				case 1:  // Edit
					cout << "Are you sure that you want to edit this entry? Y/N" << endl;
					cout << persons[i].name() << endl;
					cin >> deleteChoice;
					if (deleteChoice == 'Y' || 'y') {
						cin.ignore();
						cout << "Enter last name : ";
						getline(cin, persons[i].lastName);
						cout << "Enter first name: ";
						getline(cin, persons[i].firstName);
						cout << "Enter telephone number: ";
						getline(cin, persons[i].telephoneNumber);
						cout << "Enter street address: ";
						getline(cin, persons[i].streetAddress);
						cout << "Enter email: ";
						getline(cin, persons[i].email);
						cout << endl;
					}
					else {
						cout << "Start over from the main menu" << endl;
					}
					break;
				case 2: //Delete
						cout << "Are you sure that you want to edit this entry? Y/N" << endl;
						cout << persons[i].name() << endl;
						cin >> deleteChoice;
						if (deleteChoice == 'Y' || 'y') {
							cin.ignore();


							for (int j = i; j < (numberOfPeople - i); j++)
							{
								persons[j] = persons[j+1];
							}

							persons[numberOfPeople].firstName = "";
							persons[numberOfPeople].lastName = "";
							persons[numberOfPeople].telephoneNumber = "";
							persons[numberOfPeople].streetAddress = "";
							persons[numberOfPeople].email = "";

							numberOfPeople -= 1;
							cout << "The entry has been deleted " << endl;
							cout << endl;
						}
						else {
							cout << "Start over from the main menu" << endl;
					}
				cin.ignore();
					break;
				case 3: // Main Menu
					menu(persons, numberOfPeople);
					break;
				default: cout << "Not a valid entry" << endl;
					break;
        }
			}
		}
		cout << endl;
		cin.ignore();
		break;
	default:
		cout << "Not a valid option" << endl;
		break;
	}
	cout << endl;
	menu(persons, numberOfPeople);
}

void sortArray(Person persons[], int length) {
	int i, j;
	for (i = 0; i < length - 1; i++) {
		int minValue = i;
		for (j = i + 1; j < length; j++) {
			if (persons[j].name() < persons[minValue].name())
				minValue = j;
		}
		Person temp;
		temp = persons[i];
		persons[i] = persons[minValue];
		persons[minValue] = temp;
	}
}
