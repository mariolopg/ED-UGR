#include <iostream>
#include <string>
#include <list>

using namespace std;


template <class T, class U>
void Diccionario<T, U>::Copiar(const Diccionario<T, U> &D)
{
    /*typename list<data<T,U> >::const_iterator it_d;
               typename list<data<T,U> >::iterator it=this->datos.begin();*/

    datos.assign(D.datos.begin(), D.datos.end());
    /*for (it_d=D.datos.begin(); it_d!=D.datos.end();++it_d,++it){
                     this->datos.insert(it,it_d);

               }*/
}

template <class T, class U>
void Diccionario<T, U>::Borrar()
{
    this->datos.erase(datos.begin(), datos.end());
}

/* Constructor por defecto*/
template <class T, class U>
Diccionario<T, U>::Diccionario() : datos(list<data<T, U>>()) {}

/* Constructor de copias*/
template <class T, class U>
Diccionario<T, U>::Diccionario(const Diccionario<T, U> &D){
    Copiar(D);
}

/* Desstructor*/
template <class T, class U>
Diccionario<T, U>::~Diccionario() {}

/* Operador de asignación*/
template <class T, class U>
Diccionario<T, U> &Diccionario<T, U>::operator=(const Diccionario<T, U> &D)
{
    if (this != &D)
    {
        Borrar();
        Copiar(D);
    }
    return *this;
}

/* Busca la clave p en el diccionario. Si está devuelve un iterador a
		dónde está clave. Si no está, devuelve end() y deja el iterador de salida
		apuntando al sitio dónde debería estar la clave
		*/
template <class T, class U>
bool Diccionario<T, U>::Esta_Clave(const T &p, typename list<data<T, U>>::iterator &it_out)
{

    if (datos.size() > 0)
    {

        typename list<data<T, U>>::iterator it;

        for (it = datos.begin(); it != datos.end(); ++it)
        {
            if ((*it).clave == p)
            {
                it_out = it;
                return true;
            }
            else if ((*it).clave > p)
            {
                it_out = it;
                return false;
            }
        }

        it_out = it;
        return false;
    }
    else
    {
        it_out = datos.end();
        return false;
    }
}

/* Inserta un nuevo registro en el diccionario. Lo hace a través de la clave
		 e inserta la lista con toda la información asociada a esa clave. Si el 
		 diccionario no estuviera ordenado habría que usar la función sort() 
		 */
template <class T, class U>
void Diccionario<T, U>::Insertar(const T &clave, const list<U> &info)
{

    typename list<data<T, U>>::iterator it;

    if (!Esta_Clave(clave, it))
    {
        data<T, U> p;
        p.clave = clave;
        p.info_asoci = info;

        datos.insert(it, p);
    }
}

/*Añade una nueva informacion asocida a una clave que está en el diccionario.
		 la nueva información se inserta al final de la lista de información.
                  Si no esta la clave la inserta y añade la informacion asociada. 
		 */
template <class T, class U>
void Diccionario<T, U>::AddSignificado_Palabra(const U &s, const T &p)
{
    typename list<data<T, U>>::iterator it;

    if (!Esta_Clave(p, it))
    {
        datos.insert(it, p);
    }

    //Insertamos el siginificado al final
    (*it).info_asoci.insert((*it).info_asoci.end(), s);
}

/* Devuelve la información (una lista) asociada a una clave p. Podrían 
		 haberse definido operator[] como
		 data<T,U> & operator[](int pos){ return datos.at(pos);}
		 const data<T,U> & operator[](int pos)const { return datos.at(pos);}
		  */
template <class T, class U>
list<U> Diccionario<T, U>::getInfo_Asoc(const T &p){
    typename list<data<T, U>>::iterator it;

    if (!Esta_Clave(p, it))
    {
        return list<U>();
    }
    else
    {
        return (*it).info_asoci;
    }
}

/*Devuelve el tamaño del diccionario*/
template <class T, class U>
int Diccionario<T, U>::size() const{
    return datos.size();
}



//IMPLEMENTACION CLASS ITERATOR
template <class T, class U>
Diccionario<T, U>::iterator::iterator(
    typename list<data<T, U>>::iterator list_it) {
  this->list_it = list_it;
}

template <class T, class U> Diccionario<T, U>::iterator::iterator() {
  this->list_it = typename list<data<T,U>>::iterator();
}

template <class T, class U>
Diccionario<T, U>::iterator::iterator(const iterator &it) {
  this->list_it = it.list_it;
}

template <class T, class U>
typename Diccionario<T, U>::iterator &
Diccionario<T, U>::iterator::operator=(const iterator &it) {
  if (this != &it) {
    list_it = it.list_it;
  }

  return *this;
}

