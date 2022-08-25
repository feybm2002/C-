// Fecha

#include "Fecha.h"

using namespace std;

Fecha::Fecha(){}

Fecha::Fecha(int Anio, int Mes, int Dia){
    Anio=Anio;
    Mes=Mes;
    Dia=Dia;
}

Fecha& Fecha::operator=(const Fecha& f){
    Anio= f.Anio;
    Mes= f.Mes;
    Dia= f.Dia;
    return  *this;
}

int Fecha::getAnio() const{
    return Anio;
}
int Fecha::getMes() const{
    return Mes;
}
int Fecha::getDia() const{
    return Dia;
}

void Fecha::setAnio(const int& A){
    Anio=A;
}
void Fecha::setMes(const int& M){
    Mes=M;
}
void Fecha::setDia(const int& D){
    Dia=D;
}
string Fecha::toString() const {
    return "Fecha:"+to_string(Anio)+"/"+to_string(Mes)+"/"+to_string(Dia);
}







