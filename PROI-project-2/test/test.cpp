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

std::stringstream  s_out; //silent output for testing

using namespace boost::unit_test;

class Test_Menus_Fixture:public Menus
{

};

BOOST_AUTO_TEST_SUITE(Auto_Theater_Suite)


  BOOST_AUTO_TEST_SUITE(Auto_Customer_Suite)

    BOOST_AUTO_TEST_CASE(customer_add_test)
    {
      Queue<Customer>* cust_queue = new Queue<Customer>;
      Customer* new_cust;
      new_cust = new Customer("Adolf","Hitler",1000);
      *cust_queue+*new_cust;
      new_cust = new Woman("Janina","Juziak",67);
      *cust_queue+*new_cust;
      new_cust = new Man("Szczepan","Wodeczka",38);
      *cust_queue+*new_cust;
      new_cust = new Child("Kali","Nigga",15);
      *cust_queue+*new_cust;
    }

  BOOST_AUTO_TEST_SUITE_END()//Auto_Customer_Suite

/*
  BOOST_FIXTURE_TEST_SUITE(Auto_Menus_Suite, Menus)
    //Menus test
    BOOST_AUTO_TEST_CASE(menus_getInput_test)
    {
      std::stringstream  str;
      str opt(1) opt(7);
      BOOST_CHECK_EQUAL(1,Menus::getOption(0,5,str,s_out));
      BOOST_CHECK_THROW(Menus::getOption(0,5,str,s_out), Err_Struct);
    }

  BOOST_AUTO_TEST_SUITE_END()//Auto_Menus_Suite
*/

BOOST_AUTO_TEST_SUITE_END()//Auto_Theater_Suite
