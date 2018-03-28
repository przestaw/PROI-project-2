/*
 * test2.cpp
 *
 * - TEST #2
 * - Laboratory project 2: "Theater", PROI
 * - Tutor: dr inż. Wiktor Kuśmirek
 *
 * - A programme for testing the theater implementing classes
 * - Testing includes:
 *  > Managing the customers database
 *  > Managing the performances database
 *  > Subscribing and unsubscribing customers to the performances
 * - Version: 27.03.2018, Kamil Zacharczuk
 */

#include <iostream>
#include <string>

#include "Queue.hpp" //template linked list queue
#include "theater.hpp" //theater implementing classes

using namespace std;

/*GLOBAL VARIABLES*/

//User choices:
bool b_quit; //quit the programme
int decision; //menu choice

//Queues
Queue<Customer>* cust_queue; //customers queue
Queue<Show>* perf_queue; // performances queue

//Counting
UNSH cust_count;
UNSH perf_count;

/*FUNCTIONS*/

//Programme info
void progInfo();

//Menus
UNSH mainMenu();
void custMenu();
void perfMenu();
void signMenu();

//Customers addind/deleting
void newCust();
void delCust();

//Performances adding/deleting
void newPerf();
void delPerf();

//Displaying lists - template function
template <typename T>
bool print(Queue<T>*, int);

//Subs&unsubs
void sign();
void resign();

//Some useful procedures
void scroll(int);
void freeMemory();


/*****MAIN FUNCTION*****/

int main(){

	progInfo();

	scroll(16);

      while (!b_quit){
            decision = mainMenu();
            switch (decision){
            case 1:
                  custMenu(); break;
            case 2:
                  perfMenu(); break;
			case 3:
				signMenu(); break;
            case 0:
                  b_quit=true; break;
            default:
                  break;
            }
      }

	scroll(32);

      freeMemory();

      cout << "Dziekuje za skorzystanie z programu" << endl << endl;
      return 0;
}


/***FUNCTIONS DEFINITIONS***/


/*Programme info*/
void progInfo(){
	cout << "'Theater' - TEST #2 v1.0" << endl;
	cout << "Projekt laboratoryjny 2, PROI" << endl;
	cout << "Prowadzacy: dr inz. Wiktor Kusmirek" << endl;
	cout << "Kamil Zacharczuk, 03.2018" << endl;
}

/*Menus*/

UNSH mainMenu(){
      cout << "---MENU GLOWNE---" << endl;
      cout << "1. Zarzadzaj klientami" << endl;
      cout << "2. Zarzadzaj przedstawieniami" << endl;
	  cout << "3. Zarzadzaj rezerwacjami" << endl;
      cout << "0. Wyjdz z programu" << endl;

      UNSH dec;
      cin >> dec;

	  scroll(32);

      return dec;
}

void custMenu(){
      bool b_cquit = false;
      UNSH dec;

      while(!b_cquit){
            cout << "-ZARZADZANIE KLIENTAMI-" << endl;
            cout << "1. Nowy klient" << endl;
            cout << "2. Usun klienta" << endl;
            cout << "3. Wyswietl liste klientow teatru" << endl;
            cout << "0. Powrot do menu glownego" << endl;

            cin >> dec;

			scroll(32);

            switch (dec){
            case 1:
                  newCust(); break;
            case 2:
                  delCust(); break;
            case 3:
                  print<Customer>(cust_queue, cust_count); break;
            case 0:
                  b_cquit = true; break;
            default:
                  break;
            }
      }

	  scroll(4);
}

void perfMenu(){
      bool b_pquit = false;
      UNSH dec;

      while (!b_pquit){
            cout << "- ZARZADZANIE PRZEDSTAWIENIAMI -" << endl;
            cout << "1. Nowe przedstawienie" << endl;
            cout << "2. Usun przedstawienie" << endl;
            cout << "3. Wyswietl liste przedstawien" << endl;
            cout << "0. Powrot do menu glownego" << endl;

            cin >> dec;

			scroll(32);

            switch (dec){
            case 1:
                  newPerf(); break;
            case 2:
                  delPerf(); break;
            case 3:
                  print<Show>(perf_queue, perf_count); break;
            case 0:
                  b_pquit = true; break;
            default:
                  break;
            }
      }

	  scroll(4);
}

void signMenu(){
	bool b_squit = false;
	UNSH dec;

	while (!b_squit){
		cout << "- ZARZADZANIE REZERWACJAMI -" << endl;
		cout << "1. Zapisywanie" << endl
			<< "2. Wypisywanie" << endl
			<< "0. Powrot do meun glownego" << endl;

		cin >> dec;

		scroll(32);
		switch (dec){
			case 1:
				sign(); break;
			case 2:
				resign(); break;
			case 0:
				b_squit = true; break;
			default:
				continue; break;
		}
	}

	scroll(4);
}

/*Customers menu*/

