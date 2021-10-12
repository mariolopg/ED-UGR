#ifndef __PUNTO_H__
#define __PUNTO_H__
#include <string>
#include <iostream>

using namespace std;

class Punto{
   private:
        double longitud; //Eje x
        double latitud; //Eje y
        string etiqueta;

    public:

        /**
         @brief Constructor de la clase Punto
        */
        Punto();

        /**
         @brief Constructor de la clase Punto
         @param lat: latitud del objeto que se crea
         @param lng: longitud del objeto que se crea
         @param etiq: etiqueta del objeto que se crea, por defecto " "
        */
        Punto(double lat, double lng, string etiq="");
        
        /**
         @brief Operador ==
         @param P: punto que se va a comparar con el objeto que llama al método
         @return Devuelve true si son iguales, false en caso contrario
        */
        bool operator==(const Punto &P) const;
        
        /**
         @brief Operador ==
         @param P: punto que se va a copiar con el objeto que lo llama
        */
        void operator=(const Punto &P);
        
        /**
         @brief Consultor de la latitud
         @return valor de latitud del objeto que llama al método
        */
        double GetLatitud() const;
        
        /**
         @brief Consultor de la longitud
         @return valor de longitud del objeto que llama al método
        */
        double GetLongitud() const;
        
        /**
         @brief Consultor de la etiqueta
         @return valor de la etiqueta del objeto que llama al método
        */
        string getEtiqueta() const;

        /**
         @brief Modificador del atributo latitud
         @param lat: nuevo valor de la latitud
        */        
        void setLatitud(double lat);
        
        /**
         @brief Modificador del atributo longitud
         @param lng: nuevo valor de la longitud
        */
        void setLongitud(double lng);
        
        /**
         @brief Modificador del atributo etiqueta
         @param etiq: nuevo valor de la etiqueta
        */
        void setEtiqueta(string etiq);
        
        /**
         @brief Escritura del punto
         @param os: flujo de salida. Es MODIFICADO
         @param ar: almacen de rutas que se escribe
         @return el flujo de salida
		*/
        friend ostream & operator<<(ostream & os, const Punto &P);
        
        /**
			@brief Lectura del punto
			@param is: flujo de entrada. ES MODIFICADO
			@param ar: almacen de rutas. ES MODIFICADO
			@return el flujo de entrada
		*/
        friend istream & operator>>(istream & is, Punto &P);         
};
#endif