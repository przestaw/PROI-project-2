/* Structure for exeption handling
 *
 * PROI, Lab project 3: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Przemysław Stawczyk
 */

#include "err_struct.hpp"

Err_Struct::Err_Struct(bool ignore_c, bool retry_c, bool display_c, std::string msg_c)
  :ignore(ignore_c), retry(retry_c), display(display_c), msg(msg_c), msg_disp("\n")
{}
Err_Struct::Err_Struct(bool ignore_c, bool retry_c, bool display_c, std::string msg_c, std::string msg_disp_c)
  :ignore(ignore_c), retry(retry_c), display(display_c), msg(msg_c), msg_disp(msg_disp_c)
{}
void Err_Struct::handle(std::ostream& s_out, std::ostream& s_err)
{
  if(display)
  {
    s_out << msg_disp;
  }
  s_err << msg;
}

bool Err_Struct::operator== (Err_Struct &second) const
{
  return
		this->ignore==second.ignore&&
    this->retry==second.retry&&
    this->display==second.display&&
    this->msg==second.msg;
}
