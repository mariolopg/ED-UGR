#ifndef __VDG_H__
#define __VDG_H__


/**
   VectorDinamico::VectorDinamico, ~VectorDinamico, redimensionar,
   dimension, componente, asignar_componente, operator[]

   Este TDA representa vectores de objetos de la clase T cuyo tamaño
   puede cambiar en tiempo de ejecución.
   Son mutables.
   Residen en memoria dinámica.

   Requisitos para la instanciación:

   La clase T debe tener las siguientes operaciones:
   - Constructor por defecto
   - Constructor de copia
   - Operador de asignación
  */ 

template <class T>
class VectorDinamico {
public:
/*
 *  Operaciones
 */


  /**
     Constructor: crea un vector dinámico.
     
     @param num_elem: Número de componentes del nuevo vector.
            num_elem >= 0.

     @doc
       Crear un vector dinámico con num_elem componentes.
    */
  VectorDinamico(int num_elem);

  /**
     Destructor. 

     @doc
       Destruye v liberando los recursos que empleaba.
    */
  ~VectorDinamico();

  /**
     Modifica el tamaño del receptor.

     @param num_elem: nuevo tamaño del vector. num_elem >= 0.

     @return 0, si éxito. 
             1, si se producen errores.

     @doc
       Modifica el tamaño del receptor, dejándolo con num_elem componentes.
     a) Si dimension() < num_elem, los anteriores elementos del receptor
        se conservan en sus posiciones y las nuevas componentes se 
        inician a 0.
     b) Si dimension() <= num_elem, las primeras num_elem componentes
        de ve se mantienen en sus posiciones.
     Si todo el proceso culmina con éxito, devuelve 0. Si se produce
     algún error, devuelve 1.
    */
  int redimensionar(int num_elem);

  /**
     Devuelve el número de componentes del receptor.

     @return número de componentes del receptor.
    */
  int dimension() const;

  /**
     Acceso a una componente del vector.

     @param i: indice de la componente a obtener. 0 <= i < dimension().

     @return componente i-ésima del vector receptor.
    */
  T componente(int i) const;

  /**
     Modifica el valor de una componente del vector.

     @param i: indice de la componente a modificar. 0 <= i < dimension().
     @param valor: nuevo valor a asignar a la componente

     @doc
       Modifica la componente i-ésima de v, que pasa a ser 'valor'.
    */
  void asignar_componente(int i, const T & elem);

  /**
     Acceso a una componente del vector, con posibilidad de modificación.

     @param i: indice de la componente a obtener. 0 <= i < dimension().

     @return referencia a la componente i-ésima del vector receptor.
    */
  T & operator[](int i);

 private:
  T * datos;
  int num_comp;
};

#include "VDG.cpp"

#endif

