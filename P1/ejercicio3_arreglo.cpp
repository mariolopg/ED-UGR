#include <iostream>
#include <chrono>    // Recursos para medir tiempos
#include <cstdlib>  // Para generación de números pseudoaleatorios

using namespace std;

int operacion(int *v, int n, int x, int inf, int sup) {
  int med;
  bool enc=false;
  while ((inf<sup) && (!enc)) {
    med = (inf+sup)/2;
    if (v[med]==x)
      enc = true;
    else if (v[med] < x)
      inf = med+1;
    else
      sup = med-1;
  }
  if (enc)
    return med;
  else
    return -1;
}

void sintaxis()
{
  cerr << "Sintaxis:" << endl;
  cerr << "  TAM: Tamaño del vector (>0)" << endl;
  cerr << "Se genera un vector de tamaño TAM con elementos aleatorios" << endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
  // Lectura de parámetros
  if (argc!=2)
    sintaxis();
  int tam=atoi(argv[1]);     // Tamaño del vector
  if (tam<=0)
    sintaxis();

  // Generación del vector aleatorio
  int *v=new int[tam];       // Reserva de memoria
  for (int i=0; i<tam; i++)  // Recorrer vector ordenandolo
    v[i] = i;

    auto start = std::chrono::system_clock::now();

    // Algoritmo a evaluar
    operacion(v,tam,tam+1,0,tam-1);

    auto end = std::chrono::system_clock::now();

    std::chrono::duration<float,std::nano> duration = end - start;

    // Mostramos resultados
    cout << tam << "\t" << duration.count() << endl;

  delete [] v;     // Liberamos memoria dinámica
}
