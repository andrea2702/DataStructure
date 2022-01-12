/*
Actividad Integral estructura de datos lineales

Autores: 
	Andrea Salcedo Vasquez- A00831510
	Ian Javier Duran Román - A00829799
	Fernando Cabrera - A00831380
Fecha de Creación: 04/10/21
*/

#include "Node.h"

template <class T>
class LinkedList {
    public :
        LinkedList();
        ~LinkedList();
        void addFirst(T data);
        void addLast(T data);
        bool add(T data, int pos);
        void deleteFirst();
        void deleteLast();
        void del(int pos);
        int deleteAll();
        T set(T data, int pos);
        T get(int pos);
        void change(int posA,int posB);
        bool isEmpty();
        int getSize();
        void print();
            //2.1
        bool operator==(const LinkedList &otra);
        void shift(int n);
        void reverse();
            //2.2
        void operator+=(const LinkedList &otra);
        void operator=(const LinkedList &otra);
        LinkedList(const LinkedList &lista);
        
        
        void sort();
        int find(string data);
        void writeData(string filename);
        vector<T> toVector();
    private:
        Node<T> *head; 
        int size;
};

//Constructor que crea una lista vacía
template <class T>
LinkedList<T>::LinkedList(){ //Se crea Lista Vacia
    head = nullptr;
    size = 0; 
}

//Destructor de la clase
template <class T>
LinkedList<T>::~LinkedList(){
    deleteAll();
}

/*
Método que añade un elemento al principio de la lista
Variable de Entrada: Dato a añadir
Variable de Salida: Ninguno
Complejidad: O(1)
*/
template <class T>
void LinkedList<T>::addFirst(T data){ // Primero crea un nodo con un nuevo dato apuntando a head y luego se lo asigna a head nuevamente
    head = new Node<T>(data, head);
    size++;
}

/*
Método que añade un elemento al final de la lista
Variable de Entrada: Dato a añadir
Variable de Salida: Ninguno
Complejidad: O(n)
*/
template <class T>
void LinkedList<T>::addLast(T data){
    if(size==0){
        addFirst(data);
    }
    else{
        Node<T> *curr = head; //Obtiene el primer nodo
        while (curr->getNext() != nullptr){ //mientras el siguiente al actual nodo no apunte a NULL, avanza en una posición
            curr = curr->getNext();
        }  
        curr->setNext(new Node<T>(data)); //El nodo actual apunta a un nuevo nodo con 'data' de contenido apuntando a NULL
        size++;
    }
}

/*
Método que añade un elemento a la lista creando un nodo y anexandolo a la lista en una posición dada.
Variable de Entrada: Dato a añadir y la posición de la lista a la que será añadida
Variable de Salida: Un booleano que indica si fue posible añadir el elemento o no.
// Complejidad: O(n)
*/
template <class T>
bool LinkedList<T>::add(T data, int pos){
    if (pos>size){
        return false;
    }
    if(pos==0){
        addFirst(data);
    }
    else if(pos == size){
        addLast(data);
    }
    else{
        Node<T> *curr = head;
        for(int i=1; i<pos;i++){
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data,curr->getNext()));
        size++;
    }
    return true;
}

/*
Método que elimina un elemento al principio de la lista
Variable de Entrada: Ninguno
Variable de Salida: Ninguno
Complejidad: O(1)
*/
template <class T>
void LinkedList<T>::deleteFirst(){
    if (size != 0){
        Node<T>* curr = head;
        head = head->getNext();
        delete curr;
        size--;
    }
}

/*
Método que elimina  elemento al final de la lista
Variable de Entrada: Ninguno
Variable de Salida: Ninguno
Complejidad: O(n)
*/
template <class T>
void LinkedList<T>::deleteLast(){
    if (size <= 1){
        deleteFirst();
    }
    else{
        Node<T> *curr = head;
        while(curr->getNext()->getNext() != nullptr) { //Mientras el nodo a dos posiciones mas adelante no sea nulo, curr avanza un nodo
            curr = curr->getNext();
        } // En este punto, curr esta posicionado en el penúltimo nodo, por lo que se borra el siguiente. 
        delete curr->getNext();
        curr->setNext(nullptr); // y se apunta el siguiente ahora a null
        size--;
    }
}

/*
Método que añade un elemento en una posición determinada de la lista
Variable de Entrada: Posición del elemento a eliminar
Variable de Salida: Ninguno
Complejidad: O(n)
*/
template <class T>
void LinkedList<T>::del(int pos){
    if(pos == 0){
        deleteFirst();
    }
    else if(pos == size-1){
        deleteLast();
    }
    else{
        Node<T> *curr = head;
        for(int i=1;i<pos;i++){
            curr = curr->getNext();
        }
        Node<T> *aux = curr->getNext();
        curr->setNext(aux->getNext()); //curr->getNext()->getNext()
        delete aux;
        size--;
    }
}

