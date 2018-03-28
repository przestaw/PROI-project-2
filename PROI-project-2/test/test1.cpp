#include <iostream>
#include "Queue.hpp"
#include "theater.hpp"

using namespace std;

Customer cus1;
Show perf(Show::PANTOMIME, 18, 2018, 3, 25, 18, 3);

bool b_quit = false;
UNSH decision;

int main()
{
      cout << "INFO O PRZEDSTAWIENIU: " << endl << endl;
      perf.displayInfo();

      cout << endl << endl;
      cout << "INFO O KUPUJACYM: " << endl << endl;
      cus1.displayInfo();

      while (!b_quit){
            cout << endl << endl;
            cout << "1. Zapisz Jana na przedstawienie." << endl;
            cout << "2. Wypisz Jana z przedstawienia." << endl;
            cout << "3. Wyswietl info o przedstawieniu." << endl;
            cout << "0. Wyjdz" << endl;

            cin >> decision;
            cout << endl;

            switch (decision){
            case 1:
                  if (perf.newBuyer(cus1)){
                        cout << "Pomyslnie zapisano Jana na przedstawienie." << endl;}
                  else{
                        cout << "Nie udalo sie zapisac Jana na przedstawienie." << endl;}
                  break;
            case 2:
                  if (perf.delBuyer(cus1)){
                        cout << "Wypisano Jana z przedstawienia." << endl;}
                  else{
                        cout << "Nie udalo sie wypisac Jana z przedstawienia." << endl;}
                  break;
            case 3:
                  perf.displayInfo(); cout << endl << endl;
                  break;
            case 0:
                  b_quit=true;
            default:
                  continue; break;
            }
      }
      return 0;
}
