/**
  * @file Pila_max_VD.cpp
  * @brief Implementaci�n del TDA PilaMax
  *
  */
#include <cassert>
#include <vector>


/* _________________________________________________________________________ */

    PilaMaxVD::PilaMaxVD(const PilaMaxVD & otra){
       vd = vector<Elemento>(otra.vd);
    }


/* _________________________________________________________________________ */


    PilaMaxVD& PilaMaxVD::operator=(const PilaMaxVD& otra){
        vd = otra.vd;
    }

/* _________________________________________________________________________ */


    bool PilaMaxVD::vacia() const{
        return vd.empty();
    }

/* _________________________________________________________________________ */


    Elemento& PilaMaxVD::tope (){
        return vd.back();
    }

/* _________________________________________________________________________ */


    const Elemento & PilaMaxVD::tope () const{
        return vd.back();
    }

/* _________________________________________________________________________ */


    void PilaMaxVD::poner(int elem){
        int maximo;
        if(!vd.empty())
            elem >= vd.back().maximo ? maximo = elem : maximo =  vd.back().maximo;
        else
            maximo = elem;
        
        Elemento elemento (elem, maximo);
        vd.push_back(elemento);

    }

/* _________________________________________________________________________ */


    void PilaMaxVD::quitar(){
        vd.pop_back();
    }

/* _________________________________________________________________________ */


    int PilaMaxVD::num_elementos() const{
        vd.size();
    }