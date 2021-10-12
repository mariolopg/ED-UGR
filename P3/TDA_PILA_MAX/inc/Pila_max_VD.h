/**
  * @file cola.h
  * @brief Fichero cabecera del TDA Cola
  *
  * Gestiona una secuencia de elementos con facilidades para la inserci�n y
  * borrado de elementos en un extremo
  */

#ifndef __Pila_Max_VD_H__
#define __Pila_Max_VD_H__

#include <cassert>
#include <iostream>
#include <vector>

using namespace std; 

struct Elemento{
    int elem; ///< elemento a almacenar
    int maximo; ///< el máximo

    Elemento() : elem(0), maximo (0){}

    Elemento (int element, int max=0) : elem(element), maximo(max){}

    friend ostream & operator << (ostream &os, const Elemento & elemento){
        os << elemento.elem << " | " << elemento.maximo; 
    }
 
    
};

class PilaMaxVD{
  private:
    vector<Elemento> vd;
  public:
    // ---------------  Constructores ----------------
    /**
     * @brief Constructor por defecto
     */
    PilaMaxVD() = default;  // Usamos el constructor por defecto de vector
    /**
     * @brief Constructor de copias
     * @param otra La pila de la que se hara la copia.
     */
    PilaMaxVD(const PilaMaxVD & otra);
    // ------------------ Destructor ------------------
    /**
     * @brief Destructor
     */
    ~PilaMaxVD()=default; // // Usamos el destructor por defecto de vector
    // --------------- Otras funciones ---------------
    /**
     * @brief Operador de asignacion
     * @param otra La pila que se va a asignar.
     */
    PilaMaxVD& operator= (const PilaMaxVD& otra);
    /**
     * @brief Comprueba si la pila esta vacia
     */
    bool vacia() const;
    /**
     * @brief Devuelve el elemento del tope de la pila
     */
    Elemento& tope ();
    /**
     * @brief Devuelve el elemento del tope de una pila constante
     */
    const Elemento & tope () const;
    /**
     * @brief A�ade un elemento "encima" del tope de la pila
     * @param elem Elemento que se va a añadir.
     */
    void poner(int elem);
    /**
     * @brief Quita el elemento del tope de la pila
     */
    void quitar();
    /**
     * @brief Devuelve el numero de elementos de la pila
     */
    int num_elementos() const;
};

#include <Pila_max_VD.cpp>

#endif // __Pila_Max_VD_H__