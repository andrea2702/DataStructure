// Implementación de las funciones para un árbol de busqueda binaria
// Matrícula: A00831510
// Nombre:Andrea Marisol Salcedo Vázquez

#include "NodeT.h"
#include <queue>
#include <stack>

class BST{
	public:
		BST();
		~BST();
		bool search(int data);
		void add(int data);
		void remove(int data);
		void print(int tipo);
		int size();
		int height();
		void ancestors(int data);
		int whatLevelAmI(int data);
		BST(const BST &otro); //Recorrido en pre orden 
		int maxWidth();
		int nearestRelative(int data1, int data2);
		bool operator==(const BST &otro); //Simulación pre orden 
	private:
		NodeT *root;
		int howManyChildren(NodeT *r);
		int pred(NodeT *r);
		int succ(NodeT *r);
		void preOrden(NodeT *r);
		void inOrden(NodeT *r);
		void postOrden(NodeT *r);
		void destuye_Helper(NodeT *r);
		int size_Helper(NodeT *r);
		int height_Helper(NodeT *r);
		NodeT* constructor_Helper(NodeT *r);
		bool comparative_Helper(NodeT *r1, NodeT *r2);
};

BST::BST(){
	root = nullptr;
}

BST::~BST(){
	destuye_Helper(root);
}

void BST::destuye_Helper(NodeT *r){
	if (r != nullptr){
		destuye_Helper(r->getLeft());
		destuye_Helper(r->getRight());
		delete r;
	}
}

//Complejidad: O(1)
int BST::howManyChildren(NodeT *r){
	int cont = 0;
	if (r->getLeft() != nullptr){
		cont++;
	}
	if (r->getRight() != nullptr){
		cont++;
	}
	return cont;
}

// Predecesor solo se manda ejecutar con nodos que tienen 2 hijos
// 			==> es el mayor de los menores
//Complejidad: O(height)
int BST::pred(NodeT *r){
	NodeT *curr = r->getLeft();
	while (curr->getRight() != nullptr){
		curr = curr->getRight();
	}
	return curr->getData();
}

// Sucesor solo se manda ejecutar con nodos que tienen 2 hijos.
//       ==> es el menor de los mayores
//Complejidad: O(height)
int BST::succ(NodeT *r){
	NodeT *curr = r->getRight();
	while (curr->getLeft() != nullptr){
		curr = curr->getLeft();
	}
	return curr->getData();
}

//Complejidad: O(height)
bool BST::search(int data){
	NodeT *curr = root;
	while (curr != nullptr){
		if (curr->getData() == data){ // Si encontré el dato
			return true;
		}
		// if (curr->getData() > data){
		// 	curr = curr->getLeft();
		// }
		// else{
		// 	curr = curr->getRight();
		// }
		curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
	}
	return false;  // si root es nullptr o que el dato no esta.
}

