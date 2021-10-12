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
  int x1,y1,x2,y2;
	double media = 0.0;

  // Comprobar validez de la llamada
  if (argc != 7){
    cerr << "Error: Numero incorrecto de parametros.\n";
    cerr << "Uso: negativo <FichImagenOriginal> <FichImagenDestino> <x1> <y1> <x2> <y2>\n";
    exit (1);
  }

  origen  = argv[1];
  destino = argv[2];
  x1      = atoi(argv[3]);
  y1      = atoi(argv[4]);
  x2      = atoi(argv[5]);
  y2      = atoi(argv[6]);

  cout << endl;
  cout << "Fichero origen: " << origen << endl;
  cout << "Fichero resultado: " << destino << endl;

  TipoImagen tipo = LeerTipoImagen(origen);
  Imagen imagen;

  // Comprobamos el tipo de imagen y la leemos
  if (tipo == IMG_PGM){
    // Leer la imagen del fichero de entrada
    image = LeerImagenPGM (origen, nf, nc);
    if (!image){
      cerr << "Error: No pudo leerse la imagen." << endl;
      cerr << "Terminando la ejecucion del programa." << endl;
      exit (1);
    }
    imagen.convertirPGMaImagen(nf, nc, image);    
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
            imagen = convertirRGBaGris(nf, nc, image);
    }
    else{
    cerr << "Error. Formarto de imagen desconocido." << endl;
            exit (1);
    }
  }

    Imagen img_zoom = zoom( porcion(imagen, x1, y1, x2, y2) );

    unsigned char *imagePGM = img_zoom.pasarAPGM(nf,nc);

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