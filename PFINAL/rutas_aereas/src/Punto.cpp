#include "Punto.h"
#include <string>
#include <iostream>

using namespace std;

Punto::Punto(){
    latitud = 0;
    longitud = 0;
    etiqueta = "";
} 

Punto::Punto(double lat, double lng, string etiq){
    latitud=lat;
    longitud=lng;
    etiqueta = etiq;
}

bool Punto::operator==(const Punto &P) const{
    return (latitud==P.GetLatitud()) && (longitud == P.GetLongitud());
}

void Punto::operator=(const Punto &P){
    latitud = P.GetLatitud();
    longitud = P.GetLongitud();
    etiqueta = P.getEtiqueta();
}

double Punto::GetLatitud() const {
    return latitud;
}

double Punto::GetLongitud() const {
    return longitud;
}

string Punto::getEtiqueta() const {
    return etiqueta;
}

void Punto::setLatitud(double lat){
    latitud = lat;
}

void Punto::setLongitud(double lng){
    longitud = lng;
}

void Punto::setEtiqueta(string etiq){
    etiqueta = etiq;
}

ostream & operator<<(ostream & os, const Punto &P){
    if (P.getEtiqueta() != ""){
        os << "Punto " << P.getEtiqueta() << ": ";
    }
    os << "(" << P.GetLongitud() << ", " << P.GetLongitud() << ")";

    return os;
} 

istream & operator >> (istream &is, Punto &P){
    char caracter;
    double lng, lat;
    is >> caracter >> lat >> caracter >> lng >> caracter;
    P = Punto(lat, lng);
    return is;
}