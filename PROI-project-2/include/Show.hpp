/*
 * Show.hpp
 *
 * Class Show representing the theater performance
 * ^DECLARATION
 *
 * PROI, Lab project 2: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Version 06.04.18, Kamil Zacharczuk
 */
#ifndef _SHOW_HPP_
#define _SHOW_HPP_

#include <string>
#include "../include/Customer.hpp"
#include "../include/Queue.hpp"

class Show
{
      public:
		typedef enum { //Type of the performance
			DRAMA, COMEDY, MUSICAL, OPERA, PANTOMIME} SHOW_TYPE;

		typedef enum {
		TITLE, TYPE, MIN_AGE, DATE, HOUR, SEATS_LIMIT, SEATS_TAKEN} SHOW_INFO;

	private:
		std::string title;

		SHOW_TYPE type;
		UNSH min_age;

		//Time of the show
		UNSH date[3];
		double hour;

		UNSH seats_limit;
		UNSH seats_taken;

		Queue<Customer> audience;


	public:
		/*Constructors & destructor*/
		Show(std::string, int, UNSH, UNSH, UNSH, UNSH, double, UNSH);
		~Show();

		void displayInfo (SHOW_INFO) const;
		void displayInfo() const;
		bool displayAudience();

		//Subscribing and unsubscribing an audience member
		bool newBuyer(Customer&); 
		bool delBuyer(Customer&);
		
		//Finding a particular client in the audience queue
		Customer* getAudienceMember (int);
};

#endif //_SHOW_HPP_
