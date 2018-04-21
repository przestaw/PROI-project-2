/*
 * Child.hpp
 *
 * Class Deriviated from Customer representing the theater client
 * ^DECLARATION
 *
 * PROI, Lab project 3: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Przemysław Stawczyk
 */
#include "Customer.hpp"

class Child:public Customer
{
 private:
   static const SEX sex = KID;
 public:
   virtual uint rate(Show *show_r);
   Child();
   // two argument constructor ??
   Child(std::string, std::string, uint);
   ~Child();
};
