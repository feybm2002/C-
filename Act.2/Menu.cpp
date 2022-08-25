//Menu

#include "Menu.h"
#include "Producto.h"
#include "Fecha.h"
#include "Coleccion.h"

using namespace std;

    Menu::Menu(){}

Menu::Menu(const Menu& m){
    coleccion=m.coleccion;
}
void Menu::interfaz(){
    Coleccion inventario[500];
    string myStr;
    string codigo;
    Fecha date;
    Producto Product;
    Coleccion almacen;
    int op;
    int x=0;
    int total;
    int i=0;
    int aumento=0;
    int disminuir=0;
    int resultado=0;
    int posicion=0;
    bool b = false;
    
    do{
        system("cls");
    cout<<"---Inventario---"<<endl;
    cout<<"Seleccione su opción a realizar:"<<endl;
    cout<<"1)Agregar producto:"<<endl;
    cout<<"2)Aumentar producto:"<<endl;
    cout<<"3)Disminuir producto:"<<endl;
    cout<<"4)Lista de productos:"<<endl;
    cout<<"5)Salir"<<endl;
    cin>>op;
    switch (op) {
        case 1: {
            system("cls");
            cout << "Cuantos productos va a ingresar?: ";
            cin >> total;
            cout << " ";
            getline(cin, myStr);
            
            for(int i(0); i<total; i++) {
                
            cout<<"\t Nombre del producto:"<<endl;
            getline(cin, myStr);
            Product.setNombre(myStr);
            cout<<"\t Cantidad:"<<endl;
            getline(cin, myStr);
            Product.setCantidad(stoi(myStr));
            cout<<"\t Precio Mayoreo:"<<endl;
            getline(cin, myStr);
            Product.setPrecioMa(stoi(myStr));
            cout<<"\t Precio Menudeo:"<<endl;
            getline(cin, myStr);
            Product.setPrecioMe(stoi(myStr));
            cout<<"\t Peso:"<<endl;
            getline(cin, myStr);
            Product.setPeso(stoi(myStr));
            cout<<"\t Codigo de barras: "<<endl;
            getline(cin, myStr);
            Product.setCodigo(myStr);
            inventario[i].setProducto(Product);
            cout<<"Agregue Fecha (DD/MM/AAAA): ";
            getline(cin, myStr, '/');
            date.setDia(stoi(myStr));
            getline(cin, myStr, '/');
            date.setMes(stoi(myStr));
            getline(cin, myStr);
            date.setAnio(stoi(myStr));
            inventario[i].setFecha(date);
                x++;
            }
        }
            break;
        case 2:{
                cout<<"Aumento de productos:"<<endl;
                system("cls");
                cout<<"Codigo del producto:"<<endl;
                getline(cin, codigo);
            while(i < x && b == false) {
                if((codigo == inventario[i].getProducto().getCodigo()) == true){
                    cout<<"Agregue Fecha (DD/MM/AAAA): ";
                    getline(cin, myStr, '/');
                    date.setDia(stoi(myStr));
                    getline(cin, myStr, '/');
                    date.setMes(stoi(myStr));
                    getline(cin, myStr);
                    date.setAnio(stoi(myStr));
                    inventario[i].setFecha(date);
                    cout<<"Cantidad a aumentar:"<<endl;
                    cin>> aumento;
                    resultado = aumento + Product.getCantidad();
                    Product.setCantidad(resultado);
                    inventario[i].setProducto(Product);
                    cout << "Su aumento ha sido realizado" << endl;
                    system("pause");
                    b = true;
                    posicion = i;
                    }
                    i++;
                    }
        }
        case 3:{
              cout<<"Disminucion de productos:"<<endl;
              system("cls");
              cout<<"Codigo del producto:"<<endl;
              getline(cin, codigo);
            while(i < x && b == false) {
                if((codigo == inventario[i].getProducto().getCodigo()) == true){
                    cout<<"Agregue Fecha (DD/MM/AAAA): ";
                    getline(cin, myStr, '/');
                    date.setDia(stoi(myStr));
                    getline(cin, myStr, '/');
                    date.setMes(stoi(myStr));
                    getline(cin, myStr);
                    date.setAnio(stoi(myStr));
                    inventario[i].setFecha(date);
                    cout<<"Cantidad a disminuir:"<<endl;
                    cin>>disminuir;
                    resultado=Product.getCantidad()-disminuir;
                    if(resultado < 0) {
                        cout<<"Agotado"<<endl;
                        Product.setCantidad(Product.getCantidad());
                        inventario[i].setProducto(Product);
                        system("pause");
                    }
                    
                    else if(resultado >= 0) {
                        Product.setCantidad(resultado);
                        inventario[i].setProducto(Product);
                        cout<< "Compra Exitosa"<<endl;
                        system("pause");
                    }
                    b = true;
                    posicion = i;
                    }
                  i++;
            }
            
        }
            break;
            
        case 4:{
            system("cls");
            cout<<"Lista de productos:"<<endl;
            for(int i(0); i < x; i++) {
                cout<<inventario[i].toString()<<endl;
            }
            system("pause");
    }
            break;
    }
    
   } while (op !=6);
    }
    
 
