/*
 * Show.cpp
 *
 * Class Show representing the theater performance
 * ^DEFINITION
 *
 * PROI, Lab project 2: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Version 06.04.18, Kamil Zacharczuk
 * PROI, Lab project 3: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Przemysław Stawczyk
 */

#include <cstdlib>
#include "Show.hpp"
#include "Customer.hpp"
#include "Queue.hpp"
#include "err_struct.hpp"

/****CLASS SHOW****/

/*CONSTRUCTOR*/
Show::Show(std::string p_title, int p_type, uint p_min_age, uint p_year, uint p_month, uint p_day, double p_hour, uint p_seats_limit)
  :title(p_title), min_age(p_min_age), hour(p_hour),
  seats_limit(p_seats_limit), seats_taken(0),
  nr_of_rates(0), rate(0)
{
	date[0] = p_year; //exeption needed
	date[1] = p_month; //exeption needed
	date[2] = p_day; //exeption needed

	switch (p_type)
  {
  case 1:
    type = DRAMA;
    break;
  case 2:
    type = COMEDY;
    break;
  case 3:
    type = MUSICAL;
    break;
  case 4:
    type = OPERA;
    break;
  case 5:
    type = PANTOMIME;
    break;
	}

  if (hour<0.0 || hour >= 24.0)
  {
    Err_Struct exept(1,0,0,"invalid Show hour [noy in range]\n", "Nieistniejąca godzina\n");
    throw exept;
	}
}

/*METHODS*/
void Show::add_rate(uint rate_n)
{
  rate = (rate_n + rate* nr_of_rates)/(++nr_of_rates);
}

void Show::Rate()
{
  if(nr_of_rates == 0)
  {
    rate = 0;
  }
  Customer* aud_member = this->audience.getElement(0);
	if (aud_member==nullptr)
  {
    Err_Struct exept(1,0,0,"show not rated [empty audience]\n", "Brak widzow mogacych ocenic przedstawienie\n");
		throw exept;
	}
	for (int i=1; aud_member!=nullptr; i++)
  {
		aud_member->Rate(this);
		aud_member = this->audience.getElement(i);
	}
}

double Show::getRate()
{
  if(nr_of_rates > 0)
  {
    return rate;
  }else
  {
    Err_Struct exept(0, 0, 1, "show is not yet rated", "To przedstawienie nie zostalo jeszcze ocenione");
    throw exept;
  }
}

//// Precised info
std::stringstream Show::getInfo(SHOW_INFO info) const
{
	std::stringstream str;
	switch (info)
  {
    case TITLE:
			str << title;
			break;
		case TYPE:
			switch (type)
      {
	      case DRAMA:
					str << "Dramat";
					break;
	      case COMEDY:
					str << "Komedia";
					break;
	      case MUSICAL:
					str << "Musical";
					break;
	      case OPERA:
					str << "Opera";
					break;
	      case PANTOMIME:
					str << "Pantomima";
					break;
			}
			break;
		case MIN_AGE:
			str << min_age;
			break;
		case DATE:
			str << date[0] << "-" << date[1] << "-" << date[2];
			break;
		case HOUR:
			if (hour>=0 && hour < 10){
				str << "0";}
			str << hour;
			break;
		case SEATS_LIMIT:
			str << seats_limit;
			break;
		case SEATS_TAKEN:
			str << seats_taken;
			break;
    case RATE:
      if(nr_of_rates > 0)
      {
        str << "Nie ocenione";
      }else
      {
        str << rate;
      }
			break;
	}
	return str;
}

//// All info
std::stringstream Show::getInfo() const
{
	std::stringstream str;
	str << "|| Tytul: " << this->getInfo(TITLE).rdbuf() << '\n'
	 		<< "|| Gatunek: " << this->getInfo(TYPE).rdbuf()
	 		<< "|| Data: " << this->getInfo(DATE).rdbuf()
	 		<< "|| Godzina: " << this->getInfo(HOUR).rdbuf()  << '\n'
	 		<< "|| Minimalny wiek: " << this->getInfo(MIN_AGE).rdbuf()
	 		<< "|| Liczba miejsc: " << this->getInfo(SEATS_LIMIT).rdbuf()
	 		<< "|| Zajetych: " << this->getInfo(SEATS_TAKEN).rdbuf() << '\n'
      << "|| Ocena: " << this->getInfo(RATE).rdbuf() << '\n';
	return str;
}

std::stringstream Show::getAudience()
{
	Customer* aud_member = this->audience.getElement(0);
	std::stringstream str;
  str << this->getInfo().rdbuf()
	    << "^LISTA WIDZOW PRZEDSTAWIENIA^\n";

	if (aud_member==nullptr){
		str << " -- EMPTY -- ";
		return str;
	}

	for (int i=1; aud_member!=nullptr; i++){
		str << i << ". " << aud_member->getInfo(Customer::FORE).rdbuf()
				<< " " << aud_member->getInfo(Customer::SUR).rdbuf() << '\n';
		aud_member = this->audience.getElement(i);
	}
	return str;
}

//// Add a new audience member
void Show::newBuyer(Customer & buyer)
{
	if (buyer.tellAge() < this->min_age)
  {
    Err_Struct exept1(0,0,1, "customer does not meet requirements\n","Kupujacy nie spelnia wymagan dotyczacych wieku.\n");
		throw exept1;
	}
	else if (this->seats_taken >= this->seats_limit)
  {
    Err_Struct exept2(0,0,1, "no empty seat for customer\n","Brak wolnych miejsc na to przedstawienie.\n");
		throw exept2;
	}
	else if (this->audience.findElement(buyer))
  {
    Err_Struct exept3(0,0,1, "customer is already registered\n","Ten kupujacy jest juz zapisany na to przedstawienie.\n");
		throw exept3;
	}
	else{
		this->seats_taken++;
		this->audience+buyer;
	}
}

//// Delete an audience member
void Show::delBuyer(Customer & buyer)
{
	if (!(this->audience-buyer))
  {
    Err_Struct exept(0,0,1,"unable to delete customer from show\n", "Nie udalo sie wypisac widza z przedstawienia.\n");
    throw exept;
  }
	seats_taken--;
}

//// Return a specific audience member
Customer* Show::getAudienceMember(int cust_id)
{
  return this->audience.getElement(cust_id-1);
}

bool Show::isEmpty()
{
  return (this->audience.getElement(0)==nullptr);
}
