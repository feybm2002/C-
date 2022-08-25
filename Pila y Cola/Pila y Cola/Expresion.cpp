#include <iostream>
#include <string>
#include <ctype.h>
#include "Expresion.h"

using namespace std;

int Expresion::Fijo(const char&PAL) const
{
 switch(PAL)
 {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '^':
    return 3;
  default:
    return 4;
 }
}

void Expresion::setIf(const string&q)
{
 N=q;
 for(int i=0; i<N.length(); i++)
 {
  Fi.Enqueue(N[i]);
 }
}

string Expresion::tostring()const
{
 return N;
}

string Expresion::to_string()const
{
 Queue<char> Q(Fi), posfix;
 string P="";
 Stack<char> Stack2;
 char Dato;
 while(!Q.Empty())
 {
  Dato=Q.Dequeue();
  if(Dato== '(')
  {
   Stack2.Push(Dato);
  }
  else if(Dato== ')')
  {
   while(!Stack2.Empty() && Stack2.getTop() != '(')
   {
    posfix.Enqueue(Stack2.Pop());
   }
   Stack2.Pop();
  }
  else if(Fijo(Dato)< 4)
  {
   while(!Stack2.Empty() && Fijo(Stack2.getTop()) >= Fijo(Dato))
   {
    if(Stack2.getTop() == '(' )
    {
     break;
    }
    else posfix.Enqueue(Stack2.Pop());
   }
   Stack2.Push(Dato);
  }
  else posfix.Enqueue(Dato);
 }
 while(!posfix.Empty())
 {
  P+= posfix.Dequeue();
 }
 while(!Stack2.Empty())
 {
  P+= Stack2.Pop();
 }
 return P;
 }

void Expresion::Funtion()
{
 while(!Fi.Empty())
 {
  Fi.Dequeue();
 }
}
