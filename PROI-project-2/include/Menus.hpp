/*
 * Menus.hpp
 *
 * Class Menus created to handle travelling between menus in the test2 programme
 * ^DECLARATION
 *
 * PROI, Lab project 2: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Version 06.04.18, Kamil Zacharczuk 
 */
#ifndef _MENUS_HPP_
#define _MENUS_HPP_

#include "Queue.hpp"

typedef unsigned int UNSH;

/*Class to handle travelling between menus in the test2 programme*/
class Menus
{
	public:

		Menus();
		~Menus();

		//Helpful cls function
		void scroll(int) const;

		//Menus in which we choose further path
		UNSH main() const;
		UNSH cust();
		UNSH perf();
		UNSH sign();
};

#endif //_MENUS_HPP_

