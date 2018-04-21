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
#include <sstream>
#include "Show.hpp"

#define uint_fast16_t uint;

class Show;

/*Theater customer*/
class Customer
{
public:
		typedef enum {FORE, SUR, AGE, TYPE} CUS_INFO;
		typedef enum {KID, WOMAN, MAN, UNDEFINED} SEX;
protected:
		std::string forename;
		std::string surname;
		uint age;
		static const SEX sex = UNDEFINED;
public:
		/*Constructors & destructor*/
		Customer();
		Customer(std::string, std::string, uint);
								//Exeption to add: copy-constructor etc.
		virtual ~Customer();

		/*Operators == overloading*/
		bool operator== (Customer &) const;

		/*Methods*/
		virtual uint rate(Show *show_r); //TODO: implement here and in deriviated classes

		void displayInfo (CUS_INFO); // for compatibility - to delete
		void displayInfo(); // for compatibility - to delete
		std::ostringstream getInfo(CUS_INFO);
		std::ostringstream getInfo();
		inline uint tellAge() const { return this->age; }
};

#endif //_CUSTOMER_HPP_
