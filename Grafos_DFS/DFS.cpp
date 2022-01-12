// DFS con mLista de adyacencia, Grafo NO_Dirigido y NO_ponderado
// DFS = Depth First Search
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void leeListAdj(vector<vector<int>> &listAdj, int m){
    int a, b;
    for(int i=0; i < m; i ++){
        cin >> a >> b;
        // Recordar que el usuario tiene los nodos (base-1)
        // Y la listAdj lo maneja con (base-0)
        listAdj[a-1].push_back(b-1);
        listAdj[b-1].push_back(a-1);
    }
}

void printListAdj(vector<vector<int>> &listAdj){
    for(int i = 0; i < listAdj.size(); i++){
        cout << (i+1) << " ";
        for(int j  = 0; j < listAdj[i].size(); j ++){
            cout << "==>" << (listAdj[i][j]+1);
        }
        cout << endl;
    }
}

//Complejidad: O(|V|+|E|)
void DFS(vector<vector<int>> &listAdj){
    stack<int> pila;
    int dato; //Cuando vaya sacando de la pila
    vector<bool> status(listAdj.size(), false); //status para saber si está procesado
    int cantVisitados = 0;
    for (int i = 0; i < listAdj.size() && cantVisitados != listAdj.size(); i++){
        if(!status[i]){
            pila.push(i);
            while(!pila.empty() && cantVisitados != listAdj.size()){
                dato = pila.top();
                pila.pop();
                if(!status[dato]){
                    //Visito (proceso) al  nodo "dato", lo pongo como visitado
                    // lo despliego y cantVisitiados le sumo 1
                    status[dato] = true;
                    cantVisitados++;
                    cout << (dato + 1) << " "; //Acordarnos que la base del usuario es base -1
                    // Por cada nodo adyacente a el nodo "dato" hay que preguntar 
                    // si no ha sido visitado, en este caso se busca en la lista de adyacencias
                    // en forma inversa, para que el nodo adyacente de más pequeño nombre
                    // quede en el tope, y si no ha sido visitado lo voy a meter a la pila.
                    for(int j = listAdj[dato].size()-1; j >= 0; j--){
                        if(!status[listAdj[dato][j]]){
                            pila.push(listAdj[dato][j]);
                        }
                    }
                }
            }
        }
    }
    cout << endl;

}

int main(){
    int n, m;
    cin >> n >> m;
    //Simularemos la listAdj con un vector de vectores de int
    //Donde la dim 1 son los nodos
    //DOnde la dim 2 son los adyacentes al nodo de la dim 1
    vector<vector<int>> listAdj(n);
    leeListAdj(listAdj, m);
    //printListAdj(listAdj);
    DFS(listAdj);

}

/*
Datos del Grafo1 solo falta agregar el nodo de arranque
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
