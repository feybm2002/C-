#include <string>
#include <iostream>
#include "Menu.h"
using namespace std;
void Menu::inicializa()
{
    Expresion R;
    string Help;
    int respondera;
    cout << "\n\t\t\tEXPRESIONES DE INFIJO Y POSFIJO\n" << endl;
    do
    {
        cout << "\tAgregue su Expresion";
        cin >> Help;
        for (auto & c: Help) c = toupper(c);
        R.setIf(Help);
        cout << "\n\t Modo infija: " << R.tostring();
        cout << "\n\t Modo posfija: " << R.to_string();
        cout << "\n\n\tDeseas hacer otra?\n";
        cout << "\t(1) Si" << endl;
        cout << "\t(2) No" << endl;
        cout << "\tOpcion";
        cin >> respondera;
        cin.ignore();
        cout << "\n";
        R.Funtion();
    }
    while(respondera == 1);
}
