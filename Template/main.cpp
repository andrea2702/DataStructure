#include <iostream>

using namespace std;

/*
int menorInt(int a1, int a2){
    if(a1<a2){
        return a1;
    }
    return a2;
}

float menorFloat(float b1, float b2){
    if(b1<b2){
        return b1;
    }
    return b2;
}
*/

template <typename T>
T menor (T c1, T c2){
//    if(c1 < c2){
//        return c1;
//    }
//    return c2;
    return (c1 < c2) ? c1 : c2; //Op. Condicional
}

int main(){
    int a1, a2;
    float b1, b2;
    cin >> a1 >>a2;
    cout << menor(a1,a2)<<'\n';
    cin >> b1 >> b2;
    cout << menor(b1,b2)<<'\n';

}