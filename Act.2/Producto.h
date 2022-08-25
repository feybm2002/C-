// Producto 


#ifndef Producto_h
#define Producto_h
#include <iostream>
#include <string>

class Producto{
private:
    std::string Nombre;
    int Cantidad;
    float PrecioMa;
    float PrecioMe;
    int Peso;
    std::string Codigo;
    
public:
    Producto();
    Producto(const Producto&);
    
    std::string getNombre() const;
    int getCantidad() const;
    float getPrecioMa() const;
    float getPrecioMe()const;
    int getPeso() const;
    std::string getCodigo() const;
    
    std::string toString() const;
    
    void setNombre(const std::string&);
    void setCantidad(const int&);
    void setPrecioMa(const float&);
    void setPrecioMe(const float&);
    void setPeso(const int&);
    void setCodigo(const std::string&);
    
    Producto& operator = (const Producto&);
};
#endif /* Producto_h */
