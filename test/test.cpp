/*
 * tests designed for debuging theater project
 *
 * PROI, Lab project 3: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Przemysław Stawczyk
 */

#define BOOST_TEST_MODULE Theater_Test
#include <boost/test/included/unit_test.hpp>

#define sucess "(づ• ͜ʖ•)づ"
#define failure "( x ʖ̯ x )"

#define opt(x) << x << '\n'

#include "Menus.hpp" //it also include Customer and its deriviate classes

std::stringstream  silent; //silent output for testing

using namespace boost::unit_test;

class Test_Menus_Fixture:public Menus
{

};

BOOST_AUTO_TEST_SUITE(Auto_Theater_Suite)


  BOOST_AUTO_TEST_SUITE(Auto_Customer_Suite)
    Queue<Customer> cust_queue;

    BOOST_AUTO_TEST_CASE(customer_add_test)
    {
      Customer* new_cust;
      new_cust = new Customer("Adolf","Hitler",1000);
      cust_queue+*new_cust;
      new_cust = new Woman("Janina","Juziak",67);
      cust_queue+*new_cust;
      new_cust = new Man("Szczepan","Wodeczka",38);
      cust_queue+*new_cust;
      new_cust = new Child("Kali","Nigga",15);
      cust_queue+*new_cust;
    }

    BOOST_AUTO_TEST_CASE(customer_print_test)
    {
      std::stringstream str;
      for(int i=0;i<4;++i)
      {
        str << cust_queue.getElement(i)->getInfo().rdbuf();
      }
      BOOST_CHECK_EQUAL(str.str(),"| Imie: Adolf | Nazwisko: Hitler | Wiek: 1000 | Typ: transwestyta |\n| Imie: Janina | Nazwisko: Juziak | Wiek: 67 | Typ: kobieta |\n| Imie: Szczepan | Nazwisko: Wodeczka | Wiek: 38 | Typ: mezczynza |\n| Imie: Kali | Nazwisko: Nigga | Wiek: 15 | Typ: dziecko |\n");
    }


  BOOST_AUTO_TEST_SUITE_END()//Auto_Customer_Suite


  BOOST_FIXTURE_TEST_SUITE(Auto_Menus_Suite, Menus)
    //Menus test
    BOOST_AUTO_TEST_CASE(menus_getInput_test)
    {
      std::stringstream  input;
      input opt(1) opt(7);
      BOOST_CHECK_EQUAL(1,getOption(0,5,input, silent));
      BOOST_CHECK_THROW(getOption(0,5,input, silent), Err_Struct);
    }

    BOOST_AUTO_TEST_CASE(menus_FileExport_test)
    {
      std::stringstream  input, compare1, compare2, output;
      input opt("test.txt");
      compare1 opt("barnaba") opt("kalineusz") opt("argumenty");
      compare2 << compare1.str() << '\n';
      FileExport(input,silent,compare1);
      std::fstream file;
      file.open("test.txt",std::fstream::in);
      file >> output.rdbuf();
      file.close();
      BOOST_CHECK_EQUAL(compare2.str(),output.str());
    }

    BOOST_AUTO_TEST_CASE(menus_getPerf_test)
    {
      
    }

  BOOST_AUTO_TEST_SUITE_END()//Auto_Menus_Suite

BOOST_AUTO_TEST_SUITE_END()//Auto_Theater_Suite
