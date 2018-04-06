/*
 * Customer.cpp
 *
 * Class Customer representing the theater client
 * ^DEFINITION
 *
 * PROI, Lab project 2: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Version: 06.04.2018, Kamil Zacharczuk
 */
 
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "../include/Customer.hpp"
#include "../include/Queue.hpp"

/****CLASS CUSTOMER****/

/*CONSTRUCTORS*/

//// Parameters
Customer::Customer(std::string p_forename, std::string p_surname, UNSH p_age){
      this->forename = p_forename;
      this->surname = p_surname;
	this->age = p_age;
}

//// Default
Customer::Customer()
{
      std::srand(std::time(nullptr));

      this->forename = "Jan";
      this->surname = "Kowalski";
      this->age = rand()%77+13;
}

/*DESTRUCTOR*/
Customer::~Customer() {}


/*Operator == overloading*/
bool Customer::operator== (Customer & another) const{
	return
		this->forename==another.forename &&
		this->surname==another.surname &&
		this->age==another.age;
}

/*METHODS*/

//// Precised info
void Customer::displayInfo (CUS_INFO info) const{
      switch (info){
      case FORE: std::cout << forename; break;
      case SUR: std::cout << surname; break;
      case AGE: std::cout << age; break;
      default: std::cout << "unprecised info"; break;
      }
}

//// All info
void Customer::displayInfo() const{
      std::cout << "| Imie: "; displayInfo(FORE);
      std::cout << "| Nazwisko: "; displayInfo(SUR);
      std::cout << "| Wiek: "; displayInfo(AGE);
      std::cout << "|" << std::endl;
}
