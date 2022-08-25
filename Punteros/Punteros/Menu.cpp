#include "Menu.h"

using namespace std;

Menu::Menu(List<Song>& myinitial) {
    Initial(myinitial);
}
void Menu::Initial(List<Song>& myinitial) {
    int op1, op2;
    Song *mySong = nullptr;
    Name name;
    do {
        system("COLOR B");
        system("cls");
        cout << "Posicion | Cancion | Autor | Interprete| Ranking |MP3| "<<endl;
        cout << endl << myinitial.Tostring() << endl <<endl;
        cout<<"(1)Inserta una cancion:"<<endl;
        cout<<"(2)Inserta su posicion:"<<endl;
        cout<<"(3)Eliminar cancion:"<<endl;
        cout<<"(4)Busqueda linial:"<<endl;
        cout<<"(5)Busqueda binaria:"<<endl;
        cout<<"(6)Ordenar:"<<endl;
        cout<<"(7)Salir:"<<endl;
        cin>>op1;
        switch(op1) {
            case 1: {
                mySong = new Song;
                string aux1;
                int auxi;
                do {
                    cin.ignore();
                    cout<<"Titulo:";
                    getline(cin, aux1);
                    mySong->setNamesong(aux1);
                    cout<<"\n Autor:";
                    cout<<"\n Nombre del Autor:";
                    cin>>aux1;
                    name.setName(aux1);
                    cout<<"\n Apellido del Autor:";
                    cin>>aux1;
                    name.setLastName(aux1);
                    mySong->setNameArtis(name);
                    cout<<"\nInterprete:";
                    cout<<"\nNombre del Interprete:";
                    cin>>aux1;
                    name.setName(aux1);
                    cout<<"\nApellido del Interprete:";
                    cin>>aux1;
                    name.setLastName(aux1);
                    mySong->setNameSinger(name);
                    cout<<"\nÂ°Ingresa el Ranking:";
                    cin>>auxi;
                    mySong->setTemas(auxi);
                    cout<<"\nÂ°Ingresa el mp3:";
                    cin>>aux1;
                    mySong->setRadio(aux1);
                    try {
                        myinitial.insert(mySong, myinitial.getLastP()+1);
                    }
                    catch(Listexcepcion tf) {
                        cout<<tf.what()<<endl;
                        system("pause");
                    }
                    cout<<"\n Añadir otra cancion?:";
                    cout<<"\n 1/2"<<endl;
                    cin>>op2;
                }
                while(op2==1);
                break;
            }
            case 2: {
                string aux1;
                int auxi;
                int poss = 0;
                cout<<"Posicion:";
                cin.ignore();
                cout<<"\n Dame Titulo:";
                getline(cin, aux1);
                mySong->setNamesong(aux1);
                cout<<"\n Autor:";
                cout<<"\n Nombre del Autor:";
                cin>>aux1;
                name.setName(aux1);
                cout<<"\n Apellido del Autor:";
                cin>>aux1;
                name.setLastName(aux1);
                mySong->setNameArtis(name);
                cout<<"\n Interprete:";
                cout<<"\n Nombre del Interprete:";
                cin>>aux1;
                name.setName(aux1);
                cout<<"\n Apellido del Interprete:";
                cin>>aux1;
                name.setLastName(aux1);
                mySong->setNameSinger(name);
                cout<<"\n Ingresa el Ranking:";
                cin>>auxi;
                mySong->setTemas(auxi);
                cout<<"\n Posicion de la cancion?"<<endl;
                cin>>poss;
                try {
                    myinitial.insert(mySong, poss);
                }
                catch(Listexcepcion tf) {
                    cout<<tf.what()<<endl;
                    system("pause");
                }
                break;
            }
            case 3: {
                int poss = 0;
                cout<<"Eliminar posicion:\n";
                cin.ignore();
                cout<<"\n Posicion a eliminar:\n";
                cin>>poss;
                try {
                    myinitial.Delete(poss);
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
                cout <<"\t Busqueda lineal: "<<endl;
                cout <<"\t 1)Buscar Nombre de artista"<<endl;
                cout <<"\t 2)Buscar Titulo"<<endl;
                cin>>auxii;
                cin.ignore();
                switch(auxii) {
                    case 1: {
                        cout<<"\t Busqueda por nombre"<<endl;
                        cout<<"\t Nombre: ";
                        getline(cin,auxxs);
                        name.setName(auxxs);
                        cout<<"\tDime el apellido: ";
                        getline(cin,auxxs);
                        name.setLastName(auxxs);
                        mySong->setNameArtis(name);
                        pi = myinitial.buscalineal(mySong, Song::comparai);
                        if(pi == -1) {
                            cout<<"\t Cancion no registrada"<<endl;
                            system("PAUSE");
                        }
                        else {
                            cout<<"\t Cancion en posicion: "<<pi<<endl;
                            cout<<"\t Sus datos son: ";
                            
                            cout<<myinitial.Retrieve(pi).ToString()<<endl;
                            system ("PAUSE");
                        }
                        break;
                    }
                    case 2: {
                        cout<<"\t Busqueda por titulo: "<<endl;
                        cout<<"\t Dime el titulo: ";
                        getline(cin,auxxs);
                        mySong->setNamesong(auxxs);
                        pi = myinitial.buscalineal(mySong,Song::comparat);
                        if(pi == -1) {
                            cout<<"\t Cancion no registrada"<<endl;
                            system("PAUSE");
                        }
                        else {
                            cout<<"\t Cancion en posicion: "<<pi<<endl;
                            cout<<"\t Sus datos son: ";
                            
                            cout<<myinitial.Retrieve(pi).ToString()<<endl;
                            system ("PAUSE");
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
                cout <<"\t 1)Buscar Nombre de artista"<<endl;
                cout <<"\t 2)Buscar Titulo"<<endl;
                cin>>auxii;
                cin.ignore();
                switch(auxii) {
                    case 1: {
                        cout<<"\t Busqueda por nombre"<<endl;
                        cout<<"\t Dime el nombre: ";
                        getline(cin,auxxs);
                        name.setName(auxxs);
                        cout<<"\t Dime el apellido: ";
                        getline(cin,auxxs);
                        name.setLastName(auxxs);
                        mySong->setNameArtis(name);
                        pi = myinitial.binaria(mySong,Song::comparai);
                        if(pi == -1) {
                            cout<<"\tCancion no registrada"<<endl;
                            system("PAUSE");
                        }
                        else {
                            cout<<"\t Cancion en posicion: "<<pi<<endl;
                            cout<<"\t Sus datos son: ";
                            
                            cout<<myinitial.Retrieve(pi).ToString()<<endl;
                            system ("PAUSE");
                        }
                        break;
                    }
                    case 2: {
                        cout<<"\t Busqueda por titulo"<<endl;
                        cout<<"\t Dime el titulo: ";
                        getline(cin,auxxs);
                        mySong->setNamesong(auxxs);
                        pi = myinitial.binaria(mySong,Song::comparat);
                        if(pi == -1) {
                            cout<<"\t Cancion no registrada"<<endl;
                            system("PAUSE");
                        }
                        else {
                            cout<<"\t Cancion en posicion: "<<pi<<endl;
                            cout<<"\t Sus datos son: ";
                            
                            cout<<myinitial.Retrieve(pi).ToString()<<endl;
                            system ("PAUSE");
                        }
                        break;
                    }
                }
                break;
            }
            case 6: {
                int opc2 = 0;
                cout <<"\t Metodos de Ordenamiento"<<endl;
                cout <<"\t 1)Por titulo de cancion"<<endl;
                cout <<"\t 2)Por nombre"<<endl;
                cin >>opc2;
                switch(opc2) {
                    case 1: {
                        int opc3;
                        cout <<"\t Metodos:"<<endl;
                        cout <<"\t 1)BubbleSort"<<endl;
                        cout <<"\t 2)InsertSort"<<endl;
                        cout <<"\t 3)ShellSort"<<endl;
                        cout <<"\t 4)SelectSort"<<endl;
                        cin >>opc3;
                        switch(opc3) {
                            case 1: {
                                cout << "Posicion | Cancion | Autor |Interprete| Ranking | MP3| "<<endl;
                                myinitial.bubbleSort(Song::comparat);
                                cout << "\n" << myinitial.Tostring();
                                break;
                            }
                            case 2: {
                                cout << "Posicion | Cancion | Autor |Interprete| Ranking | MP3| "<<endl;
                                myinitial.InsertSort(Song::comparat);
                                cout << "\n" << myinitial.Tostring();
                                break;
                            }
                            case 3: {
                                cout << "Posicion | Cancion | Autor |Interprete| Ranking | MP3 | "<<endl;
                                myinitial.ShellSort(Song::comparat);
                                cout << "\n" << myinitial.Tostring();
                                break;
                            }
                            case 4: {
                                cout << "Posicion | Cancion | Autor |Interprete| Ranking | MP3 | "<<endl;
                                myinitial.SelectSort(Song::comparat);
                                cout << "\n" << myinitial.Tostring();
                                break;
                            }
                        }
                        break;
                    }
                    case 2: {
                        int opc3;
                        cout <<"\tMetodos:"<<endl;
                        cout <<"\t 1)BubbleSort"<<endl;
                        cout <<"\t 2)InsertSort"<<endl;
                        cout <<"\t 3)ShellSort"<<endl;
                        cout <<"\t 4)SelectSort"<<endl;
                        cin >>opc3;
                        switch(opc3) {
                            case 1: {
                                cout << "Posicion | Cancion | Autor |Interprete| Ranking | MP3  | "<<endl;
                                myinitial.bubbleSort(Song::comparai);
                                cout << "\n" << myinitial.Tostring();
                                break;
                            }
                            case 2: {
                                cout << "Posicion | Cancion | Autor |Interprete| Ranking | MP3  | "<<endl;
                                myinitial.InsertSort(Song::comparai);
                                cout << "\n" << myinitial.Tostring();
                                break;
                            }
                            case 3: {
                                cout << "Posicion | Cancion | Autor |Interprete| Ranking | MP3  | "<<endl;
                                myinitial.ShellSort(Song::comparai);
                                cout << "\n" << myinitial.Tostring();
                                break;
                            }
                            case 4: {
                                cout << "Posicion | Cancion | Autor |Interprete| Ranking | MP3 | "<<endl;
                                myinitial.SelectSort(Song::comparai);
                                cout << "\n" << myinitial.Tostring();
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
    while(op1 != 7);
}

                        
