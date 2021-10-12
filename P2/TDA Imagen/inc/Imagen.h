#ifndef IMAGEN
#define IMAGEN
typedef unsigned char byte;

#define MAXPIXEL 255 //Maximo valor que puede tomar un pixel

class Imagen{
private:
  int filas;
  int columnas;
  unsigned char **img;

public:

  /**
  * @brief Constructor por defecto de la clase imagen
  */
  Imagen ();

  /**
  * @brief Constructor de copia de la clase imagen
  * @param J: imagen que vamos a copiar
  */
  Imagen(const Imagen &J);

  /**
  * @brief Constructor con parametros de la clase imagen
  * @param filas: numero de filas
  * @param cols: numer columnas
  * @pre filas > 0
  * @pre cols > 0
  * @post La imagen creada contiene filas filas y cols columnas
  * @post La imagen creada contiene valores "basura" (no está incializada)
  */
  Imagen(int filas, int cols);

  /**
  * @brief Destructor de una imagen
  * @post La imagen destruida no puede volver a usarse, salvo que se vuelva a realizar sobre ella la operacion Imagen()
  */
  ~Imagen();

  /**
  * @brief Consultor del numero de filas de una imagen
  * @return Numero de filas de la imagen
  * @post La imagen no se modifica
  */
  int num_filas() const;

  /**
  * @brief Consultor del numero de columnas de una imagen
  * @return Numero de columnas de la imagen
  * @post La imagen no se modifica
  */
  int num_columnas () const;

  /**
  * @brief Asignar el valor de luminosidad valor a la casilla (fila, col) de la imagen
  * @pre 0 <= fila < num_filas ()
  * @pre 0 <= col < num_columnas ()
  * @pre 0 <= valor <= 255
  * @post La imagen se modifica. Cambia el valor de la casilla(fila, col) de la imagen por el especificado con valor. Los demás puntos no se ven modificados
  */
  void asigna_pixel (int fila, int col, unsigned char valor);


  /**
  * @brief Consultar el valor de luminosidad de la casilla (fila, col) de la imagen
  * @pre 0 <= fila < num_filas ()
  * @pre 0 <= col < num_columnas ()
  * @return Valor de luminosidad de la casilla (fila, col) ∈ [0,255]
  * @post La imagen no se modifica
  */
  byte valor_pixel (int fila, int col) const;

  /**
  * @brief Sobrecarga operador asognacion.
  * @param otra: imagen que se va a asignar al objeto que llama al metodo (Right value)
  * @return La imagen resultante (left value)
  * @post La imagen se modifica
  */
  Imagen& operator=(const Imagen &otra);

   /**
   * @brief Convierte la imagen PGM en un objeto de la clase
   * @param filas: numero de filas de la imagen PGM
   * @param columnas: numero de columnas de la imagen PGM
   * @param img: puntero a los datos de la imagen PGM
   * @post La imagen se modifica
   */
  void convertirPGMaImagen(int filas, int columnas, unsigned char *imagen);

  /**
   * @brief Convierte la imagen de la clase en una imagen PGM
   * @param filas: numero de filas de la imagen PGM (salida)
   * @param columnas: numero de columnas de la imagen PGM (salida)
   * @return El puntero a la imagen PGM
   * @post La imagen no se modifica
   */
  unsigned char *pasarAPGM(int &filas, int &columnas) const;


private:

  //METODOS AUXILIARES PARA LA GESTION DE LA MEMORIA DINAMICA

  /**
   * @brief Reserva nueva memoria, y si es necesario, libera la memoria existente
   * @param f numero de filas a reservar
   * @param c numero de columnas a reservar
   */
  void reservar(int f, int c);

  /**
   * @brief Libera la memoria
   */
  void liberar();

  /**
   * @brief Copia los datos de otro objeto en el que llama al metodo
   * @param otra: la imagen que se va a copiar
   * @pre previamente se debe de haber reservado memoria con el metodo reservar
   */
  void copiar(const Imagen &otra);

  /**
   * @brief Inicializa el objeto
   */
  void inicializar();

};

#endif