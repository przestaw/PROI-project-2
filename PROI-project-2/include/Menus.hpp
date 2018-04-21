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

#include "Queue.hpp"
#include <sstream>

#define uint_fast16_t uint;

/*Class to handle travelling between menus in the test2 programme*/
class Menus
{
	public:
		typedef enum {MAIN, CUSTOMERS, PERFORMANCES, RESERVATIONS}OPTIONS;
		Menus();
		~Menus();
		//Helpful cls function
		void scroll(int) const; //consider delete -> unnescesary
		//Menus in which we choose further path
		uint main() const; // for compatibility - to delete
		uint cust(); // for compatibility - to delete
		uint perf(); // for compatibility - to delete
		uint sign(); // for compatibility - to delete
	private:
		static uint getOption(uint min,uint max);
		static std::ostringstream putOptions(OPTIONS which) ;
};

#endif //_MENUS_HPP_
