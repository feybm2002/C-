#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


template<class T>
class Stack{
private:
    class Node{
    private:
        T data;
        Node* next;
    public:
        Node();
        Node(const T&);
        
        T getData() const;
        Node* getNext() const;
        
        void setData(const T&);
        void setNext(Node*);
        
    };
    
    Node* anchor;
    void copyAll(const Stack&);
    void deleteAll();
    
public:
    
    class Exception: public std::exception{
    private:
        std::string msg;
    public:
        explicit Exception(const char* message) : msg(message){}
        explicit Exception(const std::string& message) : msg(message){}
        
        virtual ~Exception() throw () {}
        
        virtual const char* what() const throw() {
            return msg.c_str();
        }
    };
    
    Stack();
    Stack(const Stack&);
    ~Stack();
    
    bool isEmpty() const;
    
    void push(const T&);
    
    T pop();
    
    T getTop() const;
    
    Stack& operator = (const Stack&);
};

template<class T>
Stack<T>::Node::Node(): next(nullptr){}

template<class T>
Stack<T>::Node::Node(const T& e): data(e), next(nullptr){}

template<class T>
T Stack<T>::Node::getData() const{
    return data;
}

template<class T>
typename Stack<T>::Node* Stack<T>::Node::getNext() const{
    return next;
}

template<class T>
void Stack<T>::Node::setData(const T& e){
    data=e;
}

template<class T>
void Stack<T>::Node::setNext(Node* p){
    next=p;
}

template<class T>
void Stack<T>::deleteAll(){
    Node* reco(anchor);
    Node* borra;
    while(reco != nullptr){
        borra = reco;
        reco = reco->getNext();
        delete borra;
    }
}

template<class T>
void Stack<T>::copyAll(const Stack& c){
    Node* reco(c.anchor);
    Node* last(nullptr);
    Node* newNode;
    
    while(reco != nullptr){
        newNode = new Node(reco->getData());
        if(last==nullptr){
            anchor = newNode;
        }
        else{
            last->setNext(newNode);
        }
        last=newNode;
        reco=reco->getNext();
    }
}

template<class T>
Stack<T>::Stack() : anchor(nullptr){}

template<class T>
Stack<T>::Stack(const Stack& c){
    copyAll(c);
}

template<class T>
Stack<T>::~Stack(){
    deleteAll();
}

template<class T>
bool Stack<T>::isEmpty() const{
    return anchor == nullptr;
}


template<class T>
void Stack<T>::push(const T& p){
    Node* aux(new Node(p));
    if(aux==nullptr){
        throw Exception("Memoria no disponible, push()");
    }
    
    aux->setNext(anchor);
    anchor=aux;
}

template<class T>
T Stack<T>::pop(){
    if(anchor==nullptr){
        throw Exception("Insuficiencia de Datos, pop()");
    }
    T result(anchor->getData());
    Node* aux(anchor);
    anchor = anchor->getNext();
    delete aux;
    return result;
}

template<class T>
T Stack<T>::getTop() const{
    if(anchor==nullptr){
        throw Exception("Insuficiencia de datos, getTop()");
    }
    return anchor->getData();
}

template<class T>
Stack<T>& Stack<T>:: operator = (const Stack& c){
    deleteAll();
    copyAll(c);
    return *this;
}

#endif // STACK_H_INCLUDED
