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
int main()
{
	std::fstream logs;
//consider reaname of this class -> Interface? Theater?
	Menus theater_1;
//configure the streams
	std::istream& s_in = std::cin;
	std::ostream& s_out = std::cout;
	std::stringstream s_err; //place for all occuring errors
//show most importatnt info ( ͡° ͜ʖ ͡°)
	progInfo(s_out);

	theater_1.Interface(s_in, s_out, s_err);

	logs.open("errors.log.txt", std::fstream::out);
	logs << s_err.str();
	logs.close();

  s_out << "Dziekuje za skorzystanie z programu. (づ• ͜ʖ•)づ\n";
	s_in.get();

	return 0;
}

/*Program info*/
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
