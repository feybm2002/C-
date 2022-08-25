// Menu

#ifndef Menu_h
#define Menu_h
#include <iostream>
#include <string>
#include "Coleccion.h"

class Menu{
private:
    Coleccion coleccion;
    
public:
    Menu();
    Menu(const Menu&);
    void interfaz();
};

#endif /* Menu_h */
