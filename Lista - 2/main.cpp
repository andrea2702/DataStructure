// AG01-II
// Aplicación para probar la Actividad AG01 en la parte II
// Autor: Ing. Luis H. González Guerra


#include <iostream>

using namespace std;

#include "Lista.h"

int main(){
	Lista<int> miLista1;
	miLista1.insert(154);
	miLista1.insert(587);
	miLista1.insert(874);
	miLista1.print();
	cout << "La lista tiene: "<< miLista1.getSize() << " datos"<<endl;
	miLista1.insert(999);
	miLista1.insert(888);
	cout << "La lista tiene: "<< miLista1.getSize() << " datos"<<endl;
	cout << "En la posición 3 esta: "<<miLista1.getData(3)<<endl;
	cout << "Voy a borrar el último y fue: "<< endl;
	miLista1.erase();
	int cant = miLista1.getSize();
	cout << "La lista tiene: "<< cant << " datos"<<endl;
	for (int i=0; i<cant; i++){
		miLista1.erase();
	}
	cout << "---------------------"<<endl;
	Lista<string> miLista2;
	miLista2.insert("HOLA");
	miLista2.insert("CRAYOLA");
	miLista2.insert("COMO");
	miLista2.print();
	cout << "La lista tiene: "<< miLista2.getSize() << " datos"<<endl;
	miLista2.insert("TE");
	miLista2.insert("VA?");
	cout << "La lista tiene: "<< miLista2.getSize() << " datos"<<endl;
	cout << "En la posición 3 esta: "<<miLista2.getData(3)<<endl;
	cout << "Voy a borrar el último y fue: "<< endl;
	miLista2.erase();
	cant = miLista2.getSize();
	cout << "La lista tiene: "<< cant << " datos"<<endl;
	for (int i=0; i<cant; i++){
		miLista2.erase();
	}
}