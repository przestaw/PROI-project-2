/*
 * test2.cpp
 *
 * TEST #2
 * A programme for testing the theater implementing classes
 * Testing includes:
 *  > Managing the customers database
 *  > Managing the performances database
 *  > Subscribing and unsubscribing customers to the performances
 *
 * PROI, Lab project 2: 'Theater'
 * Tutor: dr inz. Wiktor Kuśmirek
 * Version 06.04.18, Kamil Zacharczuk
 * PROI, Lab project 3: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Przemysław Stawczyk
 */

#include <iostream>
#include <string>

#include "../include/Customer.hpp"
#include "../include/Show.hpp"
#include "../include/Menus.hpp"
#include "../include/Queue.hpp" //template linked list queue

using namespace std;

//Programme info
void progInfo();

/*****MAIN FUNCTION*****/

bool b_quit; //quit the programme
bool b_quit1; //quit the menu
int decision; //menu choice

int main()
{
	std::istream& s_in = std::cin;
	std::ostream& s_out = std::cout;
	std::ostream& s_err = std::cerr;
	progInfo();
	Menus theater_1;

  while (!b_quit)
  {
    b_quit1 = false;
    decision = theater_1.main(s_in, s_out, s_err);
    //scroll(32);
    switch (decision)
    {
      case 1:
				while (!b_quit1)
        {
          decision = theater_1.cust(s_in, s_out, s_err);
          //scroll(32);
          switch (decision)
          {
					  case 1:
							try
							{
								theater_1.newCust(s_in, s_out, s_err);
							}catch(Err_Struct exept)
							{
								exept.handle(s_out, s_err);
							}
			        break;
					  case 2:
							try
							{
								theater_1.delCust(s_in, s_out, s_err);
							}catch(Err_Struct exept)
							{
								exept.handle(s_out, s_err);
							}
						  break;
					  case 3:
				//TODO: move fun to class
						  theater_1.print_db(1, s_out, s_err);
						  break;
					  case 0:
						  b_quit1 = true;
						  break;
				  }
				}
        break;
      case 2:
				while (!b_quit1)
        {
          decision = theater_1.perf(s_in, s_out, s_err);
          //scroll(32);

          switch (decision)
          {
					case 1:
						try
						{
							theater_1.newPerf(s_in, s_out, s_err);
						}catch(Err_Struct exept)
						{
							exept.handle(s_out, s_err);
							//delete new_perf?;
						}
						break;
					case 2:
						theater_1.delPerf(s_in, s_out, s_err);
						break;
					case 3:
			//TODO: move fun to class
						theater_1.print_db(2, s_out, s_err);
						break;
					case 0:
						b_quit1 = true;
						break;
					}
				}
				break;
			case 3:
				while (!b_quit1)
        {
				  decision = theater_1.sign(s_in, s_out, s_err);
				  switch (decision){
					case 1:
						try
						{
							theater_1.Sign(s_in, s_out, s_err);
						}catch(Err_Struct exept)
						{
							exept.handle(s_out, s_err);
						}
						break;
					case 2:
						try
						{
							theater_1.Resign(s_in, s_out, s_err);
						}catch(Err_Struct exept)
						{
							exept.handle(s_out, s_err);
						}
						break;
					case 0:
						b_quit1 = true;
						break;
					}
				}
			  break;
      case 0:
			  //scroll(32);
        b_quit = true;
			  break;
      default:
        break;
    }
  }


	return 0;
	//scroll(32);
  //freeMemory();
  s_out << "Dziekuje za skorzystanie z programu." << '\n' << '\n';
}

//TODO:

/*Programme info*/
void progInfo()
{
	cout << "'Theater' - TEST #2 v1.0" << endl;
	cout << "Projekt laboratoryjny 2, PROI" << endl;
	cout << "Prowadzacy: dr inz. Wiktor Kusmirek" << endl;
	cout << "Kamil Zacharczuk, 03.2018" << endl;
	cout << "Projekt laboratoryjny 3, PROI" << endl;
	cout << "Prowadzacy: dr inz. Wiktor Kusmirek" << endl;
	cout << "Przemyslaw Stawczyk, 18L" << endl;

}
