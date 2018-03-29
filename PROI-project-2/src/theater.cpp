/*
 * theater.cpp
 * 
 * - Laboratory project 2: "Theater", PROI
 * - Tutor: dr inż. Wiktor Kuśmirek
 *
 * - The file contains definitions of classes:
 *  > Customer
 *  > Show
 * - Version: 27.03.2018, Kamil Zacharczuk
 */

#include <ctime>
#include <cstdlib>

#include "Queue.hpp" //template linked list queue 
#include "theater.hpp" //classes declarations


/****CLASS CUSTOMER****/

/*CONSTRUCTORS*/

//// Parameters
Customer::Customer(std::string p_forename, std::string p_surname, UNSH p_age){
      this->forename = p_forename;
      this->surname = p_surname;
	this->age = p_age;
}

//// Default
Customer::Customer()
{
      std::srand(std::time(nullptr));

      this->forename = "Jan";
      this->surname = "Kowalski";
      this->age = rand()%77+13;
}

/*DESTRUCTOR*/
Customer::~Customer() {}

/*METHODS*/

//// Precised info
void Customer::displayInfo (CUS_INFO info) const{
      switch (info){
      case FORE: std::cout << forename; break;
      case SUR: std::cout << surname; break;
      case AGE: std::cout << age; break;
      default: std::cout << "unprecised info"; break;
      }
}

//// All info
void Customer::displayInfo() const{
      std::cout << "| Imie: "; displayInfo(FORE);
      std::cout << "| Nazwisko: "; displayInfo(SUR);
      std::cout << "| Wiek: "; displayInfo(AGE);
      std::cout << "|" << std::endl;
}



/****CLASS SHOW****/

/*CONSTRUCTOR*/

////
Show::Show(std::string p_title, int p_type, UNSH p_min_age, UNSH p_year, UNSH p_month, UNSH p_day, double p_hour, UNSH p_seats_limit){
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

	switch (p_type){
            case 1: type = DRAMA; break;
            case 2: type = COMEDY; break;
            case 3: type = MUSICAL; break;
            case 4: type = OPERA; break;
            case 5: type = PANTOMIME; break;
	}
}

/*DESTRUCTOR*/
Show::~Show(){}

/*METHODS*/

//// Precised info
void Show::displayInfo(SHOW_INFO info) const{
	switch (info){
            case TITLE:
                  std::cout << title; break;
		case TYPE:
			switch (type){
			      case DRAMA: std::cout << "Dramat"; break;
			      case COMEDY: std::cout << "Komedia"; break;
			      case MUSICAL: std::cout << "Musical"; break;
			      case OPERA: std::cout << "Opera"; break;
			      case PANTOMIME: std::cout << "Pantomima"; break;
			}
			break;
		case MIN_AGE:
			std::cout << min_age; break;
		case DATE:
			std::cout << date[0] << "-" << date[1] << "-" << date[2]; break;
		case HOUR:
			if (hour>=0 && hour < 10){
				std::cout << "0";}
			std::cout << hour; break;
		case SEATS_LIMIT:
			std::cout << seats_limit; break;
		case SEATS_TAKEN:
			std::cout << seats_taken; break;
		default:
			std::cout << "unprecised info"; break;
	}
}

//// All info
void Show::displayInfo() const{
      std::cout << "|| Tytul: "; this->displayInfo(TITLE); std::cout << std::endl;
      std::cout << "|| Gatunek: "; this->displayInfo(TYPE);
      std::cout << "|| Data: "; this->displayInfo(DATE);
      std::cout << "|| Godzina: "; this->displayInfo(HOUR); std::cout << std::endl;
      std::cout << "|| Minimalny wiek: "; this->displayInfo(MIN_AGE);
      std::cout << "|| Liczba miejsc: "; this->displayInfo(SEATS_LIMIT);
      std::cout << "|| Zajetych: "; this->displayInfo(SEATS_TAKEN);
      std::cout << std::endl;
}

//// Audience members list
bool Show::displayAudience(){
	Customer* aud_member = this->audience.getElement(0);

	if (aud_member==nullptr){
		return false;
	}

      std::cout << "^LISTA WIDZOW PRZEDSTAWIENIA^" << std::endl;

	for (int i=1; aud_member!=nullptr; i++){
		std::cout << i << ". "; aud_member->displayInfo(Customer::FORE);
		std::cout << " "; aud_member->displayInfo(Customer::SUR);
		std::cout << std::endl;
		aud_member = this->audience.getElement(i);
	}
	return true;
}

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
	else{
		if (this->audience.findElement(buyer)){
			std::cout << "Ten kupujacy jest juz zapisany na to przedstawienie." << std::endl;
			b_success = false;
		}
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




