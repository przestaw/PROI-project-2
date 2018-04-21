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

/****CLASS SHOW****/

/*CONSTRUCTOR*/

////
Show::Show(std::string p_title, int p_type, uint p_min_age, uint p_year, uint p_month, uint p_day, double p_hour, uint p_seats_limit)
  :title(p_title), min_age(p_min_age),
  seats_limit(p_seats_limit), seats_taken(0),
  nr_of_rates(0), rate(0)
{
	date[0] = p_year; //exeption needed
	date[1] = p_month; //exeption needed
	date[2] = p_day; //exeption needed

	hour = p_hour;
	if (p_hour<0.0 || hour >= 24.0){
		hour = 0.0; //exeption needed
	}

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
}

/*DESTRUCTOR*/
Show::~Show(){}

/*METHODS*/

void Show::add_rate(uint rate_n)
{
  rate = (rate_n + rate* nr_of_rates)/(++nr_of_rates);
}

//// Precised info
void Show::displayInfo(SHOW_INFO info) const
{
	std::cout << getInfo(info).rdbuf();
}

std::ostringstream Show::getInfo(SHOW_INFO info) const
{
	std::ostringstream str;
	switch (info){
    case TITLE:
			str << title;
			break;
		case TYPE:
			switch (type){
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
      str << rate;
		default:
			throw "unprecised info[fun=Show::getInfo(SHOW_INFO)]";
			break;
	}
	return str;
}

//// All info
void Show::displayInfo() const
{
    std::cout << getInfo().rdbuf();
}

std::ostringstream Show::getInfo() const
{
	std::ostringstream str;
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


//// Audience members list
bool Show::displayAudience(){
	if (this->audience.getElement(0)==nullptr)
  {
		return false;
	}

  std::cout << getAudience().rdbuf();

	return true;
}

std::ostringstream Show::getAudience()
{
	Customer* aud_member = this->audience.getElement(0);
	std::ostringstream str;

	str << "^LISTA WIDZOW PRZEDSTAWIENIA^\n";

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


// - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ TODO: newBuyer


//// Add a new audience member
bool Show::newBuyer(Customer & buyer)
{

	bool b_success = true;

	if (buyer.tellAge() < this->min_age){
		std::cout << "Kupujacy nie spelnia wymagan dotyczacych wieku." << std::endl;
		b_success = false;
	}
	else if (this->seats_taken >= this->seats_limit){
		std::cout << "Brak wolnych miejsc na to przedstawienie." << std::endl;
		b_success = false;
	}
	else if (this->audience.findElement(buyer)){
		std::cout << "Ten kupujacy jest juz zapisany na to przedstawienie." << std::endl;
		b_success = false;
	}
	else{
		this->seats_taken++;
		this->audience+buyer;
	}
	return b_success;
}

//// Delete an audience member
bool Show::delBuyer(Customer & buyer)
{

	if (!(this->audience-buyer))
		return false;

	seats_taken--;

	return true;
}

//// Return a specific audience member
Customer* Show::getAudienceMember(int cust_id)
{
      return this->audience.getElement(cust_id-1);
}
