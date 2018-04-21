/*
 * Menus.cpp
 *
 * Class Menus created to handle travelling between menus in the test2 programme
 * ^DEFINITION
 *
 * Lab project 2: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Version 06.04.18, Kamil Zacharczuk
 * PROI, Lab project 3: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Przemysław Stawczyk
 */

#include "../include/Menus.hpp"
#include "../include/Customer.hpp"
#include "../include/Show.hpp"
#include "../include/Queue.hpp"

/*Cons&des*/
Menus::Menus() {}
Menus::~Menus() {}

uint Menus::getOption(uint min,uint max)
{
  uint input;
  do{
    std::cout << "\nChoose option :";
    std::cin.clear();
    std::cin.sync();
    std::cin >> input;
  }while(std::cin.fail());
  if(input > max || input < min)
  {
    throw "invalid input[fun=Menus::getOption(int min, int max)]";
  }
  return input;
}

std::ostringstream Menus::putOptions(OPTIONS input)
{
  std::ostringstream ss_t;
  switch (input) {
    case MAIN:
      ss_t.str("---MENU GLOWNE---\n");
      ss_t.str("1. Zarzadzaj klientami\n");
      ss_t.str("2. Zarzadzaj przedstawieniami\n");
      ss_t.str("3. Zarzadzaj rezerwacjami\n");
      ss_t.str("0. Wyjdz z programu\n");
      break;
    case CUSTOMERS:
      ss_t.str("-ZARZADZANIE KLIENTAMI-\n");
      ss_t.str("1. Nowy klient\n");
      ss_t.str("2. Usun klienta\n");
      ss_t.str("3. Wyswietl liste klientow teatru\n");
      ss_t.str("0. Powrot do menu glownego\n");
      break;
    case PERFORMANCES:
      ss_t.str("- ZARZADZANIE PRZEDSTAWIENIAMI -\n");
      ss_t.str("1. Nowe przedstawienie\n");
      ss_t.str("2. Usun przedstawienie\n");
      ss_t.str("3. Wyswietl liste przedstawien\n");
      ss_t.str("0. Powrot do menu glownego\n");
      break;
    case RESERVATIONS:
      ss_t.str("- ZARZADZANIE REZERWACJAMI -\n");
    	ss_t.str("1. Zapisywanie\n");
    	ss_t.str("2. Wypisywanie\n");
    	ss_t.str("0. Powrot do meun glownego\n");
      break;
    }
  return ss_t;
}

//Cls
void Menus::scroll(int n) const
{
	for (int i=0; i<n; i++){
		std::cout << std::endl;
	}
}

//Main menu
uint Menus::main() const
{
  std::cout << this->putOptions(MAIN).rdbuf();
  return this->getOption(0,3);
}

//Customer
uint Menus::cust()
{
  std::cout << this->putOptions(CUSTOMERS).rdbuf();
	return getOption(0,3);
}

//Performance
uint Menus::perf()
{
  std::cout << this->putOptions(PERFORMANCES).rdbuf();
	return getOption(0,3);
}

//Subscriptions
uint Menus::sign()
{
  std::cout << this->putOptions(RESERVATIONS).rdbuf();
	return this->getOption(0,2);
}
