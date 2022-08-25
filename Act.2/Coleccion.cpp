// Coleccion 

#include "Coleccion.h"

using namespace std;

Coleccion::Coleccion(){}

Coleccion::Coleccion(const Coleccion& c){
    fecha=c.fecha;
    producto=c.producto;
}

Coleccion& Coleccion::operator=(const Coleccion& c){
    fecha=c.fecha;
    producto=c.producto;
    return *this;
}

Fecha Coleccion::getFecha() const{
    return fecha;
}
Producto Coleccion::getProducto() const{
    return producto;
}

void Coleccion::setFecha(const Fecha& f){
    fecha= f;
}
void Coleccion::setProducto(const Producto& p){
    producto= p;
}
string Coleccion::toString() const{
    string base = producto.toString()+fecha.toString();
    return base;
}


