
#include <Imagen.h>
#include <cassert>
#include <string>

using namespace std;


/* Funciones externas */

// EJERCICIO 0 - Convertir a RGB ---------------------------------------------------------------------------------------

  /**
   * @brief Convierte una imagen en RGB a una en niveles de girs de la clase imagen
   * @param nfilas: numero de filas de la imagen PPM
   * @param ncolumnas: numero de columnas de la imagen PPM
   * @param img: puntero a los datos de la imagen PPM 
   */
  Imagen convertirRGBaGris( const int nfilas, const int ncolumnas, const unsigned char *img ) {
    Imagen imagen_result(nfilas, ncolumnas);
    //Calculamos el valor en niveles de gris con la fórmula img[fila*ncolumnas*3+columna*3+valor_rgb] 
    // el tres es el total de colores (R, G y B) y valor_rgb es 0 para R, 1 para G y 2 para b
    for(int i = 0; i < imagen_result.num_filas(); i++)
      for(int j = 0; j < imagen_result.num_columnas(); j++){
        unsigned char valor = 0.2989 * img[i*ncolumnas*3+j*3+0] + 0.587 * img[i*ncolumnas*3+j*3+1] + 0.114 * img[i*ncolumnas*3+j*3+2];
        imagen_result.asigna_pixel(i,j,valor);
      }
    return imagen_result;
  }

  // EJERCICIO 2 - Umbralizar ---------------------------------------------------------------------------------------

  /**
   * @brief Calcula la media de todos los valores de una Imagen
   * @param imagen: Imagen de la que se va a calcular la media
   * @param npixeles: numero de pixeles de la imagen (si es -1 el numero de pixeles será nfilas*ncolumnas)
   * @return La media de todos los valores da la imagen 
   */
  double mediaImagen(Imagen imagen, int npixeles = -1){
    double media = 0.0, suma = 0.0;
    if (npixeles==-1)
      npixeles = imagen.num_filas() * imagen.num_columnas();
    for(int i = 0; i < imagen.num_filas(); i++)
      for (int j=0; j < imagen.num_columnas(); j++)
        suma += imagen.valor_pixel(i,j);
    media = suma / npixeles;
    return media;
  }

  /**
   * @brief calcula el umbral de la imagen pasada como parametro
   * @param img: Imagen de la que se va a calcular el umbral
   * @param e: Valor cercano a cero que dertemina cuando se estabiliza el umbral
   * @return el umbral de la imagen
   */
  double calcularUmbralImagen(const Imagen &img, const double e){
    int npix1 = 0, npix2 = 0;
    double umbral = 0, nuevoUmbral = mediaImagen(img);
    int filas = img.num_filas();
    int columnas = img.num_columnas();

    Imagen img1 (filas,columnas);
    Imagen img2 (filas,columnas);

    do {
      npix1 = npix2 = 0;
      umbral = nuevoUmbral;
      for(int i = 0; i < filas; i++)
        for (int j=0; j < columnas; j++) {
          unsigned char valor = img.valor_pixel(i,j);
          if ( valor <= umbral){
            img1.asigna_pixel(i,j,valor);
            img2.asigna_pixel(i,j,0);
            npix1++;
          } else {
            img1.asigna_pixel(i,j,0);
            img2.asigna_pixel(i,j,valor);
            npix2++;
          }
        }
      double u1 = mediaImagen(img1,npix1),
             u2 = mediaImagen(img2,npix2);       
      nuevoUmbral = (u1 + u2) / 2;
      
    } while ( abs(nuevoUmbral - umbral) >= e );

    return nuevoUmbral;
  }

  /**
   * @brief umbraliza la imagen pasada como parametro
   * @param img: Imagen que se va a umbralizar
   * @param T: valor del umbral
   * @return la imagen umbralizada
   */
  Imagen umbralizar(const Imagen &img, const double T ){
    Imagen umbral(img);
    for(int i = 0; i < img.num_filas(); i++)
        for (int j=0; j < img.num_columnas(); j++)
          if ( umbral.valor_pixel(i,j) >= T )  // Hemos puesto >= para que en la imagen se pasen al blanco los valores claros 
            umbral.asigna_pixel(i, j, 255);          

    return umbral;      
  }
  
   // EJERCICIO 3 - Zoom de una porcion de la imagen --------------------------------------------------------------------------

  /**
   * @brief redondea el valor pasado como parametro al entero más proximo por exceso 
   * @param valor: valor que se va a redondear
   */
  int redondear(double valor){
    int parte_entera = valor, redondeo = 0;
    double parte_decimal = valor - parte_entera;
    
    if(parte_decimal < 0.5)
      redondeo = valor;
    else
      redondeo = valor + 1;

    return redondeo;
  }

  /**
   * @brief Devuelve una porcion de la imagen pasada como parametro
   * @param img: imagen a la que se va a aplicar la fncion
   * @param x1: numero de fila de la esquina sup izq de la porcion
   * @param y1: numero de columna de la esquina sup izq de la porcion
   * @param x2: numero de fila de la esquina inf dcha de la porcion
   * @param y2: numero de columna de la esquina inf dcha de la porcion
   * @pre La porción ha de ser cuadrada
   * @return la porcion de la imagen con coordenadas (x1,y1) en la esquina superior izq, (x2,y2) en la esquina inferior derecha
   */
  Imagen porcion(const Imagen &img, int x1, int y1, int x2, int y2){
      assert( x2 - x1 == y2 - y1); // la porcion debe de ser cuadrada
      Imagen porcion (x1+x2+1, y1+y2+1);
      for(int i = x1; i < x2; i++)
        for(int j = y1; j < y2; j++)
          porcion.asigna_pixel(i-x1, j-y1, img.valor_pixel(i, j));

      return porcion;
  }

  /**
   * @brief Hace zoom a la porcion de la imagen pasada como parametro
   * @param img: porcion de la imagen que se va a ampliar
   * @return la porcion ampliada
   */
  Imagen zoom(const Imagen &img) {
    Imagen zoom (2*img.num_filas()-1, 2*img.num_columnas()-1 );
    
    // Rellenamos la imagen zoom con todos los valores de la imagen original, intercalando
    // filas y columnas vacías para posteriormente realizar la intepolación
    for(int i = 0; i < zoom.num_filas(); i+=2)
        for (int j = 0; j < zoom.num_columnas(); j+=2)
          zoom.asigna_pixel(i, j, img.valor_pixel(i/2, j/2));

    // Interpolamos sobre las columnas
    for(int i = 0; i < zoom.num_filas(); i+=2)
      for (int j = 1; j < zoom.num_columnas(); j+=2){
        double valor = (zoom.valor_pixel(i - 1, j) + zoom.valor_pixel(i + 1, j)) / 2;
        zoom.asigna_pixel(i, j, redondear(valor));        
      }

    // Interpolamos sobre las filas
    for(int i = 1; i < zoom.num_filas(); i+=2)
      for (int j = 0; j < zoom.num_columnas(); j++){
        double valor = (zoom.valor_pixel(i, j - 1) + zoom.valor_pixel(i, j + 1)) / 2;
        zoom.asigna_pixel(i, j, redondear(valor));        
      }

    return zoom;
  }

 // EJERCICIO 5 - Aumento de contraste  ---------------------------------------------------------------------------------

