// Fichero: RGBaGris.cpp
// Calcula convierte una imagen en RGB (.ppm) a niveles de Gris (.pgm)
// Formato:
//    RGB a Gris <FichImagenOriginal> <FichImagenDestino>
//    donde:
//   <FichImagenOriginal> es la imagen PPM que se va a convertir a niveles de gris,
//        no se modifica.
//   <FichImagenDestino> es la imagen PGM resultado de aplicar la conversion
//        a <FichImagenOriginal>.
//

#include <iostream>
#include <cstring>
#include <cstdlib>

#include <imagenES.h>
#include <Imagen.h>
#include <funciones.hpp>

using namespace std;

int main (int argc, char *argv[]){
 
  char *origen, *destino; // nombres de los ficheros

  unsigned char *imagePPM;
  int nf, nc, npixeles; // Num. de filas y columnas de las imagenes

  // Comprobar validez de la llamada
  if (argc != 3){
    cerr << "Error: Numero incorrecto de parametros.\n";
    cerr << "Uso: negativo <FichImagenOriginal> <FichImagenDestino>\n";
    exit (1);
  }

  origen  = argv[1];
  destino = argv[2];

  cout << endl;
  cout << "Fichero origen: " << origen << endl;
  cout << "Fichero resultado: " << destino << endl;

// Leer la imagen del fichero de entrada
  imagePPM = LeerImagenPPM (origen, nf, nc);
  if (!imagePPM){
    cerr << "Error: No pudo leerse la imagen." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    exit (1);
  }

  // Mostrar los parametros calculados por LeerImagenPPM()
  cout << endl;
  cout << "Dimensiones de " << origen << ":" << endl;
  
  cout << "   Imagen   = " << nf  << " filas x " << nc << " columnas " << endl;

  Imagen imagen_result(nf,nc);
  imagen_result = convertirRGBaGris(nf, nc, imagePPM);
  
  unsigned char *imagePGM = imagen_result.pasarAPGM(nf,nc);

  if (EscribirImagenPGM(destino, imagePGM, nf, nc))
    cout << "La imagen se guardo en " << destino << endl;
  else
  {
    cerr << "Error: No pudo guardarse la imagen." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    exit(2);
  }

  delete [] imagePPM;
  delete [] imagePGM;

  return 0;
}