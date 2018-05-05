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
		SEX sex;
public:
		/*Constructors & destructor*/
		Customer();
		Customer(std::string, std::string, uint);					
		virtual ~Customer();

		/*Operators == overloading*/
		bool operator== (Customer &) const;
		/*Methods*/
		virtual uint Rate(Show *show_r); //TODO: implement here and in deriviated classes
		virtual std::stringstream getInfo(CUS_INFO);
		virtual std::stringstream getInfo();
		inline uint tellAge() const { return this->age; }
};

#endif //_CUSTOMER_HPP_
