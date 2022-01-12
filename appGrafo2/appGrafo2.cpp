//Andrea Marisol Salcedo Vázquez
//A00831510
//13/11/21
//Topological sort

#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

//Complejidad: O(E) ---> depende de la cantidad de arcos
//Guarda los nodos a los que apunta cada nodo en una lista adjunta
void loadGraph(vector<vector<int>> &listAdj, vector<int> &indegree, int m){
    int a, b;
    for(int i=0; i < m; i ++){
        cin >> a >> b;
        // Recordar que el usuario tiene los nodos (base-1)
        // Y la listAdj lo maneja con (base-0)
        //Al ser una lista dirigida no se guarda en ambos nodos
        listAdj[a-1].push_back(b-1);
        indegree[b-1]++;
    }
}

//Complejidad: O(|V|+|E|)
//Regresa un vector con el orden topologico
vector<int> topologicalSort(vector<vector<int>> &listAdj, vector<int> &indegree, int m){
    stack<int> pila;
    int dato; //Cuando vaya sacando de la pila
    vector<bool> status(listAdj.size(), false); //status para saber si está procesado
    vector<int> orden_topologico(listAdj.size(),0); //Vector que se va a regresar
    int cantVisitados = 0; //Nodos que se han visitado
    for (int i = 0; i < listAdj.size() && cantVisitados != listAdj.size(); i++){
        if(indegree[i] == 0 && !status[i]){ //Checa si no hay nodos que apunten hacia él y si no ha sido procesado
            pila.push(i); //Lo mete en la pila
            //Se ejecuta mientras la pila no esté vacía y no se hayan visitado todos los nodos
            while(!pila.empty() && cantVisitados != listAdj.size()){ 
                dato = pila.top(); //Se saca el dato
                pila.pop(); //Se elimina
                //Se checa si no hay nodos apuntando hacia él y si no ha sido procesado
                if(indegree[dato] == 0 && !status[dato]){
                    //cout << (dato + 1) << " "; Acordarnos que la base del usuario es base -1
                    //Cambio el estado del dato a visitado
                    status[dato] = true;
                    //Lo agrego al orden topologico que se regresará
                    orden_topologico[cantVisitados] = dato;
                    //Le sumo uno a cantidad de visitados
                    cantVisitados++;
                    // Por cada nodo adyacente a el nodo "dato" hay que restar uno
                    // en el vector indegree para borrar la flecha que lo apunta,
                    // en este caso se busca en la lista de adyacencias
                    // en forma inversa, para que el nodo adyacente de más pequeño nombre
                    // quede en el tope, y si su indegree es 0, es decir que no hay nodos apuntandole, se mete a la pila.
                    for(int j = listAdj[dato].size()-1; j >= 0; j--){
                        indegree[listAdj[dato][j]]--;
                        if(indegree[listAdj[dato][j]]==0){
                            pila.push(listAdj[dato][j]);
                        }
                    }
                }
            }
        }
    }
    //cout << endl;
    return orden_topologico;
}


int main(){
    int n, m;
    cin >> n >> m;
    //Simularemos la listAdj con un vector de vectores de int
    //Donde la dim 1 son los nodos
    //DOnde la dim 2 son los adyacentes al nodo de la dim 1
    vector<vector<int>> listAdj(n);
    vector<int> indegree(n,0), topological_sort;
    loadGraph(listAdj, indegree, m);
    topological_sort = topologicalSort(listAdj, indegree, m);
    for(int i = 0; i < topological_sort.size() ; i++){
        cout << (topological_sort[i] + 1) << " ";
    }
    cout << endl;
}


/*
9 13
1 2
1 3
2 3
2 4
3 4
3 5
4 8
5 6
5 7
6 8
7 8
9 3
9 5
*/