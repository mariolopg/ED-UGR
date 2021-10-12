#include <map>
#include <iostream>
#include <string>
#include <guiatlf.h>

using namespace std;

istream & operator>>(istream &is,pair<string,string> &d){
	  
	  getline(is,d.first,'\t');
	  getline(is,d.second);
	  return is;
}	

string &Guia_Tlf::operator[](const string &nombre)
{
    return datos[nombre];
}

string Guia_Tlf::gettelefono(const string &nombre)
{
    map<string, string>::iterator it = datos.find(nombre);
    if (it == datos.end())
        return string("");
    else
        return it->second;
}

/**
    @brief Insert un nuevo telefono 
    @param nombre: nombre clave del nuevo telefono
    @param tlf: numero de telefono
    @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o false en caso contrario
*/
pair<map<string, string>::iterator, bool> Guia_Tlf::insert(string nombre, string tlf)
{
    pair<string, string> p(nombre, tlf);
    pair<map<string, string>::iterator, bool> ret;

    ret = datos.insert(p);
    return ret;
}

/**
    @brief Insert un nuevo telefono 
    @param p: pair con el nombre y el telefono asociado
    @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o false en caso contrario
*/
pair<map<string, string>::iterator, bool> Guia_Tlf::insert(pair<string, string> p)
{

    pair<map<string, string>::iterator, bool> ret;

    ret = datos.insert(p);
    return ret;
}

/**
    @brief Borrar un telefono
    @param nombre: nombre que se quiere borrar
    @note: en caso de que fuese un multimap borraria todos con ese nombre
*/
void Guia_Tlf::borrar(const string &nombre)
{
    map<string, string>::iterator itlow = datos.lower_bound(nombre);   //el primero que tiene dicho nombre
    map<string, string>::iterator itupper = datos.upper_bound(nombre); //el primero que ya no tiene dicho nombre
    datos.erase(itlow, itupper);                                       //borramos todos aquellos que tiene dicho nombre
}

/**
    @brief Borrar un telefono
    @param nombre: nombre que se quiere borrar y telefono asociado
    @note: esta funcion nos permite borrar solamente aquel que coincida en nombre y tlf
*/
//con map siempre hay uno con multimap puede existir mas de uno
void Guia_Tlf::borrar(const string &nombre, const string &tlf)
{
    map<string, string>::iterator itlow = datos.lower_bound(nombre);   //el primero que tiene dicho nombre
    map<string, string>::iterator itupper = datos.upper_bound(nombre); //el primero que ya no tiene dicho nombre
    map<string, string>::iterator it;
    bool salir = false;
    for (it = itlow; it != itupper && !salir; ++it)
    {
        if (it->second == tlf)
        {
            datos.erase(it);
            salir = true;
        }
    }
}
/**
    @brief  Numero de telefonos 
    @return el numero de telefonos asociados
    */
int Guia_Tlf::size() const
{
    return datos.size();
}
/**
    @brief Contabiliza cuantos telefonos tenemos asociados a un nombre
    @param nombre: nombre sobre el que queremos consultar
    @return numero de telefonos asociados a un nombre
*/
//al ser un map debe de ser 0 o 1. Si fuese un multimap podr�amos tener mas de uno
unsigned int Guia_Tlf::contabiliza(const string &nombre)
{
    return datos.count(nombre);
}

/**
		      @brief Limpia la guia
		     */
void Guia_Tlf::clear()
{
    datos.clear();
}
/**
    @brief Union de guias de telefonos
    @param g: guia que se une
    @return: una nueva guia resultado de unir el objeto al que apunta this y g
*/
Guia_Tlf Guia_Tlf::operator+(const Guia_Tlf &g)
{
    Guia_Tlf aux(*this);
    map<string, string>::const_iterator it;
    for (it = g.datos.begin(); it != g.datos.end(); ++it)
    {
        aux.insert(it->first, it->second);
    }
    return aux;
}

/**
    @brief Diferencia de guias de telefonos
    @param g: guia que se une
    @return: una nueva guia resultado de la diferencia del objeto al que apunta this y g
*/
Guia_Tlf Guia_Tlf::operator-(const Guia_Tlf &g)
{
    Guia_Tlf aux(*this);
    map<string, string>::const_iterator it;
    for (it = g.datos.begin(); it != g.datos.end(); ++it)
    {
        aux.borrar(it->first, it->second);
    }
    return aux;
}

/**
		      @brief Escritura de la guia de telefonos
		      @param os: flujo de salida. Es MODIFICADO
		      @param g: guia de telefonos que se escribe
		      @return el flujo de salida
		     */

ostream &operator<<(ostream &os, Guia_Tlf &g)
{
    map<string, string>::iterator it;
    for (it = g.datos.begin(); it != g.datos.end(); ++it)
    {
        os << it->first << "\t" << it->second << endl;
    }
    return os; 
}

/**
    @brief Lectura de  la guia de telefonos
    @param is: flujo de entrada. ES MODIFICADO
    @param g: guia de telefonos. ES MODIFICADO
    @return el flujo de entrada
*/

istream &operator>>(istream &is, Guia_Tlf &g)
{
    pair<string, string> p;
    Guia_Tlf aux;

    while (is >> p)
    {
        aux.insert(p);
    }
    g = aux;
    return is;
}

//IMPLEMENTACION CLASS ITERATOR
Guia_Tlf::iterator::iterator(typename map<string, string>::iterator map_it) {
  this->map_it = map_it;
}
 Guia_Tlf::iterator::iterator() {
  this->map_it = map<string, string>::iterator();
}

