/*
Actividad Integral estructura de datos lineales

Autores: 
	Andrea Salcedo Vasquez- A00831510
	Ian Javier Duran Román - A00829799
	Fernando Cabrera - A00831380
Fecha de Creación: 04/10/21
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
#include "LinkedList.h"

struct Registro{
    string fecha;
    string hora;
    char entrada;
    string ubi;
    int fechaInt;
    bool operator>(const Registro &otro) const{ //O(1)
        if(this->ubi == otro.ubi){
            return this->fechaInt > otro.fechaInt;
        }
        return(this->ubi.compare(otro.ubi)>0);
    }
	string getSerie(){ //O(n)
		return ubi.substr(0,3);
	}
	string getMes(){//O(n)
		string mes = "";
		int i=fecha.find('-');
		i++;
		while (fecha[i] != '-'){  //O(n)
			mes += fecha[i];
			i++;
		}
		return mes;
	}
	string getYear(){//O(n)
		string year = "";
		int i=fecha.find('-');
		i++;
		while (fecha[i] != '-'){  //O(n)
			i++;
		}
		year += fecha[++i];
		year += fecha[++i];
		return year;
	}
	bool operator==(string serie){  //O(1)
		return this->getSerie()==serie;
	}
    friend ostream& operator<<(ostream &os, const Registro &r);
};

/* 
Funcion implementada para poder trabajar con fstream
Complejidad de Ejecución: O(1)
*/
ostream& operator<<(ostream &os, const Registro &r){ //O(1)
    os << r.ubi << " " << r.fecha << " " << r.hora << " " << r.entrada << endl;
    return os;
}

/* 
Funcion que devuelve un entero en función al mes
Variables de entrada: string del mes
Variables de Retorno: entero
Complejidad de Ejecución: O(1)
*/
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

/* 
Funcion que devuelve una cadena del mes en función a un entero
Variables de entrada: entero
Variables de Retorno: string del mes
Complejidad de Ejecución: O(1)
*/
string intToMes(int m){
	if (m==1){
		return "jan";
	}
	if (m==2){
		return "feb";
	}
	if (m==3){
		return "mar";
	}
	if (m==4){
		return "apr";
	}
	if (m==5){
		return "may";
	}
	if (m==6){
		return "jun";
	}
	if (m==7){
		return "jul";
	}
	if (m==8){
		return "aug";
	}
	if (m==9){
		return "sep";
	}
	if (m==10){
		return "oct";
	}
	if (m==11){
		return "nov";
	}
	return "dec";
}

/*
Funcion que devuelve un entero en función a la fecha
Variables de entrada: string de la fecha actual en formato dd-mm-yy
Variables de Retorno: entero calculado
Complejidad de Ejecución: O(n)
*/
int ftoi(string fecha){
	int salida= 0;
	int aux = 0;
	int i = 0;
	//O(n)
	while (fecha[i] != '-'){
		aux*=10;
		aux+= (fecha[i] - '0'); // '5' -'0' == 5 como entero (53-48)
		i++;
	}
	salida += aux;
	i++;
	string mes = "";
	while (fecha[i] != '-'){  //O(n)
		mes += fecha[i];
		i++;
	}
	salida += (mestoi(mes)*100);
	aux = 0;
	i++;
	while (i < fecha.length()){  ////O(n)
		aux*=10;
		aux+= (fecha[i] - '0'); // '5' -'0' == 5 como entero (53-48)
		i++;	
	}
	salida += (aux*10000);
	return salida;
}




int main(){
    LinkedList<Registro> registroBuquesM, registroBuquesR;
    string filename;
    ifstream ifs;
    

    cout << "Ingrese nombre del archivo .txt" << endl;
    getline(cin, filename);
    ifs.open(filename);
    Registro reg;
    while(ifs >> reg.fecha >> reg.hora >> reg.entrada >> reg.ubi){
        reg.fechaInt = ftoi(reg.fecha);
        if(reg.entrada=='M'){
            registroBuquesM.addFirst(reg);
        }
        else{
            registroBuquesR.addFirst(reg);
        }
    }


    ifs.close();
    

	vector<Registro> vectBuquesM;
	vector<Registro> vectBuquesR;
	cout << "Ordenando los registros... Por favor espere." << endl;
    registroBuquesM.sort();
    registroBuquesR.sort();

	//Genera un archivo de todos los registros de buques con entrada = R
    cout << "Especifique el nombre de archivo para los buques del MAR MEDITERRANEO" << endl;
    getline(cin,filename);
	registroBuquesM.writeData(filename);
	
	//Genera un archivo de todos los registros de buques con entrada = R
    cout << "Especifique el nombre de archivo para los buques del MAR ROJO" << endl;
    getline(cin,filename);
	registroBuquesR.writeData(filename);

	// Realiza la b
	string serie;
	cout<<"Indique la serie a Buscar:"<<endl;
	getline(cin,serie);
	int posM = registroBuquesM.find(serie);
	int posR = registroBuquesR.find(serie);


	if(posM==-1 && posR==-1) // El ubi no existe ya que no se hallaron posiciones en ningun vector
		cout<<"El UBI no existe en ningun registro"<<endl;
	else{

		vectBuquesM = registroBuquesM.toVector();
		vectBuquesR = registroBuquesR.toVector();

		map<int, pair<int,int> > contador;
		string year;
		if(posM!=-1){ //Si existe la serie en el primer vector
			while(vectBuquesM[posM].getSerie()==serie){ //Mientras hayan elementos con la misma serie
				Registro curr = vectBuquesM[posM];
				year = curr.getYear();
				int mesActual = mestoi(curr.getMes());
				contador[mesActual].first++;
				posM++;
			}
		}
		if(posR!=-1){ //Si existe la serie en el primer vector
			while(vectBuquesR[posR].getSerie()==serie){ //Mientras hayan elementos con la misma serie
				Registro curr = vectBuquesR[posR];
				year = curr.getYear();
				int mesActual = mestoi(curr.getMes());
				contador[mesActual].second++;
				posR++;
			}
		}

		// Se itera el mapa y se imprimen los datos obtenidos
		for(auto it: contador){
			cout << intToMes(it.first) << " " << year << " " << it.second.first << " " << it.second.second << endl;
		}
	}

}

