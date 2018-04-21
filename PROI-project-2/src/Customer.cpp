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

#include "Customer.hpp"
#include "Queue.hpp"

/****CLASS CUSTOMER****/

/*CONSTRUCTORS*/

//// Parameters
Customer::Customer(std::string p_forename, std::string p_surname, uint p_age)
{
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
bool Customer::operator== (Customer & another) const
{
	return
		this->forename==another.forename &&
		this->surname==another.surname &&
		this->age==another.age;
}

/*METHODS*/

uint Customer::rate(Show *show_r)
{
  int rate = rand()%10;
  show_r->add_rate(rate);
  return rate;
}

//// Precised info
void Customer::displayInfo (CUS_INFO info)
{
      std::cout << getInfo(info).rdbuf();
}

//// All info
void Customer::displayInfo()
{
      std::cout << getInfo().rdbuf();
}

//// Precised info
std::ostringstream Customer::getInfo ( CUS_INFO info)
{
    std::ostringstream str;
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
      case TYPE:
        str << sex;
        break;
      default:
        throw "unprecised info[fun=Customer::getInfo(CUS_INFO)]";
        break;
      }
  return str;
}

//// All info
std::ostringstream Customer::getInfo()
{
  std::ostringstream str;
      str << "| Imie: " << getInfo(FORE).rdbuf()
          << "| Nazwisko: " << getInfo(SUR).rdbuf()
          << "| Wiek: " << getInfo(AGE).rdbuf()
          << "| Typ: " << getInfo(TYPE).rdbuf()
          << "|\n";
  return str;
}
