#ifndef __Pila_max_H__
#define __Pila_max_H__

#include <cassert>
#include <iostream>

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

class PilaMax{
  private:
    struct Celda {
      Elemento elemento; ///< Elemento
      Celda * siguiente; ///< Puntero al siguiente nodo.

      /**
       * @brief Constructor por defecto
       */
      Celda() : siguiente(0){}
      /**
       * @brief Constructor con par�metros
       * @param elem Elemento de informaci�n.
       * @param sig Puntero al siguiente nodo.
       */
      Celda(const Elemento & elem, Celda * sig): elemento(elem), siguiente(sig){}
    };

    Celda * primera; ///< Puntero al primer nodo de la lista.
    int num_elem;    ///< Numero de elementos de la pila.

  public:
    // ---------------  Constructores ----------------
    /**
     * @brief Constructor por defecto
     */
    PilaMax(): primera(0), num_elem(0){
    }
    /**
     * @brief Constructor de copias
     * @param otra La pila de la que se hara la copia.
     */
    PilaMax(const PilaMax & otra);
    // ------------------ Destructor ------------------
    /**
     * @brief Destructor
     */
    ~PilaMax();
    // --------------- Otras funciones ---------------
    /**
     * @brief Operador de asignacion
     * @param otra La pila que se va a asignar.
     */
    PilaMax& operator= (const PilaMax& otra);
    /**
     * @brief Comprueba si la pila esta vacia
     */
    bool vacia() const{
      return (primera==0);
    }
    /**
     * @brief Devuelve el elemento del tope de la pila
     */
    Elemento& tope (){
      assert(primera!=0);       //Si la pila esta vacia, abortar
      return primera->elemento; //Devuelve el elemento del tope de la pila
    }
    /**
     * @brief Devuelve el elemento del tope de una pila constante
     */
    const Elemento & tope () const{
      assert(primera!=0);       //Si la pila esta vacia, abortar
      return primera->elemento; //Devuelve el elemento del tope de la pila
    }
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
    int num_elementos() const{
      return num_elem;
    }
};


#endif // __Pila_Max_H__

