/*
 * Child.cpp
 *
 * Class Deriviated from Customer representing the theater client
 * ^IMPLEMENTATION
 *
 * PROI, Lab project 3: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Przemysław Stawczyk
 */
#include "Child.hpp"

#include <ctime>
#include <cstdlib>

Child::Child()
  :Customer("Janek", "Kowalczyk", rand()%8+10) {}

Child::Child(std::string p_forename, std::string p_surname, uint p_age)
  :Customer(p_forename, p_surname, p_age)
{
  if(p_age > 17)
  {
    throw "invalid age[fun=Child::Child(std::string p_forename, std::string p_surname, uint p_age)]";
  }
}

Child::~Child() {}

uint Child::rate(Show *show_r)
{
  int rate = rand()%5;
  show_r->add_rate(rate);
  return rate;
}
