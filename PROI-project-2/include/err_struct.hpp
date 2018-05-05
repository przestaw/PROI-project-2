/* Structure for exeption handling
 *
 * PROI, Lab project 3: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Przemysław Stawczyk
 */

#ifndef _ERR_STRUCT_
#define _ERR_STRUCT_

#include <string>
#include <exception>
#include <iostream>

class Err_Struct
  :public std::exception
{
public:
  Err_Struct(bool ignore_c, bool retry_c, bool display_c, std::string msg_c);
  Err_Struct(bool ignore_c, bool retry_c, bool display_c, std::string msg_c, std::string msg_disp_c);
  void handle(std::ostream& s_out = std::cout, std::ostream& s_err = std::cerr);
  bool operator== (Err_Struct &) const;
private:
  bool ignore;
  bool retry;
  bool display;
  std::string msg;
  std::string msg_disp;
};

#endif //_ERR_STRUCT_
