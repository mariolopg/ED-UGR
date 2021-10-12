#include "almacen_rutas.h" 
#include <iostream>
#include <string>
#include <map>

using namespace std;

Ruta & Almacen_Rutas::operator[](const string &codigo){
    return rutas[codigo];
}


Ruta Almacen_Rutas::GetRuta(const string &codigo){
    map<string, Ruta>::iterator it = rutas.find(codigo);
    if (it == rutas.end())
        return Ruta();
    else
        return it->second;
}
    

pair<map<string,Ruta>::iterator,bool>  Almacen_Rutas::insert(string codigo, const Ruta &ruta){
    pair<string, Ruta> p(codigo, ruta);
    pair<map<string, Ruta>::iterator, bool> ret;

    ret = rutas.insert(p);
    return ret;
}


pair<map<string,Ruta>::iterator,bool>  Almacen_Rutas::insert(pair<string,Ruta> p){
    pair<map<string, Ruta>::iterator, bool> ret;

    ret = rutas.insert(p);
    return ret;
}



void Almacen_Rutas::borrar(const string & codigo){
    map<string, Ruta>::iterator itlow = rutas.lower_bound(codigo);   //el primero que tiene dicho codigo
    map<string, Ruta>::iterator itupper = rutas.upper_bound(codigo); //el primero que ya no tiene dicho codigo
    rutas.erase(itlow, itupper);  
}


void Almacen_Rutas::borrar(const string &codigo,const Ruta &ruta){
    map<string, Ruta>::iterator itlow = rutas.lower_bound(codigo);   //el primero que tiene dicho codigo
    map<string, Ruta>::iterator itupper = rutas.upper_bound(codigo); //el primero que ya no tiene dicho codigo
    map<string, Ruta>::iterator it;
    bool salir = false;
    for (it = itlow; it != itupper && !salir; ++it)
    {
        if (it->second == ruta)
        {
            rutas.erase(it);
            salir = true;
        }
    }
}


int Almacen_Rutas::size()const{
    return rutas.size();
}     


void Almacen_Rutas::clear(){
    rutas.clear();
}

//CLASS ITERATOR ---------------------------------------------

Almacen_Rutas::iterator::iterator(typename map<string, Ruta>::iterator it){
    map_it = it;
}

Almacen_Rutas::iterator::iterator()
{
    this->map_it = map_it;
}

Almacen_Rutas::iterator::iterator(const Almacen_Rutas::iterator &it)
{
    this->map_it = map<string, Ruta>::iterator();
}

Almacen_Rutas::iterator &Almacen_Rutas::iterator::operator=(const iterator &it)
{
    if (this != &it)
    {
        map_it = it.map_it;
    }

    return *this;
}

Almacen_Rutas::iterator &Almacen_Rutas::iterator::operator++()
{
    map_it++;
    return *this;
}

Almacen_Rutas::iterator &Almacen_Rutas::iterator::operator--()
{
    map_it--;
    return *this;
}

pair<const string, Ruta> &Almacen_Rutas::iterator::operator*()
{
    return *map_it;
}

bool Almacen_Rutas::iterator::operator==(const Almacen_Rutas::iterator &it) const
{
    return this->map_it == it.map_it;
}

bool Almacen_Rutas::iterator::operator!=(const Almacen_Rutas::iterator &it) const
{
    return this->map_it != it.map_it;
}

// -------------------------------------------------------------------------------------

Almacen_Rutas::iterator Almacen_Rutas::begin() {
  return Almacen_Rutas::iterator(rutas.begin());
}

Almacen_Rutas::iterator Almacen_Rutas::end()
{
    return Almacen_Rutas::iterator(rutas.end());
}

ostream & operator<<(ostream & os, Almacen_Rutas &ar){
    map<string, Ruta>::iterator it;
    for (it = ar.rutas.begin(); it != ar.rutas.end(); ++it)
    {
        os << it->first << " " << ar.size() << " " << it->second << endl;
    }
    return os; 
}


istream & operator>>(istream & is, Almacen_Rutas &ar){
    string codigo;
    Ruta ruta;
    string palabra_magica;
    cout << "entra operador >> almacen ruta" << endl;
    getline(is, palabra_magica);
    if (palabra_magica == "#Rutas")  
        while(!is.eof()){
            is >> codigo >> ruta; 
            ar.insert(codigo,ruta);
        }
    return is;
} 