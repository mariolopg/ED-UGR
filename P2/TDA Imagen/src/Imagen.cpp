#include <Imagen.h>

Imagen::Imagen() { inicializar(); }

// _____________________________________________________________________________

Imagen::Imagen(const Imagen &J) {
  inicializar();
  copiar(J);
}

// _____________________________________________________________________________

Imagen::Imagen(int filas, int cols) {
  inicializar();
  reservar(filas, cols);
}

// _____________________________________________________________________________

Imagen::~Imagen() { liberar(); }

// _____________________________________________________________________________

int Imagen::num_filas() const { return filas; }

// _____________________________________________________________________________

int Imagen::num_columnas() const { return columnas; }

// _____________________________________________________________________________

void Imagen::asigna_pixel(int fila, int col, unsigned char valor) {
  if ((fila >= 0 && col >= 0) && (fila < filas && col < columnas) && (valor >= 0 && valor <= MAXPIXEL))
    img[fila][col] = valor;
}

// _____________________________________________________________________________

byte Imagen::valor_pixel(int fila, int col) const {
  if ((fila >= 0 && col >= 0) && (fila < filas && col < columnas))
    return img[fila][col];
}

// _____________________________________________________________________________

Imagen& Imagen::operator=(const Imagen &otra) {
  if (this != &otra) {
    liberar();
    inicializar();
    copiar(otra);
  }
  return *this;
}

// _____________________________________________________________________________

void Imagen::convertirPGMaImagen(int filas, int columnas, unsigned char *imagen){
  liberar();
  reservar(filas, columnas);
  for (int i=0; i<filas; i++)
    for(int j = 0; j < columnas; j++)
      img[i][j] = imagen[i*columnas + j]; 
}

// _____________________________________________________________________________

unsigned char * Imagen::pasarAPGM(int &filas, int &columnas) const{
  unsigned char* imagenPGM = new unsigned char [this->filas * this->columnas];
  filas = this->filas;
  columnas = this->columnas;
  for (int i=0; i<filas; i++)
    for(int j = 0; j <columnas; j++)
      imagenPGM[i*columnas + j] = img[i][j];
  
  return imagenPGM;
}

// _____________________________________________________________________________

void Imagen::reservar(int f, int c) {
  if (f >= 0 && c >= 0) {
    filas = f;
    columnas = c;
    img = new unsigned char *[filas];
    img[0] = new unsigned char[filas * columnas];

    for (int i = 1; i < filas; i++)
      img[i] = img[i - 1] + columnas;

    for (int i = 0; i < filas; i++)
      for (int j = 0; j < columnas; j++)
        img[i][j] = 0;
  }
}

// _____________________________________________________________________________

void Imagen::liberar() {
  if (img != nullptr) {
    delete[] img[0];
    delete[] img;
  }
}

// _____________________________________________________________________________

void Imagen::copiar(const Imagen &otra) {
  reservar(otra.num_filas(), otra.num_columnas()); //presuponemos que previamente a la copia no se reserva
  for (int i = 0; i < num_filas(); i++)
    for (int j = 0; j < num_columnas(); j++)
      img[i][j] = otra.valor_pixel(i, j);
}

// _____________________________________________________________________________

void Imagen::inicializar() {
  img = nullptr;
  columnas = 0;
  filas = 0;
}

// _____________________________________________________________________________

