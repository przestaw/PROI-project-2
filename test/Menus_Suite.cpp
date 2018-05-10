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
	
	BOOST_AUTO_TEST_CASE(Menus_newCust_test_1)
    {
      std::stringstream input, out;
      input opt("Adolf") opt("Hitler") opt("1000") opt(0);
        BOOST_CHECK_NO_THROW(newCust(input, silent));
    }
	
	BOOST_AUTO_TEST_CASE(Menus_newCust_test_2)
    {
      std::stringstream input, out;
      input opt("Janina") opt("Juziak") opt("67") opt(1);
        BOOST_CHECK_NO_THROW(newCust(input, silent));
    }

	BOOST_AUTO_TEST_CASE(Menus_newCust_test_3)
    {
      std::stringstream input, out;
      input opt("Szczepan") opt("Wodeczka") opt("38") opt(2);
        BOOST_CHECK_NO_THROW(newCust(input, silent));
    }

	BOOST_AUTO_TEST_CASE(Menus_newCust_test_4)
    {
      std::stringstream input, out;
      input opt("Kali") opt("Nigga") opt("15") opt(3);
        BOOST_CHECK_NO_THROW(newCust(input, silent));
    }

	
	BOOST_AUTO_TEST_CASE(Menus_newCust_test_5)
    {
      std::stringstream input, out;
      input opt("Adolf") opt("Hitler") opt("1000") opt(0);
      input opt("Janina") opt("Juziak") opt("67") opt(1);
      input opt("Szczepan") opt("Wodeczka") opt("38") opt(2);
      input opt("Kali") opt("Nigga") opt("15") opt(3);
      for(int i=0; i<4; ++i)
      {
        BOOST_CHECK_NO_THROW(newCust(input, silent));
      }      
    }
	
    BOOST_AUTO_TEST_CASE(Menus_print_Customer_test)
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

