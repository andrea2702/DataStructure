// Andrea Marisol Salcedo Vázquez
// 01/11/2021
// Clase priority_queue con metodos para insertar un dato, eliminar y obtener el dato más grande
// saber el tamaño y si está vacía, asi como imprimirla.

class priority_queue{
    public:
        priority_queue(); //Constructor sin parametros
        void push (int data); //Meter a la PQ
        void pop(); //Sacar de la priority queue
        int top(); //Observa el dato con mayor prioridad
        bool empty(); //Regresa si la lista está vacía
        int size(); //Regresa la cantidad de datos
        void print(); //Imprime la queue
    private:
        vector<int> datos;
};

//Inicializamos el vector con un número en la posición 0
//pues esa posición no se usa
//Complejidad: O(1)
priority_queue::priority_queue(){
    datos.push_back(-9999999);
}

//Mete a dato en la priority_queue
//Complejidad: O(log n)
void priority_queue::push(int data){ 
    datos.push_back(data); //Lo agrega al final 
    int pos = datos.size()-1;
    bool sigue = true;
    while(pos > 1 && sigue){
        int posPadre = pos/2;
        //Compara el dato agregado con su padre
        //Si es mayor los cambia de lugar y vuelve a comparar
        //con su nuevo padre
        if(datos[pos] > datos[posPadre]){
            int temp = datos[pos];
            datos[pos] = datos[posPadre];
            datos[posPadre] = temp;
            pos = posPadre;
        }
        //Si es menor entonces se rompe el ciclo
        else{
            sigue = false;
        }
    }
}

//Elimina el dato más grande, o sea la raíz
//Complejidad: O(log2 n)
void priority_queue::pop(){
    datos[1] = datos[datos.size()-1]; //Pone el valor del ultimo dato en la primera posición
    datos.pop_back(); //Elimina el ultimo dato
    //Se ejecuta siempre y cuando hayan dos datos en la queue
    if(datos.size()>1){
        int pos = 1;
        bool sigue = true;
        while(pos*2 < datos.size() && sigue){ //Reacomodando la posición pos
            //Detectar la posición del hijo mayor
            int posHijoMayor = pos*2;
            //Checa si hay segundo hijo
            if(posHijoMayor+1 < datos.size()){
                //Checa cual hijo es mayor
                if(datos[posHijoMayor]<datos[posHijoMayor+1]){
                    posHijoMayor++;
                }
            }
            // Comparar al dato con el hijoMayor
            //Si el padre es menor entonces se intercambia
            if(datos[pos] < datos[posHijoMayor]){
                int temp = datos[posHijoMayor];
                datos[posHijoMayor] = datos[pos];
                datos[pos] = temp;
                pos = posHijoMayor;
            //Si no termina el ciclo
            }else{
                sigue = false;
            }
        }
    }
}

//Regresa el elemento más grande en la queue, o sea el primer elemento del vector
//Complejidad: O(1)
int priority_queue::top(){
    return datos[1];
}

//Regresa si la queue está vacía, es decir, si solo está oucupada la posición 0
//Complejidad: O(1)
bool priority_queue::empty(){
    return datos.size() == 1;
}

//Regresa el tamaño de la queue
//Se le resta uno porque la posición 0 no se usa
//Complejidad: O(1)
int priority_queue::size(){
    return datos.size()-1;
}

//Imprime la queue
//Complejidad: O(n)
void priority_queue::print(){
    for(int i = 1; i < datos.size(); i++){
        cout << datos[i] << " ";
    }
    cout << endl;
}