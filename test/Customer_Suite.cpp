/*
 * tests designed for debuging theater project
 *
 * PROI, Lab project 3: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Przemysław Stawczyk
 */


#include <boost/test/unit_test.hpp>

#define opt(x) << x << '\n'

#include "Menus.hpp" //it also include Customer and its deriviate classes

std::stringstream  silent; //silent output for testing

using namespace boost::unit_test;

  BOOST_AUTO_TEST_SUITE(Auto_Customer_Suite)
    
    BOOST_AUTO_TEST_CASE(Customer_add_test)
    {
	  Queue<Customer> cust_queue;
      Customer* new_cust;
      BOOST_CHECK_NO_THROW(
        new_cust = new Customer("Adolf","Hitler",1000);
        cust_queue+*new_cust;
      );
    }

    BOOST_AUTO_TEST_CASE(Woman_add_test)
    {
	  Queue<Customer> cust_queue;
      Customer* new_cust;
      BOOST_CHECK_NO_THROW(
        new_cust = new Woman("Janina","Juziak",67);
        cust_queue+*new_cust;
      );
    }
    
    BOOST_AUTO_TEST_CASE(Man_add_test)
    {
	  Queue<Customer> cust_queue;
      Customer* new_cust;
      BOOST_CHECK_NO_THROW(
        new_cust = new Man("Szczepan","Wodeczka",38);
        cust_queue+*new_cust;
      );
    } 
    
    BOOST_AUTO_TEST_CASE(Child_add_test)
    {
	  Queue<Customer> cust_queue;
      Customer* new_cust;
      BOOST_CHECK_NO_THROW(
        new_cust = new Child("Kali","Nigga",15);
        cust_queue+*new_cust;
      );
    }
    
    BOOST_AUTO_TEST_CASE(Customer_print_test)
    {
	  Queue<Customer> cust_queue;
      Customer* new_cust;
	  new_cust = new Customer("Adolf","Hitler",1000);
      cust_queue+*new_cust;
      new_cust = new Woman("Janina","Juziak",67);
      cust_queue+*new_cust;
      new_cust = new Man("Szczepan","Wodeczka",38);
      cust_queue+*new_cust;
      new_cust = new Child("Kali","Nigga",15);
      cust_queue+*new_cust;
      std::stringstream str;
      for(int i=0;i<4;++i)
      {
        str << cust_queue.getElement(i)->getInfo().rdbuf();
      }
      BOOST_CHECK_EQUAL(str.str(),"| Imie: Adolf | Nazwisko: Hitler | Wiek: 1000 | Typ: transwestyta |\n| Imie: Janina | Nazwisko: Juziak | Wiek: 67 | Typ: kobieta |\n| Imie: Szczepan | Nazwisko: Wodeczka | Wiek: 38 | Typ: mezczynza |\n| Imie: Kali | Nazwisko: Nigga | Wiek: 15 | Typ: dziecko |\n");
    }

  BOOST_AUTO_TEST_SUITE_END()//Auto_Customer_Suite

