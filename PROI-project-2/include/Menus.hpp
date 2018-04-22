/*
 * Menus.hpp
 *
 * Class Menus created to handle travelling between menus in the test2 programme
 * ^DECLARATION
 *
 * PROI, Lab project 2: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Version 06.04.18, Kamil Zacharczuk
 * PROI, Lab project 3: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Przemysław Stawczyk
 */
#ifndef _MENUS_HPP_
#define _MENUS_HPP_

#include "Customer.hpp"
#include "Show.hpp"
#include "Queue.hpp"
#include <sstream>
#include <iostream>

#define uint_fast16_t uint;

/*Class to handle travelling between menus in the test2 programme*/
class Menus
{
private:
	bool b_quit; //quit the programme
	bool b_quit1; //quit the menu
	int decision; //menu choice

	//Queues
	Queue<Customer>* cust_queue; //customers queue
	Queue<Show>* perf_queue; // performances queue

	//Counting
	uint cust_count;
	uint perf_count;
public:
	typedef enum {MAIN, CUSTOMERS, PERFORMANCES, RESERVATIONS}OPTIONS;
	Menus();
	~Menus();
	//Helpful cls function
	void scroll(int) const; //consider delete -> unnescesary
	//Menus in which we choose further path
	uint main(std::istream&, std::ostream&) const; // for compatibility - to delete
	uint cust(std::istream&, std::ostream&); // for compatibility - to delete
	uint perf(std::istream&, std::ostream&); // for compatibility - to delete
	uint sign(std::istream&, std::ostream&); // for compatibility - to delete
	//Moved from main file ~przestaw
	void init(std::istream&, std::ostream&); //TODO: remove cin/cout/endl
	void newCust(std::istream&, std::ostream&);
	void delCust(std::istream&, std::ostream&);
	void newPerf(std::istream&, std::ostream&);
	void delPerf(std::istream&, std::ostream&);
	void Sign(std::istream&, std::ostream&);
	void Resign(std::istream&, std::ostream&);
private:
	static uint getOption(uint min, uint max, std::istream& s_in, std::ostream& s_out);
	static std::stringstream putOptions(OPTIONS which);
};

#endif //_MENUS_HPP_
