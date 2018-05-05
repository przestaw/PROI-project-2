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
  this->sex = UNDEFINED;
}

//// Default
Customer::Customer()
{
  std::srand(std::time(nullptr));

  this->forename = "Adolf";
  this->surname = "Hitler";
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
		this->age==another.age &&
    this->sex==another.sex;
}

/*METHODS*/
uint Customer::Rate(Show *show_r)
{
  int rate = rand()%11;
  show_r->add_rate(rate);
  return rate;
}

//// Precised info
std::stringstream Customer::getInfo ( CUS_INFO info)
{
    std::stringstream str;
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
        switch (sex)
        {
          case KID:
            str << "dziecko";
            break;
          case WOMAN:
            str << "kobieta";
            break;
          case MAN:
            str << "mezczynza";
            break;
          case UNDEFINED:
            str << "transwestyta";
            break;
          default:
            str << "error";
        };
        break;
      default:
        str << "error";
        break;
      }
  return str;
}

//// All info
std::stringstream Customer::getInfo()
{
  std::stringstream str;
      str << "| Imie: " << getInfo(FORE).rdbuf()
          << " | Nazwisko: " << getInfo(SUR).rdbuf()
          << " | Wiek: " << getInfo(AGE).rdbuf()
          << " | Typ: " << getInfo(TYPE).rdbuf()
          << " |\n";
  return str;
}
