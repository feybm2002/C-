#ifndef EXPRESION_H_INCLUDED
#define EXPRESION_H_INCLUDED
#include "Stack.h"
#include "Queue.h"
#include <exception>

using namespace std;
class Expresion
{
private:
string N;
Queue<char> Fi;
int Fijo(const char&)const;
public:
    void setIf(const string&);
    string tostring()const;
    string to_string()const;
    void Funtion();
};

#endif // EXPRESION_H_INCLUDED
