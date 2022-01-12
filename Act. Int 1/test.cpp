#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Registro{
    string fecha;
    string hora;
    char entrada;
    string ubi;
	string sububi;
    int fechaInt;
};


int buscaBinaria(vector <Registro> &vec, string substr){
	int izq = 0, der=vec.size()-1;
 	while(izq <=der){
    	int med = (izq + der)/2;
		int comparacion = vec[med].sububi.compare(substr);
		
    	if(comparacion == 0){
			if(vec[med].sububi.compare(vec[med-1])<0){
				return med;
			}
			izq = med + 1
		}
        	
		
    	if(comparacion > 0){
			der = med-1;
		}
        
    	else
        	izq = med+1;
 	}
 	return -1;

}


int mestoi(string m){
	if (m=="jan"){
		return 1;
	}
	if (m=="feb"){
		return 2;
	}
	if (m=="mar"){
		return 3;
	}
	if (m=="apr"){
		return 4;
	}
	if (m=="may"){
		return 5;
	}
	if (m=="jun"){
		return 6;
	}
	if (m=="jul"){
		return 7;
	}
	if (m=="aug"){
		return 8;
	}
	if (m=="sep"){
		return 9;
	}
	if (m=="oct"){
		return 10;
	}
	if (m=="nov"){
		return 11;
	}
	return 12;
}

int ftoi(string fecha){
	int salida= 0;
	int aux = 0;
	int i = 0;
	while (fecha[i] != '-'){
		aux*=10;
		aux+= (fecha[i] - '0'); // '5' -'0' == 5 como entero (53-48)
		i++;
	}
	salida += aux;
	i++;
	string mes = "";
	while (fecha[i] != '-'){
		mes += fecha[i];
		i++;
	}
	salida += (mestoi(mes)*100);
	aux = 0;
	i++;
	while (i < fecha.length()){
		aux*=10;
		aux+= (fecha[i] - '0'); // '5' -'0' == 5 como entero (53-48)
		i++;	
	}
	salida += (aux*10000);
	return salida;
}


bool acompare(const Registro &lhs,const Registro &rhs){
	if(lhs.ubi == rhs.ubi){
		return lhs.fechaInt < rhs.fechaInt;
	}
	return (lhs.ubi.compare(rhs.ubi)<0);
}


int main(){
    vector<Registro> vectRegistro;
    string filename;
    ifstream ifs;
    // 1. Solicite el nombre del archivo de entrada (Ej. canal.txt) y lo abra, almacenando los datos en un vector.
    cout << "Ingrese el nombre del archivo .txt: " << endl;
    getline(cin,filename);
    ifs.open(filename);
    Registro reg;
    while(ifs >> reg.fecha >> reg.hora >> reg.entrada >> reg.ubi){
		reg.sububi = reg.ubi.substr(0,2);
        reg.fechaInt = ftoi(reg.fecha);
        vectRegistro.push_back(reg);
    }
    ifs.close();
    // 2. Ordene la información por UBI + Fecha (primero por UBI, al haber empate ordenar por fecha).

	sort(vectRegistro.begin(),vectRegistro.end(), acompare);
    // 3. Solicite al usuario la serie a buscar (los primeros tres caracteres de el UBI).
	string serie;
	getline(cin,serie);
	// Busqueda Binaria
	// int pos = buscaBinaria();

	//Usuario: V2N
	// Programa si (V2N es parte de UBI)

	
    // 4. Despliegue todas las entradas al canal de los buques de esas series en forma ordenada UBI+Fecha.
    

	// Solo de los ingresados por el usuario?
    for(auto it: vectRegistro){
        cout << "-----" << endl;
        cout << "Fecha: " << it.fecha << endl;
        cout << "Hora: " << it.hora << endl;
        cout << "Entrada: " << it.entrada << endl;
        cout << "Ubi: " << it.ubi << endl;
		cout << "Substr" << it.sububi << endl;
    }
}