/**
 * @brief Calcula el valor minimo de gris de la imagen pasada como parametro
 * @param img: imagen de la que se va a calcular el minimo
 * @return el valor minimo de gris de la imagen
 */
unsigned char valorMinGris(const Imagen &img){
  
  unsigned char minimo = 255;

  for (int i = 0; i < img.num_filas(); i++)
      for (int j = 0; j < img.num_columnas(); j++)
        if(img.valor_pixel(i, j) < minimo)
          minimo = img.valor_pixel(i, j);
          
  return minimo;
}
 
/**
 * @brief Calcula el valor maximo de gris de la imagen pasada como parametro
 * @param img: imagen de la que se va a calcular el maximo
 * @return el valor maximo de gris de la imagen
 */
unsigned char valorMaxGris(const Imagen &img){
  
  unsigned char maximo = 0;

  for(int i = 0; i < img.num_filas(); i++)
      for (int j = 0; j < img.num_columnas(); j++)
        if (img.valor_pixel(i,j) > maximo)
          maximo = img.valor_pixel(i,j);

  return maximo;
}

/**
 * @brief Realiza la trasformacion lineal de un pixel
 * @param pixel: pixel al que se va a realizar la transformacion
 * @param a: minimo nivel de gris de la imagen
 * @param minimo: minimo nivel de gris que queremos conseguir en la imagen
 * @param cociente: Valor de la expresion (max-min)/(b-a)
 * @return El valor de pixel transformado
 * @post El valor del cociente debe ser previamente calculado 
 */
