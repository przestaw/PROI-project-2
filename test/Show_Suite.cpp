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



  BOOST_AUTO_TEST_SUITE(Auto_Show_Suite)

    BOOST_AUTO_TEST_CASE(Show_Rate_throw_test)
    {
	  Show perf("test",1,13,2018,5,10,9,4);
      BOOST_CHECK_THROW(perf.Rate(), Err_Struct);
    }

    BOOST_AUTO_TEST_CASE(Show_add_test_Woman)
    {
	  Show perf("test",1,13,2018,5,10,9,4);
      BOOST_CHECK_NO_THROW(
        perf.newBuyer(*(new Woman("Janina","Juziak",67)));
      );
    }

	BOOST_AUTO_TEST_CASE(Show_add_test_Man)
    {
	  Show perf("test",1,13,2018,5,10,9,4);
      BOOST_CHECK_NO_THROW(
        perf.newBuyer(*(new Man("Szczepan","Wodeczka",38)));
      );
    }
    
    BOOST_AUTO_TEST_CASE(Show_add_test_Child)
    {
	  Show perf("test",1,13,2018,5,10,9,4);
      BOOST_CHECK_NO_THROW(
        perf.newBuyer(*(new Child("Kali","Nigga",15)));
      );
    }
    
    BOOST_AUTO_TEST_CASE(Show_add_test_Customer)
    {
	  Show perf("test",1,13,2018,5,10,9,4);
      BOOST_CHECK_THROW(perf.newBuyer(*(new Customer("Maluczki","Ludzik", 10))), Err_Struct);
    }
    
    BOOST_AUTO_TEST_CASE(Show_add_test_2_times)
    {
	  Show perf("test",1,13,2018,5,10,9,4);
	  BOOST_REQUIRE_NO_THROW(perf.newBuyer(*(new Customer("Josef","Stalin", 100))));
      BOOST_CHECK_THROW(perf.newBuyer(*(new Customer("Josef","Stalin", 100))), Err_Struct);
    }
    
	BOOST_AUTO_TEST_CASE(Show_add_test_limited_seats)
    {
	  Show perf("test",1,13,2018,5,10,9,1);
      perf.newBuyer(*(new Woman("Janina","Juziak",67)));
      BOOST_CHECK_THROW(perf.newBuyer(*(new Customer("Adolf","Hitler",1000))), Err_Struct);
    }
    BOOST_AUTO_TEST_CASE(Show_Rate_sucess_test)
    {
	  Show perf("test",1,13,2018,5,10,9,4);
	  perf.newBuyer(*(new Woman("Janina","Juziak",67)));
      perf.newBuyer(*(new Man("Szczepan","Wodeczka",38)));
	  perf.newBuyer(*(new Child("Kali","Nigga",15)));
      BOOST_CHECK_NO_THROW(perf.Rate());
    }

  BOOST_AUTO_TEST_SUITE_END()

