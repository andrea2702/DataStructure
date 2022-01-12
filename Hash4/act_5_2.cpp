/*
Act 5.2 - Actividad Integral sobre el uso de códigos hash
Autores: 
	Andrea Salcedo Vasquez- A00831510
	Ian Javier Duran Román - A00829799
	Fernando Cabrera - A00831380
Fecha de Creación: 25/11/21
*/

#include <iostream>
#include <unordered_map>

using namespace std;

//Complejidad: O(m + n*palbEnParr)
int main(){
    int desc, cantParr, points;
    string s;
    cin >> desc >> cantParr;
    unordered_map<string,int> unlimitedSeas;
    // se usan mapas donde se usa la palabra como llave y el
    // valor la cantidad de puntos que tiene esa palabra 
    //Complejidad: O(m), donde m es la cantidad de palabras en
    //el diccionario
    for(int i=0;i<desc;i++){
        cin >> s >> points;
        unlimitedSeas[s] = points;
        // Aquellas palabras que no se encuentren en el mapa,
        // tendrán el valor de 0
    }
    int total=0;
    // Se leen parrafos que terminan en punto y se hace una sumatoria
    // con valores según las palabras que estén registradas en el
    // Diccionario
    //Complejidad: O(n*palbEnParr), donde n es la cantidad de parrafos  
    while(cantParr){
        cin>> s;
        if(s=="."){ // Fin del Parrafo
            cantParr--;
            cout << total << endl;
            total = 0;
        }
        else{
            // si encuentra una palabra en el diccionario -> unlimitedSeas[s]!=0
            // si no, unlimitedSeas[s]=0
            //Complejidad: O(1)
            total+=unlimitedSeas[s];
            
        }
    }
}