#ifndef CANCION_H_INCLUDED
#define CANCION_H_INCLUDED
#include <iostream>
#include <string>
#include "Nombre.h"
class Cancion {
private:
    std::string radio;
    std::string name_song;
    Nombre nombre_artista;
    Nombre nombre_cantante;
    int temas;
public:
    Cancion();
    void setRadio(const std::string&);
    void setNamesong(const std::string&);
    void setNombreartis(const Nombre&);
    void setNombrecanta(const Nombre&);
    void setTemas(const int&);
    std::string getRadio()const;
    std::string getNamesong()const;
    Nombre getNombreartis()const;
    Nombre getNombrecanta()const;
    int getTemas()const;
    std::string ToString()const;
    static int comparai(const Cancion& hi, const Cancion& ho);
    static int comparat(const Cancion& hi, const Cancion& ho);
};
#endif // CANCION_H_INCLUDED
