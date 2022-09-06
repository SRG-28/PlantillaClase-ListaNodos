#pragma once
#include<iostream>
#include<sstream>
using namespace std;

//Plantilla de clase

template<class T>
class Nodo {
private:
	T * objetoPtr;	//Puntero a un objeto dinamico  // En lugar del puntero persona pongo un puntero para cualquier clase
	Nodo* sig;      //Enlace hacia otro posible Nodo
public:
	Nodo(T*, Nodo*); //Constructor de nodo(puntero de lo que va a cargar, puntero al otro nodo)
	virtual ~Nodo(); //Destructor
	T* getObjetoPtr(); //Devuelve el objeto del nodo
	Nodo* getSiguiente(); //Devuelve el enlace al siguiente
	void setObjetoPtr(T*); //Establece el objeto en el nodo
	void setSiguiente(Nodo*); //Establece el siguiente nodo 
};

//------------Definicion de los metodos de la clase Nodo----------------------------------
template<class T>
Nodo<T>::Nodo(T* ptr, Nodo<T>* nod):
			objetoPtr(ptr), sig(nod){
}

template<class T>
Nodo<T>::~Nodo() {
	delete objetoPtr;
}

template<class T>
T* Nodo<T>::getObjetoPtr() {
	return objetoPtr;
}

template<class T>
Nodo<T>* Nodo<T>::getSiguiente() {
	return sig;
}

template<class T>
void Nodo<T>::setObjetoPtr(T* ptr) {
	objetoPtr = ptr;
}

template<class T>
void Nodo<T>::setSiguiente(Nodo<T>* nod) {
	sig = nod;
}


//---------------LISTA--------------------
//Plantilla de clase

template<class T>
class Lista {   //Lista o contenedor generico (con nodos)
private:
	Nodo<T>* ppio; //Puntero externo al inicio de la lista
public:
	Lista();
	virtual ~Lista();
	void ingresarDePrimero(T*); 
	void ingresarDeUltimo(T*);
	T* retornaElemento(int lug);
	string toString();
	bool eliminaPrimero(); //si esta vacio retorna false
	bool eliminaElemento(int lug); // si ese lugar existe  entonces lo elimina y retorna true,
		//si el lugar no exite retorna false

};

//-----------Definicion de los metodos de la lista generica-------------------
//Metodos de la plantilla de clase

template<class T>
Lista<T>::Lista() {
	ppio = NULL;
}

template<class T>
Lista<T>::~Lista() {
	// Elimina a todos los obj dinamicos y a sus nodos TAREA
}

template<class T>
void Lista<T>::ingresarDePrimero(T* ptr) {
	ppio = new Nodo <T>(ptr, ppio);
}

template<class T>
void Lista<T>::ingresarDeUltimo(T* ptr) {
	Nodo<T>* p = ppio; //p es un puntero externo...  
	if (p == NULL) { //Esto quiere decir que la lista esta vacia
		ingresarDePrimero(ptr);
	}
	else { //el else me enviara al final de la  lista...
		Nodo<T>* nuevo = new Nodo<T>(ptr, NULL);
		while (p->getSiguiente() != NULL) {
			p = p->getSiguiente();
		}
		p->setSiguiente(nuevo); //Aqui lo ingreso al final
	}
}

template<class T>
T* Lista<T>::retornaElemento(int lug) {
	int cont = 1;
	Nodo<T>* p = ppio; //p es el que recorre la lista y nunca de ppio
	while (p != NULL && cont < lug) {
		p = p->getSiguiente();
		cont++;
	}
	if (cont == lug) {
		return p->getObjetoPtr();
	}
	return NULL;
}

template<class T>
string Lista<T>::toString() {
	Nodo<T>* p = ppio;
	int cont = 1;
	stringstream s;
	s << "-----------LISTADO----------" << endl;
	if (p == NULL) {
		s << "No hay elementos en la lista" << endl;
	}
	else {
		while (p != NULL) {
			s << "No." << cont << "-->" << *(p->getObjetoPtr()) << endl;
			p = p->getSiguiente();
			cont++;
 		}
	}
	s << "------------------------------------------------" << endl;
	return s.str();
}

template<class T>
bool Lista<T>::eliminaPrimero() {
	//TAREA
}

template<class T>
bool Lista<T>::eliminaElemento(int lug) {
	//TAREA
}
