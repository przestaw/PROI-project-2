/*
 * Woman.hpp
 *
 * Class Deriviated from Customer representing the theater client
 * ^DECLARATION
 *
 * PROI, Lab project 3: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Przemysław Stawczyk
 */
#include "Customer.hpp"

#ifndef _WOMAN_HPP_
#define _WOMAN_HPP_

class Woman:public Customer
{
  public:
    virtual uint Rate(Show *show_r);
    Woman();
    Woman(std::string, std::string, uint);
    ~Woman();
};

#endif //_WOMAN_HPP_
