//Andrea Marisol Salcedo Vázquez
//A00831510
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//Complejidad:  O(sqrt(n))
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

//Complejidad: O(n)
//saca el modulo del dato con el tamaño para ver en qué idx lo agrega
//Si ya está ocupado lo agrega en esa posición al final del vector.
void chain(vector<vector<int>> &hash, int n){
    int dato, tam = hash.size();
    for(int i = 0; i < n; i++){
        cin >> dato;
        int idx = dato%tam;
        hash[idx].push_back(dato);
    }
}


//Complejidad: O(n)
//Imprime los datos
void print(vector<vector<int>> &hash){
    for(int i = 0; i < hash.size(); i++){
        cout << i << " - ";
        for(int j = 0; j < hash[i].size(); j++){
            cout << hash [i][j] << ", ";
        }
        cout << endl;
    }
}
int main(){
    int n, tam;
    cin >> n;
    tam = n;
    while (!isPrime(tam)){
        tam++;
    }
    vector<vector<int>> hash(tam); 
    chain(hash, n);
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
