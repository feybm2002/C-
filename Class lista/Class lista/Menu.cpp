#include "Menu.h"
#include <string>
#include <exception>
#include "List.h"
class ListException : public std::exception {
private:
    std::string msg;
public:
    explicit ListException(const char* message) : msg(message) { }
    explicit ListException(const std::string& message) :
    msg(message) { }
    virtual ~ListException() throw () { }
    virtual const char* what() const throw () {
        return msg.c_str();
    }
};
using namespace std;
Menu::Menu(List<int>&call) {
    userInterface(call);
}
void Menu::userInterface(List<int>&call) {
    cout << "Algoritmos de ordenamiento:" << endl;
    default_random_engine
    generator(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int>distribution(0,100000);
    auto dice = bind(distribution, generator);
    List<int>listorder;
    cout << "Generando lista" << endl;
    cout << "Espereun momento ... " << endl;
    for(int i(0); i < 100000; i++) {
        try {
            call.insertList(call.getLastP(), dice());
        }
        catch(ListException x) {
            cout << x.what() << endl;
            system("PAUSE");
        }
    }
    listorder.operator=(call);
    if(listorder.order()) {
        cout << "\n Lista Ordenada." << endl;
    }
    else {
        cout << "\n Lista No Ordenada. " << endl;
    }
    cout << "\n Algoritmos de Ordenamiento:" << endl;
    cout << "\n BubbleSort:" << endl;
    auto start = chrono::system_clock::now();
    listorder.bubblesort();
    auto end = chrono::system_clock::now();
    chrono::duration<float>duration1= end - start;
    cout << duration1.count() << " \n Segundos para ordenar:" << endl;
    if(listorder.order()) {
        cout << "\n Lista Ordenada." << endl;
    }
    else {
        cout << "\n Lista No Ordenada." << endl;
    }
    listorder.deleteList();
    listorder.operator=(call);
    if(listorder.order()) {
        cout << "\n Lista Ordenada." << endl;
    }
    else {
        cout << "\n Lista No Ordenada." << endl;
    }
    cout << "InsertSort:" << endl;
    auto start2 = chrono::system_clock::now();
    listorder.insertsort();
    auto end2 = chrono::system_clock::now();
    chrono::duration<float>duration2= end2 - start2;
    cout << duration2.count() << " \n Segundos para ordenar:" << endl;
    if(listorder.order()) {
        cout << "\n Lista Ordenada." << endl;
    }
    else {
        cout << "\n Lista No Ordenada." << endl;
    }
    listorder.deleteList();
    listorder.operator=(call);
    if(listorder.order()) {
        cout << "\n Lista Ordenada." << endl;
    }
    else {
        cout << "\n Lista No Ordenada." << endl;
    }
    cout << "SelectSort:" << endl;
    auto start3 = chrono::system_clock::now();
    listorder.selectsort();
    auto end3 = chrono::system_clock::now();
    chrono::duration<float>duration3= end3 - start3;
    cout << duration3.count() << " \n Segundos para ordenar:" << endl;
    if(listorder.order()) {
        cout << "\n Lista Ordenada." << endl;
    }
    else {
        cout << "\n Lista No Ordenada." << endl;
    }
    listorder.deleteList();
    listorder.operator=(call);
    if(listorder.order()) {
        cout << "\n Lista Ordenada." << endl;
    }
    else {
        cout << "\n Lista No Ordenada." << endl;
    }
    cout << "ShellSort:" << endl;
    auto start4 = chrono::system_clock::now();
    listorder.shellsort();
    auto end4 = chrono::system_clock::now();
    chrono::duration<float>duration4= end4 - start4;
    cout << duration4.count() << " \n Segundos para ordenar:" << endl;
    if(listorder.order()) {
        cout << "\n Lista Ordenada." << endl;
    }
    else {
        cout << "\n Lista No Ordenada." << endl;
    }
    listorder.deleteList();
    listorder.operator=(call);
    if(listorder.order()) {
        cout << "\n Lista Ordenada." << endl;
    }
    else {
        cout << "\n Lista No Ordenada." << endl;
    }
    cout << "MergeSort:" << endl;
    auto start5 = chrono::system_clock::now();
    listorder.mergeSortI();
    auto end5 = chrono::system_clock::now();
    chrono::duration<float>duration5= end5 - start5;
    cout << duration5.count() << " \n Segundos para ordenar:" << endl;
    if(listorder.order()) {
        cout << "\n Lista Ordenada." << endl;
    }
    else {
        cout << "\n Lista No Ordenada." << endl;
    }
    listorder.deleteList();
    listorder.operator=(call);
    if(listorder.order()) {
        cout << "\n Lista Ordenada." << endl;
    }
    else {
        cout << "\n Lista No Ordenada." << endl;
    }
    cout << "QuickSort:" << endl;
    auto start6 = chrono::system_clock::now();
    listorder.quickSortI();
    auto end6 = chrono::system_clock::now();
    chrono::duration<float>duration6= end6 - start6;
    cout << duration6.count() << " \n Segundos para ordenar:" <<
    endl;
    if(listorder.order()) {
        cout << "\n Lista Ordenada." << endl;
    }
    else {
        cout << "\n Lista No Ordenada." << endl;
    }
    listorder.deleteList();
    listorder.operator=(call);
    if(listorder.order()) {
        cout << "\n Lista Ordenada." << endl;
    }
    else {
        cout << "\n Lista No Ordenada." << endl;
    }
}

