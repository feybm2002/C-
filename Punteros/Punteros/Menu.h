#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "List.h"
#include "Song.h"

class Menu {
private:
    void Initial(List<Song>&);
public:
    Menu (List<Song>&);
};
#endif // MENUU_H_INCLUDED
