#ifndef NOMBRE_H_INCLUDED
#define NOMBRE_H_INCLUDED
#include <iostream>
#include <string>
class Nombre {
private:
    std::string nombre;
    std::string apellidos;
public:
    Nombre();
    void setNombre(const std::string&);
    void setApellidos(const std::string&);
    std::string getNombre()const;
    std::string getApellidos()const;
    std::string ToString()const;
};
#endif // NOMBRE_H_INCLUDED
