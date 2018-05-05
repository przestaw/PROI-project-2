#include <iostream>
#include "queue.hpp"

using namespace std;

Queue<int> Integers;

int decision;
bool quit = false;

int menu();
void add();
void sub();
void print();

int main()
{
      while (!quit)
      {
            decision = menu();

            switch (decision){
            case 1:
                  add(); break;
            case 2:
                  sub(); break;
            case 3:
                  print(); break;
            case 0:
                  quit=true; break;
            }
      }

      return 0;
}

int menu(){
      cout << endl << endl;
      cout << "1. Dodaj liczbe do kolejki" << endl
            << "2. Usun liczbe z kolejki" << endl
            << "3. Wypisz zawartosc" << endl
            << "0. Wyjdz" << endl;

      int choice;
      do{
            cin >> choice;
      } while (choice<0 || choice>3);

      return choice;
}

void add()
{
      int number;
      cout << "Podaj liczbe. ";
      cin >> number;
	int &r = number;	
      if (Integers+r == nullptr)
            cout << "Cos poszlo nie tak." << endl;
}

void sub()
{
      int number;
      cout << "Podaj liczbe. ";
      cin >> number;
	  int &r = number;

      bool success = Integers-r;

      if (success == false)
            cout << "Nie udalo sie usunac elementu." << endl;
      else if (success == true)
            cout << "Usunieto element " << number << endl;
}

void print()
{
	!Integers;
}
