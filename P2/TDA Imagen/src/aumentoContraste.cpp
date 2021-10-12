// Fichero: aumentoConstraste.cpp
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
  Imagen imagen_contraste_aumentado;

  // Comprobamos el tipo de imagen y la leemos
  if (tipo == IMG_PGM){
    // Leer la imagen del fichero de entrada
    image = LeerImagenPGM (origen, nf, nc);
    if (!image){
      cerr << "Error: No pudo leerse la imagen." << endl;
      cerr << "Terminando la ejecucion del programa." << endl;
      exit (1);
    }
    imagen_contraste_aumentado.convertirPGMaImagen(nf, nc, image);    
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
			imagen_contraste_aumentado = convertirRGBaGris(nf, nc, image);
    }
    else{
      cerr << "Error. Formarto de imagen desconocido." << endl;
			exit (1);
    }
  }

  double a = valorMinGris(imagen_contraste_aumentado),
         b = valorMaxGris(imagen_contraste_aumentado);

    cout << "Valor minimo del rango de grises: " << a << endl;
    cout << "Valor maximo del rango de grises: " << b << endl;

  double minimo, maximo;

	cout << "Introduce el valor minimo del nuevo rango de grises: ";
	cin >> minimo; 

  cout << "Introduce el valor maximo del nuevo rango de grises: ";
	cin >> maximo; 

  double cociente = (maximo - minimo) / (b - a);
  
  imagen_contraste_aumentado = aumentoContraste(imagen_contraste_aumentado, a, minimo, cociente);

  unsigned char *imagePGM = imagen_contraste_aumentado.pasarAPGM(nf,nc);

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