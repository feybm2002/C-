#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED


template<class T>
class Queue{
private:
    class Node{
    private:
        T* dataPtr;
        Node* next;
        Node* prev;
    public:
        class Exception : public std::exception{
        private:
            std::string msg;
            
        public:
            explicit Exception(const char* message) : msg(message){}
            
            explicit Exception(const std::string& message): msg(message){}
            
            virtual ~Exception() throw() {}
            
            virtual const char* what() const throw(){
                return msg.c_str();
            }
        };
        Node();
        Node(const T&);
        ~Node();
        
        T* getDataPtr() const;
        T getData() const;
        Node* getNext() const;
        Node* getPrev() const;
        
        void setDataPtr(T*);
        void setData(const T&);
        void setNext(Node*);
        void setPrev(Node*);
    };
    
    Node* header;
    
    void copyAll(const Queue<T>&);
    void deleteAll();
    
public:
    
    class Exception : public std::exception{
    private:
        std::string msg;
        
    public:
        explicit Exception(const char* message) : msg(message){}
        
        explicit Exception(const std::string& message): msg(message){}
        
        virtual ~Exception() throw() {}
        
        virtual const char* what() const throw(){
            return msg.c_str();
        }
    };
    Queue();
    Queue(const Queue&);
    ~Queue();
    
    bool isEmpty();
    
    void enqueue(const T&);
    
    T dequeue();
    
    T getFront() const;
    
    Queue<T>& operator = (const Queue<T>&);
    
};

using namespace std;
//Implementacion
template <class T>
Queue<T>::Node::Node() : dataPtr(nullptr), prev(nullptr), next(nullptr) {}

template <class T>
Queue<T>::Node::Node(const T&e): dataPtr(new T(e)), prev(nullptr), next(nullptr) {
    if(dataPtr == nullptr){
        throw Exception("Memoria insuficiente, creando nodo");
    }
}

template <class T>
Queue<T>::Node::~Node(){
    delete dataPtr;
}

template <class T>
T* Queue<T>::Node::getDataPtr() const{
    return dataPtr;
}

template <class T>
T Queue<T>:: Node::getData() const{
    if(dataPtr==nullptr){
        throw Exception("Dato inexistente, getData()");
    }
    return *dataPtr;
}

template <class T>
typename Queue<T>::Node* Queue<T>::Node::getNext() const{
    return next;
}

template <class T>
typename Queue<T>::Node* Queue<T>::Node::getPrev() const
{
    return prev;
}

template <class T>
void Queue<T>::Node::setDataPtr(T* p){
    dataPtr=p;
}

template <class T>
void Queue<T>::Node::setData(const T& e){
    if(dataPtr==nullptr){
        if((dataPtr= new T(e)) == nullptr){
            throw Exception("Memoria no disponible, setData");
        }
    }
    else{
        *dataPtr = e;
    }
}

template <class T>
void Queue<T>::Node::setNext(Node* p){
    next = p;
}

template <class T>
void Queue<T>::Node::setPrev(Node* p){
    prev = p;
}

template <class T>
void Queue<T>::copyAll(const Queue<T>& m){
    Node* aux(m.header->getNext());
    Node* newNode;
    
    while(aux!= m.header){
        try{
            if((newNode = new Node(aux->getData())) == nullptr){
                throw Exception("Memoria no disponible, copyAll");
            }
        }
        catch(typename Node::Exception ex){
            throw Exception(ex.what());
        }
        newNode->setPrev(header->getPrev());
        newNode->setNext(header);
        
        header->getPrev()->setNext(newNode);
        header->setPrev(newNode);
        
        aux = aux->getNext();
    }
}

template <class T>
void Queue<T>::deleteAll(){
    Node* aux;
    
    while(header->getNext() != header){
        aux = header->getNext();
        
        header->setNext(aux->getNext());
        
        delete aux;
    }
    header->setPrev(header);
}

template <class T>
Queue<T>::~Queue(){
    deleteAll();
    delete header;
}





template <class T>
Queue<T>::Queue() : header(new Node){
    if(header==nullptr){
        throw Exception("Memoria no disponible, inicializando queue");
    }
    header->setPrev(header);
    header->setNext(header);
    
}

template <class T>
Queue<T>::Queue(const Queue<T>& p) : Queue(){
    copyAll(p);
}

template <class T>
bool Queue<T>::isEmpty(){
    return header->getNext() == header;
}


template <class T>
void Queue<T>::enqueue(const T& e){
    Node* aux;
    
    try{
        if((aux = new Node(e)) == nullptr){
            throw Exception("Memoria no disponible, enqueue()");
        }
    } catch(typename Node::Exception ex){
        throw Exception(ex.what());
    }
    aux->setPrev(header->getPrev());
    aux->setNext(header);
    
    header->getPrev()->setNext(aux);
    header->setPrev(aux);
}

template <class T>
T Queue<T>::dequeue(){
    if(isEmpty()){
        throw Exception("Insuficiencia de Datos, dequeue");
    }
    T result(header->getNext()->getData());
    
    Node* aux(header->getNext());
    
    aux->getPrev()->setNext(aux->getNext());
    aux->getNext()->setPrev(aux->getPrev());
    
    delete aux;
    
    return result;
}

template <class T>
T Queue<T>::getFront() const{
    if(isEmpty()){
        throw Exception("Insuficiencia de datos, getFront");
    }
    return header->getNext()->getData();
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& m){
    deleteAll();
    copyAll(m);
    return *this;
}



#endif // QUEUE_H_INCLUDED
