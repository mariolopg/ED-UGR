#include <iostream>
#include <string>
#include <guiatlf.h>
#include <fstream>

using namespace std;

int main(){
Guia_Tlf g;

	fstream ifile1, ifile2;
    ifile1.open("data/guia.txt");
	ifile2.open("data/guia2.txt");
    istream *is = &ifile1;

	cout<<"Introduce una guia"<<endl;
	*is>>g;
	cout << endl;
	//cout<<"La guia insertada "<<g<<endl;
	cin.clear();
	// cout<<"Dime un nombre sobre el que quieres obtener el telefono"<<endl;
	string n;
	/* while (getline(cin,n)){
		cout<<"Buscando "<<n<<"...."<<endl;
		string tlf = g.gettelefono(n);
		if (tlf==""){
				cout<<"No existe ese nombre en la guia"<<endl;
		}
		else 
			cout<<"El telefono es "<<tlf<<endl;
		cout<<"Dime un nombre sobre el que quieres obtener el telefono"<<endl;
	}	
	cin.clear();
	cout<<"Dime el nombre que quieres borrar"<<endl;
	
	while (getline(cin,n)){
		g.borrar(n);
		cout<<"Dime el nombre que quieres borrar"<<endl;
	}
	
	cout<<"Dime el nombre que quieres borrar"<<endl;
	
	while (getline(cin,n)){
		g.borrar(n);
		cout<<"Ahora la guia es:"<<endl;
		cout<<g<<endl;
		cout<<"Dime el nombre que quieres borrar"<<endl;
	}
	*/

	cin.clear();
	Guia_Tlf otraguia;
	cout<<"Introduce otra guia"<<endl;

	is = &ifile2;
	*is>>otraguia; 
	cin.clear();
	Guia_Tlf un = g+otraguia;
	Guia_Tlf dif = g-otraguia;

	cout<<"La union de las dos guias: "<<endl <<un<<endl;
	
	cout<<"La diferencia de las dos guias:"<<endl <<dif<<endl;

cout << "**************************************" << endl;

string numero;
cout << "Introduce un numero de tlf ";
cin >> numero;

cout << "El contacto que tiene el numero " << numero << " se llama " << g.getNombre(numero) << endl;

cout << "**************************************" << endl;

cout << "Introduce un nombre: " << flush;
string nombre;
cin >> nombre;
getline(cin, nombre);

cout << "El numero de contactos con el mismo nombre es " << g.numeroNombresIguales(nombre, otraguia) << endl;

cout << "**************************************" << endl;

cout << "Introduce un nombre: " << flush;
cin.clear();
getline(cin, nombre);

Guia_Tlf guia_nombres = g.Buscar_contactos_por_debajo_nombre(nombre);

cout << "La nueva guia es: " << guia_nombres << endl;

cout << "**************************************" << endl;

char letra;
cout << "Introduce una letra ";
cin >> letra;

Guia_Tlf guia_letra = g.Buscar_contactos_por_letra(letra);

cout << "Los contactos que empiezan por la letra " << letra << " son " << guia_letra << endl;
 
}
