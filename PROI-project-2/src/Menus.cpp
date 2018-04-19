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

#include <iostream>
#include "../include/Menus.hpp"
#include "../include/Customer.hpp"
#include "../include/Show.hpp"
#include "../include/Queue.hpp"

/*Cons&des*/
Menus::Menus() {}
Menus::~Menus() {}

uint getOption(uint min,uint max)
{
  uint input;
  do{
    std::cout << "\nChoose option :"
    std::cin.clear();
    std::cin.sync();
    std::cin >> input;
  }while(std::cin.fail());
}

std::ostream putOptions(Options which)
{
  std::ostream str;
  switch (which) {
    case Main:
      str << "---MENU GLOWNE---\n"
          << "1. Zarzadzaj klientami\n"
          << "2. Zarzadzaj przedstawieniami\n"
          << "3. Zarzadzaj rezerwacjami\n"
          << "0. Wyjdz z programu\n"
      break;
    case Customers:
      str << "-ZARZADZANIE KLIENTAMI-\n"
          << "1. Nowy klient\n"
          << "2. Usun klienta\n"
          << "3. Wyswietl liste klientow teatru\n"
          << "0. Powrot do menu glownego\n"
      break;
    case Performances:
      str << "- ZARZADZANIE PRZEDSTAWIENIAMI -\n"
          << "1. Nowe przedstawienie\n"
          << "2. Usun przedstawienie\n"
          << "3. Wyswietl liste przedstawien\n"
          << "0. Powrot do menu glownego\n"
      break;
    case Reservations:
      str << "- ZARZADZANIE REZERWACJAMI -\n"
    	    << "1. Zapisywanie\n"
    	    << "2. Wypisywanie\n"
    	    << "0. Powrot do meun glownego\n"
      break;
    }
  return str;
}

//Cls
void Menus::scroll(int n) const{
	for (int i=0; i<n; i++){
		std::cout << std::endl;
	}
}

//Main menu
uint Menus::main() const{
  std::cout << getOptions(Main);
  return getOption(0,3);
}

//Customer
uint Menus::cust() {
  std::cout << getOptions(Customers);
	return getOption(0,3);
}

//Performance
uint Menus::perf(){
  std::cout << getOptions(Performances);
	return getOption(0,3);
}

//Subscriptions
uint Menus::sign(){
  std::cout << getOptions(Reservations);
	return getOption(0,2);
}
