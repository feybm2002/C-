// Producto

#include "Producto.h"

using namespace std;

Producto::Producto(){}

Producto::Producto(const Producto& p):
Nombre(p.Nombre),
Cantidad (p.Cantidad),
PrecioMa (p.PrecioMa),
PrecioMe (p.PrecioMe),
Peso(p.Peso),
Codigo(p.Codigo){}
Producto& Producto::operator=(const Producto& p){
    Nombre= p.Nombre;
    Cantidad= p.Cantidad;
    PrecioMa= p.PrecioMa;
    PrecioMe= p.PrecioMe;
    Peso= p.Peso;
    Codigo= p.Codigo;
    return *this;
}
string Producto::getNombre() const{
    return Nombre;
}
int Producto::getCantidad() const{
    return Cantidad;
}
float Producto::getPrecioMa() const{
    return PrecioMa;
}
float Producto::getPrecioMe() const{
    return PrecioMe;
}
int Producto::getPeso() const{
    return Peso;
}
string Producto::getCodigo() const{
    return Codigo;
}

void Producto::setNombre(const string& N){
    Nombre = N;
}
void Producto::setCantidad(const int& C){
    Cantidad = C;
}
void Producto::setPrecioMa(const float& PA){
    PrecioMa = PA;
}
void Producto::setPrecioMe(const float& PE){
    PrecioMe = PE;
}
void Producto::setPeso(const int& P){
    Peso = P ;
}
void Producto::setCodigo(const string& Co){
    Codigo = Co;
}
string Producto::toString() const {
    return "Información del producto:"+(Nombre)+"/"+to_string(Cantidad)+"/"+to_string(PrecioMa)+"/"+to_string(PrecioMe)+"/"+to_string(Peso)+"/"+(Codigo);
}

