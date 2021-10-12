/**
  * @file Pila_max_Cola.cpp
  * @brief Implementaci�n del TDA PilaMax
  *
  */
#include <cassert>
#include <Pila_max_Cola.h>

/* _________________________________________________________________________ */


    PilaMaxCola::PilaMaxCola(){
        cola = Cola<Elemento>(); // Usamos el constructor por defecto de cola
    }

/* _________________________________________________________________________ */

    PilaMaxCola::PilaMaxCola(const PilaMaxCola & otra){
       cola = Cola<Elemento>(otra.cola);
    }


/* _________________________________________________________________________ */


    PilaMaxCola& PilaMaxCola::operator=(const PilaMaxCola& otra){
        cola = otra.cola;
    }

/* _________________________________________________________________________ */


    bool PilaMaxCola::vacia() const{
        return cola.vacia(); 
    }

/* _________________________________________________________________________ */


    Elemento& PilaMaxCola::tope (){
        return cola.frente();
    }

/* _________________________________________________________________________ */


    const Elemento & PilaMaxCola::tope () const{
        return cola.frente();
    }

/* _________________________________________________________________________ */


    void PilaMaxCola::poner(int elem){
        int maximo;
        if(!cola.vacia())
            elem > cola.frente().maximo ? maximo = elem : maximo = cola.frente().maximo;
        else
            maximo = elem;
        
        Elemento elemento (elem, maximo);
        Cola<Elemento> aux;
        aux.poner(elemento);
        while (!vacia()){
            elemento = cola.frente();
            aux.poner(elemento);
            cola.quitar();
        }
        cola = aux;

    }

/* _________________________________________________________________________ */


    void PilaMaxCola::quitar(){
        cola.quitar();
    }

/* _________________________________________________________________________ */


    int PilaMaxCola::num_elementos() const{
        cola.num_elementos();
    }