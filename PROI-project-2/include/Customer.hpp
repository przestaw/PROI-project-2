/*
 * Customer.hpp
 *
 * Class Customer representing the theater client
 * ^DECLARATION
 *
 * PROI, Lab project 2: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Version: 06.04.2018, Kamil Zacharczuk
 */
#ifndef _CUSTOMER_HPP_
#define _CUSTOMER_HPP_

#include <string>

typedef unsigned int UNSH;

/*Theater customer*/
class Customer
{
	private:
		std::string forename;
		std::string surname;
		UNSH age;

	public:
		typedef enum {FORE, SUR, AGE} CUS_INFO;

		/*Constructors & destructor*/
		Customer();
		Customer(std::string, std::string, UNSH);
		~Customer();

		/*Operators == overloading*/
		bool operator== (Customer &) const;

		/*Methods*/
		void displayInfo (CUS_INFO) const;
		void displayInfo() const;
		inline UNSH tellAge() const { return this->age; }
};

#endif //_CUSTOMER_HPP_
