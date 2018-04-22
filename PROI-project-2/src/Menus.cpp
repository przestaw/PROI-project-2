/*
 * Menus.cpp
 *
 * Class Menus created to handle travelling between menus in the test2 programme
 * ^DEFINITION
 *
 * Lab project 2: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Version 06.04.18, Kamil Zacharczuk
 * PROI, Lab project 3: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Przemysław Stawczyk
 */

#include "../include/Menus.hpp"
#include "../include/Customer.hpp"
#include "../include/Show.hpp"
#include "../include/Queue.hpp"

/*Cons&des*/
Menus::Menus()
  :cust_count(0), perf_count(0)
{}

Menus::~Menus()
{
  //Free the memory used by customers queue
      if (cust_count)
			{
            Customer* temp_cust;
            for (uint i=0; i<cust_count; i++){
                  temp_cust = cust_queue->getElement(i);
                  if (temp_cust!=nullptr)
									{
                        delete temp_cust;
                  }
                  else
									{ //Just in case, not to let the memory leak
                        cout << "Wystapil problem przy usuwaniu klientow. Nie ma klienta o numerze porzadkowym w kolejce " << i
                        << "." << endl;
                  }
            }
            delete cust_queue;
      }

	//Free the memory used by shows queue
      if (perf_count)
			{
            Show* temp_perf;
            for (uint i=0; i<perf_count; i++)
						{
                  temp_perf = perf_queue->getElement(i);
                  if (temp_perf!=nullptr)
									{
                        delete temp_perf;
                  }
                  else
									{ //Just in case, not to let the memory leak
                        cout << "Wystapil problem przy usuwaniu przedstawien. Nie ma przedstawienia o numerze porzadkowym w kolejce "
                        << i << "." << endl;
                  }
            }
            delete perf_queue;
      }
}

uint Menus::getOption(uint min,uint max)
{
  uint input;
  do{
    std::cout << "\nChoose option :";
    std::cin.clear();
    std::cin.sync();
    std::cin >> input;
  }while(std::cin.fail());
  if(input > max || input < min)
  {
    throw "invalid input[fun=Menus::getOption(int min, int max)]";
  }
  return input;
}

std::stringstream Menus::putOptions(OPTIONS input)
{
  std::stringstream ss_t;
  switch (input) {
    case MAIN:
      ss_t << "---MENU GLOWNE---\n"
           << "1. Zarzadzaj klientami\n"
           << "2. Zarzadzaj przedstawieniami\n"
           << "3. Zarzadzaj rezerwacjami\n"
           << "0. Wyjdz z programu\n";
      break;
    case CUSTOMERS:
      ss_t << "-ZARZADZANIE KLIENTAMI-\n"
           << "1. Nowy klient\n"
           << "2. Usun klienta\n"
           << "3. Wyswietl liste klientow teatru\n"
           << "0. Powrot do menu glownego\n";
      break;
    case PERFORMANCES:
      ss_t << "- ZARZADZANIE PRZEDSTAWIENIAMI -\n"
           << "1. Nowe przedstawienie\n"
           << "2. Usun przedstawienie\n"
           << "3. Wyswietl liste przedstawien\n"
           << "0. Powrot do menu glownego\n";
      break;
    case RESERVATIONS:
      ss_t << "- ZARZADZANIE REZERWACJAMI -\n"
    	     << "1. Zapisywanie\n"
    	     << "2. Wypisywanie\n"
    	     << "0. Powrot do meun glownego\n";
      break;
    }
  return ss_t;
}

//Cls
void Menus::scroll(int n) const
{
	for (int i=0; i<n; i++){
		std::cout << std::endl;
	}
}
// TODO: DELETE _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ -
//Main menu
uint Menus::main() const
{
  std::cout << this->putOptions(MAIN).rdbuf();
  return this->getOption(0,3);
}

//Customer
uint Menus::cust()
{
  std::cout << this->putOptions(CUSTOMERS).rdbuf();
	return getOption(0,3);
}

//Performance
uint Menus::perf()
{
  std::cout << this->putOptions(PERFORMANCES).rdbuf();
	return getOption(0,3);
}

//Subscriptions
uint Menus::sign()
{
  std::cout << this->putOptions(RESERVATIONS).rdbuf();
	return this->getOption(0,2);
}
// TODO: DELETE<endof> _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ -

