//Andrea Marisol Salcedo Vázquez
//A00831510
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//Complejidad: O(sqrt(n))
//Regresa si un número es primo o no, para esto lo divide entre
//todos los números hasta su raíz, si obtenemos resuido 0 en algun
//número entonces no es primo
bool isPrime(int tam){
    for(int i = 2; i <= sqrt(tam); i++){
        if(tam%i == 0){
            return false;
        }
    }
    return true;
}

//Complejidad: O(n^2)
//Añade los datos en el idx obtenidos con el residuo de dato/tam
//si ya está ocupado lo pasa al siguiente, y así hasta encontrar una casilla desocupada
//Si llega a la última se regresa a 0 para no salirse de la tabla
void open(vector<int> &hash, int n){
    int dato, tam = hash.size();
    for(int i = 0; i < n; i++){
        cin >> dato;
        int idx = dato%tam;
        while(hash[idx] != 0){
            idx = (idx+1) % tam;
        }
        hash[idx] = dato;
    }
}

//Complejidad: O(n)
//Imprime los datos
void print(vector<int> &hash){
    for(int i = 0; i < hash.size(); i++){
        cout << i << " - " << hash[i] << endl;
    }
}

// n = Cantidad de Datos
// tam = El tamaño de la tabla, tiene que ser número primo
int main(){
    int n, tam;
    cin >> n;
    tam  = n;
    while (!isPrime(tam)){
        tam++;
    }
    vector<int> hash(tam, 0); // 0 = Está desocupada esa casilla
    open(hash, n);
    print(hash);
    return 0;
}

/*
9
100
123
423
111
18
14
99
21
109
*/
