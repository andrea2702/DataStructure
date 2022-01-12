#include <iostream>
using namespace std;

const int MAX=100;
class Lista{
    private:
        int data[MAX];
        int size;
    public:
        Lista();
        void insert(int);
        void erase();
        int getData(int);
        int getSize();
        void print();
};

Lista::Lista(){
    size = 0;
}

void Lista::insert(int d){
    if(size<MAX){
        data[size++] = d;
    }
}

void Lista::erase(){
    if(size>0){
        size--;
        cout<<"[" << size << "] - " << data[size] << endl;
    }else{
        cout << "NO HAY ELEMENTOS" <<endl;
    }

}

int Lista::getData(int pos){
    return data[pos];
}

int Lista::getSize(){
    return size;
}

void Lista::print(){
    for(int i=0; i <size; i++){
        cout << "[" << i << "] - "<< data[i] << endl;
    }
}