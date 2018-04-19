/*
 * Customer.hpp
 *
 * Class Customer representing the theater client
 * ^DECLARATION
 *
 * PROI, Lab project 2: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Version: 06.04.2018, Kamil Zacharczuk
 * PROI, Lab project 3: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Przemysław Stawczyk
 */
#ifndef _CUSTOMER_HPP_
#define _CUSTOMER_HPP_

#include <string>
#include <iostream>

#define uint_fast16_t uint;

/*Theater customer*/
class Customer
{
	private:
		std::string forename;
		std::string surname;
		uint age;

	public:
		typedef enum {FORE, SUR, AGE} CUS_INFO;

		/*Constructors & destructor*/
		Customer();
		Customer(std::string, std::string, uint);
		~Customer();

		/*Operators == overloading*/
		bool operator== (Customer &) const;

		/*Methods*/
		void displayInfo (CUS_INFO) const; // for compatibility - to delete
		void displayInfo() const; // for compatibility - to delete
		std::iostream getInfo(CUS_INFO) const;
		std::iostream getInfo() const;
		inline uint tellAge() const { return this->age; }
};

#endif //_CUSTOMER_HPP_
