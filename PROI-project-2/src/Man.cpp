/*
 * Man.cpp
 *
 * Class Deriviated from Customer representing the theater client
 * ^IMPLEMENTATION
 *
 * PROI, Lab project 3: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Przemysław Stawczyk
 */
#include "Man.hpp"

#include <ctime>
#include <cstdlib>
#include "err_struct.hpp"

Man::Man()
  :Customer("Jan", "Kowal", 18+rand()%60) {}

Man::Man(std::string p_forename, std::string p_surname, uint p_age)
  :Customer(p_forename, p_surname, p_age)
{
  this->sex = MAN;
  if(p_age < 18)
  {
    Err_Struct exept(0,1,1,"err = invalid age\n", "Mezczyzni sa pelnoletni !\n");
    throw exept;
  }
}

Man::~Man() {}

uint Man::Rate(Show *show_r)
{
  int rate = 3+rand()%6;
  show_r->add_rate(rate);
  return rate;
}
