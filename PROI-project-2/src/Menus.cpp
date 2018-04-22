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

#include "Menus.hpp"
using std::string;

template <typename T>
bool print(Queue<T>* queue, int count, std::ostream& s_out)
{
	if (count){
		T* temp_el;
		s_out << "~~~Lista elementow bazy danych~~~\n";
		for (int i = 0; i<count; i++)
    {
			s_out << "NUMER " << i+1 << "/\n";

			temp_el = queue->getElement(i);
			if (temp_el!=nullptr)
      {
        temp_el->displayInfo();
      }
			else
      {
        throw "Error[fun=Menus::Print()]" ;
      }
		}
	}
	else
  {
		return false;
	}
	return true;
}

/*Cons&des*/
Menus::Menus()
  :cust_count(0), perf_count(0), b_quit(false), b_quit1(false)
{}

Menus::~Menus()
{
  //Free the memory used by customers queue
  if (cust_count)
	{
    Customer* temp_cust;
    for (uint i=0; i<cust_count; i++)
    {
      temp_cust = cust_queue->getElement(i);
      if (temp_cust!=nullptr)
			{
        delete temp_cust;
      }
      else
			{ //Just in case, not to let the memory leak
        throw "Wystapil problem przy usuwaniu klientow. Nie ma klienta o numerze porzadkowym w kolejce "+std::to_string(i);
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
        throw "Wystapil problem przy usuwaniu przedstawien. Nie ma przedstawienia o numerze porzadkowym w kolejce "+std::to_string(i);
      }
    }
    delete perf_queue;
  }
}

uint Menus::getOption(uint min, uint max, std::istream& s_in, std::ostream& s_out)
{
  uint input;
  do{
    s_out << "\nChoose option :";
    s_in.clear();
    s_in.sync();
    s_in >> input;
  }while(s_in.fail());
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
	for (int i=0; i<n; i++)
  {
		std::cout << '\n';  //Warning - to deprecate completly do not use
	}
}
// TODO: DELETE _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ -
//Main menu
uint Menus::main(std::istream& s_in, std::ostream& s_out) const
{
  s_out << this->putOptions(MAIN).rdbuf();
  return this->getOption(0, 3, s_in, s_out);
}

//Customer
uint Menus::cust(std::istream& s_in, std::ostream& s_out)
{
  s_out << this->putOptions(CUSTOMERS).rdbuf();
	return getOption(0, 3, s_in, s_out);
}

//Performance
uint Menus::perf(std::istream& s_in, std::ostream& s_out)
{
  s_out << this->putOptions(PERFORMANCES).rdbuf();
	return getOption(0, 3, s_in, s_out);
}

//Subscriptions
uint Menus::sign(std::istream& s_in, std::ostream& s_out)
{
  s_out << this->putOptions(RESERVATIONS).rdbuf();
	return this->getOption(0, 2, s_in, s_out);
}
// TODO: DELETE<endof> _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ -

// TODO: From this line COMPLETE REWORK
//        add: stream support[remove cin/cout ad cerr],
//             remove endl, add exeptions
//             move specified print<> method form main.cpp template function
// TODO(?): Removal of counters -> implement in Queue
// TODO(??): Destructor -> implement in Queue


