#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <exception>
#include <string>
#include "Song.h"
#include "Name.h"

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

template <class T, int ARRAYSIZE=5000>
class List{
private:
    T *data[ARRAYSIZE];
    int index;
    bool ValidPosition(const int &);
    void Copy(const List<T, ARRAYSIZE>&);
    void movPosition(T&,T&);
public:
    ~List();
    List();
    List(const List<T, ARRAYSIZE>&);
    bool Empy();
    bool Full();
    void insert(T*,const int&);
    void Delete(const int&);
    T Retrieve(const int&);
    int getFirtP();
    int getLastP();
    int getPrevP(const int&);
    int getNextP(const int&);
    void DeleteAll();
    int buscalineal (T*, int(const T&, const T&));
    int binaria (T*, int(const T&, const T&));
    List<T, ARRAYSIZE>& operator = (const List<T, ARRAYSIZE>&);
    std::string Tostring()const;
    void bubbleSort();
    void ShellSort();
    void InsertSort();
    void SelectSort();
    void bubbleSort (int(T*, T*));
    void ShellSort (int(T*, T*));
    void InsertSort (int(T*, T*));
    void SelectSort (int(T*, T*));
    };
using namespace std;
template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>::~List() {}
template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::Copy(const List<T,ARRAYSIZE>& call) {
    int i(0);
    while(i<=call->top) {
        *data[i]=call->data[i];
        i++;
    }
    index = call->index;
}
template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::ValidPosition(const int&pos) {
    return pos>= 0 && pos <= index + 1;
}
template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>::List():index(-1) {}
template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>::List(const List<T, ARRAYSIZE>&call) {
    Copy(call);
}
template <class T,int ARRAYSIZE>
bool List<T, ARRAYSIZE>::Empy() {
    return index == -1;
}
template <class T,int ARRAYSIZE>
bool List<T, ARRAYSIZE>::Full() {
    return index == ARRAYSIZE -1;
}
template <class T,int ARRAYSIZE>
void List<T, ARRAYSIZE>::insert (T *Song,const int& pos) {
    if(Full()) {
        throw Listexcepcion("LLena");
    }
    else if(pos != -1 && !ValidPosition(pos)) {
        throw Listexcepcion("Posicion no encontrada");
    }
    else {
        int j(index);
        if (pos == index + 1) {
            data[pos] = Song;
        }
        else {
            while(j >= pos) {
                data[j + 1] = data[j];
                j--;
            }
            data[j +1] = Song;
        }
        index++;
    }
}
template <class T,int ARRAYSIZE>
void List<T,ARRAYSIZE>::Delete(const int& pos) {
    if(!ValidPosition(pos)) {
        throw Listexcepcion("Posicion no aceptada");
    }
    int j(pos);
    while(j < index) {
        *data[j] = *data[j +1];
        j++;
    }
    index--;
}
template <class T,int ARRAYSIZE>
T List<T,ARRAYSIZE>::Retrieve(const int& pos) {
    if(!ValidPosition(pos)) {
        throw Listexcepcion("Posicion no aceptada");
    }
    return *data[pos];
}
template <class T,int ARRAYSIZE>
int List<T,ARRAYSIZE>::getFirtP() {
    if(Empy()) {
        return -1;
    }
    return 0;
}
template <class T,int ARRAYSIZE>
int List<T,ARRAYSIZE>::getLastP() {
    return index;
}
template <class T,int ARRAYSIZE>
int List<T,ARRAYSIZE>::getPrevP(const int&pos) {
    if(pos == getFirtP() || !ValidPosition(pos)) {
        return -1;
    }
    return pos - 1;
}
template <class T,int ARRAYSIZE>
int List<T,ARRAYSIZE>::getNextP(const int& pos) {
    if(pos == getLastP() || !ValidPosition(pos)) {
        return -1;
    }
    return pos +1;
}
template <class T,int ARRAYSIZE>
void List<T,ARRAYSIZE>::DeleteAll() {
    index = -1;
}
template <class T,int ARRAYSIZE>
int List<T,ARRAYSIZE>::buscalineal(T *Song, int cps(const T&,const T&)) {
    for(int x(0); x<=x; x++) {
        if(cps(*data[x], *Song) == 0) {
            return x;
        }
    }
    return -1;
}
template <class T,int ARRAYSIZE>
int List<T,ARRAYSIZE>::binaria (T *Song, int cps(const T&, const T&)) {
    int b = index,c;
    for (int a(0); a<=b;) {
        c = (a+b)/2;
        if(cps(*data[c],*Song) == 0) {
            return c;
        }
        else if(cps(*data[c],*Song ) < 0) {
            b=c--;
        }
        else {
            a=c++;
        }
    }
    return - 1;
}
template <class T,int ARRAYSIZE>
string List<T,ARRAYSIZE>::Tostring()const {
    string fr;
    int x = 0;
    while(x<=index) {
        fr += "\t";
        fr += to_string(x);
        fr += "\t";
        fr += data[x]->ToString();
        fr += "\n";
        x++;
    }
    return fr;
}
template <class T,int ARRAYSIZE>
List<T, ARRAYSIZE>&List<T, ARRAYSIZE>::operator = (const List<T, ARRAYSIZE>&call) {
    Copy(call);
    return *this;
}
template <class T,int ARRAYSIZE>
void List<T,ARRAYSIZE>::movPosition(T& a, T& b) {
    T aug(a);
    a = b;
    b = aug;
}
template <class T,int ARRAYSIZE>
void List<T,ARRAYSIZE>::bubbleSort() {
    int i(index);
    bool band;
    do {
        band = false;
        int j = 0;
        while(j < i) {
            if(*data[j] > *data[j + 1]) {
                movPosition(data[j], data[j + 1]);
                band = true;
            }
            j++;
        }
        i--;
    }
    while(band);
}
template <class T,int ARRAYSIZE>
void List<T,ARRAYSIZE>::ShellSort() {
    unsigned ciura[]=
    {510774,227011,100894,44842,19930,8858,3973,1750,701,301,132,57,23,10,4,1
        ,0};
    unsigned pos(0), dif(ciura[pos]), i, j;
    while(dif > 0) {
        i = dif;
        while(i <= index) {
            j = i;
            while(j >= dif && data[j - dif] > data[j]) {
                movPosition(data[j - dif], data[j]);
                j -= dif;
            }
            i++;
        }
        dif= ciura[++pos];
    }
}
template <class T,int ARRAYSIZE>
void List<T,ARRAYSIZE>::InsertSort() {
    int i(1), j;
    T aux;
    while(i <= index) {
        aux = data[i];
        j = i;
        while(j > 0 && aux < data[j - 1]) {
            data[j] = data[j - 1];
            j--;
        }
        if(i != j) {
            data[j] = aux;
        }
        i++;
    }
}
template <class T,int ARRAYSIZE>
void List<T,ARRAYSIZE>::SelectSort() {
    int i(0), j, m;
    while (i < index) {
        m = i;
        j = i + 1;
        while(j <= index) {
            if(data[j] < data[m]) {
                m = j;
            }
            j++;
        }
        if(i != m) {
            movPosition(data[i], data[m]);
        }
        i++;
    }
}
template <class T,int ARRAYSIZE>
void List<T,ARRAYSIZE>::bubbleSort(int bubble(T*, T*)) {
    int i(index);
    bool band;
    do {
        band = false;
        int j = 0;
        while(j < i) {
            if(bubble(data[j], data[j + 1]) > 0) {
                movPosition(*data[j], *data[j + 1]);
                band = true;
            }
            j++;
        }
        i--;
    }
    while(band);
}
template <class T,int ARRAYSIZE>
void List<T,ARRAYSIZE>::ShellSort(int shell(T*, T*)) {
    unsigned ciura[]=
    {510774,227011,100894,44842,19930,8858,3973,1750,701,301,132,57,23,10,4,1
        ,0};
    unsigned pos(0), dif(ciura[pos]), i, j;
    while(dif > 0) {
        i = dif;
        while(i <= index) {
            j = i;
            while(j >= dif && shell(data[j - dif],data[j]) > 0) {
                movPosition(*data[j - dif], *data[j]);
                j -= dif;
            }
            i++;
        }
        dif= ciura[++pos];
    }
}
template <class T,int ARRAYSIZE>
void List<T,ARRAYSIZE>::InsertSort(int inser(T*, T*)) {
    int i(1), j;
    T *aux;
    while(i <= index) {
        aux = data[i];
        j = i;
        while(j > 0 && inser(aux, data[j - 1]) < 0) {
            data[j] = data[j - 1];
            j--;
        }
        if(i != j) {
            data[j] = aux;
        }
            i++;
        }
    }
template <class T,int ARRAYSIZE>
void List<T,ARRAYSIZE>::SelectSort(int select(T*, T*)) {
    int i(0), j, m;
    while (i < index) {
        m = i;
        j = i + 1;
        while(j <= index) {
            if(select(data[j], data[m]) < 0) {
                m = j;
            }
            j++;
        }
        if(i != m) {
            movPosition(*data[i], *data[m]);
        }
        i++;
    }
}
#endif // LIST_H_INCLUDED
