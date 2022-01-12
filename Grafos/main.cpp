//BFS con matriz de adyacencia, Grafo NO_Dirigido y NO_ponderado
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 10

void iniMatAdj(bool matAdj[MAX][MAX]){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            matAdj[i][j] = false;
        }
    }
}

void leeMatAdj(bool matAdj[MAX][MAX], int m){
    int a,b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        // Recordar que usuario tiene como 1° nodo al 1
        // y en la matAdj el primer nodo es el nodo 0
        // Por eso le rebajamos 1 a a y b
        // Recordar que es un grafo NO-Dirigido y NO-Ponderado
        matAdj[a-1][b-1] = matAdj[b-1][a-1] = true;
    }
}

void printMatAdj(bool matAdj[MAX][MAX], int n){
    for (int i = 0; i < n; i++){
        for(int j = 0; j< n; j++){
            cout << matAdj[i][j] << " ";
        }
        cout << endl; 
    }
}

//Complejidad: O(n^2) ==>  
void BFS(bool matAdj[MAX][MAX], int n){
    queue<int> fila;
    vector<bool> status(n, false);
    int dato;
    for(int i = 0; i < n; i++){
        if(!status[i]){
            fila.push(i);
            status[i] = true;
            while(!fila.empty()){
                dato = fila.front();
                fila.pop();
                // Le sumamos uno para mostrarlo como el usuario lo pide (base-1)
                cout << (dato + 1) << " ";
                // Checar el renglón (dato) en la matAdj con cada col y si es true
                // y luego checo el status de esa columna para ver si no ha sido
                // procesado, para entonces meterlo en la fila
                for(int j=0; j < n; j++){
                    if(matAdj[dato][j] && !status[j]){
                        fila.push(j);
                        status[j] = true;
                    }
                }
            }
        }
    }
}

int main(){
    //Matriz de adyacencias (base-0) Renglón = Nodo_Origen, columna = Nodo_Destino
    bool matAdj[MAX][MAX];
    //n = cant de nodos (base-1)
    //m = cantidad de arcos
    int n,m;
    cin >> n >> m;
    iniMatAdj(matAdj);
    leeMatAdj(matAdj, m);
    //printMatAdj(matAdj,n);
    BFS(matAdj, n);
}


/*
Datos del Grafo1 solo falta agregar el nodo de arranque
n = cant de nodos (base-1)
m = cantidad de arcos
7 11
1 2
1 3
1 4
2 3  
2 5
3 4
3 5
4 5
4 6
5 7
6 7
Resultado: 1 2 3 4 5 7 6 

0 -> 1 -> 2 -> 3
1 -> 0 -> 2 -> 4
2 -> 0 -> 1 -> 3 -> 4
3 -> 0 -> 2 -> 4 -> 5
4 -> 1 -> 2 -> 3 -> 6
5 -> 3 -> 6
6 -> 4 -> 5

---------------------------------
Datos del Grafo2 solo falta agregar el nodo de arranque
7 6
1 2
2 3  
2 5
3 4
4 6
5 7
Resultado: 1 2 3 4 6 5 7 

*/
