#pragma once
#include<iostream>
#include<string>
using namespace std;

class Persona {
private:
	string cedula;
	string nombre;
	int edad;
public:
	Persona();
	Persona(string, string, int);
	virtual~Persona();
	friend ostream& operator << (ostream&, const Persona&);
};

//-----------Definicion---------------
Persona::Persona() {
	cedula = "";
	nombre = "";
	edad = 0;

}
Persona::Persona(string ced, string nom, int ed) {
	cedula = ced;
	nombre = nom;
	edad = ed;

}
Persona::~Persona() {

}
ostream& operator << (ostream& out, const Persona& p) { //Sobrecarga para darle forma a la salida
	return out << "\nCedula: " << p.cedula << "\nNombre:  " << p.nombre
				<< "\nEdad:   " << p.edad << endl;

}