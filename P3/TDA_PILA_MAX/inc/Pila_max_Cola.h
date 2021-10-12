#ifndef __Pila_max_cola_H__
#define __Pila_max_cola_H__

#include <cassert>
#include <iostream>
#include <cola.h>

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

class PilaMaxCola{
  private:
    Cola<Elemento> cola;
  public:
    // ---------------  Constructores ----------------
    /**
     * @brief Constructor por defecto
     */
    PilaMaxCola();  
    /**
     * @brief Constructor de copias
     * @param otra La pila de la que se hara la copia.
     */
    PilaMaxCola(const PilaMaxCola & otra);
    // ------------------ Destructor ------------------
    /**
     * @brief Destructor
     */
    ~PilaMaxCola()=default;
    // --------------- Otras funciones ---------------
    /**
     * @brief Operador de asignacion
     * @param otra La pila que se va a asignar.
     */
    PilaMaxCola& operator= (const PilaMaxCola& otra);
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


#endif // __Pila_max_cola_H__