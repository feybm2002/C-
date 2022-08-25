//  Menu.h
//  Metodos

#ifndef Menu_h
#define Menu_h
#include <iostream>
#include <string>
#include "list.h"

class Menu {
private:
    void userInterface(List<int>&);
    
public:
    Menu(List<int>&);
};

#endif /* Menu_h */
