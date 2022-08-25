// Fecha

#ifndef Fecha_h
#define Fecha_h
#include <iostream>
#include <string>

class Fecha{// Clase

private: // Atributos
int Anio;
int Mes;
int Dia;

public: // Metodos
Fecha(); // Constructor
Fecha(int Anio,int Mes, int Dia);
// Getters
int getAnio() const;
int getMes() const;
int getDia() const;
std::string toString() const;
// Setters
void setAnio(const int&);
void setMes(const int&);
void setDia(const int&);

Fecha& operator = (const Fecha&);
};
#endif /* Fecha_h */
