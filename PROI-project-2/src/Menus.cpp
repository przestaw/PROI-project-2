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

/*Cons&des*/
Menus::Menus()
  :cust_count(0), perf_count(0)//, b_quit(false), b_quit1(false)
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
        std::cerr << "Wystapil problem przy usuwaniu klientow. Nie ma klienta o numerze porzadkowym w kolejce " << i;
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
        std::cerr << "Wystapil problem przy usuwaniu przedstawien. Nie ma przedstawienia o numerze porzadkowym w kolejce " << i;
      }
    }
    delete perf_queue;
  }
}

uint Menus::getOption(uint min, uint max, std::istream& s_in, std::ostream& s_out, std::ostream& s_err)
{
  uint input;
  s_out << "\nChoose option :";
  s_in >> input;
  if(s_in.fail())
  {
    Err_Struct exept1(0,1,0,"error during int input","Nieprawidlowy typ danych\n");
    throw exept1;
  }else
  {
    if(input > max || input < min)
    {
      Err_Struct exept2(0,0,0,"invalid int input","Nieprawidlowa opcja\n");
      throw exept2;
    }
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
		case GENDERS:
			ss_t << "- ROZROZNIENIE KLIENTOW -\n"
					 << "1. Kobieta\n"
					 << "2. Mezczyzna\n"
					 << "3. Dziecko\n";
				break;
    }
  return ss_t;
}

//Cls// TODO: DELETE
void Menus::scroll(int n) const
{
	for (int i=0; i<n; i++)
  {
		std::cout << '\n';  //Warning - to deprecate completly do not use
	}
}
// TODO: DELETE _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ -
//Main menu
uint Menus::main(std::istream& s_in, std::ostream& s_out, std::ostream& s_err) const
{
  s_out << this->putOptions(MAIN).rdbuf();
  return this->getOption(0, 3, s_in, s_out, s_err);
}

//Customer
uint Menus::cust(std::istream& s_in, std::ostream& s_out, std::ostream& s_err)
{
  s_out << this->putOptions(CUSTOMERS).rdbuf();
	return getOption(0, 3, s_in, s_out, s_err);
}

//Performance
uint Menus::perf(std::istream& s_in, std::ostream& s_out, std::ostream& s_err)
{
  s_out << this->putOptions(PERFORMANCES).rdbuf();
	return getOption(0, 3, s_in, s_out, s_err);
}

//Subscriptions
uint Menus::sign(std::istream& s_in, std::ostream& s_out, std::ostream& s_err)
{
  s_out << this->putOptions(RESERVATIONS).rdbuf();
	return this->getOption(0, 2, s_in, s_out, s_err);
}
// TODO: DELETE<endof> _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ -

void Menus::newCust(std::istream& s_in, std::ostream& s_out, std::ostream& s_err)
{
      string new_forename;
      string new_surname;
      uint new_age;
      s_out << "Wprowadz imie: "; s_in >> new_forename;
      s_out << "Wprowadz nazwisko: "; s_in >> new_surname;
      s_out << "Wprowadz wiek: "; s_in >> new_age;
			s_out << putOptions(GENDERS).rdbuf();

			Customer* new_cust;

      switch(getOption(0,3,s_in, s_out, s_err))
      {
        case 1:
          new_cust = new Woman(new_forename, new_surname, new_age); //create the new customer, his ID is custs numb.
          break;
        case 2:
          new_cust = new Man(new_forename, new_surname, new_age); //create the new customer, his ID is custs numb.
          break;
        case 3:
          new_cust = new Child(new_forename, new_surname, new_age); //create the new customer, his ID is custs numb.
          break;
        case 0:
          new_cust = new Customer(new_forename, new_surname, new_age); //create the new customer, his ID is custs numb.
          break;
        default:
          Err_Struct exept(0,0,1,"invalid type entered", "Nieprawidlowy typ klienta");
          throw exept;
      }

      s_out << "Utworzono klienta " << new_cust->getInfo().rdbuf();

      //put the new customer in the customers queue
      if (!cust_count){
            //if the new customer is the first one, the queue does not exist - create it
            cust_queue = new Queue<Customer>;
      }
      cust_count++;

      *cust_queue+*new_cust; //attach the new cust to the queue
}

