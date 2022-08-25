#ifndef MENUU_H_INCLUDED
#define MENUU_H_INCLUDED
#include "Listaa.h"
#include "Cancion.h"
class Menu {
private:
    void iniciar(Lista<Cancion>&);
public:
    Menu (Lista<Cancion>&);
};
#endif // MENUU_H_INCLUDED
