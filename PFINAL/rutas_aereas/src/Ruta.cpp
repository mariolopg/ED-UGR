#include "Ruta.h"
#include <iostream>
#include <vector>

using namespace std;

Ruta::Ruta(){
    puntos = vector<Punto>();
}
 
Ruta::Ruta(int numPuntos){
    puntos = vector<Punto>(numPuntos);
}

Ruta::Ruta(const Ruta &otra){
    puntos = vector<Punto>(otra.puntos);
}

int Ruta::getNumPuntos() const{
    return puntos.size();
}

void Ruta::insertarPunto(const Punto &P){
    puntos.push_back(P);
}

bool Ruta::operator==(const Ruta &ruta) const{
   return puntos == ruta.puntos;
}

// CLASE ITERATOR ----------------------------------------------
Ruta::iterator::iterator(typename vector<Punto>::iterator it){
    vit = it;
}
            
Ruta::iterator::iterator(){
    vit = typename vector<Punto>::iterator();
}

Ruta::iterator::iterator(const iterator &it){
    vit = it.vit;
}

typename Ruta::iterator &
Ruta::iterator::operator=(const iterator &it){
     if (this != &it){
        vit = it.vit;
    }

    return *this;
}
 
typename Ruta::iterator &
Ruta::iterator::operator++(){
    vit++;
    return *this;
}

typename Ruta::iterator &
Ruta::iterator::operator--(){
    vit--;
    return *this;
}

Punto &Ruta::iterator::operator*(){
    return (*vit);
}

bool Ruta::iterator::operator!=(const iterator &it) const{
    return vit != it.vit;
}

bool Ruta::iterator::operator==(const iterator &it) const{
    return vit == it.vit;
} 

// --------------------------------------------------------------

Ruta::iterator Ruta::begin(){
    return Ruta::iterator(puntos.begin());
}

Ruta::iterator Ruta::end(){
    return Ruta::iterator(puntos.end());
}

Punto Ruta::getPunto(Ruta::iterator it){
    return *it;
}

ostream & operator<<(ostream & os, const Ruta &R){
    Ruta::iterator it;
    Ruta copia = Ruta(R); //Para usar metodos no const
    os << copia.getNumPuntos();
    for (it = copia.begin(); it != copia.end(); ++it){
        os << (*it)  << " ";
    }
    return os;
}

istream & operator>>(istream & is, Ruta &R){
    Punto pto;
    int size;
    is >> size;
    for(int i = 0; i < size; i++){
        is >> pto;
        R.insertarPunto(pto);
    }

    return is;    
}