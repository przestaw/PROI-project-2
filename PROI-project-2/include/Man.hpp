/*
 * Man.hpp
 *
 * Class Deriviated from Customer representing the theater client
 * ^DECLARATION
 *
 * PROI, Lab project 3: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Przemysław Stawczyk
 */
#include "Customer.hpp"

#ifndef _MAN_HPP_
#define _MAN_HPP_

class Man:public Customer
{
  public:
    virtual uint Rate(Show *show_r);
    Man();
    // two argument constructor ??
    Man(std::string, std::string, uint);
    ~Man();
};

#endif //_MAN_HPP_
