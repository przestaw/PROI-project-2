/*
 * test2.cpp
 *
 * TEST #2
 * A programme for testing the theater implementing classes
 * Testing includes:
 *  > Managing the customers database
 *  > Managing the performances database
 *  > Subscribing and unsubscribing customers to the performances
 *
 * PROI, Lab project 2: 'Theater'
 * Tutor: dr inz. Wiktor Kuśmirek
 * Version 06.04.18, Kamil Zacharczuk
 * PROI, Lab project 3: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Przemysław Stawczyk
 */

#include <iostream>
#include <string>

#include "../include/Customer.hpp"
#include "../include/Show.hpp"
#include "../include/Menus.hpp"
#include "../include/Queue.hpp" //template linked list queue

using namespace std;

//Programme info
void progInfo();

//Displaying lists - template function
template <typename T>
bool print(Queue<T>*, int);

/*****MAIN FUNCTION*****/

int main()
{
	progInfo();
	Menus theater_1;
	theater_1.init(cin, cout);

  return 0;
}

//TODO:

/*Programme info*/
void progInfo()
{
	cout << "'Theater' - TEST #2 v1.0" << endl;
	cout << "Projekt laboratoryjny 2, PROI" << endl;
	cout << "Prowadzacy: dr inz. Wiktor Kusmirek" << endl;
	cout << "Kamil Zacharczuk, 03.2018" << endl;
	cout << "Projekt laboratoryjny 3, PROI" << endl;
	cout << "Prowadzacy: dr inz. Wiktor Kusmirek" << endl;
	cout << "Przemyslaw Stawczyk, 18L" << endl;

}


/*Printing the elements - template function*/
template <typename T>
bool print(Queue<T>* queue, int count)
{
	if (count){
		T* temp_el;
		cout << "~~~Lista elementow bazy danych~~~" << endl;
		for (int i = 0; i<count; i++){
			cout << "NUMER " << i+1 << "/" << endl;

			temp_el = queue->getElement(i);
			if (temp_el!=nullptr) { temp_el->displayInfo(); }
			else { cout << "Cos poszlo nie tak." << endl; }
		}
	}
	else{
		return false;
	}
	return true;
}
