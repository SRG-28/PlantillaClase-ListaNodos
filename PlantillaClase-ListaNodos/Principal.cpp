#include"Lista.h"
#include"Persona.h"

int main() {
	//variables de entorno...
	int num;
	char letra;
	cout << "----Creando un contenedor tipo Lista de enteros------" << endl;
	cout << "-----------------------------------------------------" << endl;
	Lista<int> Conten1;
	cout << "----Ingresar valores en el contenedor----" << endl;
	Conten1.ingresarDeUltimo(new int(5));
	Conten1.ingresarDeUltimo(new int(6)); 
	Conten1.ingresarDeUltimo(new int(7));
	Conten1.ingresarDeUltimo(new int(8));
	Conten1.ingresarDeUltimo(new int(9));
	cout << "----Imprimiendo la lista del contenedor Conten1----" << endl;
	cout << Conten1.toString() << endl;

	cout << "---------------------------------------------------" << endl;
	cout << "----Creando un contenedor tipo Lista de Personas------" << endl;
	cout << "-----------------------------------------------------" << endl;
	Lista<Persona> Conten2;
	cout << "----Ingresar valores en el contenedor----" << endl;
	Conten2.ingresarDeUltimo(new Persona("12345678","Juan",12));
	Conten2.ingresarDeUltimo(new Persona("234568798","Ale",45));
	Conten2.ingresarDeUltimo(new Persona("34456578","Ambar", 20));
	Conten2.ingresarDeUltimo(new Persona("45353676","Luis", 34));
	Conten2.ingresarDeUltimo(new Persona("56790234","Tobi", 56));
	cout << "----Imprimiendo la lista del contenedor Conten2----" << endl;
	cout << Conten2.toString() << endl;
	cout << endl << endl << endl << "Digite el numero de la persona a eliminar";
	cin >> num;
	cout << "Realmente quieres eliminar a " << *(Conten2.retornaElemento(num)) << endl;
	cout << "Responda s/n... ";
	cin >> letra;
	if (letra == 's')
		//Conten2.eliminaElemento(num); HACER ESTO
	cout << "----Imprimiendo la lista del contenedor Conten2 de nuevo----" << endl;
	cout << Conten2.toString() << endl;


	system("pause");
	return 0;
}