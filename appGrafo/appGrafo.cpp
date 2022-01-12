//Andrea Marisol Salcedo Vázquez
//A00831510
//08/11/21
//DFS y BFS en grafos

#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

#define MAX 10

//Complejidad: O(E) ---> depende de la cantidad de arcos
void loadGraph(int n, int m, bool matAdj[MAX][MAX], vector<vector<int>> &listAdj){
    int a, b;
    for(int i=0; i < m; i ++){
        cin >> a >> b;
        // Recordar que el usuario tiene los nodos (base-1)
        // Y la listAdj lo maneja con (base-0)
        listAdj[a-1].push_back(b-1);
        listAdj[b-1].push_back(a-1);
        // Recordar que usuario tiene como 1° nodo al 1
        // y en la matAdj el primer nodo es el nodo 0
        // Por eso le rebajamos 1 a a y b
        // Recordar que es un grafo NO-Dirigido y NO-Ponderado
        matAdj[a-1][b-1] = matAdj[b-1][a-1] = true;
    }
}

//Complejidad: O(MAX^2)
void iniMatAdj(bool matAdj[MAX][MAX]){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            matAdj[i][j] = false;
        }
    }
}

//Complejidad: O(n^2)
//Imprime la listAdj para ver si se creó bien
void printListAdj(vector<vector<int>> &listAdj){
    for(int i = 0; i < listAdj.size(); i++){
        cout << (i+1) << " ";
        for(int j  = 0; j < listAdj[i].size(); j ++){
            cout << "==>" << (listAdj[i][j]+1);
        }
        cout << endl;
    }
}

//Complejidad: O(n^2)
//Imprime la matAdj para ver si se creó bien
void printMatAdj(bool matAdj[MAX][MAX], int n){
    for (int i = 0; i < n; i++){
        for(int j = 0; j< n; j++){
            cout << matAdj[i][j] << " ";
        }
        cout << endl; 
    }
}

//Complejidad: O(n^2)
//DFS usando matAdj en lugar de listAdj
void DFS(bool matAdj[MAX][MAX], int n){
    stack<int> pila;
    int dato; //Cuando vaya sacando de la pila
    vector<bool> status(n, false);
    int cantVisitados = 0;
    for (int i = 0; i < n && cantVisitados != n; i++){
        if(!status[i]){
            pila.push(i);
            while(!pila.empty() && cantVisitados != n){
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
                    for(int j = n - 1; j >= 0; j--){
                        if(matAdj[dato][j] && !status[j]){
                            pila.push(j);
                        }
                    }
                }
            }
        }
    }
    cout << endl;

}

//Complejidad: O(|V|+|E|)
//BFS implementada con una listAdj. Se adaptó el código que se hizo en la clase para 
//usar ahora listAdj en lugar de la matAdj
void BFS(vector<vector<int>> &listAdj){
    queue<int> fila;
    vector<bool> status(listAdj.size(), false); //status para saber si está procesado
    int dato;
    for(int i = 0; i < listAdj.size(); i++){
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
                for(int j = 0; j < listAdj[dato].size(); j++){
                    if(!status[listAdj[dato][j]]){
                        fila.push(listAdj[dato][j]);
                        status[listAdj[dato][j]] = true;
                    }
                }
            }
        }
    }
    cout << endl;
}


int main(){
    //Matriz de adyacencias (base-0) Renglón = Nodo_Origen, columna = Nodo_Destino
    bool matAdj[MAX][MAX];
    iniMatAdj(matAdj);
    //n = cant de nodos (base-1)
    //m = cantidad de arcos
    int n, m;
    cin >> n >> m;
    //Simularemos la listAdj con un vector de vectores de int
    vector<vector<int>> listAdj(n);
    loadGraph(n, m, matAdj, listAdj);
    //printMatAdj(matAdj,n);
    //printListAdj(listAdj);
    cout << "DFS" << endl;
    DFS(matAdj, n);
    cout << "BFS" << endl;
    BFS(listAdj);
}