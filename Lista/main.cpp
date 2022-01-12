// AG01-I
// Aplicación para probar la Actividad AG01 en la parte I
// Autor: Ing. Luis H. González Guerra#include <iostream>

using namespace std;

#include "Lista.h"

int main(){
	Lista miLista;
	miLista.insert(154);
	miLista.insert(587);
	miLista.insert(874);
	miLista.print();
	cout << "La lista tiene: "<< miLista.getSize() << " datos"<<endl;
	miLista.insert(999);
	miLista.insert(888);
	cout << "La lista tiene: "<< miLista.getSize() << " datos"<<endl;
	cout << "En la posición 3 esta: "<<miLista.getData(3)<<endl;
	cout << "Voy a borrar el último y fue: "<< endl;
	miLista.erase();
	int cant = miLista.getSize();
	cout << "La lista tiene: "<< cant << " datos"<<endl;
	for (int i=0; i<cant; i++){
		miLista.erase();
	}
}