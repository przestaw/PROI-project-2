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
#include "Child.hpp"
#include "Man.hpp"
#include "Woman.hpp"
#include "Show.hpp"
#include "Queue.hpp"
#include "err_struct.hpp"
#include <sstream>
#include <iostream>

#define uint_fast16_t uint;

/*Class to handle travelling between menus in the test2 programme*/
class Menus
{
private:
	//Queues
	Queue<Customer>* cust_queue; //customers queue
	Queue<Show>* perf_queue; // performances queue

	//Counting
	uint cust_count;
	uint perf_count;
public:
	typedef enum {MAIN, CUSTOMERS, PERFORMANCES, RESERVATIONS, GENDERS}OPTIONS;
	Menus();
	~Menus();
	void Interface(std::istream& s_in, std::ostream& s_out, std::ostream&);

	//Helpful cls function
	//void scroll(int) const; //consider delete -> unnescesary
//consider making all of below private
	//void print_db(uint mode,  std::ostream& s_out, std::ostream& s_err);
	//Menus in which we choose further path
	//uint main(std::istream& s_in, std::ostream& s_out, std::ostream& s_err) const; // for compatibility - to delete
	//uint cust(std::istream& s_in, std::ostream& s_out, std::ostream& s_err); // for compatibility - to delete
	//uint perf(std::istream& s_in, std::ostream& s_out, std::ostream& s_err); // for compatibility - to delete
	//uint sign(std::istream& s_in, std::ostream& s_out, std::ostream& s_err); // for compatibility - to delete

//Moved from main file ~przestaw
	void newCust(std::istream& s_in, std::ostream& s_out, std::ostream& s_err);
	void delCust(std::istream& s_in, std::ostream& s_out, std::ostream& s_err);
	void newPerf(std::istream& s_in, std::ostream& s_out, std::ostream& s_err);
	void delPerf(std::istream& s_in, std::ostream& s_out, std::ostream& s_err);
	void Sign(std::istream& s_in, std::ostream& s_out, std::ostream& s_err);
	void Resign(std::istream& s_in, std::ostream& s_out, std::ostream& s_err);
private:
	static uint getOption(uint min, uint max, std::istream& s_in, std::ostream& s_out, std::ostream& s_err);
	static std::stringstream putOptions(OPTIONS which);
};

template <typename T>
std::stringstream print(Queue<T>* queue, int count)
{
	std::stringstream str;
	if (count)
	{
		T* temp_el;
		str << "~~~Lista elementow~~~\n";
		for (int i = 0; i<count; i++)
    {
			str << "NR " << i+1 << "\n";
			temp_el = queue->getElement(i);
			if (temp_el!=nullptr)
			{
				str << temp_el->getInfo().rdbuf();
			}
			else
			{
				Err_Struct exept(1,0,0,"unknown error in print [emplate function]");
				throw  exept;
			}
		}
	}
	else
  {
		str << "~~~Lista jest pusta~~~\n";
	}
	return str;
}

#endif //_MENUS_HPP_
