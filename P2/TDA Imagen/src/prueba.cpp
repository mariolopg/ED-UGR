#include <iostream>
#include <string>
using namespace std;

int main (){
    const char* nombre = "nombre";
    string nombreFinal = nombre;
    int numero = 200;
  int centena = numero / 100;
  int decena = (numero - (centena * 100)) / 10;
  int unidad = (numero - (centena * 100 + decena * 10));

  nombreFinal = nombreFinal + to_string(centena) + to_string(decena) + to_string(unidad);

  char *nFinal =  c_str();

  cout << nFinal << endl;
}

// run data/cameraman.pgm result/cameraman_neg.pgm result/morphing/c