/*
Método que elimina todos los elementos de la lista
Variable de Entrada: Ninguno
Variable de Salida: Ninguno
Complejidad: O(n)
*/
template <class T>
int LinkedList<T>::deleteAll(){
    Node<T> *curr = head;
    while(head != nullptr){
        head = head->getNext();
        delete curr;
        curr = head;
    }
    int cant = size;
    size = 0;
    return cant;
}

/*
Método que reemplaza el valor de un elemento determinado de la lista
Variable de Entrada: Dato a modificar y la posición
Variable de Salida: Valor modificado
Complejidad: O(n)
*/
template <class T>
T LinkedList<T>::set(T data, int pos){
    Node<T> *curr = head;
    for(int i=1;i<=pos;i++){ //for(int i=0;i<pos;i++)
        curr = curr->getNext();
    }
    T dataAux = curr->getData();
    curr->setData(data);
    return dataAux;
}

/*
Método que obtiene el valor de un elemento determinado de una lista
Variable de Entrada: Posición del elemento
Variable de Salida: Valor del elemento
Complejidad: O(n)
*/
template <class T>
T LinkedList<T>::get(int pos){
    Node<T> *curr = head;
    for(int i=1;i<=pos;i++){
       curr= curr->getNext(); 
    }
    return curr->getData();
}

/*
Método que intercambia los valores de dos elementos de la lista
Variable de Entrada: Las posiciones de ambos elementos
Variable de Salida: Ninguno
Complejidad: O(n)
*/
template <class T>
void LinkedList<T>::change(int posA,int posB){
    if(posA!=posB){
        int posMen = (posA<posB) ? posA : posB;
        int posMay = (posA>posB) ? posA : posB;
        Node<T> *curr1 = head;
        for(int i=1; i<=posMen;i++){
            curr1 = curr1->getNext();
        }
        Node<T> *curr2 = curr1;
        for(int i = 1; i<=(posMay-posMen);i++){
            curr2 = curr2->getNext();
        }
        T dataAux = curr1->getData();
        curr1->setData(curr2->getData());
        curr2->setData(dataAux);
    }
}

/*
Método que verifica si la lista está vacía
Variable de Entrada: Ninguno
Variable de Salida: Booleano que indica si la lista esta vacia o no
Complejidad: O(1)
*/
template <class T>
bool LinkedList<T>::isEmpty(){
    return size==0; //Tambien (head == nullptr);
}

/*
Método que obtiene el tamaño de la lista
Variable de Entrada: Ninguno
Variable de Salida: Tamaño de la lista
Complejidad: O(1)
*/
template <class T>
int LinkedList<T>::getSize(){
    return size;
}

/*
Método que imprime todos los elementos de la lista
Variable de Entrada: Ninguno
Variable de Salida: Ninguno
Complejidad: O(n)
*/
template <class T>
void LinkedList<T>::print(){
    Node<T> *curr = head;
    while(curr!=nullptr){
        cout << curr->getData() << endl;
        curr=curr->getNext();
    }
    
}

/*
Metodo que verifica si dos listas son iguales
Entrada: Segunda lista con la que se va a comparar
Salida: Booleano indicando si son iguales o no
Complejidad O(n)
*/
template <class T> //LISTO
bool LinkedList<T>::operator==(const LinkedList<T> &otra){
    if(this->size != otra.size){
        return false;
    }
    Node<T> *curr1 = this->head;
    Node<T> *curr2 = otra.head;
    while(curr1!=nullptr){
        if(curr1->getData()!=curr2->getData()){
            return false;
        }
        curr1 = curr1->getNext();
        curr2 = curr2->getNext();
    }
    return true;
}

/*
Metodo que desplaza los elementos de una lista segun un numero de pasos
Entrada: Numero de pasos para desplazar
Salida: Ninguno
Complejidad O(n)
*/
template <class T>
void LinkedList<T>::shift(int n){
    if(n%size !=0){
        int residuo = n%size;
        if(residuo<0)
            residuo+=size;
        int saltos = size-residuo;
        Node<T> *curr = head, *aux = head;
        for(int i = 0; i<saltos;i++){
            aux = head;
            head = head->getNext();
        }
        aux->setNext(nullptr);
        aux=head;
        while(aux->getNext()!=nullptr){
            aux=aux->getNext();
        }
        aux->setNext(curr);
    }
}

