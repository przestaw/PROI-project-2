/*
 * Menus.cpp
 *
 * Class Menus created to handle travelling between menus in the test2 programme
 * ^DEFINITION
 *
 * Lab project 2: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Version 06.04.18, Kamil Zacharczuk 
 */
 
#include <iostream>
#include "../include/Menus.hpp"
#include "../include/Customer.hpp"
#include "../include/Show.hpp"
#include "../include/Queue.hpp"

/*Cons&des*/
Menus::Menus() {}
Menus::~Menus() {}

//Cls
void Menus::scroll(int n) const{
	for (int i=0; i<n; i++){
		std::cout << std::endl;
	}
}

//Main menu
UNSH Menus::main() const{
      std::cout << "---MENU GLOWNE---" << std::endl;
      std::cout << "1. Zarzadzaj klientami" << std::endl;
      std::cout << "2. Zarzadzaj przedstawieniami" << std::endl;
	  std::cout << "3. Zarzadzaj rezerwacjami" << std::endl;
      std::cout << "0. Wyjdz z programu" << std::endl;

      UNSH dec;
      std::cin >> dec;

      return dec;
}

//Customer
UNSH Menus::cust() {
            UNSH dec;

            std::cout << "-ZARZADZANIE KLIENTAMI-" << std::endl;
            std::cout << "1. Nowy klient" << std::endl;
            std::cout << "2. Usun klienta" << std::endl;
            std::cout << "3. Wyswietl liste klientow teatru" << std::endl;
            std::cout << "0. Powrot do menu glownego" << std::endl;

            std::cin >> dec;

			return dec;
}

//Performance
UNSH Menus::perf(){
      UNSH dec;
            std::cout << "- ZARZADZANIE PRZEDSTAWIENIAMI -" << std::endl;
            std::cout << "1. Nowe przedstawienie" << std::endl;
            std::cout << "2. Usun przedstawienie" << std::endl;
            std::cout << "3. Wyswietl liste przedstawien" << std::endl;
            std::cout << "0. Powrot do menu glownego" << std::endl;

            std::cin >> dec;

			return dec;
}

//Subscriptions
UNSH Menus::sign(){
	UNSH dec;
		std::cout << "- ZARZADZANIE REZERWACJAMI -" << std::endl;
		std::cout << "1. Zapisywanie" << std::endl
			<< "2. Wypisywanie" << std::endl
			<< "0. Powrot do meun glownego" << std::endl;

		std::cin >> dec;

		return dec;
}