// TODO: From this line COMPLETE REWORK
//        add: stream support[remove cin/cout ad cerr],
//             remove endl, add exeptions
//             move specified print<> method form main.cpp template function
// TODO(?): Removal of counters -> implement in Queue
// TODO(??): Destructor -> implement in Queue
void Menus::init()
{
  while (!b_quit)
  {
    b_quit1 = false;
    decision = main();
    scroll(32);
    switch (decision)
    {
      case 1:
				while (!b_quit1)
        {
          decision = cust();
          scroll(32);
          switch (decision)
          {
					  case 1:
              newCust();
			        break;
					  case 2:
						  delCust();
						  break;
					  case 3:
						  if(!print<Customer> (cust_queue, cust_count))
              {
							  cout << "Nie ma zadnych klientow!" << endl;
							  scroll(4);
						  }
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
          decision = perf();
          scroll(32);

          switch (decision)
          {
					case 1:
						newPerf();
						break;
					case 2:
						delPerf();
						break;
					case 3:
						if(!print<Show> (perf_queue, perf_count))
            {
							cout << "Nie ma zadnych przedstawien!" << endl;
							scroll(4);
						}
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
				  decision = sign();
				  scroll(32);

				  switch (decision){
					case 1:
						sign();
						break;
					case 2:
						resign();
						break;
					case 0:
						b_quit1 = true;
						break;
					}
				}
				break;
            case 0:
				scroll(32);
                  b_quit = true;
				  break;
            default:
                  break;
            }
      }

	scroll(32);

      //freeMemory();

      cout << "Dziekuje za skorzystanie z programu." << endl << endl;
}

void Menus::newCust()
{

      string new_forename;
      string new_surname;
      uint new_age;

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

void Menus::delCust()
{

      if (cust_count)
      {
            uint del_id;

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

void Menus::newPerf()
{

      string new_title;
      uint new_type;
      uint new_min_age;
      uint new_date[3];
      double new_hour;
      uint new_seats_limit;

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

void Menus::delPerf()
{

      if (perf_count){
            uint del_id;
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

//Subscribe a customers to a show
void Menus::sign()
{
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
			else{
				cout << "Nie ma zadnych klientow!" << endl;
			}
		}
		else{
			cout << "Nie ma takiego przedstawienia!" << endl;
		}
	}
	else{
		cout << "Nie ma zadnych przedstawien!" << endl;
	}

	scroll(4);
}

//Unsubscribe a customer from a show
void Menus::resign()
{
	if (print<Show>(perf_queue, perf_count))
	{ //Print the shows list; if it's empty, say it and return
		Show* temp_perf;
		int perf_id;

		cout << "Wybierz przedstawienie, z ktorego chcesz wypisac klienta. ";
		cin >> perf_id;

		temp_perf = perf_queue->getElement(perf_id-1);

		scroll(32);

		if (temp_perf!=nullptr)
		{
			cout << "Przedstawienie '"; temp_perf->displayInfo(Show::TITLE);
			cout << "', "; temp_perf->displayInfo(Show::DATE);
			cout << " godz. "; temp_perf->displayInfo(Show::HOUR);
			cout << ". " << endl;

			int anything; //Wait for any key before cleaning screen
			cout << "OK... ";
			cin >> anything;

			scroll(32);

			if (temp_perf->displayAudience())
			{ //Print the list of the members of the show's audience; if it's empty, say it and return
				int cust_id;
				Customer* temp_cust;

                        scroll(2);

				cout << "Wybierz numer widza, ktorego chcesz wypisac. " << endl;
				cin >> cust_id;

				temp_cust = temp_perf->getAudienceMember(cust_id);

				scroll(32);

				if (temp_cust!=nullptr)
				{
					if (temp_perf->delBuyer(*temp_cust))
					{
						cout << "Pomyslnie wypisano widza z przedstawienia!" << endl;
					}
					else
					{
						cout << "Nie udalo sie wypisac widza z przedstawienia." << endl;
					}
				}
				else
				{
					cout << "Nie ma takiego widza na tym przedstawieniu." << endl;
				}
			}
			else
			{
				cout << "Brak zapisanych widzow na to przedstawienie!" << endl;
			}
		}
		else
		{
			cout << "Nie ma przedstawienia o takim numerze." << endl;
		}
	}
	else
	{
		cout << "Nie ma zadnych przedstawien!" << endl;
	}

	scroll(4);
}