unsigned char transformacionLineal( unsigned char pixel, int a, int minimo, double cociente){
  double pixelPrima = 0.0;
  pixelPrima = ( minimo + cociente * (pixel - a) );
  return redondear(pixelPrima);
}

/**
 * @brief Realiza el aumento de contraste a la imagen pasada como argumento
 * @param img: imagen a la que se va a realizar el aumento de contraste
 * @param a: minimo nivel de gris de la imagen
 * @param minimo: minimo nivel de gris que queremos conseguir en la imagen
 * @param cociente: Valor de la expresion (max-min)/(b-a)
 * @return La imagen con el aumento de contraste realizado
 * @post El valor del cociente debe ser previamente calculado 
 */
Imagen aumentoContraste(const Imagen &img, int a, int minimo, double cociente){

  Imagen imgConstrasteAumentado(img.num_filas(), img.num_columnas());

  for(int i = 0; i < imgConstrasteAumentado.num_filas(); i++)
      for (int j = 0; j < imgConstrasteAumentado.num_columnas(); j++){
        unsigned char pixel = img.valor_pixel(i, j);
        unsigned char valor = transformacionLineal(pixel, a, minimo, cociente);
        imgConstrasteAumentado.asigna_pixel(i, j, valor);
      }

  return imgConstrasteAumentado;

}

// EJERCICIO 6 - Morphing  ---------------------------------------------------------------------------------------------

/**
 * @brief Genera un fichero intermecio de la imagen origen y la imagen resultado
 * @param orig: imagen origen desde la que se quiere realizar el fichero intermedio
 * @param resultado: imagen resultado a la que se quiere llegar para realizar el fichero intermedio
 * @param iguales: parametro de salida que indica si las imágenes pasadas como parametro son iguales
 * @return La imagen con intermedia
 */
Imagen generarFintermedio(const Imagen &orig, const Imagen &result, bool &iguales ){
  Imagen intermedio(orig);
  bool cambio = false;
  for (int i = 0; i < orig.num_filas(); i++)
      for (int j = 0; j < orig.num_columnas(); j++){
        int valor = (int) intermedio.valor_pixel(i,j);
         unsigned char valorC;
        if (orig.valor_pixel(i, j) < result.valor_pixel(i, j)){
          valor++;
          valorC = (unsigned char) valor;
          intermedio.asigna_pixel(i, j, valorC);
          cambio = true;
        }
        
        else if (orig.valor_pixel(i, j) > result.valor_pixel(i, j)){
          valor--;
          valorC = (unsigned char) valor;
          intermedio.asigna_pixel(i, j, valorC);
          cambio = true;
        }
      }         
          
  if (!cambio)
    iguales = true;
  else
    iguales = false;

  return intermedio;

}

/**
 * @brief Genera el nombre de un fichero intermedio con tres digitos
 * @param nombre: nombre de los ficheros intermedios
 * @param numero: numero de fichero intermedio
 * @return Nombre generado como la composicion del nombre de los 
 *         archivos intermedios y el número de fichero contres digitos
 */
char *generarNombreFichero (const char* nombre, int numero){
  string nombreFinal = nombre;
  int centena = numero / 100;
  int decena = (numero - (centena * 100)) / 10;
  int unidad = (numero - (centena * 100 + decena * 10));

  nombreFinal = nombreFinal + to_string(centena) + to_string(decena) + to_string(unidad);

  char *nFinal = new char [nombreFinal.size()];

  for (int i = 0; i < nombreFinal.size(); i++)
    nFinal[i] = nombreFinal[i];

  return nFinal;
}