Guia_Tlf::iterator::iterator(const iterator &it) {
  this->map_it = it.map_it;
}

Guia_Tlf::iterator &Guia_Tlf::iterator::operator=(const iterator &it) {
  if (this != &it) {
    map_it = it.map_it;
  }

  return *this;
}

Guia_Tlf::iterator &Guia_Tlf::iterator::operator++() {
  map_it++;
  return *this;
}

Guia_Tlf::iterator &Guia_Tlf::iterator::operator--() {
  map_it--;
  return *this;
}

pair<const string, string> &Guia_Tlf::iterator::operator*() {
  return *map_it;
}

bool Guia_Tlf::iterator::operator==(
    const Guia_Tlf::iterator &it) const {
  return this->map_it == it.map_it;
}

bool Guia_Tlf::iterator::operator!=(const Guia_Tlf::iterator &it) const {
  return this->map_it != it.map_it;
}

//Métodos begin y end de la clase Diccionario
Guia_Tlf::iterator Guia_Tlf::begin() {
  return Guia_Tlf::iterator(datos.begin());
}

Guia_Tlf::iterator Guia_Tlf::end() {
  return Guia_Tlf::iterator(datos.end());
}


//IMPLEMENTACION CLASS CONST ITERATOR
Guia_Tlf::const_iterator::const_iterator( typename map<string, string>::const_iterator map_it) {
  this->map_it = map_it;
}
 Guia_Tlf::const_iterator::const_iterator() {
  this->map_it = map<string, string>::iterator();
}

Guia_Tlf::const_iterator::const_iterator(const const_iterator &it) {
  this->map_it = it.map_it;
}

Guia_Tlf::const_iterator &Guia_Tlf::const_iterator::operator=(const const_iterator &it) {
  if (this != &it) {
    map_it = it.map_it;
  }

  return *this;
}

Guia_Tlf::const_iterator &Guia_Tlf::const_iterator::operator++() {
  map_it++;
  return *this;
}

Guia_Tlf::const_iterator &Guia_Tlf::const_iterator::operator--() { 
  map_it--;
  return *this;
}

const pair<const string, string> &Guia_Tlf::const_iterator::operator*() const {
  return *map_it;
}

bool Guia_Tlf::const_iterator::operator==(
    const Guia_Tlf::const_iterator &it) const {
  return this->map_it == it.map_it;
}

bool Guia_Tlf::const_iterator::operator!=(const Guia_Tlf::const_iterator &it) const {
  return this->map_it != it.map_it;
}

/*Funciones cbegin y cend asociadas al diccionario*/
Guia_Tlf::const_iterator Guia_Tlf::cbegin() const {
  return Guia_Tlf::const_iterator(datos.cbegin());
}

Guia_Tlf::const_iterator Guia_Tlf::cend() const {
  return Guia_Tlf::const_iterator(datos.cend());
}

/**
    @brief Método busca los contactos por debajo de un nombre dado (inclusive)
    @param n1: nombre de un contacto
    @return guia de teléfonos nueva
*/
Guia_Tlf Guia_Tlf::Buscar_contactos_por_debajo_nombre(string n1){
    Guia_Tlf::iterator it_n1;
    Guia_Tlf::iterator it_i;
    bool encuentra_n1;
    Guia_Tlf guiatlf_new;

    for(it_i = begin(); it_i != end() && !encuentra_n1; ++it_i)
        if((*it_i).first == n1){
            it_n1 = it_i;
            encuentra_n1 = true;
        }

   for(it_i = it_n1; it_i != end(); ++it_i)
       guiatlf_new.insert((*it_i).first, (*it_i).second);
    
    if( it_n1 == end())
      guiatlf_new.insert((*it_n1).first, (*it_n1).second);

   return guiatlf_new;
}

/**
    @brief Método que devuelve una guia de teléfonos con los contactos que empiezan por la misma letra
    @param letra: primera letra del nombre
    @return guia de teléfonos nueva
*/
Guia_Tlf Guia_Tlf::Buscar_contactos_por_letra(char letra){
    Guia_Tlf::iterator it_i;
    Guia_Tlf guiatlf_new;

    for(it_i = begin(); it_i != end(); ++it_i)
        if((*it_i).first[0] == letra)
            guiatlf_new.insert((*it_i).first, (*it_i).second);
    
    return guiatlf_new;
}

/**
	@brief Método que devuelve el nombre de un numero de tlf
	@param tlf: numero de tlf
	@return nombre asociado al tlf
*/
string  Guia_Tlf::getNombre(const string & tlf){
    Guia_Tlf::iterator it_i;
    string nombre = "No hay contactos con el tlf " + tlf;
    for(it_i = begin(); it_i != end(); ++it_i)
        if((*it_i).second == tlf)
            nombre = (*it_i).first;

    return nombre;
}

/**
	@brief Método que cuenta cuantos contactos hay con un nombre concreto en dos guias distintas
	@param nombre: nombre de un contacto
    @param guia: guia de tlf
	@return numero de nombres iguales
*/
int Guia_Tlf::numeroNombresIguales(const string &nombre, const Guia_Tlf &guia2){
    Guia_Tlf::iterator it_this;
    Guia_Tlf::iterator it;
    int numero_total = 0;

    for(it_this = datos.begin(); it_this != end(); ++it_this)
      if((*it_this).first == nombre)
        numero_total++;

    for(it = begin(); it != end(); ++it)
      if((*it).first == nombre)
        numero_total++;
    
    return numero_total;
}