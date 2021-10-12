#include <cstdlib>
#include <iostream>
#include <cassert>

// #include "VDG.h"

/*

  ** Función de abstracción:
     ----------------------

     fA : tipo_rep  -------> Tipo Abstracto
        {datos, num_comp}--> { datos[0], datos[1], ..., datos[num_comp - 1]}


  ** Invariante de Representación:
     ----------------------------
     Cualquier objeto del tipo_rep, {datos, num_comp}, debe cumplir:
     - num_comp >= 0;
     - datos: apunta a una zona con capacidad para albergar a
       'num_comp' objetos de la clase T.
 */


template <class T>
VectorDinamico<T>::VectorDinamico(int num_elem)
{
  datos = new T[num_elem];
  if (datos == 0)
    {
      cerr << "Memoria Insuficiente\n";
      exit(-1);
    }
  num_comp = num_elem;
}


template <class T>
VectorDinamico<T>::~VectorDinamico()
{
  delete [] datos;
  datos = 0;
  num_comp = 0;
}


template <class T>
int 
VectorDinamico<T>::redimensionar(int num_elem)
{
  int i, min;

  /* Si piden el mismo tamaño que tiene: no hacer nada */
  if (num_elem == num_comp)
    return 0;

  /* Reserva nuevo espacio */
  T * p = new T [num_elem];
  if (p == 0)
    return 1;

  /* Si el vector estaba vacío, simplemente iniciar a 0 */
  if (num_comp == 0)
    return 0;

  /* Copiar los componentes que se mantienen */
  min = (num_comp < num_elem ? num_comp : num_elem);
  for (i = 0; i < min; i++)
    p[i] = datos[i];

  delete(datos);
  datos = p;
  num_comp = num_elem;
  return 0;
}


template <class T>
int 
VectorDinamico<T>::dimension() const
{
  return num_comp;
}


template <class T>
T  
VectorDinamico<T>::componente(int i) const
{
  assert (0 <= i && i < num_comp);

  return datos[i];
}


template <class T>
void 
VectorDinamico<T>::asignar_componente(int i, const T & valor)
{
  datos[i] = valor;
}


template <class T>
T &
VectorDinamico<T>::operator[](int i)
{
  assert (0 <= i && i < num_comp);

  return datos[i];
}
