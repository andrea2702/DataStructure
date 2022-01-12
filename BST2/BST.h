/*
Actividad Integral de Árboles
Autores: 
	Andrea Salcedo Vasquez- A00831510
	Ian Javier Duran Román - A00829799
	Fernando Cabrera - A00831380
Fecha de Creación: 21/10/21
*/
#include "NodeT.h"

class BST{
	public:
		BST();
		~BST();

		void add(dataCS data); 
		void print(); //INORDENCONV

	private:
		NodeT *root;
		void inOrdenC(NodeT *r);
		void destuye_Helper(NodeT *r);
};


/* Constructor */
BST::BST(){
	root = nullptr;
}
/* Destructor */
//Complejidad: O(n)
BST::~BST(){
	destuye_Helper(root);
}

/* Funcion recursiva que destruye los nodos de un arbol
Entrada: Nodo de un arbol
Complejidad: O(n) */
void BST::destuye_Helper(NodeT *r){
	if (r != nullptr){
		destuye_Helper(r->getLeft());
		destuye_Helper(r->getRight());
		delete r;
	}
}

/* Funcion que añade un nuevo nodo a un arbol
Entrada: Datos
Complejidad: O(height) */
void BST::add(dataCS data){
	if (root == nullptr){
		root = new NodeT(data);
	}
	else{
		NodeT *curr = root;
		NodeT *parent = nullptr;
		while (curr != nullptr){
			if (curr->getData() == data){
				return;
			}
			parent = curr;
			curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
		}
		// if (parent->getData() > data){
		// 	parent->setLeft(new NodeT(data));
		// }
		// else{
		// 	parent->setRight(new NodeT(data));
		// }
		parent->getData() > data ? parent->setLeft(new NodeT(data)) : parent->setRight(new NodeT(data));
	}
}

/* Funcion que imprime los nodos de un arbol
Complejidad: O(n) */
void BST::print(){
	inOrdenC(root);
	cout << endl;
}



/* Funcion recursiva que imprime los nodos en orden descendente
Entrada: Datos
Complejidad: O(n) */
void BST::inOrdenC(NodeT *r){
	if (r != nullptr){
		inOrdenC(r->getRight());
		cout << r->getData();
		inOrdenC(r->getLeft());
	}
}