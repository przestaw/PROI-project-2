/*
 * Menus.hpp
 *
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
#include <fstream>

#define uint_fast16_t uint;

/*Class to handle travelling between menus in the test2 programme*/
class Menus
{
protected:
	//Queues
	Queue<Customer>* cust_queue; //customers queue
	Queue<Show>* perf_queue; // performances queue
	//Counting
	uint cust_count;
	uint perf_count;
public:
	typedef enum {MAIN, CUSTOMERS, PERFORMANCES, PERFORMANCES_SUB, RESERVATIONS, GENDERS}OPTIONS;
	Menus();
	~Menus();
	void Interface(std::istream& s_in, std::ostream& s_out, std::ostream&);
protected: // consider private - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _
//Moved and re-made fun from main file ~przestaw
	void newCust(std::istream& s_in, std::ostream& s_out);
	void delCust(std::istream& s_in, std::ostream& s_out);
	void newPerf(std::istream& s_in, std::ostream& s_out);
	void delPerf(std::istream& s_in, std::ostream& s_out);
	void Sign(std::istream& s_in, std::ostream& s_out);
	void Resign(std::istream& s_in, std::ostream& s_out);
//New fun replacing and extending old ones ~przestaw
	Show* getPerf(std::istream& s_in, std::ostream& s_out);
	Customer* getCus(std::istream& s_in, std::ostream& s_out);
	Customer* getAudMem(Show* perf, std::istream& s_in, std::ostream& s_out);
	void FileExport(std::istream& s_in, std::ostream& s_out, std::stringstream& str);
	static uint getOption(uint min, uint max, std::istream& s_in, std::ostream& s_out);
	static std::stringstream putOptions(OPTIONS which);
	void print(Show* perf, std::ostream& s_out);
	void print(Show* perf, std::ostream& s_out, std::ostream& s_export);
	template <typename T>
	void print(Queue<T>* queue, int count, std::ostream& s_out);
	template <typename T>
	std::stringstream getStream(Queue<T>* queue, int count);
};

template <typename T>
std::stringstream Menus::getStream(Queue<T>* queue, int count)
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
				Err_Struct exept(1,0,0,"unknown error in print [template function]");
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

template <typename T>
void Menus::print(Queue<T>* queue, int count, std::ostream& s_out)
{
	std::stringstream str = getStream<T>(queue, count);
  s_out << str.rdbuf();
}

#endif //_MENUS_HPP_