/*
Metodo que invierte el orden de los valores de la lista
Entrada: Ninguna
Salida: Ninguna
Complejidad O(n)
*/
template <class T> //CHECK
void LinkedList<T>::reverse(){
    if(size>1){
        Node<T> *aux = nullptr;
        Node<T> *curr = head->getNext();
        head->setNext(nullptr);
        while(curr!=nullptr){
            aux = head;
            head = curr;
            curr = curr->getNext();
            head->setNext(aux);
        }
    }
}
/*
Metodo que añade los elementos de una lista a la actual
Entrada: Segunda lista con la que se va a operar
Salida: Ninguna
Complejidad O(n)
*/
template <class T>
void LinkedList<T>::operator+=(const LinkedList &otra){
    if(otra.size>0){
        Node<T> *curr1, *curr2 = otra.head;
        if(this->size==0){
            head = new Node<T>(otra.head->getData());
            curr2 = curr2->getNext();
        }
        curr1 = this->head;
        while(curr1->getNext()!=nullptr){
            curr1=curr1->getNext();
        }
        while(curr2!=nullptr){
            curr1->setNext(new Node<T>(curr2->getData()));
            curr1 = curr1->getNext();
            curr2 = curr2->getNext();
        }
        this->size+=otra.size;
    }
}

/*
Metodo que asigna todos los valores de una lista a la actual, reemplazando el contenido previo
Entrada: Segunda lista con la que se va a operar
Salida: Ninguna
Complejidad O(n)
*/
template <class T>
void LinkedList<T>::operator=(const LinkedList &otra){
    this->deleteAll();
    if(otra.size>0){
        this->head = new Node<T>(otra.head->getData());
        Node<T> *curr1 = head, *curr2 = otra.head->getNext();
        while(curr2!=nullptr){
            curr1->setNext(new Node<T>(curr2->getData()));
            curr1 = curr1->getNext();
            curr2 = curr2->getNext();
        }
        this->size=otra.size;
    }
}

/*
Constructor que toma como parametro otra lista
Entrada: Segunda lista con la que se va a operar
Salida: Ninguna
Complejidad O(n)
*/
template <class T>
LinkedList<T>::LinkedList(const LinkedList &lista){
    this->size = 0;
    this->head = nullptr;
    if(lista.size>0){
        this->head = new Node<T>(lista.head->getData());
        Node<T> *curr1 = head, *curr2 = lista.head->getNext();
        while(curr2!=nullptr){
            curr1->setNext(new Node<T>(curr2->getData()));
            curr1 = curr1->getNext();
            curr2 = curr2->getNext();
        }
        this->size=lista.size;
    }
}

/* Método que ordena la lista utilizando el método de intercambio
Complejidad:  O(n^2)*/
template <class T>

void LinkedList<T>::sort(){
    if(size > 1){
        Node<T> *i = head;
        while (i->getNext() != nullptr){
            Node<T> *j = i -> getNext();
            while(j != nullptr){
                if(i -> getData() > j -> getData()){
                    T aux = i -> getData();
                    i -> setData(j -> getData());
                    j -> setData(aux);
                }
                j = j->getNext();
            }
            i = i -> getNext();
        }
    }
}

/* Método que busca si un elemento de tipo string se encuentra en la lista
Variable de entrada: cadena
Variable de salida: posicion del elemento que tenga la misma cadena
Complejidad:  O(n)*/
template <class T>
int LinkedList<T>::find(string data){
    int i = 0;
    Node<T> *curr = head;
    while(curr!=nullptr){
        if(curr->getData()==data)
            return i;
        i++;
        curr = curr->getNext();
    }
    return -1;
    
}

/* Método que escribe los elementos de una lista a un archivo de texto
Variable de entrada: nombre del archivo con extensión
Variable de salida: Ninguna
Complejidad:  O(n)*/
template <class T>
void LinkedList<T>::writeData(string filename){
    ofstream ofs;
    ofs.open(filename);
    Node<T> *curr = head;
    while(curr!=nullptr){
        ofs << curr->getData();
        curr = curr->getNext();
    }
    ofs.close();
}

/* Método que escribe el valor de los elementos de la lista a un vector y lo devuelve
Variable de salida: Vector con los elementos de la lista
Complejidad:  O(n)*/
template <class T>
vector<T> LinkedList<T>::toVector(){
    vector<T> vect;
    Node<T> *curr = head;
    while(curr!=nullptr){
        vect.push_back(curr->getData());
        curr = curr->getNext();
    }
    return vect;
}