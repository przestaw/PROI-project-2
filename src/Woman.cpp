/*
 * Woman.cpp
 *
 * Class Deriviated from Customer representing the theater client
 * ^IMPLEMENTATION
 *
 * PROI, Lab project 3: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Przemysław Stawczyk
 */
#include "Woman.hpp"

#include <ctime>
#include <cstdlib>
#include "err_struct.hpp"

Woman::Woman()
  :Customer("Janina", "Kowalczowa", 20+rand()%50) {}

Woman::Woman(std::string p_forename, std::string p_surname, uint p_age)
  :Customer(p_forename, p_surname, p_age)
{
  this->sex = WOMAN;
  if(p_age < 18)
  {
    Err_Struct exept(0,1,1,"err = invalid age\n", "Kobiety sa pelnoletnie !\n");
    throw exept;
  }
}

Woman::~Woman() {}

uint Woman::Rate(Show *show_r)
{
  int rate = 5+rand()%6;
  show_r->add_rate(rate);
  return rate;
}
