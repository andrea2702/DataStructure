/*
Actividad Integral de Árboles
Autores: 
	Andrea Salcedo Vasquez- A00831510
	Ian Javier Duran Román - A00829799
	Fernando Cabrera - A00831380
Fecha de Creación: 21/10/21
*/
#include <iostream>
#include <fstream>

using namespace std;

#include "BST.h"

/* Funcion que añade elementos aun arbol según los datos leidos de un archivo
Entrada: nombre del archivo, arbol al cual se añadiran los datos
Complejidad: O(n*height)
*/
void llenarArbol(string filename, BST &arbol){
    ifstream ifs;
    ifs.open(filename);
    int cont = 1;
    string fecha, hora, entrada, ubi, serieActual, serieAnt;
    ifs >> ubi >> fecha >> hora >> entrada;
    serieAnt = ubi.substr(0,3);
    //o(n*height)
    while(ifs >> ubi >> fecha >> hora >> entrada){
        serieActual = ubi.substr(0,3);
        if(serieActual != serieAnt){
            dataCS datos(cont,serieAnt);
            //o(height)
            arbol.add(datos);
            cont = 0;
            serieAnt = serieActual;
        }
        cont++;
    }
    dataCS datos(cont,serieAnt);
    arbol.add(datos);
    ifs.close();
}


int main(){
    string filename;
    cout << "Ingrese el nombre de archivo de los buques de entrada de Mediterraneo: ";
    getline(cin,filename);
    BST entradasM, entradasR;
    cout << "ENTRADAS MAR MEDITERRANEO" << endl;
    llenarArbol(filename,entradasM);
    entradasM.print();

    cout << "Ingrese el nombre de archivo de los buques de entrada de Rojo: ";
    getline(cin,filename);
    cout << "ENTRADAS MAR ROJO" << endl;
    llenarArbol(filename,entradasR);
    entradasR.print();
    
} 