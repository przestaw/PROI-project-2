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
#include "err_struct.hpp"

Child::Child()
  :Customer("Janek", "Kowalczyk", rand()%8+10) {}

Child::Child(std::string p_forename, std::string p_surname, uint p_age)
  :Customer(p_forename, p_surname, p_age)
{
  this->sex = KID;
  if(p_age > 17)
  {
    Err_Struct exept(0,1,1,"err = invalid age\n", "Dzieci sa jedynie niepelnoletnie !\n");
    throw exept;
  }
}

Child::~Child() {}

uint Child::Rate(Show *show_r)
{
  int rate = rand()%5;
  show_r->add_rate(rate);
  return rate;
}
