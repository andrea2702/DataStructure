#include <iostream>

using namespace std;

#include "BST.h"

int main(){
    BST miArbol, miArbol3;
    if(miArbol==miArbol3){
        cout << "Son iguales" << endl;
    }else{
        cout << "Son diferentes" << endl;
    }
    if(miArbol3==miArbol){
        cout << "Son iguales" << endl;
    }else{
        cout << "Son diferentes" << endl;
    }
    cout << "-------------------" << endl;
    miArbol.print(4);
    miArbol3.print(4);
    cout << miArbol3.maxWidth() << endl;
    cout << miArbol.maxWidth() << endl;
    cout << "-------------------" << endl;
    cout << "La altura del arbol es: " << endl;
    cout << miArbol.height() << endl;
    cout << "-------------------" << endl;
    cout << "El dato 12 esta en el nivel: " << miArbol.whatLevelAmI(12) << endl;
    cout << "Los ancestros del 12 son: "; 
    miArbol.ancestors(12);
    cout << "-------------------" << endl;
    miArbol.add(22);
    cout << "La altura del arbol es: " << endl;
    cout << miArbol.height() << endl;
    miArbol.print(4);
    cout << miArbol.maxWidth() << endl;
    cout << "-------------------" << endl; 
    miArbol.add(10);
    miArbol.add(8);
    miArbol.add(4);
    miArbol.add(14);
    miArbol.add(7);
    miArbol.add(30);
    miArbol.add(23);
    miArbol.add(17);
    miArbol.add(27);
    miArbol.add(9);
    miArbol.add(100);
    miArbol.print(1);
    miArbol.print(2);
    miArbol.print(3);
    miArbol.print(4);
    if(miArbol==miArbol3){
        cout << "Son iguales" << endl;
    }else{
        cout << "Son diferentes" << endl;
    }
    if(miArbol3==miArbol){
        cout << "Son iguales" << endl;
    }else{
        cout << "Son diferentes" << endl;
    }
    cout << "-------------------" << endl;
    cout << miArbol.nearestRelative(10,30)<<endl;
    cout << miArbol.nearestRelative(30,10)<<endl;
    cout << miArbol.nearestRelative(27,7)<<endl;
    cout << miArbol.nearestRelative(7,4)<<endl;
    cout << miArbol.nearestRelative(4,9)<<endl;
    cout << miArbol.nearestRelative(27,23)<<endl;
    cout << "-------------------" << endl;
    cout << miArbol.maxWidth() << endl;
    cout << "-------------------" << endl;
    cout << "El dato 12 esta en el nivel: " << miArbol.whatLevelAmI(12) << endl;
    cout << "Los ancestros del 12 son: ";
    miArbol.ancestors(12);
    cout << "El dato 27 esta en el nivel: " << miArbol.whatLevelAmI(27) << endl;
    cout << "Los ancestros del 27 son: ";
    miArbol.ancestors(27);
    cout << "El dato 22 esta en el nivel: " << miArbol.whatLevelAmI(22) << endl;
    cout << "Los ancestros del 22 son: ";
    miArbol.ancestors(22);
    cout << "El dato 9 esta en el nivel: " << miArbol.whatLevelAmI(9) << endl;
    cout << "Los ancestros del 9 son: ";
    miArbol.ancestors(9);
    cout << "-------------------" << endl;
    cout << "La altura del arbol es: " << endl;
    cout << miArbol.height() << endl;
    cout << "-------------------" << endl;
    cout << "El size de mi arbol es: " << miArbol.size() << endl;
    cout << "-------------------" << endl;
    if(miArbol.search(9)){
        cout << "Sí encontré al 9" << endl;
    }
    else{
        cout << "No encontré el 9" << endl;
    }
    if(miArbol.search(22)){
        cout << "Sí encontré al 22" << endl;
    }
    else{
        cout << "No encontré el 22" << endl;
    }
    if(miArbol.search(90)){
        cout << "Sí encontré al 90" << endl;
    }
    else{
        cout << "No encontré el 90" << endl;
    }
    if(miArbol.search(8)){
        cout << "Sí encontré al 8" << endl;
    }
    else{
        cout << "No encontré el 8" << endl;
    }
    cout << "-------------------" << endl;
    miArbol.remove(7);
    miArbol.print(1);
    miArbol.print(2);
    miArbol.print(3);
    cout << "-------------------" << endl;
    miArbol.remove(22);
    miArbol.print(1);
    miArbol.print(2);
    miArbol.print(3);
    cout << "-------------------" << endl;
    cout << "El size de mi arbol es: " << miArbol.size() << endl;
    cout << "-------------------" << endl;
    cout << "La altura del arbol es: " << endl;
    cout << miArbol.height() << endl;
    cout << "-------------------" << endl;
    BST miArbol2(miArbol);
    miArbol.print(4);
    miArbol2.print(4);
    cout << "-------------------" << endl;
    if(miArbol==miArbol2){
        cout << "Son iguales" << endl;
    }else{
        cout << "Son diferentes" << endl;
    }
    if(miArbol2==miArbol){
        cout << "Son iguales" << endl;
    }else{
        cout << "Son diferentes" << endl;
    }
    cout << "-------------------" << endl;
    miArbol2.add(3);
    miArbol.print(4);
    miArbol2.print(4);
    cout << "-------------------" << endl;
    if(miArbol==miArbol2){
        cout << "Son iguales" << endl;
    }else{
        cout << "Son diferentes" << endl;
    }
    if(miArbol2==miArbol){
        cout << "Son iguales" << endl;
    }else{
        cout << "Son diferentes" << endl;
    }
    cout << "-------------------" << endl;
    BST miArbol4, miArbol5;
    cout << miArbol4.maxWidth() << endl;
    miArbol4.add(12);
    miArbol4.add(5);
    miArbol4.add(15);
    miArbol4.add(20);
    miArbol5.add(12);
    miArbol5.add(5);
    miArbol5.add(20);
    miArbol5.add(15);
    if(miArbol4==miArbol5){
        cout << "Son iguales" << endl;
    }else{
        cout << "Son diferentes" << endl;
    }
    cout << "-------------------" << endl;
    cout << miArbol4.maxWidth() << endl;
    cout << miArbol4.nearestRelative(15,20) << endl;
    cout << miArbol5.nearestRelative(15,5) << endl;
}