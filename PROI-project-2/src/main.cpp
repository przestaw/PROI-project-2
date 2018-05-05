/*
 * test2.cpp
 *
 * TEST #2
 * A programme for testing the theater
 *
 * PROI, Lab project 2: 'Theater'
 * Tutor: dr inz. Wiktor Kuśmirek
 * Version 06.04.18, Kamil Zacharczuk
 * PROI, Lab project 3: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Przemysław Stawczyk
 */

#include <sstream>
#include <iostream>
#include <fstream>

#include "Menus.hpp"

//Programme info
void progInfo(std::ostream& s_out);

/*****MAIN FUNCTION*****/
/*
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

	//std::stringstream str;
	//str << 1 << '\n' << 0 << '\n' << 0 << '\n';

	//theater_1.Interface(str, s_out, s_err);

	Queue<Customer>* cust_queue;
	Customer* new_cust;
	new_cust = new Customer("Adolf","Hitler",1000);
	*cust_queue+*new_cust;
	new_cust = new Woman("Janina","Juziak",67);
	*cust_queue+*new_cust;
	new_cust = new Man("Szczepan","Wodeczka",38);
	*cust_queue+*new_cust;
	new_cust = new Child("Kali","Nigga",15);
	*cust_queue+*new_cust;

	theater_1.Interface(s_in, s_out, s_err);

	//scroll(32);
  //freeMemory();
  s_out << "( ͡° ͜ʖ ͡°) Dziekuje za skorzystanie z programu. (づ• ͜ʖ•)づ\n";
	s_in.get();
	return 0;
}
*/
//TODO:

/*Programme info*/
void progInfo(std::ostream& s_out)
{
	s_out << " ~ 'Theater' ~ \n\n"
	 			<< "Projekt laboratoryjny 3, PROI\n"
	 			<< "Prowadzacy: dr inz. Wiktor Kusmirek\n"
	 			<< "Przemyslaw Stawczyk, 18L\n\n"
				<< "Bazowany na :\n"
				<< "Projekt laboratoryjny 2, PROI\n"
				<< "Prowadzacy: dr inz. Wiktor Kusmirek\n"
	 			<< "Kamil Zacharczuk, 03.2018\n\n";
}
