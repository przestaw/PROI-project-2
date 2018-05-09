/*
 * Menus.cpp
 *
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
  :cust_count(0), perf_count(0)
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

void Menus::print(Show* perf, std::ostream& s_out)
{
	std::stringstream str = perf->getAudience();
  s_out << str.rdbuf();
}

uint Menus::getOption(uint min, uint max, std::istream& s_in, std::ostream& s_out)
{
  uint input;
  s_out << "\nChoose option :";
  s_in >> input;
  if(s_in.fail())
  {
    Err_Struct exept1(0,1,1,"error during int input\n","Nieprawidlowy typ danych\n");
    throw exept1;
  }else
  {
    if(input > max || input < min)
    {
      Err_Struct exept2(0,0,1,"invalid int input\n","Nieprawidlowa opcja\n");
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
           << "4. Eksportuj do pliku liste klientow teatru\n"
           << "0. Powrot do menu glownego\n";
      break;
    case PERFORMANCES:
      ss_t << "- ZARZADZANIE PRZEDSTAWIENIAMI -\n"
           << "1. Nowe przedstawienie\n"
           << "2. Usun przedstawienie\n"
           << "3. Wyswietl liste przedstawien\n"
           << "4. Eksportuj do pliku liste przedstawien\n"
           << "5. Szczegolowe informacje o przedstawieniach\n"
           << "0. Powrot do menu glownego\n";
      break;
    case PERFORMANCES_SUB:
      ss_t << "- SZCZEGOLY PRZEDSTAWIEN -\n"
           << "1. Szczegoly i lista widzow przedstawienia\n"
           << "2. Eksportuj do pliku szczegoly i liste widzow przedstawienia\n"
           << "3. Popros widzow o ocene przedstawienia\n"
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

void Menus::Interface(std::istream& s_in, std::ostream& s_out, std::ostream& s_err)
{
  bool b_quit0=false, b_quit1=false;

  while (!b_quit0)
  {
    b_quit1 = false;
		try
		{
			s_out << this->putOptions(MAIN).rdbuf();
	    switch (this->getOption(0, 3, s_in, s_out))
	    {
	      case 1:
					while (!b_quit1)
	        {
						s_out << this->putOptions(CUSTOMERS).rdbuf();
	          switch (this->getOption(0, 4, s_in, s_out))
	          {
						  case 1:
								this->newCust(s_in, s_out);
				        break;
						  case 2:
								this->delCust(s_in, s_out);
							  break;
						  case 3:
                print<Customer>(cust_queue, cust_count, s_out);
							  break;
              case 4:
                {
                  std::stringstream str = getStream<Customer>(cust_queue, cust_count);
                  this->FileExport(s_in, s_out, str);
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
						s_out << this->putOptions(PERFORMANCES).rdbuf();
	          switch (this->getOption(0, 5, s_in, s_out))
	          {
						case 1:
							this->newPerf(s_in, s_out);
							break;
						case 2:
							this->delPerf(s_in, s_out);
							break;
						case 3:
              print<Show>(perf_queue, perf_count, s_out);
              break;
            case 4:
              {
                std::stringstream str = getStream<Show>(perf_queue, perf_count);
                this->FileExport(s_in, s_out, str);
              }
              break;
            case 5:
              while(!b_quit1)
              {
                s_out << this->putOptions(PERFORMANCES_SUB).rdbuf();
                switch (this->getOption(0, 3, s_in, s_out))
                {
                case 1:
                  {
                    Show* temp_perf1 = getPerf(s_in, s_out);
                    std::stringstream str1 = temp_perf1->getInfo();
                    str1 << temp_perf1->getAudience().rdbuf();
                    s_out << str1.rdbuf();
                  }
                  break;
                case 2:
                  {
                    Show* temp_perf2 = getPerf(s_in, s_out);
                    std::stringstream str2 = temp_perf2->getInfo();
                    str2 << temp_perf2->getAudience().rdbuf();
                    FileExport(s_in, s_out, str2);
                  }
                  break;
                case 3:
                  {
                    Show* temp_perf3 = getPerf(s_in, s_out);
                    temp_perf3->Rate();
                    s_out << "Aktualna ocena to : " << temp_perf3->getRate();
                  }
                case 0:
                  b_quit1 = true;
                  break;
                }
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
						s_out << this->putOptions(RESERVATIONS).rdbuf();
					  switch (this->getOption(0, 2, s_in, s_out)){
						case 1:
							this->Sign(s_in, s_out);
							break;
						case 2:
							this->Resign(s_in, s_out);
							break;
						case 0:
							b_quit1 = true;
							break;
						}
					}
				  break;
	      case 0:
				  //scroll(32);
	        b_quit0 = true;
				  break;
	      default:
	        break;
	    }
		}catch(Err_Struct exept0)
		{
      if(s_in.fail())
      {
        s_in.clear();
        s_in.ignore(128,'\n');
      }
      exept0.handle(s_out, s_err);
		}
  }
}

void Menus::FileExport(std::istream& s_in, std::ostream& s_out, std::stringstream& str)
{
  //s_out << str.rdbuf() << '\n';

  std::string filename;
  std::fstream file;

  s_out << "Wprowadz nazwe pliku do ktorego chcesz eksportowac liste : ";
  s_in  >> filename;
  s_out << "Wprowadzona nazwa : " << filename;

  file.open(filename, std::ofstream::out | std::ofstream::ate);

  file << str.rdbuf() << std::endl;

  file.close();
}

Customer* Menus::getCus(std::istream& s_in, std::ostream& s_out)
{
	Customer* cust = nullptr;
	if (cust_count)
  {
    uint id;
    print<Customer>(cust_queue, cust_count, s_out);
    s_out << "Wprowadz numer klienta na liscie: ";
    s_in >> id;
    cust = cust_queue->getElement(id-1);
	}else
  {
    Err_Struct exept1(0,0,1, "there is no customers\n","\nNie ma zadnych klientow!");
    throw exept1;
  }
	if (cust == nullptr)
	{
		Err_Struct exept2(0,0,1, "no customer with given id\n","Nie ma takiego klienta!\n");
    throw exept2;
	}
	return cust;
}

Show* Menus::getPerf(std::istream& s_in, std::ostream& s_out)
{
	Show* perf = nullptr;
	if (perf_count)
  {
    uint id;
    print<Show>(perf_queue, perf_count, s_out);
    s_out << "Wprowadz numer przedstawienia na liscie: ";
    s_in >> id;
    perf = perf_queue->getElement(id-1);
	}else
  {
    Err_Struct exept1(0,0,1, "there is no shows\n","\nNie ma zadnych przedstawien!");
    throw exept1;
  }
	if (perf == nullptr)
	{
		Err_Struct exept2(0,0,1, "no show with given id\n","Nie ma takiego przedstawienia!\n");
    throw exept2;
	}
	return perf;
}

Customer* Menus::getAudMem(Show* perf, std::istream& s_in, std::ostream& s_out)
{
	Customer* cust;
	if(perf != nullptr)
	{
		s_out << "Przedstawienie '" << perf->getInfo(Show::TITLE).rdbuf()
					<< "', " << perf->getInfo(Show::DATE).rdbuf()
					<< " godz. " << perf->getInfo(Show::HOUR).rdbuf()
					<< ".\n";

		s_out << "wcisnij dowolny przycisk by kontynuowac\n\n";
		s_in.get();
		if(perf->isEmpty())
		{
			int id;
			print(perf, s_out);
			s_out << "Wybierz numer widza: " << '\n';
			s_in >> id;

			cust = perf->getAudienceMember(id);
		}else
		{
			Err_Struct exept2(0,0,1, "there is no audience members\n","\nNie ma zadnych widzow!");
	    throw exept2;
		}
	}else
	{
		Err_Struct exept1(0,0,1, "no show with given id\n","Nie ma takiego przedstawienia!\n");
    throw exept1;
	}
	if (cust == nullptr)
	{
		Err_Struct exept2(0,0,1, "no audience members with given id\n","Nie ma takiego widza!\n");
    throw exept2;
	}
	return cust;
}

void Menus::newCust(std::istream& s_in, std::ostream& s_out)
{
      string new_forename;
      string new_surname;
      uint new_age;
      s_out << "Wprowadz imie: "; s_in >> new_forename;
      s_out << "Wprowadz nazwisko: "; s_in >> new_surname;
      s_out << "Wprowadz wiek: "; s_in >> new_age;
			s_out << putOptions(GENDERS).rdbuf();

			Customer* new_cust;

      switch(getOption(0,3,s_in, s_out))
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

void Menus::delCust(std::istream& s_in, std::ostream& s_out)
{
  Customer* del_cust = getCus(s_in, s_out);
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

  Show* new_perf = new Show(new_title, new_type-1, new_min_age, new_date[0], new_date[1], new_date[2], new_hour, new_seats_limit);
  if (!perf_count)
  { //if this is the first perf in the database
      perf_queue = new Queue<Show>;
  }
  perf_count++;

  *perf_queue+*new_perf; //attach the new perf to the queue
}

void Menus::delPerf(std::istream& s_in, std::ostream& s_out)
{
  Show* del_perf = getPerf(s_in, s_out);

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

//Subscribe a customers to a show
void Menus::Sign(std::istream& s_in, std::ostream& s_out)
{
  Show* temp_perf = getPerf(s_in, s_out);
  s_out << "Przedstawienie '" << temp_perf->getInfo(Show::TITLE).rdbuf()
        << "', " << temp_perf->getInfo(Show::DATE).rdbuf()
        << " godz. " << temp_perf->getInfo(Show::HOUR).rdbuf()
        << ".\n";

  s_out << "wcisnij dowolny przycisk by kontynuowac\n";
  s_in.get();

  if (cust_count)
  { //Print the customers list; if it's empty, say it and return
    print<Customer>(cust_queue, cust_count, s_out);

    int cust_id;
    Customer* temp_cust;

    s_out << "Wybierz numer klienta, ktorego chcesz zapisac:\n";
    s_in >> cust_id;

    temp_cust = cust_queue->getElement(cust_id-1);

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

//Unsubscribe a customer from a show
void Menus::Resign(std::istream& s_in, std::ostream& s_out)
{
  Show* temp_perf = getPerf(s_in, s_out);
  Customer* temp_cust = getAudMem(temp_perf, s_in, s_out);
  temp_perf->delBuyer(*temp_cust);
  s_out << "Pomyslnie wypisano widza z przedstawienia!" << '\n';
}
