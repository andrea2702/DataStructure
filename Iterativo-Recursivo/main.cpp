/* 
Realiza la suma de los números desde 1 a n de forma iterativa, recursiva y directa.
Autor: Andrea Marisol Salcedo Vázquez
Creado: 15/08/2021
Modificado: 17/08/2021
*/

#include <iostream>
using namespace std;

//Suma los numeros de 1 a n mediante un for
//Complejidad: O(n)
long long sumaIterativa(long long n){
  long long acum=0;
  for(int i=1;i<=n;i++){
    acum+=i;
  }
  return acum;
}

//Suma los numeros de 1 a n llamandose a sí misma n veces
//Complejidad: O(n)
long long sumaRecursiva(long long n){
  if(n<=1){
    return n;
  }
  return n + sumaRecursiva(n-1);
}

//Suma de los numeros de 1 a n mediante una formula matematica
//Complejidad: O(1)
long long sumaDirecta(long long n){
  return (n*(n+1))/2;
}

//Funcion main donde se llaman las otras funciones y se imprimen los resultados
int main() {
  long long n, cant;
  cin>>cant;
  for(int i=1;i<=cant;i++){
    cin>>n;
    cout << sumaIterativa(n)<<" "<< sumaRecursiva(n)<<" "<<sumaDirecta(n)<<endl;
  }
}