void Menus::delCust(std::istream& s_in, std::ostream& s_out, std::ostream& s_err)
{
  if (cust_count)
  {
    uint del_id;
    s_out << "Wprowadz numer klienta na liscie: "; s_in >> del_id;

    Customer* del_cust = cust_queue->getElement(del_id-1);

    if (del_cust!=nullptr)
    {
      s_out << "Klient :" << del_cust->getInfo().rdbuf();

      if(*cust_queue-*del_cust)
      {
        s_out << "Pomyslnie usunieto klienta !\n";
        if (!(--cust_count))
        { //if it was the only customer, delete the customers queue
          delete cust_queue;
        }
      }else
      {
        Err_Struct exept1(0,0,1,"Client could not be deleted\n","Nie udalo sie usunac klienta.\n");
	      throw  exept1;
      }
    }else
    {
      Err_Struct exept2(0,0,1,"Invalid client number\n","Nie ma takiego numeru na liscie.\n");
      throw  exept2;
    }
  }else
  {
    Err_Struct exept3(0,0,1,"Empty client Queue\n","Nie ma zadnych klientow\n");
    throw  exept3;
  }
}

void Menus::newPerf(std::istream& s_in, std::ostream& s_out, std::ostream& s_err)
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

  Show* new_perf = new Show(new_title, new_type-1, new_min_age, new_date[0], new_date[1], new_date[2], new_hour, new_seats_limit);
  if (!perf_count)
  { //if this is the first perf in the database
      perf_queue = new Queue<Show>;
  }
  perf_count++;

  *perf_queue+*new_perf; //attach the new perf to the queue
}

void Menus::delPerf(std::istream& s_in, std::ostream& s_out, std::ostream& s_err)
{
  if (perf_count)
  {
    uint del_id;
    Show* del_perf;

    s_out << "Wprowadz numer przedstawienia na liscie: ";
    s_in >> del_id;
    del_perf = perf_queue->getElement(del_id-1);

    if (del_perf!=nullptr)
    {
			s_out << "Przedstawienie '" << del_perf->getInfo(Show::TITLE).rdbuf()
						<< "', " << del_perf->getInfo(Show::DATE).rdbuf()
						<< " godz. " << del_perf->getInfo(Show::HOUR).rdbuf()
						<< ".\n";

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
        Err_Struct exept1(0,0,1, "cannot delete show\n","Nie udalo sie usunac przedstawienia.\n");
        throw exept1;
      }
    }
    else
    {
      Err_Struct exept2(0,0,1, "ther is no such performance\n","Nie ma takiego numeru na liscie.\n");
      throw exept2;
    }
  }
  else
  {
    Err_Struct exept3(0,0,1, "there is no shows\n","\nNie ma zadnych przedstawien!");
    throw exept3;
  }
}

