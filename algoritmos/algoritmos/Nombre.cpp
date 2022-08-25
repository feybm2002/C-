#include <iostream>
#include "Nombre.h"
#include "string"
Nombre::Nombre() {}
void Nombre::setNombre(const std::string& name) {
    nombre=name;
}
void Nombre::setApellidos(const std::string& lastname) {
    apellidos=lastname;
}
std::string Nombre::getNombre()const {
    return nombre;
}
std::string Nombre::getApellidos()const {
    return apellidos;
}
std::string Nombre::ToString()const {
    return nombre + " " + apellidos;
}
