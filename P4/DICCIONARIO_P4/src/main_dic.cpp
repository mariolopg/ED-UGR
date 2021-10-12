#include <iostream>
#include <list>
#include <string>
#include "diccionario.h"

using namespace std;

ostream & operator<<(ostream & os, const Diccionario<string,string> & D){
	  
	  Diccionario<string,string>::const_iterator it;
	  
	  for (it=D.cbegin(); it!=D.cend(); ++it){
	  
		    list<string>::const_iterator it_s;
		    
		    os<<endl<<(*it).clave<<endl<<" informacion asociada:"<<endl;
		    for (it_s=(*it).info_asoci.begin();it_s!=(*it).info_asoci.end();++it_s){
			      os<<(*it_s)<<endl;
		    }
		    os<<"**************************************"<<endl;
	  }
	  
	  return os;
}

int main(){

    Diccionario<string,string> D1;
    Diccionario<string,string> D2;

    string palabra, definicion;
    list<string> definicionesD1, definicionesD2;
    char continuar;

    cout << "Diccionario 1" << endl;

    cout << "Palabra: ";
    cin >> palabra;

    cout << "Definicion: ";
    cin >> definicion;

    definicionesD1.push_back(definicion);

    cout << "Desea continuar? [s/n]" << endl;
    cin >> continuar;

    while(continuar == 's'){

        cout << "Definicion: ";
        cin >> definicion;

        definicionesD1.push_back(definicion);

        cout << "Desea continuar? [s/n]" << endl;
        cin >> continuar;
    }


    

    D1.Insertar(palabra, definicionesD1);

    cout << "*****************************" << endl;

    cout << "Diccionario 2" << endl;

    cout << "Palabra: ";
    cin >> palabra;

    cout << "Definicion: ";
    cin >> definicion;

    definicionesD2.push_back(definicion);

    cout << "Desea continuar? [s/n]" << endl;
    cin >> continuar;

    while(continuar == 's'){

        cout << "Definicion: ";
        cin >> definicion;

        definicionesD2.push_back(definicion);

        cout << "Desea continuar? [s/n]" << endl;
        cin >> continuar;
    }

    D2.Insertar(palabra, definicionesD2);

    cout << "*****************************" << endl;
    cout << "Método comunes" << endl;

    Diccionario<string,string> D_comunes;
    D_comunes = D1.comunes(D2);
    cout << D_comunes << endl;

    cout << "*****************************" << endl;

    cout << "Método concatenar" << endl;
    
    D1.concatenar(D2);
    cout << D1 << endl;
    

}

