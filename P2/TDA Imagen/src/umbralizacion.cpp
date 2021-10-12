
#include <iostream>
#include <cstring>
#include <cstdlib>

#include <imagenES.h>
#include <Imagen.h>
#include <funciones.hpp>

using namespace std;

int main (int argc, char *argv[]){
 
  char *origen, *destino; // nombres de los ficheros

  unsigned char *image;
  int nf, nc, npixeles; // Num. de filas y columnas de las imagenes
	double media = 0.0;

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

  TipoImagen tipo = LeerTipoImagen(origen);
  Imagen imagen_umbral;

  // Comprobamos el tipo de imagen y la leemos
  if (tipo == IMG_PGM){
    // Leer la imagen del fichero de entrada
    image = LeerImagenPGM (origen, nf, nc);
    if (!image){
      cerr << "Error: No pudo leerse la imagen." << endl;
      cerr << "Terminando la ejecucion del programa." << endl;
      exit (1);
    }
    imagen_umbral.convertirPGMaImagen(nf, nc, image);    
  }
	else{
    if (tipo == IMG_PPM){
      // Leer la imagen del fichero de entrada
      image = LeerImagenPPM (origen,  nf, nc);
      if (!image){
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        exit (1);
    	}
			imagen_umbral = convertirRGBaGris(nf, nc, image);
    }
    else{
      cerr << "Error. Formarto de imagen desconocido." << endl;
			exit (1);
    }
	}

  double e;
	cout << "Introduce el valor cercano a 0 para estabilizar el valor del umbral: ";
	cin >> e; 
  
  imagen_umbral = umbralizar(imagen_umbral,calcularUmbralImagen(imagen_umbral, e));

  unsigned char *imagePGM = imagen_umbral.pasarAPGM(nf,nc);

  if (EscribirImagenPGM(destino, imagePGM, nf, nc))
    cout << "La imagen se guardo en " << destino << endl;
  else
  {
    cerr << "Error: No pudo guardarse la imagen." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    exit(2);
  }

  delete [] image;
  delete [] imagePGM;

  return 0;

}