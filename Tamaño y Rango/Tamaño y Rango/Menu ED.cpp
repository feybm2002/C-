
// Maria Fernanda Barroso Monroy
//  Created by Fer on 20/01/22.
//  Copyright © 2022 Fey . All rights reserved.
//

#include <iostream>
#include <limits>
#include <stdlib.h>
#include <random>
#include <time.h>
#include <iomanip>

using namespace std;

int main()
{
    
    int op;
    bool stop = true;
    
    do{
        system("cls");
        
        cout << "\n Seleccione una opción:\n" << endl;
        cout << "1.Tamaño y rango de los tipos de datos primitivos." << endl;
        cout << "2.Ejemplo de dato estructurado." << endl;
        cout << "3.Salir" << endl;
        
        cout << "Ingrese su opción:" << endl;
        cin >> op;
        
        switch (op) {
            case 1:
                cout << "Tamaño:" << endl;
                cout << "\t Caracter con signo: " << (sizeof(signed char)*8) << endl;
                cout << "\t Caracter sin signo:  " << (sizeof(unsigned char)*8) << endl;
                cout << "\t Entero corto con signo:  " << (sizeof(signed short int)*8) << endl;
                cout << "\t Entero corto sin signo:  " << (sizeof(unsigned short int)*8) << endl;
                cout << "\t Entero largo con signo: " << (sizeof(signed long int)*8) << endl;
                cout << "\t Entero largo sin signo: " << (sizeof(unsigned long int)*8) << endl;
                cout << "\t Real de presición simple: " << (sizeof(double)*8) << endl;
                cout << "\t Real de doble presición: " << (sizeof(long double)*8) << endl;
                
                cout << "Rango:" << endl;
                cout << "\t Caracter con signo: " << endl;
                cout << "\t min: " << numeric_limits<signed char>::min() << endl;
                cout << "\t max: " << numeric_limits<signed char>::max() << endl;
                cout << "\t Caracter sin signo: " << endl;
                cout << "\t min: " << numeric_limits<unsigned char>::min() << endl;
                cout << "\t max: " << numeric_limits<unsigned char>::max() << endl;
                cout << "\t Entero corto con signo: " << endl;
                cout << "\t min: " << numeric_limits<signed short  int>::min() << endl;
                cout << "\t max: " << numeric_limits<signed short int>::max() << endl;
                cout << "\t Entero corto sin signo: " << endl;
                cout << "\t min: " << numeric_limits<unsigned short int>::min() << endl;
                cout << "\t max: " << numeric_limits<unsigned short int>::max() << endl;
                cout << "\t Entero largo con signo: " << endl;
                cout << "\t min: " << numeric_limits<signed long int>::min() << endl;
                cout << "\t max: " << numeric_limits<signed long int>::max() << endl;
                cout << "\t Entero largo sin signo: " << endl;
                cout << "\t min: " << numeric_limits<unsigned long int>::min() << endl;
                cout << "\t max: " << numeric_limits<unsigned long int>::max() << endl;
                cout << "\t Real de presición simple: " << endl;
                cout << "\t min: " << numeric_limits<double>::min() << endl;
                cout << "\t max: " << numeric_limits<double>::max() << endl;
                cout << "\t Real de doble presición: " << endl;
                cout << "\t min: " << numeric_limits<long double>::min() << endl;
                cout << "\t max: " << numeric_limits<long double>::max() << endl;
                break;
            case 2:
                int x,y,i,j,z;
                float A[10][10];
                float B[10][10];
                float C[10][10];
                float D[10][10];
                cout<<"Tamaño de la Matriz: 3-10\n";
                cin>>x>>y;
                
                srand(time(NULL));
                
                cout << setprecision(4);
                
                for(i=0; i<x; i++)
                {
                    for(j=0; j<y; j++)
                    {
                        A[i][j]=(-100.00 - 100.00) * ( (double)rand()/ (double)RAND_MAX) + 100.00;
                    }
                }
                
                cout<<"Matriz A: "<<endl<<endl;
                
                for(i=0; i<x; i++)
                {
                    for(j=0; j<y; j++)
                    {
                        cout<<"| "<<A[i][j]<<" |";
                    }
                    cout<<endl;
                }
                
                cout<<endl;
                
                for(i=0; i<x; i++)
                {
                    for(j=0; j<y; j++)
                    {
                        B[i][j]=(-100.00 - 100.00) * ( (double)rand()/ (double)RAND_MAX) + 100.00;
                    }
                }
                
                cout<<"Matriz B: "<<endl<<endl;
                
                for(i=0; i<x; i++)
                {
                    for(j=0; j<y; j++)
                    {
                        cout<<"| "<<B[i][j]<<" |";
                    }
                    cout<<endl;
                }
                
                cout<<endl;
                
                for(i=0; i<x; i++)
                {
                    for(j=0; j<y; j++)
                    {
                        C[i][j]=A[i][j]+B[i][j];
                    }
                }
                
                cout<<"La suma final es: "<<endl<<endl;
                for(i=0; i<x; i++)
                {
                    for(j=0; j<y; j++)
                    {
                        cout<<"| "<<C[i][j]<<" |";
                    }
                    cout<<endl<<endl;
                }
                
                for(i=0; i<x; i++)
                {
                    for(j=0; j<y; j++)
                    {
                        for(z=0; z<x; z++)
                            D[i][j]=A[i][j]*B[i][j];
                        
                    }
                }
                
                cout<<"La multiplicación final es: "<<endl<<endl;
                
                for(i=0; i<x; i++)
                {
                    for(j=0; j<y; j++)
                    {
                        cout<<"| "<<D[i][j]<<" |";
                    }
                    cout<<endl<<endl;
                }
                
                break;
                
            case 3:
                stop = false;
        }
        
    } while (stop);
    return 0;
}
