// List
#ifndef List_h
#define List_h
#include <string>
#include <iostream>
#include <exception>
#include <Functional>

class ListException : public std::exception {
    private:
        std::string msg;

    public:
        explicit ListException(const char* message) : msg(message) { }

        explicit ListException(const std::string& message) : msg(message) { }

        virtual ~ListException() throw () { }

        virtual const char* what() const throw () {
            return msg.c_str();
            }
    };

//Definicion
template <class T, int ARRAYSIZE = 200000>
class List {
    private:
        T dataList[ARRAYSIZE];
        int index;
        bool isValidP(const int&);
        void copyAll(const List<T, ARRAYSIZE>&);
        void mov(T&, T&);

    public:
        List();
        List(const List<T, ARRAYSIZE>&);

        bool isEmpty();
        bool isFull();
        bool order();
        void insertList(const int&, const T&);
        void deleteList();
        int getFirstP();
        int getLastP();
        int getPrevP(const int&);
        int getNextP(const int&);
        T retrieve(const int&);
        std::string toString();
        void bubblesort();
        void insertsort();
        void selectsort();
        void shellsort();
        void mergesort(const int&, const int&);
        void mergeSortI();
        void quicksort(const int&, const int&);
        void quickSortI();
        List<T, ARRAYSIZE>& operator = (const List<T, ARRAYSIZE>&);

    };

//Implementacion
using namespace std;

template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isValidP(const int& p) {
    return p >= 0 and p <= index;
    }
template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::copyAll(const List<T, ARRAYSIZE>& call) {
    int i(0);
    while(i <= call.index) {
        dataList[i] = call.dataList[i];
        i++;
        }
    index = call.index;
    }
template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>::List() : index(-1) { }

template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>::List(const List<T, ARRAYSIZE>& call) {
    copyAll(call);
    }
template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isEmpty() {
    return index == -1;
    }
template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isFull() {
    return index == ARRAYSIZE - 1;
    }
template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::order() {
    int j(index);
    for(int i(0); i < j; i++) {
        if(dataList[i]>dataList[i+1]) {
            return 0;
            }
        return 1;
        }
    }
template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::insertList(const int& p, const T& i) {
    if(isFull()) {
        throw ListException("No hay espacio");
        }
    else if(p != -1 && !isValidP(p)) {
        throw ListException("La posicion es invalida");
        }
    else {
        int j(index);
        if(p==index + 1) {
            dataList[p]=i;
            }
        else {
            while(j>=p) {
                dataList[j+1]= dataList[j];
                j--;
                }
            dataList[j+1]=i;
            }
        index++;
        }
    }
template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::deleteList() {
    index= -1;
    }
template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getFirstP() {
    if(isEmpty()) {
        return -1;
        }
    return 0;
    }
template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getLastP() {
    return index;
    }
template <class T, int ARRAYSIZE>
int List<T,ARRAYSIZE>::getPrevP(const int& p) {
    if(p == getFirstP() or !isValidP(p)) {
        return -1;
        }
    return p - 1;
    }
template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getNextP(const int& p) {
    if(p == getLastP() or !isValidP(p)) {
        return -1;
        }
    return p + 1;
    }
template <class T, int ARRAYSIZE>
T List<T, ARRAYSIZE>::retrieve(const int& p) {
    if(!isValidP(p)) {
        throw ListException("Posicion invalida, recupera");
        }
    return dataList[p];
    }

template <class T, int ARRAYSIZE>
string List<T, ARRAYSIZE>::toString() {
    string result;
    int i(0);

    while(i <= index) {
        result += "    " + to_string(i) + "     | " + dataList[i].toString() + "\n";

        i++;
        }
    return result;
    }
template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>& List<T, ARRAYSIZE>::operator=(const List<T, ARRAYSIZE>& call) {
    copyAll(call);
    return *this;
    }
template <class T,int ARRAYSIZE>
void List<T,ARRAYSIZE>::mov(T& x, T& y) {
    T aux(x);
    x = y;
    y = aux;
    }

template <class T,int ARRAYSIZE>
void List<T, ARRAYSIZE>::bubblesort() {
    int i(index);
    bool band;
    do {
        band = false;
        int j = 0;
        while(j < i) {
            if(dataList[j]>dataList[j+1]) {
                mov(dataList[j], dataList[j + 1]);
                band = true;
                }
            j++;
            }
        i--;
        }
    while(band);
    }
template <class T,int ARRAYSIZE>
void List<T,ARRAYSIZE>::shellsort() {
    unsigned ciura[]= {510774,227011,100894,44842,19930,8858,3973,1750,701,301,132,57,23,10,4,1,0};
    unsigned pos(0), dif(ciura[pos]), i, j;
    while(dif > 0) {
        i = dif;
        while(i <= index) {
            j = i;
            while(j >= dif && dataList[j-dif] > dataList[j]) {
                mov(dataList[j - dif], dataList[j]);
                j -= dif;
                }
            i++;
            }
        dif= ciura[++pos];
        }
    }
template <class T,int ARRAYSIZE>
void List<T, ARRAYSIZE>::insertsort() {
    int i(1), j;
    T aux;
    while(i <= index) {
        aux = dataList[i];
        j = i;
        while(j > 0 && aux < dataList[j - 1]) {
            dataList[j] = dataList[j - 1];
            j--;
            }
        if(i != j) {
            dataList[j] = aux;
            }
        i++;
        }
    }
template <class T,int ARRAYSIZE>
void List<T,ARRAYSIZE>::selectsort() {
    int x,y;
    for(int j=0; j<index; j++) {
        y=j;
        x=j+1;
        for(; x<=index; x++) {
            if(dataList[x]<dataList[y]) {
                y=x;
                }
            }
        if(j!=y) {
            mov(dataList[j],dataList[y]);
            }
        }
    }

template <class T,int ARRAYSIZE>
void List<T,ARRAYSIZE>::mergeSortI() {
    mergesort(0, index);
    }

template <class T,int ARRAYSIZE>
void List<T,ARRAYSIZE>::mergesort(const int& LE, const int& RE) {
    if(LE>=RE) {
        return;
        }
    int s((LE+RE)/2);
    mergesort(LE,s);
    mergesort(s+1,RE);
    static T auxs[ARRAYSIZE];
    for(int x(LE); x <=RE; x++) {
        auxs[x]=dataList[x];
        }
    int i(LE), j(s+1), x(LE);
    while(i <=s && auxs[i] <= auxs[j]) {
        dataList[x++]= auxs[i++];
        }
    if(i<=s) {
        while(j<=RE && auxs[j] <= auxs[i]) {
            dataList[x++] = auxs[j++];
            }
        }
    }

template <class T,int ARRAYSIZE>
void List<T,ARRAYSIZE>::quickSortI() {
    quicksort(0, index);
    }

template <class T,int ARRAYSIZE>
void List<T,ARRAYSIZE>::quicksort(const int& LE, const int& RE) {
    if(LE >= RE) {
        return;
        }
    int i(LE), j(RE);
    while(i < j) {
        while(i < j && dataList[i] <= dataList[RE]) {
            i++;
            }
        while(i < j && dataList[j] >= dataList[RE]) {
            j--;
            }
        if(i != j) {
            mov(dataList[i], dataList[j]);
            }
        }
    if(i != RE) {
        mov(dataList[i], dataList[RE]);
        }
    quicksort(LE, i - 1);
    quicksort(i + 1, LE);
    }
#endif /* List_h */
