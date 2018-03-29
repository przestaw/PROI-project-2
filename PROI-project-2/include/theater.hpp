/* 
 * theater.hpp 
 *
 * - Laboratory project 2: "Theater", PROI
 * - Tutor: dr inż. Wiktor Kuśmirek
 *
 * - The file contains declarations of classes:
 *  > Customer - a theater customer
 *  > Show - a theater performance
 * - Version: 27.03.2018, Kamil Zacharczuk
 */
 
#ifndef _THEATER_HPP
#define _THEATER_HPP

#include <string>

typedef unsigned short UNSH;

class Show;

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

            bool operator== (Customer & another) const{
                  return
                        this->forename==another.forename &&
                        this->surname==another.surname &&
                        this->age==another.age;
            }
		inline UNSH tellAge() const { return this->age; }
		void displayInfo (CUS_INFO) const;
		void displayInfo() const;
};


/*Theater performance*/
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
		
		bool newBuyer(Customer&);
		bool delBuyer(Customer&);

		Customer* getAudienceMember (int);
};

#endif // _THEATER_HPP
