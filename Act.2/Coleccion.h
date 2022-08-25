// Colección

#ifndef Coleccio_n_h
#define Coleccio_n_h
#include <iostream>
#include <string>
#include "Producto.h"
#include "Fecha.h"

class Coleccion{
private:
    Fecha fecha;
    Producto producto;
    
public:
    Coleccion();
    Coleccion(const Coleccion&);
    
    Fecha getFecha() const;
    Producto getProducto() const;
    
    void setFecha(const Fecha&);
    void setProducto(const Producto&);
    
    std::string toString() const;
    
    Coleccion& operator = (const Coleccion&);
};

#endif /* Coleccio_n_h */