template <class T, class U>
typename Diccionario<T, U>::iterator &Diccionario<T, U>::iterator::operator++() {
  list_it++;
  return *this;
}

template <class T, class U>
typename Diccionario<T, U>::iterator &Diccionario<T, U>::iterator::operator--() {
  list_it--;
  return *this;
}

template <class T, class U>
data<T, U> &Diccionario<T, U>::iterator::operator*() {
  return *list_it;
}

template <class T, class U>
bool Diccionario<T, U>::iterator::operator==(
    const Diccionario<T, U>::iterator &it) const {
  return this->list_it == it.list_it;
}

template <class T, class U>
bool Diccionario<T, U>::iterator::operator!=(const Diccionario<T, U>::iterator &it) const {
  return this->list_it != it.list_it;
}

//Métodos begin y end de la clase Diccionario
template <class T, class U>
typename Diccionario<T, U>::iterator Diccionario<T, U>::begin() {
  return Diccionario<T, U>::iterator(datos.begin());
}

template <class T, class U>
typename Diccionario<T, U>::iterator Diccionario<T, U>::end() {
  return Diccionario<T, U>::iterator(datos.end());
}


//IMPLEMENTACION CLASS CONST ITERATOR
template <class T, class U>
Diccionario<T, U>::const_iterator::const_iterator(
    typename list<data<T, U>>::const_iterator list_it) {
  this->list_it = list_it;
}

template <class T, class U> Diccionario<T, U>::const_iterator::const_iterator() {
  this->list_it = typename list<data<T,U>>::iterator();
}

template <class T, class U>
Diccionario<T, U>::const_iterator::const_iterator(const const_iterator &it) {
  this->list_it = it.list_it;
}

template <class T, class U>
typename Diccionario<T,U>::const_iterator &
Diccionario<T, U>::const_iterator::operator=(const const_iterator &it) {
  if (this != &it) {
    list_it = it.list_it;
  }

  return *this;
}

template <class T, class U>
typename Diccionario<T, U>::const_iterator &
Diccionario<T, U>::const_iterator::operator++() {
  list_it++;
  return *this;
}

template <class T, class U>
typename Diccionario<T, U>::const_iterator &
Diccionario<T, U>::const_iterator::operator--() {
  list_it--;
  return *this;
}

template <class T, class U>
const data<T, U> &Diccionario<T, U>::const_iterator::operator*() const {
  return *list_it;
}

template <class T, class U>
bool Diccionario<T, U>::const_iterator::operator==(
    const Diccionario<T, U>::const_iterator &it) const {
  return this->list_it == it.list_it;
}

template <class T, class U>
bool Diccionario<T, U>::const_iterator::operator!=(const Diccionario<T, U>::const_iterator &it) const {
  return this->list_it != it.list_it;
}

/*Funciones cbegin y cend asociadas al diccionario*/
template <class T, class U>
typename Diccionario<T, U>::const_iterator Diccionario<T, U>::cbegin() const {
  return Diccionario<T, U>::const_iterator(datos.cbegin());
}

template <class T, class U>
typename Diccionario<T, U>::const_iterator Diccionario<T, U>::cend() const {
  return Diccionario<T, U>::const_iterator(datos.cend());
}


template <class T, class U>
T Diccionario<T,U>::getClave(Diccionario<T, U>::iterator it){
  return (*it).clave;
}

template <class T, class U>
Diccionario<T, U> Diccionario<T, U>::operator +(Diccionario<T, U> &D){
  Diccionario<T,U>::iterator it;
      for(it = D.begin(); it != D.end(); ++it){
        T clave = D.getClave(it);
        Insertar(clave, D.getInfo_Asoc(clave));
      }
   return *this;
}

template <class T, class U>
Diccionario<T, U> Diccionario<T,U>::comunes(Diccionario<T,U> &D2){
  Diccionario <T, U> dic;
  if(size() > 0 && D2.size() > 0){
    Diccionario<T,U>::iterator it;
    Diccionario<T,U>::iterator itD;
    for(itD = begin(); itD != end(); ++itD){
      bool insertar = false;
      T claveD1 = getClave(itD);
      for(it = D2.begin(); it != D2.end(); ++it){
        T claveD2 = D2.getClave(it);
        if( claveD2 == claveD1)
            insertar = true;
      }
          
      if(insertar)
        dic.Insertar(claveD1, getInfo_Asoc(claveD1));
    }
  }  

  return dic;
}

template <class T, class U>
void Diccionario<T,U>::concatenar(Diccionario<T,U> &D){
  *this = *this + D;
}