//Complejidad: O(height)
void BST::add(int data){
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

//Complejidad: O(height)
void BST::remove(int data){
	// localizar al dato que se quiere borrar
	// si se esta el dato, checar cuantos hijos tiene, y dependiendo de esto procedemos a borra
	NodeT *curr = root;
	NodeT *parent = nullptr;
	// cicla hasta que no está o lo localiza
	while (curr != nullptr && curr->getData() != data){ 
		parent = curr;
		curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
	}
	if (curr == nullptr){
		return; // El dato no existe
	}
	int cantHijos = howManyChildren(curr);
	switch (cantHijos){
		case 0: if (parent == nullptr){
					root = nullptr;
				}
				else{
					if (parent->getData() > data){
						parent->setLeft(nullptr);
					}
					else{
						parent->setRight(nullptr);
					}
				}
				delete curr;
				break;
		case 1: if (parent == nullptr){		// El que quiero borrar es root y tiene 1 hijp
					if (curr->getLeft() != nullptr){
						root = curr->getLeft();
					}
					else{
						root = curr->getRight();
					}
				}
				else{
					if (parent->getData() > data){
						// El dato que quiero borrar es hijo izq de parent
						if (curr->getLeft() != nullptr){
							// El único hijo del que quiero borrar esta a la izq
							parent->setLeft(curr->getLeft());
						}
						else{
							// El único hijo del que quiero borrar esta a la der
							parent->setLeft(curr->getRight());
						}
					}
					else{
						// El dato que quiero borrar es hijo der de parent
						if (curr->getLeft() != nullptr){
							// El único hijo del que quiero borrar esta a la izq
							parent->setRight(curr->getLeft());
						}
						else{
							// El único hijo del que quiero borrar esta a la der
							parent->setRight(curr->getRight());
						}
					}
				}
				delete curr;
				break;
		case 2:	int sucesor = succ(curr);
				remove(sucesor);
				curr->setData(sucesor);
				break;
	}
}

// Tipo
// 1 : Preorden
// 2 : Inorden
// 3 : Postorden
// 4 : levelByLevel
//Complejidad: O(n)
void BST::print(int tipo){
	switch (tipo){
		case 1 : 
				preOrden(root);
				break;
		case 2 : 
				inOrden(root);
				break;
		case 3 : 
				postOrden(root);
				break;
		case 4:
				//Si la raíz es diferente de nullptr entonces va agregando los nodos a una queue
				//nivel por nivel y los va imprimiendo, del nodo que imprime agrega sus hijos a 
				//el final de la queue y va eliminando el número que ya imprimió. El ciclo termina
				//cuando la queue esté vacía, eso indica que ya imprimió el último.
				//Complejidad: O(n)
				if (root != nullptr){
				queue<NodeT*> datos;
				NodeT* curr = root;
				datos.push(curr);
				while(!datos.empty()){
					cout << datos.front()->getData() << " " ;
					if(datos.front() -> getLeft() != nullptr){
						datos.push(datos.front() -> getLeft());
					}
					if(datos.front() -> getRight() != nullptr){
						datos.push(datos.front() -> getRight());
					}
					datos.pop();
				}
			}
				break;
	}
	cout << endl;
}

//Regresa la altura del árbol con ayuda de la función height_Helper() 
//si la raíz es diferente de nullptr
// Complejidad: O(n)
int BST::height(){
	return height_Helper(root);
}

//Checa si la raíz es igual a nullptr para imprimir dato inexistente y salir
//Luego revisa si el primero es el dato para regresar sin ancestros
//Finalmente recorre el árbol hasta encontrar el dato o llegar a un nullptr
//y en el camino va guardando los datos en un stack, en caso de que no encontrara el dato 
//imprime que no existe, pero si está imprime el stack.
//Complejidad: O(height)
void BST::ancestors(int data){
    if(root == nullptr){
        cout << "DATO INEXISTENTE" << endl;
        return;
    }
	if(root->getData() == data){
		cout << "SIN ANCESTROS" << endl;
		return;
	}
	stack <int> ancestros;
	NodeT *curr = root;
    NodeT *parent = nullptr;
    bool datoEncontrado = false;
	while (curr != nullptr){
        if (curr->getData() == data){
            datoEncontrado = true;
            break;
        }
        parent = curr;
        ancestros.push(parent->getData());
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }
    if(!datoEncontrado){
        cout << "DATO INEXISTENTE" << endl;
        return;
    }
    while(!ancestros.empty()){
        cout << ancestros.top() << " ";
        ancestros.pop(); 
    }
	cout << endl;
}

//Recorre el árbol llevando la cuenta de en qué nivel está por el contador
//Si lo encuentra regresa el contador, si no lo encuentra regresa un -1
//Complejidad: O(height)
int BST::whatLevelAmI(int data){
    NodeT *curr = root;
    NodeT *parent = nullptr;
    int contador = 0;
	while (curr != nullptr){
        if (curr->getData() == data){
            return contador;
        }
        parent = curr;
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
        contador++;
    }
	return -1;
}

//Es una función recursiva que va recorriendo el árbol izquierda y derecha, cuando encuentra un nullptr regresa un 0
//porque quiere decir que ya no hay nodos, si es diferente de nullptr regresa 1 + el que haya tenido más altura del hijo izquierdo
//o el hijo derecho, de esta forma siempre se considerará la altura mayor
//Complejidad: O(n)
int BST::height_Helper(NodeT *r){
	if(r == nullptr){
		return 0;
	}
	int left = height_Helper(r -> getLeft());
	int right = height_Helper(r -> getRight());
	return 1 + ((left > right ) ? left : right);
}

//Complejidad: O(n)
void BST::preOrden(NodeT *r){
	if (r != nullptr){
		cout << r->getData() << " ";
		preOrden(r->getLeft());
		preOrden(r->getRight());
	}
}

//Complejidad: O(n)
void BST::inOrden(NodeT *r){
	if (r != nullptr){
		inOrden(r->getLeft());
		cout << r->getData() << " ";
		inOrden(r->getRight());
	}
}

//Complejidad: O(n)
void BST::postOrden(NodeT *r){
	if (r != nullptr){
		postOrden(r->getLeft());
		postOrden(r->getRight());
		cout << r->getData() << " ";
	}
}

//Complejidad: O(n)
int BST::size(){
	return size_Helper(root);
}

//Complejidad: O(n)
int BST::size_Helper(NodeT *r){
	if (r != nullptr){
		return 1 + size_Helper(r->getLeft()) + size_Helper(r->getRight());
	}
	else{
		return 0;
	}
}

//========================================== FUNCIONES DE TAREA ==============================================

//Apunta el root a nullptr y si el otro árbol no está vacío 
//llama a la función constructor_Helper que realiza un recorrido
//en pre orden y va añadiendo los nodos
//Complejidad: O(n)
BST::BST(const BST &otro){
	this->root = nullptr;
	if(otro.root != nullptr){
		root = constructor_Helper(otro.root);
	}
} //Recorrido en pre orden 

//Usa dos queue en donde va guardando los nodos por nivel
//en la primera queue va sacando y agregandolos a la segunda 
//mientras cuenta cuantos habia en el final, una vez que la
//queue está vacía entonces checa si el número que contó era mayor al
//guardado en max, en dicho caso lo cambia, en caso contrario, se conserva
//y luego recorré la segunda queue agregando los hijos de los nodos a la primera
//Complejidad: O(n)
int BST::maxWidth(){
	int max = 0;
	if(root!=nullptr){
		int cont=0;
		queue<NodeT*> nivel, padres;
		nivel.push(root);
		while(!nivel.empty()){
			padres.push(nivel.front());
			nivel.pop();
			cont++;
			if(nivel.empty()){
				if(cont > max){
					max = cont;
				}
				cont = 0;
				while(!padres.empty()){
					if(padres.front() -> getLeft() != nullptr){
						nivel.push(padres.front() -> getLeft());
					}
					if(padres.front() -> getRight() != nullptr){
						nivel.push(padres.front() -> getRight());
					}
					padres.pop();
				}
			}
		}
	}
	return max;
}

//Comienza a recorrer el árbol en busca de los datos, y va guardando el nodo en curr
//para moverse a la izquierda o derecha checa si el nodo es mayor o menor que ambos datos
//en caso de que sea mayor que uno y menor que otro el ciclo se rompe y regresa la data guardada 
//en el nodo padre, de igual forma, en caso de que el curr sea uno de los dos nodos ya no entra al ciclo 
//y regresa al padre
//Complejidad: O(height)
int BST::nearestRelative(int data1, int data2){
	NodeT *curr = root;
    NodeT *parent = nullptr;
	//En caso de que alguno de los datos pueda ser la raíz
	/*
	if(curr->getData()==data1 || curr->getData()==data2){
		cout << "NO EXISTE" << endl;
		return 0;
	}*/
	while (curr->getData() != data1 && curr->getData() != data2){
        parent = curr;
        if(curr->getData() > data1 && curr->getData() > data2 ){
			curr =  curr->getLeft();
		}
		else if(curr->getData() < data1 && curr->getData() < data2 ){
			curr =  curr->getRight();
		}else{
			break;
		}
    }
	return parent->getData();
}

//Hace uso de la funcion comparative_helper
//Complejidad: O(n)
bool BST::operator==(const BST &otro){
	return comparative_Helper(this->root, otro.root);
} //Simulación pre orden 

//Va recorriendo el árbol en el orden de pre orden solo que en lugar de
//imprimir los nodos va añadiendo la data en el nuevo árbol
//Complejidad: O(n)
NodeT* BST::constructor_Helper(NodeT *r){
	if (r != nullptr){
		NodeT* curr = new NodeT(r->getData());
		curr->setLeft(constructor_Helper(r->getLeft()));
		curr->setRight(constructor_Helper(r->getRight()));
		return curr;
	}
	return nullptr;
}

//Va recorriendo el árbol en preorden y en caso de que la data en ambos nodos sea diferente
//regresa un false, pero si llega a nullptr en ambos nodos y no a regresado ningún false
//va a regresar un true
//Complejidad: O(n)
bool BST::comparative_Helper(NodeT *r1, NodeT *r2){
	if (r1!= nullptr){
		if(r2!=nullptr){
			if(r1->getData() != r2->getData()){
				return false;
			}
			bool l = comparative_Helper(r1->getLeft(),r2->getLeft());
			bool d = comparative_Helper(r1->getRight(),r2->getRight());
			return (l && d);
		}
		return false;
	}
	if(r2!=nullptr){
		return false;
	}
	return true;
}








