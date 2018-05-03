/*
 * test2.cpp
 *
 * TEST #2
 * A programme for testing the theater implementing classes
 * Testing includes:
 *  > Managing the customers database
 *  > Managing the performances database
 *  > Subscribing and unsubscribing customers to the performances
 *
 * PROI, Lab project 2: 'Theater'
 * Tutor: dr inz. Wiktor Kuśmirek
 * Version 06.04.18, Kamil Zacharczuk
 * PROI, Lab project 3: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Przemysław Stawczyk
 */

#include <iostream>
#include <string>

#include "../include/Customer.hpp"
#include "../include/Show.hpp"
#include "../include/Menus.hpp"
#include "../include/Queue.hpp" //template linked list queue

using namespace std;

//Programme info
void progInfo(std::ostream& s_out);

/*****MAIN FUNCTION*****/
int main()
{
//consider reaname of this class -> Interface? Theater?
	Menus theater_1;
//configure the streams
	std::istream& s_in = std::cin;
	std::ostream& s_out = std::cout;
	std::ostream& s_err = std::cerr;
//show most importatnt info ( ͡° ͜ʖ ͡°)
	progInfo(s_out);

	theater_1.Interface(s_in, s_out, s_err);
	//scroll(32);
  //freeMemory();
  s_out << "( ͡° ͜ʖ ͡°) Dziekuje za skorzystanie z programu. (づ• ͜ʖ•)づ\n";
	s_in.get();
	return 0;
}

//TODO:

/*Programme info*/
void progInfo(std::ostream& s_out)
{
	s_out << " ~ 'Theater' ~ \n\n"
	 			<< "Projekt laboratoryjny 3, PROI\n"
	 			<< "Prowadzacy: dr inz. Wiktor Kusmirek\n"
	 			<< "Przemyslaw Stawczyk, 18L\n"
				<< "Bazowany na :\n"
				<< "Projekt laboratoryjny 2, PROI\n"
				<< "Prowadzacy: dr inz. Wiktor Kusmirek\n"
	 			<< "Kamil Zacharczuk, 03.2018\n\n";
}
