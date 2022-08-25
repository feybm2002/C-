#include "Menuu.h"
using namespace std;
Menu::Menu(Lista<Cancion>& myiniciar) {
    iniciar(myiniciar);
}
void Menu::iniciar(Lista<Cancion>& myiniciar) {
    int res1, res2;
    Cancion cans;
    Nombre nom;
    do {
        system("COLOR B");
        system("cls");
        cout << " Posicion | Cancion | Autor | Interprete | Ranking | Archivo MP3";
        cout << endl << myiniciar.Tostring() << endl <<endl;
        cout << " Menu:" << endl;
        cout << " 1) Agrega Cancion" << endl;
        cout << " 3) Eliminar cancion " << endl;
        cout << " 4) Busqueda lineal " << endl;
        cout << " 5) Busqueda binaria " << endl;
        cout << " 6) Ordenar: " << endl;
        cout << " 7) Salir " << endl;
        cin>>res1;
        switch(res1) {
            case 1: {
                string aux1;
                int auxi;
                do {
                    cin.ignore();
                    cout<<"Titulo:";
                    getline(cin, aux1);
                    cans.setNamesong(aux1);
                    cout<<"\nAutor:";
                    cout<<"\nNombre del Autor:";
                    cin>>aux1;
                    nom.setNombre(aux1);
                    cout<<"\nApellido del Autor:";
                    cin>>aux1;
                    nom.setApellidos(aux1);
                    cans.setNombreartis(nom);
                    cout<<"\nInterprete:";
                    cout<<"\nNombre del Interprete:";
                    cin>>aux1;
                    nom.setNombre(aux1);
                    cout<<"\nApellido del Interprete:";
                    cin>>aux1;
                    nom.setApellidos(aux1);
                    cans.setNombrecanta(nom);
                    cout<<"\nIngresa el Ranking:";
                    cin>>auxi;
                    cans.setTemas(auxi);
                    cout<<"\nIngresa el MP3:";
                    cin>>aux1;
                    cans.setRadio(aux1);
                    try {
                        myiniciar.inserta(cans, myiniciar.getUltimo()+1);
                    }
                    catch(Listexcepcion tf) {
                        cout<<tf.what()<<endl;
                        system("pause");
                    }
                    cout<<"\nÂ°Agregar otra cancion?:";
                    cout<<"1/2\n"<<endl;
                    cout<<"Â°=>:";
                    cin>>res2;
                }
                while(res2==1);
                break;
            }
            case 2: {
                string aux1;
                int auxi;
                int poss = 0;
                cout<<"Posicion:";
                cin.ignore();
                cout<<"\nDime Titulo:";
                getline(cin, aux1);
                cans.setNamesong(aux1);
                cout<<"\nAutor:";
                cout<<"\nNombre del Autor:";
                cin>>aux1;
                nom.setNombre(aux1);
                cout<<"\nApellido del Autor:";
                cin>>aux1;
                nom.setApellidos(aux1);
                cans.setNombreartis(nom);
                cout<<"\nInterprete:";
                cout<<"\nNombre del Interprete:";
                cin>>aux1;
                nom.setNombre(aux1);
                cout<<"\nApellido del Interprete:";
                cin>>aux1;
                nom.setApellidos(aux1);
                cans.setNombrecanta(nom);
                cout<<"\nIngresa el Ranking:";
                cin>>auxi;
                cans.setTemas(auxi);
                cout<<"\nPosicion de la cancion?"<<endl;
               
                cin>>poss;
                try {
                    myiniciar.inserta(cans, poss);
                }
                catch(Listexcepcion tf) {
                    cout<<tf.what()<<endl;
                    system("pause");
                }
                break;
            }
            case 3: {
                int poss = 0;
                cout<<"Eliminar posicion:";
                cin.ignore();
                cout<<"\nPosicion a eliminar:";
                cin>>poss;
                try {
                    myiniciar.elimina(poss);
                }
                catch(Listexcepcion tf) {
                    cout<<tf.what()<<endl;
                    system("pause");
                }
                break;
            }
            case 4: {
                string auxxs;
                int auxii;
                int pi = 0;
                cout <<"\tBusqueda lineal"<<endl;
                cout <<"\t(1)Buscar Nombre de artista"<<endl;
                cout <<"\t(2)Buscar Titulo"<<endl;
                
                cin>>auxii;
                cin.ignore();
                switch(auxii) {
                    case 1: {
                        cout<<"\tBusqueda por nombre"<<endl;
                        cout<<"\tNombre: ";
                        getline(cin,auxxs);
                        nom.setNombre(auxxs);
                        cout<<"\tDime el apellido: ";
                        getline(cin,auxxs);
                        nom.setApellidos(auxxs);
                        cans.setNombreartis(nom);
                        pi =
                        myiniciar.buscalineal(cans,Cancion::comparai);
                        if(pi == -1) {
                            cout<<"\tCancion no registrada"<<endl;
                            system("pause");
                        }
                        else {
                            cout<<"\tCancion en posicion: "<<pi<<endl;
                            cout<<"\tSus datos son: ";
                            
                            cout<<myiniciar.recupera(pi).ToString()<<endl;
                            system ("pause");
                        }
                        break;
                    }
                    case 2: {
                        cout<<"\tBusqueda por titulo"<<endl;
                        cout<<"\tDime el titulo: ";
                        getline(cin,auxxs);
                        cans.setNamesong(auxxs);
                        pi =
                        myiniciar.buscalineal(cans,Cancion::comparat);
                        if(pi == -1) {
                            cout<<"\tCancion no registrada"<<endl;
                            system("pause");
                        }
                        else {
                            cout<<"\tCancion en posicion: "<<pi<<endl;
                            cout<<"\tSus datos son: ";
                            
                            cout<<myiniciar.recupera(pi).ToString()<<endl;
                            system ("pause");
                        }
                    }
                        break;
                }
                break;
            }
            case 5: {
                string auxxs;
                int auxii;
                int pi = 0;
                cout <<"\tBusqueda binaria"<<endl;
                cout <<"\t(1)Buscar Nombre de artista"<<endl;
                cout <<"\t(2)Buscar Titulo"<<endl;
                cout <<"\t-->:";
                cin>>auxii;
                cin.ignore();
                switch(auxii) {
                    case 1: {
                        cout<<"\tBusqueda por nombre"<<endl;
                        cout<<"\tDime el nombre: ";
                        getline(cin,auxxs);
                        nom.setNombre(auxxs);
                        cout<<"\tDime el apellido: ";
                        getline(cin,auxxs);
                        nom.setApellidos(auxxs);
                        cans.setNombreartis(nom);
                        pi = myiniciar.binaria(cans,Cancion::comparai);
                        if(pi == -1) {
                            cout<<"\tCancion no registrada"<<endl;
                            system("pause");
                        }
                        else {
                            cout<<"\tCancion en posicion: "<<pi<<endl;
                            cout<<"\tSus datos son: ";
                            
                            cout<<myiniciar.recupera(pi).ToString()<<endl;
                            system ("pause");
                        }
                        break;
                    }
                    case 2: {
                        cout<<"\tBusqueda por titulo"<<endl;
                        cout<<"\tDime el titulo: ";
                        getline(cin,auxxs);
                        cans.setNamesong(auxxs);
                        pi = myiniciar.binaria(cans,Cancion::comparat);
                        if(pi == -1) {
                            cout<<"\tCancion no registrada"<<endl;
                            system("pause");
                        }
                        else {
                            cout<<"\tCancion en posicion: "<<pi<<endl;
                            cout<<"\tSus datos son: ";
                            
                            cout<<myiniciar.recupera(pi).ToString()<<endl;
                            system ("pause");
                        }
                        break;
                    }
                }
                break;
            }
            case 6: {
                int opc2 = 0;
                cout <<"\t°Metodos de Ordenamiento"<<endl;
                cout <<"\t(1)Por titulo de cancion"<<endl;
                cout <<"\t(2)Por nombre"<<endl;
                cout <<"\t-->:";
                cin >>opc2;
                switch(opc2) {
                    case 1: {
                        int opc3;
                        cout <<"\tMetodos a usar:"<<endl;
                        cout <<"\t1)BubbleSort"<<endl;
                        cout <<"\t2)InsertSort"<<endl;
                        cout <<"\t3)ShellSort"<<endl;
                        cout <<"\t4)SelectSort"<<endl;
                        cout <<"-->:";
                        cin >>opc3;
                        switch(opc3) {
                            case 1: {
                                cout << " Posicion | Cancion | Autor | Interprete | Ranking | Archivo MP3";
                                myiniciar.bubbleSort(Cancion::comparat);
                                cout << "\n" << myiniciar.Tostring();
                                break;
                            }
                            case 2: {
                                 cout << " Posicion | Cancion | Autor | Interprete | Ranking | Archivo MP3";
                                myiniciar.InsertSort(Cancion::comparat);
                                cout << "\n" << myiniciar.Tostring();
                                break;
                            }
                            case 3: {
                                cout << " Posicion | Cancion | Autor | Interprete | Ranking | Archivo MP3";
                                myiniciar.ShellSort(Cancion::comparat);
                                cout << "\n" << myiniciar.Tostring();
                                break;
                            }
                            case 4: {
                                cout << " Posicion | Cancion | Autor | Interprete | Ranking | Archivo MP3";
                                myiniciar.SelectSort(Cancion::comparat);
                                cout << "\n" << myiniciar.Tostring();
                                break;
                            }
                        }
                        break;
                    }
                    case 2: {
                        int opc3;
                        cout <<"\tMetodos a usar:"<<endl;
                        cout <<"\t1)BubbleSort"<<endl;
                        cout <<"\t2)InsertSort"<<endl;
                        cout <<"\t3)ShellSort"<<endl;
                        cout <<"\t4)SelectSort"<<endl;
                        cout <<"-->:";
                        cin >>opc3;
                        switch(opc3) {
                            case 1: {
                                cout << " Posicion | Cancion | Autor | Interprete | Ranking | Archivo MP3";
                                myiniciar.bubbleSort(Cancion::comparai);
                                cout << "\n" << myiniciar.Tostring();
                                break;
                            }
                            case 2: {
                                cout << " Posicion | Cancion | Autor | Interprete | Ranking | Archivo MP3";
                                myiniciar.InsertSort(Cancion::comparai);
                                cout << "\n" << myiniciar.Tostring();
                                break;
                            }
                            case 3: {
                               cout << " Posicion | Cancion | Autor | Interprete | Ranking | Archivo MP3";
                                myiniciar.ShellSort(Cancion::comparai);
                                cout << "\n" << myiniciar.Tostring();
                                break;
                            }
                            case 4: {
                                 cout << " Posicion | Cancion | Autor | Interprete | Ranking | Archivo MP3";
                                myiniciar.SelectSort(Cancion::comparai);
                                cout << "\n" << myiniciar.Tostring();
                                break;
                            }
                                break;
                        }
                    }
                        break;
                }
            }
                break;
        }
    }
    while(res1 != 7);
    }