//Add a new cust
void newCust(){

      string new_forename;
      string new_surname;
      UNSH new_age;

      cout << "Wprowadz imie: "; cin >> new_forename;
      cout << "Wprowadz nazwisko: "; cin >> new_surname;
      cout << "Wprowadz wiek: "; cin >> new_age;

      scroll(32);

      Customer* new_cust = new Customer(new_forename, new_surname, new_age); //create the new customer, his ID is custs numb.
      cout << "Utworzono klienta ";
      new_cust->displayInfo(Customer::FORE);
      cout << " ";
      new_cust->displayInfo(Customer::SUR);
      cout << ", ";
      new_cust->displayInfo(Customer::AGE);
      cout << " lat." << endl;

      //put the new customer in the customers queue
      if (!cust_count){
            //if the new customer is the first one, the queue does not exist - create it
            cust_queue = new Queue<Customer>;
      }
      cust_count++;

      *cust_queue+*new_cust; //attach the new cust to the queue

	scroll(4);
}

//Del a cust
void delCust(){

      if (cust_count){
            UNSH del_id;

            cout << "Wprowadz numer klienta na liscie: "; cin >> del_id;

            Customer* del_cust = cust_queue->getElement(del_id-1);

			scroll(32);

            if (del_cust!=nullptr){
                  cout << "Klient "; del_cust->displayInfo(Customer::FORE);
                  cout << " "; del_cust->displayInfo(Customer::SUR);
                  cout << ", lat "; del_cust->displayInfo(Customer::AGE);
                  cout << "." << endl;

                  if(*cust_queue-*del_cust){
                        cout << "Pomyslnie usunieto klienta!" << endl;
                        if (!(--cust_count)){ //if it was the only customer, delete the customers queue
                              delete cust_queue;
                        }
                  }
                  else{
                        cout << "Nie udalo sie usunac klienta." << endl;
                  }
            }
            else{
                  cout << "Nie ma takiego numeru na liscie." << endl;
            }
      }
      else{
            cout << "Nie ma zadnych klientow!" << endl;
      }

      scroll(4);
}

/*Performances menu*/

//Add a new show
void newPerf()
{

      string new_title;
      UNSH new_type;
      UNSH new_min_age;
      UNSH new_date[3];
      double new_hour;
      UNSH new_seats_limit;

      cout << "Wprowadz tytul: "; cin >> new_title;
      cout << "Wybierz rodzaj: 1. Dramat, 2. Komedia, 3. Musical 4. Opera, 5. Pantomima" << endl;
      cin >> new_type;
      cout << "Wprowadz czas.";
      cout << endl << "Rok: "; cin >> new_date[0];
      cout << "Miesiac: "; cin >> new_date[1];
      cout << "Dzien: "; cin >> new_date[2];
      cout << "Godzina: "; cin >> new_hour;
      cout << "Wprowadz limit miejsc: "; cin >> new_seats_limit;
      cout << "Wprowadz ograniczenie wiekowe: "; cin >> new_min_age;

      scroll(32);


      Show* new_perf = new Show(new_title, new_type-1, new_min_age, new_date[0], new_date[1], new_date[2], new_hour, new_seats_limit);
      cout << "Pomyslnie dodano przedstawienie." << endl;


      if (!perf_count){ //if this is the first perf in the database
            perf_queue = new Queue<Show>;
      }

      perf_count++;

      *perf_queue+*new_perf; //attach the new perf to the queue

	  scroll(4);
}

//Delete a show
void delPerf(){

      if (perf_count){
            UNSH del_id;
            Show* del_perf;

            cout << "Wprowadz numer przedstawienia na liscie: ";
            cin >> del_id;
            del_perf = perf_queue->getElement(del_id-1);

			scroll(32);

            if (del_perf!=nullptr){
                  cout << "Przedstawienie \""; del_perf->displayInfo(Show::TITLE);
                  cout << "\", data "; del_perf->displayInfo(Show::DATE);
                  cout << " godz. "; del_perf->displayInfo(Show::HOUR);
                  cout << "." << endl;

                  if (*perf_queue-*del_perf){
                        cout << "Pomyslnie usunieto przedstawienie!" << endl;
                        if (!(--perf_count)){ //if it was the only show, delete the show queue
                              delete perf_queue;
                        }
                  }
                  else{
                        cout << "Nie udalo sie usunac przedstawienia." << endl;
                  }
            }
            else{
                  cout << "Nie ma takiego numeru na liscie." << endl;
            }
      }
      else{
            cout << "Nie ma zadnych przedstawien!" << endl;
      }

      scroll(4);
}

/*Printing the elements - template function*/
template <typename T>
bool print(Queue<T>* queue, int count){
	if (count){
		T* temp_el;

		cout << "~~~Lista elementow bazy danych~~~" << endl;
		for (int i = 0; i<count; i++){
			cout << "NUMER " << i+1 << "/" << endl;

			temp_el = queue->getElement(i);
			if (temp_el!=nullptr) { temp_el->displayInfo(); }
			else { cout << "Cos poszlo nie tak." << endl; }
		}
	}
	else{
		cout << "Nie ma elementow w bazie danych!" << endl;
		scroll(4);
		return false;
	}

	scroll(4);
	return true;
}


