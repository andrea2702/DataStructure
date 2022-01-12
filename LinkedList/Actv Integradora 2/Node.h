/*
Actividad Integral estructura de datos lineales

Autores: 
	Andrea Salcedo Vasquez- A00831510
	Ian Javier Duran Román - A00829799
	Fernando Cabrera - A00831380
Fecha de Creación: 04/10/21
*/

template <class T>
class Node{
    public:
        Node(T data);
        Node(T data, Node<T> *next);
        T getData();
        Node<T>* getNext();
        void setData(T data);
        void setNext(Node<T> *next);
    private:
        T data;
        Node<T> *next;
};

/* CONSTRUCTOR
Variable de entrada: Dato T
Complejidad:  O(1)*/
template <class T>
Node<T>::Node(T data){
    this->data = data;
    this->next = nullptr; //apunta a NULL
}

/* CONSTRUCTOR
Variable de entrada: Dato T y apuntador a siguiente nodo
Complejidad:  O(1)*/
template <class T>
Node<T>::Node(T data, Node<T> *next){
    this->data = data;
    this->next = next;
}

/* Método que obtiene el valor del nodo
Variable de salida: Valor del nodo
Complejidad:  O(1)*/
template <class T>
T Node<T>::getData(){
    return data;
}

/* Método que obtiene el apuntador al siguiente nodo
Variable de salida: Apuntador al siguiente nodo
Complejidad:  O(1)*/
template <class T>
Node<T>* Node<T>::getNext(){
    return next;
}

/* Método que modifica el valor del nodo
Variable de entrada: Valor del nodo
Complejidad:  O(1)*/
template <class T>
void Node<T>::setData(T data){
    this->data = data;
}

/* Método que modifica el apuntador al siguiente nodo
Variable de entrada: apuntador al siguiente nodo
Complejidad:  O(1)*/
template <class T>
void Node<T>::setNext(Node<T> *next){
    this->next = next;
}
