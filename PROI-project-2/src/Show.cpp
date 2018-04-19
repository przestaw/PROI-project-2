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
#include "../include/Show.hpp"
#include "../include/Customer.hpp"
#include "../include/Queue.hpp"


/****CLASS SHOW****/

/*CONSTRUCTOR*/

////
Show::Show(std::string p_title, int p_type, uint p_min_age, uint p_year, uint p_month, uint p_day, double p_hour, uint p_seats_limit){
      title = p_title;

	min_age = p_min_age;

	date[0] = p_year;
	date[1] = p_month;
	date[2] = p_day;

	hour = p_hour;
	if (p_hour<0.0 || hour >= 24.0){
		hour = 0.0;
	}

	seats_limit = p_seats_limit;
	seats_taken = 0;

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

//// Precised info
void Show::displayInfo(SHOW_INFO info) const{
	std::cout << getInfo(info);
}

std::iostream Show::getInfo(SHOW_INFO info) const{
	std::iostream str
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
		default:
			throw "unprecised info[fun=Show::getInfo(SHOW_INFO)]";
			break;
	}
	return str;
}

//// All info
void Show::displayInfo() const{
    std::cout << getInfo;
}

std::iostream Show::getInfo() const{
	std::iostream
	str << "|| Tytul: " << this->getInfo(TITLE) << '\n'
	 		<< "|| Gatunek: " << this->getInfo(TYPE)
	 		<< "|| Data: " << this->getInfo(DATE)
	 		<< "|| Godzina: " << this->getInfo(HOUR)  << '\n'
	 		<< "|| Minimalny wiek: " << this->getInfo(MIN_AGE)
	 		<< "|| Liczba miejsc: " << this->getInfo(SEATS_LIMIT)
	 		<< "|| Zajetych: " << this->getInfo(SEATS_TAKEN) << '\n';
	return str;
}


//// Audience members list
bool Show::displayAudience(){
	if (this->audience.getElement(0)==nullptr){
		return false;
	}

  std::cout << getAudience();

	return true;
}

std::iostream Show::getAudience(){
	Customer* aud_member = this->audience.getElement(0);
	std::iostream str;

	str << "^LISTA WIDZOW PRZEDSTAWIENIA^\n";

	if (aud_member==nullptr){
		str << " -- EMPTY -- "
		return str;
	}

	for (int i=1; aud_member!=nullptr; i++){
		str << i << ". " << aud_member->getInfo(Customer::FORE)
				<< " " << aud_member->getInfo(Customer::SUR) << '\n';
		aud_member = this->audience.getElement(i);
	}
	return str;
}
// - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ TODO: newBuyer
//// Add a new audience member
bool Show::newBuyer(Customer & buyer){

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
bool Show::delBuyer(Customer & buyer){

	if (!(this->audience-buyer))
		return false;

	seats_taken--;

	return true;
}

//// Return a specific audience member
Customer* Show::getAudienceMember(int cust_id){
      return this->audience.getElement(cust_id-1);
}