//Subscribe a customers to a show
void Menus::Sign(std::istream& s_in, std::ostream& s_out, std::ostream& s_err)
{
	if(perf_count)
  { //Print the performances list; if it's empty, return to sub&unsub menu
    s_out << print<Show>(perf_queue, perf_count).rdbuf();

    Show* temp_perf;
		int perf_id = 0;

		s_out << "Wybierz przedstawienie, na ktore chcesz zapisac klienta. ";
		s_in >> perf_id;

		temp_perf = perf_queue->getElement(perf_id-1);

		if (temp_perf!=nullptr)
    {
			s_out << "Przedstawienie '" << temp_perf->getInfo(Show::TITLE).rdbuf()
						<< "', " << temp_perf->getInfo(Show::DATE).rdbuf()
						<< " godz. " << temp_perf->getInfo(Show::HOUR).rdbuf()
						<< ".\n";

			s_out << "wcisnij dowolny przycisk by kontynuowac\n";
			s_in.get();

		  if (cust_count)
      { //Print the customers list; if it's empty, say it and return
        s_out << print<Customer>(cust_queue, cust_count).rdbuf();

				int cust_id;
				Customer* temp_cust;

				s_out << "Wybierz numer klienta, ktorego chcesz zapisac:\n";
				s_in >> cust_id;

				temp_cust = cust_queue->getElement(cust_id-1);

				//scroll(32);

				if (temp_cust!=nullptr)
        {
					temp_perf->newBuyer(*temp_cust);
					s_out << "Pomyslnie zapisano klienta na przedstawienie!\n";
				}
				else
        {
          Err_Struct exept1(0,0,1, "no customer with given id\n","Nie ma klienta o takim numerze.\n");
					throw exept1;
				}
			}
			else
      {
        Err_Struct exept2(0,0,1, "no customers\n","Nie ma zadnych klientow!\n");
				throw exept2;
			}
		}
		else
    {
      Err_Struct exept3(0,0,1, "no show with given id\n","Nie ma takiego przedstawienia!\n");
			throw exept3;
		}
	}
	else
  {
    Err_Struct exept4(0,0,1, "no shows\n","Nie ma zadnych przedstawien!\n");
		throw exept4;
	}
}

//Unsubscribe a customer from a show
void Menus::Resign(std::istream& s_in, std::ostream& s_out, std::ostream& s_err)
{
	if (perf_count)
	{ //Print the shows list; if it's empty, say it and return
    s_out << print<Show>(perf_queue, perf_count).rdbuf();
		Show* temp_perf;
		int perf_id;

		s_out << "Wybierz przedstawienie, z ktorego chcesz wypisac klienta. ";
		s_in >> perf_id;

		temp_perf = perf_queue->getElement(perf_id-1);

		//scroll(32);

		if (temp_perf!=nullptr)
		{
			s_out << "Przedstawienie '" << temp_perf->getInfo(Show::TITLE).rdbuf()
						<< "', " << temp_perf->getInfo(Show::DATE).rdbuf()
						<< " godz. " << temp_perf->getInfo(Show::HOUR).rdbuf()
						<< ".\n";

			s_out << "wcisnij dowolny przycisk by kontynuowac\n";
			s_in.get();

			if(temp_perf->isEmpty())
			{ //Print the list of the members of the show's audience;
        s_out << temp_perf->getAudience().rdbuf();
        int cust_id;
				Customer* temp_cust;

        //scroll(2);
				s_out << "Wybierz numer widza, ktorego chcesz wypisac. " << '\n';
				s_in >> cust_id;

				temp_cust = temp_perf->getAudienceMember(cust_id);

				//scroll(32);
				if (temp_cust!=nullptr)
				{
          temp_perf->delBuyer(*temp_cust);
					s_out << "Pomyslnie wypisano widza z przedstawienia!" << '\n';
				}
				else
				{
          Err_Struct exept1(0,0,1, "there is no such customer in audience\n","Nie ma takiego widza na tym przedstawieniu.\n");
					throw exept1;
				}
			}
			else
			{
        Err_Struct exept2(0,0,1, "no audience for show\n","Brak zapisanych widzow na to przedstawienie!\n");
				throw exept2;
			}
		}
		else
		{
      Err_Struct exept3(0,0,1, "there is no such performance\n","Nie ma przedstawienia o takim numerze.\n");
			throw exept3;
		}
	}
	else
	{
    Err_Struct exept4(0,0,1, "there is no performances\n","Nie ma zadnych przedstawien!\n");
		throw exept4;
	}

	//scroll(4);
}

void Menus::print_db(uint mode, std::ostream& s_out, std::ostream& s_err)
{
  try
  {
    switch (mode)
  	{
  		case 1:
  			s_out << print<Customer>(cust_queue, cust_count).rdbuf();
  			break;
  		case 2:
  			s_out << print<Show>(perf_queue, cust_count).rdbuf();
  			break;
  	}
  }
  catch(Err_Struct exept)
	{
		exept.handle(s_out, s_err);
	}
}