void Menus::init(std::istream& s_in, std::ostream& s_out)
{
  while (!b_quit)
  {
    b_quit1 = false;
    decision = main(s_in, s_out);
    scroll(32);
    switch (decision)
    {
      case 1:
				while (!b_quit1)
        {
          decision = cust(s_in, s_out);
          scroll(32);
          switch (decision)
          {
					  case 1:
              newCust(s_in, s_out);
			        break;
					  case 2:
						  delCust(s_in, s_out);
						  break;
					  case 3:
						  if(!print<Customer> (cust_queue, cust_count, s_out))
              {
							  s_out << "Nie ma zadnych klientow!" << '\n';
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
          decision = perf(s_in, s_out);
          scroll(32);

          switch (decision)
          {
					case 1:
						newPerf(s_in, s_out);
						break;
					case 2:
						delPerf(s_in, s_out);
						break;
					case 3:
						if(!print<Show> (perf_queue, perf_count, s_out))
            {
							s_out << "Nie ma zadnych przedstawien!" << '\n';
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
				  decision = sign(s_in, s_out);
				  scroll(32);

				  switch (decision){
					case 1:
						Sign(s_in, s_out);
						break;
					case 2:
						Resign(s_in, s_out);
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
  s_out << "Dziekuje za skorzystanie z programu." << '\n' << '\n';
}

void Menus::newCust(std::istream& s_in, std::ostream& s_out)
{
      string new_forename;
      string new_surname;
      uint new_age;

      s_out << "Wprowadz imie: "; s_in >> new_forename;
      s_out << "Wprowadz nazwisko: "; s_in >> new_surname;
      s_out << "Wprowadz wiek: "; s_in >> new_age;

      scroll(32);

      Customer* new_cust = new Customer(new_forename, new_surname, new_age); //create the new customer, his ID is custs numb.
      s_out << "Utworzono klienta ";
      new_cust->displayInfo(Customer::FORE);
      s_out << " ";
      new_cust->displayInfo(Customer::SUR);
      s_out << ", ";
      new_cust->displayInfo(Customer::AGE);
      s_out << " lat." << '\n';

      //put the new customer in the customers queue
      if (!cust_count){
            //if the new customer is the first one, the queue does not exist - create it
            cust_queue = new Queue<Customer>;
      }
      cust_count++;

      *cust_queue+*new_cust; //attach the new cust to the queue
	scroll(4);
}

void Menus::delCust(std::istream& s_in, std::ostream& s_out)
{
      if (cust_count)
      {
            uint del_id;

            s_out << "Wprowadz numer klienta na liscie: "; s_in >> del_id;

            Customer* del_cust = cust_queue->getElement(del_id-1);

			scroll(32);

            if (del_cust!=nullptr){
                  s_out << "Klient "; del_cust->displayInfo(Customer::FORE);
                  s_out << " "; del_cust->displayInfo(Customer::SUR);
                  s_out << ", lat "; del_cust->displayInfo(Customer::AGE);
                  s_out << "." << '\n';

                  if(*cust_queue-*del_cust){
                        s_out << "Pomyslnie usunieto klienta!" << '\n';
                        if (!(--cust_count)){ //if it was the only customer, delete the customers queue
                              delete cust_queue;
                        }
                  }
                  else{
                        s_out << "Nie udalo sie usunac klienta." << '\n';
                  }
            }
            else{
                  s_out << "Nie ma takiego numeru na liscie." << '\n';
            }
      }
      else{
            s_out << "Nie ma zadnych klientow!" << '\n';
      }
      scroll(4);
}

void Menus::newPerf(std::istream& s_in, std::ostream& s_out)
{
      string new_title;
      uint new_type;
      uint new_min_age;
      uint new_date[3];
      double new_hour;
      uint new_seats_limit;

      s_out << "Wprowadz tytul: "; s_in >> new_title;
      s_out << "Wybierz rodzaj: 1. Dramat, 2. Komedia, 3. Musical 4. Opera, 5. Pantomima" << '\n';
      s_in >> new_type;
      s_out << "Wprowadz czas.";
      s_out << '\n' << "Rok: "; s_in >> new_date[0];
      s_out << "Miesiac: "; s_in >> new_date[1];
      s_out << "Dzien: "; s_in >> new_date[2];
      s_out << "Godzina: "; s_in >> new_hour;
      s_out << "Wprowadz limit miejsc: "; s_in >> new_seats_limit;
      s_out << "Wprowadz ograniczenie wiekowe: "; s_in >> new_min_age;

      scroll(32);

      Show* new_perf = new Show(new_title, new_type-1, new_min_age, new_date[0], new_date[1], new_date[2], new_hour, new_seats_limit);
      s_out << "Pomyslnie dodano przedstawienie." << '\n';

      if (!perf_count)
      { //if this is the first perf in the database
            perf_queue = new Queue<Show>;
      }
      perf_count++;

      *perf_queue+*new_perf; //attach the new perf to the queue
	  scroll(4);
}

void Menus::delPerf(std::istream& s_in, std::ostream& s_out)
{
  if (perf_count)
  {
    uint del_id;
    Show* del_perf;

    s_out << "Wprowadz numer przedstawienia na liscie: ";
    s_in >> del_id;
    del_perf = perf_queue->getElement(del_id-1);
		scroll(32);

    if (del_perf!=nullptr)
    {
      s_out << "Przedstawienie \""; del_perf->displayInfo(Show::TITLE);
      s_out << "\", data "; del_perf->displayInfo(Show::DATE);
      s_out << " godz. "; del_perf->displayInfo(Show::HOUR);
      s_out << "." << '\n';

      if (*perf_queue-*del_perf)
      {
        s_out << "Pomyslnie usunieto przedstawienie!" << '\n';
        if (!(--perf_count))
        { //if it was the only show, delete the show queue
          delete perf_queue;
        }
      }
      else
      {
        s_out << "Nie udalo sie usunac przedstawienia." << '\n';
      }
    }
    else
    {
      s_out << "Nie ma takiego numeru na liscie." << '\n';
    }
  }
  else
  {
    s_out << "Nie ma zadnych przedstawien!" << '\n';
  }

  scroll(4);
}

//Subscribe a customers to a show
void Menus::Sign(std::istream& s_in, std::ostream& s_out)
{
	if (print<Show>(perf_queue, perf_count, s_out))
  { //Print the performances list; if it's empty, return to sub&unsub menu
		Show* temp_perf;
		int perf_id;

		s_out << "Wybierz przedstawienie, na ktore chcesz zapisac klienta. ";
		s_in >> perf_id;

		temp_perf = perf_queue->getElement(perf_id-1);

		scroll(32);

		if (temp_perf!=nullptr)
    {
			s_out << "Przedstawienie '"; temp_perf->displayInfo(Show::TITLE);
			s_out <<	"', "; temp_perf->displayInfo(Show::DATE);
			s_out << " godz. "; temp_perf->displayInfo(Show::HOUR);
			s_out <<	". " << '\n' << '\n';

			int anything; //Wait for any key before cleaning the screen
			s_out << "OK... ";
			s_in >> anything;

			scroll(32);

			if (print<Customer>(cust_queue, cust_count, s_out))
      { //Print the customers list; if it's empty, say it and return
				int cust_id;
				Customer* temp_cust;

				s_out << "Wybierz numer klienta, ktorego chcesz zapisac: " << '\n';
				s_in >> cust_id;

				temp_cust = cust_queue->getElement(cust_id-1);

				scroll(32);

				if (temp_cust!=nullptr){
					if (temp_perf->newBuyer(*temp_cust))
          {
						s_out << "Pomyslnie zapisano klienta na przedstawienie!" << '\n';
					}
					else
          {
						s_out << "Nie udalo sie zapisac klienta." << '\n';
					}
				}
				else
        {
					s_out << "Nie ma klienta o takim numerze." << '\n';
				}
			}
			else
      {
				s_out << "Nie ma zadnych klientow!" << '\n';
			}
		}
		else
    {
			s_out << "Nie ma takiego przedstawienia!" << '\n';
		}
	}
	else
  {
		s_out << "Nie ma zadnych przedstawien!" << '\n';
	}

	scroll(4);
}

//Unsubscribe a customer from a show
void Menus::Resign(std::istream& s_in, std::ostream& s_out)
{
	if (print<Show>(perf_queue, perf_count, s_out))
	{ //Print the shows list; if it's empty, say it and return
		Show* temp_perf;
		int perf_id;

		s_out << "Wybierz przedstawienie, z ktorego chcesz wypisac klienta. ";
		s_in >> perf_id;

		temp_perf = perf_queue->getElement(perf_id-1);

		scroll(32);

		if (temp_perf!=nullptr)
		{
			s_out << "Przedstawienie '"; temp_perf->displayInfo(Show::TITLE);
			s_out << "', "; temp_perf->displayInfo(Show::DATE);
			s_out << " godz. "; temp_perf->displayInfo(Show::HOUR);
			s_out << ". " << '\n';

			int anything; //Wait for any key before cleaning screen
			s_out << "OK... ";
			s_in >> anything;

			scroll(32);

			if (temp_perf->displayAudience())
			{ //Print the list of the members of the show's audience; if it's empty, say it and return
				int cust_id;
				Customer* temp_cust;

        scroll(2);
				s_out << "Wybierz numer widza, ktorego chcesz wypisac. " << '\n';
				s_in >> cust_id;

				temp_cust = temp_perf->getAudienceMember(cust_id);

				scroll(32);
				if (temp_cust!=nullptr)
				{
					if (temp_perf->delBuyer(*temp_cust))
					{
						s_out << "Pomyslnie wypisano widza z przedstawienia!" << '\n';
					}
					else
					{
						s_out << "Nie udalo sie wypisac widza z przedstawienia." << '\n';
					}
				}
				else
				{
					s_out << "Nie ma takiego widza na tym przedstawieniu." << '\n';
				}
			}
			else
			{
				s_out << "Brak zapisanych widzow na to przedstawienie!" << '\n';
			}
		}
		else
		{
			s_out << "Nie ma przedstawienia o takim numerze." << '\n';
		}
	}
	else
	{
		s_out << "Nie ma zadnych przedstawien!" << '\n';
	}

	scroll(4);
}
