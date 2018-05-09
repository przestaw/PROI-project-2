/*
 * Show.hpp
 *
 * Class Show representing the theater performance
 * ^DECLARATION
 *
 * PROI, Lab project 2: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Version 06.04.18, Kamil Zacharczuk
 * PROI, Lab project 3: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Przemysław Stawczyk
 */
#ifndef _SHOW_HPP_
#define _SHOW_HPP_

#include <string>
#include "Customer.hpp"
#include "Queue.hpp"

#define uint_fast16_t uint;

class Customer;

class Show
{
  public:
		typedef enum { //Type of the performance
	     DRAMA, COMEDY, MUSICAL, OPERA, PANTOMIME} SHOW_TYPE;
		typedef enum {
		    TITLE, TYPE, MIN_AGE, DATE, HOUR, SEATS_LIMIT, SEATS_TAKEN, RATE} SHOW_INFO;
	protected:
		std::string title;
		SHOW_TYPE type;
		uint min_age;
		uint date[3]; //Time of the show
		double hour;
		uint seats_limit;
		uint seats_taken;
    uint nr_of_rates;
    uint rate;
		Queue<Customer> audience;
	public:
		/*Constructors & destructor*/
		Show(std::string, int, uint, uint, uint, uint, double, uint);

    void add_rate(uint);
    void Rate();
    double getRate();
		std::stringstream getInfo(SHOW_INFO) const;
    std::stringstream getInfo() const;
    std::stringstream getAudience();
		//Subscribing and unsubscribing an audience member
		void newBuyer(Customer&);
		void delBuyer(Customer&);
		//Finding a particular client in the audience queue
		Customer* getAudienceMember (int);
    bool isEmpty();
};

#endif //_SHOW_HPP_
