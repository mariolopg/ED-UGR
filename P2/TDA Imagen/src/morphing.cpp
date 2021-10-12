 #include <iostream>
#include <cstring>
#include <cstdlib>

#include <imagenES.h>
#include <Imagen.h>
#include <funciones.hpp>

using namespace std;

int main (int argc, char *argv[]){
 
  char *origen, *resultado, *nombreFintermedio; // nombres de los ficheros

  unsigned char *image;
  int nf, nc, npixeles; // Num. de filas y columnas de las imagenes
	double media = 0.0;

  // Comprobar validez de la llamada
  if (argc != 4){
    cerr << "Error: Numero incorrecto de parametros.\n";
    cerr << "Uso: negativo <FichImagenOriginal> <FichImagenResultado> <FichImagenInterm>\n";
    exit (1);
  }

  origen  = argv[1];
  resultado = argv[2];
  nombreFintermedio = argv[3];

  cout << endl;
  cout << "Fichero origen: " << origen << endl;
  cout << "Fichero resultado: " << resultado << endl;
  cout << "Ficheros intermedios: " << nombreFintermedio << endl;

  TipoImagen tipoOrig = LeerTipoImagen(origen);
  TipoImagen tipoRdo = LeerTipoImagen(resultado);
  Imagen imagen_origen;
  Imagen imagen_resultado;

  // Comprobamos el tipo de imagen origen y la leemos
  if (tipoOrig == IMG_PGM){
    // Leer la imagen del fichero de entrada
    image = LeerImagenPGM (origen, nf, nc);
    if (!image){
      cerr << "Error: No pudo leerse la imagen." << endl;
      cerr << "Terminando la ejecucion del programa." << endl;
      exit (1);
    }
    imagen_origen.convertirPGMaImagen(nf, nc, image);    
  }
  else{
      if (tipoOrig == IMG_PPM){
      // Leer la imagen del fichero de entrada
      image = LeerImagenPPM (origen,  nf, nc);
      if (!image){
          cerr << "Error: No pudo leerse la imagen." << endl;
          cerr << "Terminando la ejecucion del programa." << endl;
          exit (1);
          }
              imagen_origen = convertirRGBaGris(nf, nc, image);
      }
      else{
      cerr << "Error. Formarto de imagen desconocido." << endl;
              exit (1);
      }
  }

  // Comprobamos el tipo de imagen resultado y la leemos
  if (tipoRdo == IMG_PGM){
    // Leer la imagen del fichero de entrada
    image = LeerImagenPGM (resultado, nf, nc);
    if (!image){
      cerr << "Error: No pudo leerse la imagen." << endl;
      cerr << "Terminando la ejecucion del programa." << endl;
      exit (1);
    }
    imagen_resultado.convertirPGMaImagen(nf, nc, image);    
  }
  else{
      if (tipoRdo == IMG_PPM){
      // Leer la imagen del fichero de entrada
      image = LeerImagenPPM (resultado,  nf, nc);
      if (!image){
          cerr << "Error: No pudo leerse la imagen." << endl;
          cerr << "Terminando la ejecucion del programa." << endl;
          exit (1);
          }
              imagen_resultado = convertirRGBaGris(nf, nc, image);
      }
      else{
      cerr << "Error. Formarto de imagen desconocido." << endl;
              exit (1);
      }
  }

  
  bool iguales = false;

  Imagen intermedio(imagen_origen);
  for (int i = 0; i < 256 && !iguales; i++){
    intermedio = generarFintermedio(intermedio, imagen_resultado, iguales);

    unsigned char *imageInter = intermedio.pasarAPGM(nf,nc);
    nombreFintermedio = generarNombreFichero(nombreFintermedio, i+1);
    if (EscribirImagenPGM( nombreFintermedio, imageInter, nf, nc))
      cout << "La imagen se guardo en " << nombreFintermedio << endl;
    else
    {
      cerr << "Error: No pudo guardarse la imagen." << endl;
      cerr << "Terminando la ejecucion del programa." << endl;
      exit(2);
    }

    delete [] imageInter;
  }

  
  delete [] image;

  return 0;

}