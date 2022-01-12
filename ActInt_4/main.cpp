/*
Act 4.3 - Actividad Integral de Grafos
Autores: 
	Andrea Salcedo Vasquez- A00831510
	Ian Javier Duran Román - A00829799
	Fernando Cabrera - A00831380
Fecha de Creación: 18/11/21
*/

#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

// Funcion que carga un grafo y un mapa que permite indexar los nombres de las ubicaciones con números
// Entrada: Nodos, Vertices, Lista de Adjacencia, Mapa de nombres
// Complejidad: O(n+m)
void loadGraph(int n, int m, vector<vector<int>> &listAdj, map<string,int> &nombres){
    for(int i = 0; i < n;i++){
        string nombre;
        cin >> nombre;
        nombres[nombre] = i; 
    }
    for(int j = 0; j < m; j++){
        string nombre_1, nombre_2;
        cin >> nombre_1 >> nombre_2;
        int nodo1 = nombres[nombre_1], nodo2 = nombres[nombre_2];
        listAdj[nodo1].push_back(nodo2);
        listAdj[nodo2].push_back(nodo1);
    }
}

// Funcion que realiza un recorrido por anchura al grafo y devuelve
// la cantidad de nodos no visitados segun un numero máximo de pasos
// Entrada: Nodo Inicial, lista de Adjacencia, Numero Máximo de Pasos
// Salida: Numero de nodos no visitados
// O(|V|+|E|)
int BFS(int nodoInicial, vector<vector<int>> &listAdj, int MNP){
    int nodosNoVisitados=0;
    // par<nodo,nivel>
    int level = 0;
    queue<pair<int,int>> fila;
    vector<bool> status(listAdj.size(),false);
    int dato;
    fila.push(make_pair(nodoInicial,level));
    status[nodoInicial] = true;
    while(!fila.empty()){
        dato = fila.front().first;
        level = ++fila.front().second;
        fila.pop();
        // Checar el renglón (dato) en la matAdj con cada col y si es true
        // y luego checo el status de esa columna para ver si no ha sido
        // procesado, para entonces meterlo en la fila
        for(int j = 0; j < listAdj[dato].size(); j++){
            if(!status[listAdj[dato][j]]){
                if(level>MNP){
                    nodosNoVisitados++;
                }
                fila.push(make_pair(listAdj[dato][j],level));
                status[listAdj[dato][j]] = true;
            }
        }
    }
    return nodosNoVisitados;
}

int main(){
    int n,m, NQ;
    string str;
    cin >> n >> m;
    vector<vector<int>> listAdj(n);
    map<string, int> nombres;
    cin.ignore();
    loadGraph(n,m,listAdj,nombres);
    cin >> NQ;
    //O(NQ*(V+E))
    for(int i=0;i<NQ;i++){
        int MNP, res;
        string nodoInicial;
        cin >> nodoInicial >> MNP;
        res = BFS(nombres[nodoInicial],listAdj,MNP);
        cout << "Case " << i+1 <<": " << res << " ports not reachable from port " << nodoInicial << " with MNP = " << MNP << "." << endl;
    }
}



// CASOS DE PRUEBA
/*
13 16
Haikou
Yantai
Balboa
Fuzhou
Busan
Mersin
Alejandria
Taipei
Singapore
Karachi
Zhuhai
London
Ambarli
Haikou Yantai
Haikou Balboa
Balboa Mersin
Mersin Singapore
Yantai Busan
Busan Singapore
Yantai Fuzhou
Busan Taipei
Singapore Zhuhai
Taipei Zhuhai
Fuzhou Taipei
Fuzhou Alejandria
Alejandria Karachi
Karachi London
London Ambarli
Zhuhai Ambarli
3
Busan 2
Haikou 3
Haikou 2

*/

//res
/*
Busan 2
Case 1: 5 ports not reachable from port Busan with MNP = 2.
Haikou 3
Case 2: 4 ports not reachable from port Haikou with MNP = 3.
Haikou 2
Case 3: 7 ports not reachable from port Haikou with MNP = 2.
*/