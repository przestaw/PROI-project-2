/*
 * tests designed for debuging theater project
 *
 * PROI, Lab project 3: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Przemysław Stawczyk
 */

#define BOOST_TEST_MODULE PROI__PROJECT_3_TEST
#include <boost/test/included/unit_test.hpp>

#define sucess "(づ• ͜ʖ•)づ" //unfortunately cannot use custom sucess message ~ TO DELETE
#define failure "( x ʖ̯ x )" //unfortunately cannot use custom fail message ~ TO DELETE

#define opt(x) << x << '\n'

#include "Menus.hpp" //it also include Customer and its deriviate classes

std::stringstream  silent; //silent output for testing

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE(Auto_Theater_Suite)

  BOOST_AUTO_TEST_SUITE(Auto_Customer_Suite)
    Queue<Customer> cust_queue;
//global for this suite
    BOOST_AUTO_TEST_CASE(Customer_add_test)
    {
      Customer* new_cust;
      BOOST_CHECK_NO_THROW(
        new_cust = new Customer("Adolf","Hitler",1000);
        cust_queue+*new_cust;
        new_cust = new Woman("Janina","Juziak",67);
        cust_queue+*new_cust;
        new_cust = new Man("Szczepan","Wodeczka",38);
        cust_queue+*new_cust;
        new_cust = new Child("Kali","Nigga",15);
        cust_queue+*new_cust;
      );
    }

    BOOST_AUTO_TEST_CASE(Customer_print_test)
    {
      std::stringstream str;
      for(int i=0;i<4;++i)
      {
        str << cust_queue.getElement(i)->getInfo().rdbuf();
      }
      BOOST_CHECK_EQUAL(str.str(),"| Imie: Adolf | Nazwisko: Hitler | Wiek: 1000 | Typ: transwestyta |\n| Imie: Janina | Nazwisko: Juziak | Wiek: 67 | Typ: kobieta |\n| Imie: Szczepan | Nazwisko: Wodeczka | Wiek: 38 | Typ: mezczynza |\n| Imie: Kali | Nazwisko: Nigga | Wiek: 15 | Typ: dziecko |\n");
    }
//free memory
    BOOST_AUTO_TEST_CASE(free_memory_after_test)
    {
      Customer* temp_cust;
      for (uint i=0; i<4; i++)
      {
        temp_cust = cust_queue.getElement(i);
        if (temp_cust!=nullptr)
  			{
          delete temp_cust;
        }
      }
    }
  BOOST_AUTO_TEST_SUITE_END()//Auto_Customer_Suite

  BOOST_AUTO_TEST_SUITE(Auto_Show_Suite)
    Show perf("test",1,13,2018,5,10,9,4);

    BOOST_AUTO_TEST_CASE(Show_Rate_throw_test)
    {
      BOOST_CHECK_THROW(perf.Rate(), Err_Struct);
    }

    BOOST_AUTO_TEST_CASE(Show_add_test)
    {
      BOOST_CHECK_NO_THROW(
        perf.newBuyer(*(new Woman("Janina","Juziak",67)));
        perf.newBuyer(*(new Man("Szczepan","Wodeczka",38)));
        perf.newBuyer(*(new Child("Kali","Nigga",15)));
      )
      Customer * temp = new Customer("Maluczki","Ludzik", 10);
      BOOST_CHECK_THROW(perf.newBuyer(*(temp)), Err_Struct);
      delete temp;
      temp = new Customer("Adolf","Hitler",1000);
      BOOST_CHECK_NO_THROW(perf.newBuyer(*(temp)));
      BOOST_CHECK_THROW(perf.newBuyer(*(temp)), Err_Struct);
      temp = new Customer("Josef","Stalin", 100);
      BOOST_CHECK_THROW(perf.newBuyer(*(temp)), Err_Struct);
      delete temp;
    }

    BOOST_AUTO_TEST_CASE(Show_Rate_sucess_test)
    {
      BOOST_CHECK_NO_THROW(perf.Rate());
    }
    //free memory
    BOOST_AUTO_TEST_CASE(free_memory_after_test)
    {
      Customer* temp_cust;
      for (uint i=1; i<5; ++i)
      {
        temp_cust = perf.getAudienceMember(i);
        if (temp_cust!=nullptr)
        {
          delete temp_cust;
        }
      }
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_FIXTURE_TEST_SUITE(Auto_Menus_Suite, Menus)
    //Menus test
    BOOST_AUTO_TEST_CASE(Menus_getInput_test)
    {
      std::stringstream  input;
      input opt(1) opt(7);
      BOOST_CHECK_EQUAL(1,getOption(0,5,input, silent));
      BOOST_CHECK_THROW(getOption(0,5,input, silent), Err_Struct);
    }

    BOOST_AUTO_TEST_CASE(Menus_FileExport_test)
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

    BOOST_AUTO_TEST_CASE(Menus_newCust_print_Customer_test)
    {
      std::stringstream input, out;
      input opt("Adolf") opt("Hitler") opt("1000") opt(0);
      input opt("Janina") opt("Juziak") opt("67") opt(1);
      input opt("Szczepan") opt("Wodeczka") opt("38") opt(2);
      input opt("Kali") opt("Nigga") opt("15") opt(3);
      for(int i=0; i<4; ++i)
      {
        newCust(input, silent);
      }
      print<Customer>(cust_queue, 4, out);
      BOOST_CHECK_EQUAL(out.str(),"~~~Lista elementow~~~\nNR 1\n| Imie: Adolf | Nazwisko: Hitler | Wiek: 1000 | Typ: transwestyta |\nNR 2\n| Imie: Janina | Nazwisko: Juziak | Wiek: 67 | Typ: kobieta |\nNR 3\n| Imie: Szczepan | Nazwisko: Wodeczka | Wiek: 38 | Typ: mezczynza |\nNR 4\n| Imie: Kali | Nazwisko: Nigga | Wiek: 15 | Typ: dziecko |\n");
    }

    BOOST_AUTO_TEST_CASE(Menus_Basic_Interface_Test)
    {
      std::stringstream input;
      input opt(9) opt(1) opt(0) opt(2) opt(0) opt(3) opt(0);
      input opt(1) opt(6) opt(2) opt(7) opt(3) opt(5);
      input opt(2) opt(5) opt(0) opt(5) opt(0);
      BOOST_CHECK_NO_THROW( Interface(input,silent,silent) );
    }

  BOOST_AUTO_TEST_SUITE_END()//Auto_Menus_Suite

BOOST_AUTO_TEST_SUITE_END()//Auto_Theater_Suite
