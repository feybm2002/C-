#ifndef LISTAA_H_INCLUDED
#define LISTAA_H_INCLUDED
#include <exception>
#include <string>
#include "Cancion.h"
#include "Nombre.h"
class Listexcepcion : public std::exception {
private:
    std::string mens;
public:
    explicit Listexcepcion(const char* message): mens(message) {}
    explicit Listexcepcion(const std::string& message): mens(message)
    {}
    virtual ~Listexcepcion()throw() {}
    virtual const char* what() const throw() {
        return mens.c_str();
    }
};
template <class Tam, int T=3000>
class Lista {
private:
    Tam dato[T];
    int terminar;
    bool Validarposicion(const int &);
    void Copy(const Lista<Tam, T>&);
    void cambiarpos(Tam&,Tam&);
public:
    Lista();
    Lista(const Lista<Tam, T>&);
    bool vacia();
    bool llena();
    void inserta(const Tam&,const int&);
    void elimina(const int&);
    Tam recupera(const int&);
    int getPrimero();
    int getUltimo();
    int getAnterior(const int&);
    int getSiguiente(const int&);
    void anula();
    int buscalineal (const Tam&, int(const Tam&, const Tam&));
    int binaria (const Tam&, int(const Tam&, const Tam&));
    Lista<Tam, T>& operator = (const Lista<Tam, T>&);
    std::string Tostring()const;
    void bubbleSort(int(const Tam&, const Tam&));
    void ShellSort (int(const Tam&, const Tam&));
    void InsertSort (int(const Tam&, const Tam&));
    void SelectSort (int(const Tam&, const Tam&));
};
using namespace std;
template <class Tam, int T>
void Lista<Tam, T>::Copy(const Lista<Tam,T>& call) {
    int i(0);
    while(i<=call.top) {
        dato[i]=call.dato[i];
    }
    terminar = call.terminar;
}
template <class Tam, int T>
bool Lista<Tam, T>::Validarposicion(const int&pos) {
    return pos>= 0 && pos <= terminar + 1;
}
template <class Tam, int T>
Lista<Tam, T>::Lista():terminar(-1) {}
template <class Tam, int T>
Lista<Tam, T>::Lista(const Lista<Tam, T>&call) {
    Copy(call);
}
template <class Tam,int T>
bool Lista<Tam, T>::vacia() {
    return terminar == -1;
}
template <class Tam,int T>
bool Lista<Tam, T>::llena() {
    return terminar == T -1;
}
template <class Tam,int T>
void Lista<Tam, T>::inserta (const Tam& canciooo,const int& pos) {
    if(llena()) {
        throw Listexcepcion("LLena");
    }
    else if(pos != -1 && !Validarposicion(pos)) {
        throw Listexcepcion("Posicion no encontrada");
    }
    else {
        int j(terminar);
        if (pos == terminar + 1) {
            dato[pos] = canciooo;
        }
        else {
            while(j >= pos) {
                dato[j + 1] = dato[j];
                j--;
            }
            dato[j +1] = canciooo;
        }
        terminar++;
    }
}
template <class Tam,int T>
void Lista<Tam,T>::elimina(const int& pos) {
    if(!Validarposicion(pos)) {
        throw Listexcepcion("Posicion no aceptada");
    }
    int j(pos);
    while(j < terminar) {
        dato[j] = dato[j +1];
        j++;
    }
    terminar--;
}
template <class Tam,int T>
Tam Lista<Tam,T>::recupera(const int& pos) {
    if(!Validarposicion(pos)) {
        throw Listexcepcion("Posicion no aceptada");
    }
    return dato[pos];
}
template <class Tam,int T>
int Lista<Tam,T>::getPrimero() {
    if(vacia()) {
        return -1;
    }
    return 0;
}
template <class Tam,int T>
int Lista<Tam,T>::getUltimo() {
    return terminar;
}
template <class Tam,int T>
int Lista<Tam,T>::getAnterior(const int&pos) {
    if(pos == getPrimero() || !Validarposicion(pos)) {
        return -1;
    }
    return pos - 1;
}
template <class Tam,int T>
int Lista<Tam,T>::getSiguiente(const int& pos) {
    if(pos == getUltimo() || !Validarposicion(pos)) {
        return -1;
    }
    return pos +1;
}
template <class Tam,int T>
void Lista<Tam,T>::anula() {
    terminar = -1;
}
template <class Tam,int T>
int Lista<Tam,T>::buscalineal(const Tam& cancioss, int cps(const
                                                           Tam&,const Tam&)) {
    for(int x(0); x<=0; x++) {
        if(cps(dato[x], cancioss) == 0) {
            return x;
        }
    }
    return -1;
}
template <class Tam,int T>
int Lista<Tam,T>::binaria (const Tam& cancioss, int cps(const Tam&, const
                                                        Tam&)) {
    int b = terminar,c;
    for (int a(0); a<=b;) {
        c = (a+b)/2;
        if(cps(dato[c],cancioss) == 0) {
            return c;
        }
        else if(cps(dato[c],cancioss ) < 0) {
            b=c--;
        }
        else {
            a=c++;
        }
    }
    return - 1;
}
template <class Tam,int T>
string Lista<Tam,T>::Tostring()const {
    string fr;
    int x = 0;
    while(x<=terminar) {
        fr += "\t";
        fr += to_string(x);
        fr += "\t";
        fr += dato[x].ToString();
        fr += "\n";
        x++;
    }
    return fr;
}
template <class Tam,int T>
Lista<Tam, T>&Lista<Tam, T>::operator = (const Lista<Tam, T>&call) {
    Copy(call);
    return *this;
}
template <class Tam,int T>
void Lista<Tam,T>::cambiarpos(Tam& a, Tam& b) {
    Tam aug(a);
    a = b;
    b = aug;
}
template <class Tam,int T>
void Lista<Tam,T>::bubbleSort(int bubble(const Tam&, const Tam&)){
    int i(terminar);
    bool band;
    do {
        band = false;
        int j = 0;
        while(j < i) {
            if(bubble(dato[j], dato[j + 1]) > 0)
            {
                cambiarpos(dato[j], dato[j + 1]);
                band = true;
            }
            j++;
        }
        i--;
    }
    while(band);
}
template <class Tam,int T>
void Lista<Tam,T>::ShellSort(int shell(const Tam&, const Tam&)) {
    unsigned ciura[]=
    {510774,227011,100894,44842,19930,8858,3973,1750,701,301,132,57,23,10,4,1
        ,0};
    unsigned pos(0), dif(ciura[pos]), i, j;
    while(dif > 0) {
        i = dif;
        while(i <= terminar) {
            j = i;
            while(j >= dif && shell(dato[j - dif],dato[j]) > 0) {
                cambiarpos(dato[j - dif], dato[j]);
                j -= dif;
            }
            i++;
        }
        dif= ciura[++pos];
    }
}
template <class Tam,int T>
void Lista<Tam,T>::InsertSort(int inser(const Tam&, const Tam&)) {
    int i(1), j;
    Tam aux;
    while(i <= terminar) {
        aux = dato[i];
        j = i;
        while(j > 0 && inser(aux, dato[j - 1]) < 0) {
            dato[j] = dato[j - 1];
            j--;
        }
        if(i != j) {
            dato[j] = aux;
        }
        i++;
    }
}
template <class Tam,int T>
void Lista<Tam,T>::SelectSort(int select(const Tam&, const Tam&)){
    int i(0), j, m;
    while (i < terminar) {
        m = i;
        j = i + 1;
        while(j <= terminar) {
            if(select(dato[j], dato[m]) < 0) {
                m = j;
            }
            j++;
        }
        if(i != m) {
            cambiarpos(dato[i], dato[m]);
        }
        i++;
    }
}
#endif // LISTAA_H_INCLUDED
