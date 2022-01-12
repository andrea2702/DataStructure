#include <iostream>
using namespace std;

const int MAX=100;

template <class T>
class Lista{
    private:
        T data[MAX];
        int size;
    public:
        Lista();
        void insert(T);
        void erase();
        T getData(int);
        int getSize();
        void print();
};

template <class T>
Lista<T>::Lista(){
    size = 0;
}

template <class T>
void Lista<T>::insert(T d){
    if(size < MAX){
        data[size++] = d;
    }
}

template <class T>
void Lista <T>::erase(){
    if(size>0){
        size--;
        cout<<"[" << size << "] - " << data[size] << endl;
    }else{
        cout << "NO HAY ELEMENTOS" <<endl;
    }

}

template <class T>
T Lista<T>::getData(int pos){
    return data[pos];
}

template <class T>
int Lista<T>::getSize(){
    return size;
}

template <class T>
void Lista<T>::print(){
    for(int i=0; i <size; i++){
        cout << "[" << i << "] - "<< data[i] << endl;
    }
}