/*
 * Customer.cpp
 *
 * Class Customer representing the theater client
 * ^DEFINITION
 *
 * PROI, Lab project 2: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Version: 06.04.2018, Kamil Zacharczuk
 * PROI, Lab project 3: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Przemysław Stawczyk
 */

#include <ctime>
#include <cstdlib>

#include "../include/Customer.hpp"
#include "../include/Queue.hpp"

/****CLASS CUSTOMER****/

/*CONSTRUCTORS*/

//// Parameters
Customer::Customer(std::string p_forename, std::string p_surname, uint p_age){
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
      std::cout << getInfo(info);
}

//// All info
void Customer::displayInfo() {
      std::cout << getInfo();
}

//// Precised info
std::iostream Customer::getInfo (CUS_INFO info) const{
  std::iostream str;
      switch (info){
      case FORE:
        str << forename;
        break;
      case SUR:
        str << surname;
        break;
      case AGE:
        str << age;
        break;
      default:
        throw "unprecised info[fun=Customer::getInfo(CUS_INFO)]";
        break;
      }
  return str;
}

//// All info
std::iostream Customer::getInfo() {
  std::iostream str;
      str << "| Imie: " << getInfo(FORE)
          << "| Nazwisko: " << getInfo(SUR);
          << "| Wiek: " << getInfo(AGE);
          << "|\n;
}