/*Subs&unsubs*/

//Subscribe a customers to a show
void sign(){

	if (print<Show>(perf_queue, perf_count)){ //Print the performances list; if it's empty, return to sub&unsub menu
		Show* temp_perf;
		int perf_id;

		cout << "Wybierz przedstawienie, na ktore chcesz zapisac klienta. ";
		cin >> perf_id;

		temp_perf = perf_queue->getElement(perf_id-1);

		scroll(32);

		if (temp_perf!=nullptr){
			cout << "Przedstawienie '"; temp_perf->displayInfo(Show::TITLE);
			cout <<	"', "; temp_perf->displayInfo(Show::DATE);
			cout << " godz. "; temp_perf->displayInfo(Show::HOUR);
			cout <<	". " << endl << endl;

			int anything; //Wait for any key before cleaning the screen
			cout << "OK... ";
			cin >> anything;

			scroll(32);

			if (print<Customer>(cust_queue, cust_count)){ //Print the customers list; if it's empty, say it and return
				int cust_id;
				Customer* temp_cust;

				cout << "Wybierz numer klienta, ktorego chcesz zapisac: " << endl;
				cin >> cust_id;

				temp_cust = cust_queue->getElement(cust_id-1);

				scroll(32);

				if (temp_cust!=nullptr){
					if (temp_perf->newBuyer(*temp_cust)){
						cout << "Pomyslnie zapisano klienta na przedstawienie!" << endl;
					}
					else{
						cout << "Nie udalo sie zapisac klienta." << endl;
					}
				}
				else{
					cout << "Nie ma klienta o takim numerze." << endl;
				}
			}
		}
		else{
			cout << "Nie ma takiego przedstawienia!" << endl;
		}
	}

	scroll(4);
}

//Unsubscribe a customer from a show
void resign(){

	if (print<Show>(perf_queue, perf_count)){ //Print the shows list; if it's empty, say it and return
		Show* temp_perf;
		int perf_id;

		cout << "Wybierz przedstawienie, z ktorego chcesz wypisac klienta. ";
		cin >> perf_id;

		temp_perf = perf_queue->getElement(perf_id-1);

		scroll(32);

		if (temp_perf!=nullptr){
			cout << "Przedstawienie '"; temp_perf->displayInfo(Show::TITLE);
			cout << "', "; temp_perf->displayInfo(Show::DATE);
			cout << " godz. "; temp_perf->displayInfo(Show::HOUR);
			cout << ". " << endl;

			int anything; //Wait for any key before cleaning screen
			cout << "OK... ";
			cin >> anything;

			scroll(32);

			if (temp_perf->displayAudience()){ //Print the list of the members of the show's audience; if it's empty, say it and return
				int cust_id;
				Customer* temp_cust;

                        scroll(2);

				cout << "Wybierz numer widza, ktorego chcesz wypisac. " << endl;
				cin >> cust_id;

				temp_cust = temp_perf->getAudienceMember(cust_id);

				scroll(32);

				if (temp_cust!=nullptr){
					if (temp_perf->delBuyer(*temp_cust)){
						cout << "Pomyslnie wypisano widza z przedstawienia!" << endl;
					}
					else{
						cout << "Nie udalo sie wypisac widza z przedstawienia." << endl;
					}
				}
				else{
					cout << "Nie ma takiego widza na tym przedstawieniu." << endl;
				}
			}
			else{
                        cout << "Brak zapisanych widzow na to przedstawienie!" << endl;
			}
		}
		else{
			cout << "Nie ma przedstawienia o takim numerze." << endl;
		}
	}

	scroll(4);
}


/*Other functions*/

//Clean the screen
void scroll(int n){
      for (int i=0; i<n; i++){
            cout << endl;}
}

//Free any memory allocated during the programme
void freeMemory(){

	//Free the memory used by customers queue
      if (cust_count){
            Customer* temp_cust;
            for (int i=0; i<cust_count; i++){
                  temp_cust = cust_queue->getElement(i);
                  if (temp_cust!=nullptr){
                        delete temp_cust;
                  }
                  else{ //Just in case, not to let the memory leak
                        cout << "Wystapil problem przy usuwaniu klientow. Nie ma klienta o numerze porzadkowym w kolejce " << i
                        << "." << endl;
                  }
            }
            delete cust_queue;
      }

	//Free the memory used by shows queue
      if (perf_count){
            Show* temp_perf;
            for (int i=0; i<perf_count; i++){
                  temp_perf = perf_queue->getElement(i);
                  if (temp_perf!=nullptr){
                        delete temp_perf;
                  }
                  else{ //Just in case, not to let the memory leak
                        cout << "Wystapil problem przy usuwaniu przedstawien. Nie ma przedstawienia o numerze porzadkowym w kolejce "
                        << i << "." << endl;
                  }
            }
            delete perf_queue;
      }
}

/////////////
