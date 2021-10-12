/**
  * @file pila.cpp
  * @brief Implementaci�n del TDA PilaMax
  *
  */
#include <cassert>
#include <Pila_max_Pila.h>


/* _________________________________________________________________________ */

PilaMax::PilaMax(const PilaMax & otra){
  if (otra.primera!=0){            //Si la pila original no está vacía
    Celda *p = otra.primera;       //Copio el puntero al primer nodo
    Celda *nueva;
    primera = nueva = new Celda(p->elemento,0); //Creamos el primer nodo
    p = p->siguiente;                 //Avanzamos el puntero
    while (p!=0){                                  //Mientras queden elementos
      nueva->siguiente = new Celda(p->elemento,0); //Creamos un nuevo nodo
      nueva = nueva->siguiente;                    //Avanzamos los punteros
      p = p->siguiente;
    }
  }
  else                              //Si la pila original está vacía
    primera = 0;
  num_elem = otra.num_elem;     //En cualquier caso, copiamos num_elem
}

/* _________________________________________________________________________ */

PilaMax::~PilaMax(){
  Celda *aux;
  while (primera!=0){              //Mientras la pila no está vacía,
    aux = primera;                 //Copiamos el puntero al tope de la pila
    primera = primera->siguiente;  //Avanzamos primera
    delete aux;                    //Borramos el nodo de la lista
  }
}

/* _________________________________________________________________________ */

PilaMax& PilaMax::operator=(const PilaMax & otra){
  Celda * p;
  
  if (this!=&otra){    //Comprobación de rigor. Si son diferentes objetos
    while (primera!=0){    //Borramos la lista de nodos de la pila *this
      p = primera;
      primera = primera->siguiente;
      delete p;
    }
    if (otra.primera!=0){        //Si la otra pila tiene elementos
      p = otra.primera;          //Copiamos el puntero al primero nodo
      Celda *nueva;
      primera = nueva = new Celda(p->elemento,0);//Reservamos el primer nodo
      p = p->siguiente;                             //Avanzamos el puntero
      while (p!=0){                                 //Mientras queden elementos
        nueva->siguiente = new Celda(p->elemento,0); //Creamos un nuevo nodo
        nueva = nueva->siguiente;                   //Avanzamos nueva (auxiliar)
        p = p->siguiente;                           //Avanzamos el puntero
      }
    }
    num_elem=otra.num_elem;      //En cualquier caso, copiamos num_elem
  }
  return *this; //Devolvemos el objeto para permitir el encadenamiento (a=b=c)
}

/*_________________________________________________________________________ */

void PilaMax::poner(int elem){
  Elemento element(elem);
  primera = new Celda(element, primera); //Creamos un nuevo nodo en el tope
  int max;
  if (num_elem>0){
    elem >= primera->siguiente->elemento.maximo ? max = elem : max = primera->siguiente->elemento.maximo ;
    primera->elemento.maximo = max;
  }
  else{
    primera->elemento.maximo = primera->elemento.elem;
  }
  num_elem++;                        //Actualizamos num_elem
}

/* _________________________________________________________________________ */

void PilaMax::quitar(){
  assert(primera!=0);           //Si la pila no tiene elementos, abortar
  Celda *p = primera;           //Copiamos el puntero al tope
  primera = primera->siguiente; //Actualizamos primera
  delete p;                     //Borramos el nodo que ocupaba el tope
  num_elem--;                   //Actualizamos num_elem
}
