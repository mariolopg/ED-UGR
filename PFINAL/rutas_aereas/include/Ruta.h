#include <vector>
#include <Punto.h>
#include <iostream>

class Ruta {

    private:
        vector<Punto> puntos;
 
    public:
    
    
        /**
         @brief Constructor de la clase Ruta
        */
        Ruta();
        
        /**
         @brief Constructor de la clase Ruta
         @param numPuntos: numero de puntos que va a tener la ruta
        */
        Ruta(int numPuntos);

        /**
         @brief Constructor de copia de la clase Ruta
         @param otra: ruta que se va a copiar en el objeto que se crea
        */
        Ruta(const Ruta &otra);

        /**
         @brief Consultor del tamaño de la ruta
         @return Devuelve el tamaño de la ruta
        */
        int getNumPuntos() const;
        
        /**
         @brief Método que inserta un punto en la ruta
         @param P: punto que va a ser insertado en la ruta
        */
        void insertarPunto(const Punto &P);
        
        /**
         @brief Operador ==
         @param ruta: ruta que se va a comparar con el objeto que llama al método
         @return Devuelve true si son iguales, false en caso contrario
        */
        bool operator==(const Ruta &ruta) const;

        class iterator {
        private:
            typename vector<Punto>::iterator vit;
            
            /**
             @brief Constructor privado a partir de un iterador de vector
            */
            iterator(typename vector<Punto>::iterator it);
            
            friend class Ruta;

        public:
            
            /**
             @brief Constructor por defecto de iterator
            */
            iterator();

            /**
             @brief Constructor de copia de la clase iterator
             @param it: iterador que se va a usar para inicializar el objeto que se crea
            */
            iterator(const iterator &it);
            
            /**
             @brief Sobrecarga del operador =
             @param it: iterador que se va a copiar en el objeto que llama al metodo.
             @return El nuevo valor del objeto que llama al metodo
            */
            iterator &operator=(const iterator &it);

            /**
             @brief Sobrecarga del operador ++ 
             @return El iterador que llama al metodo desplazado una posición más
            */
            iterator &operator++();

            /**
             @brief Sobrecarga del operador -- 
             @return El iterador que llama al metodo desplazado una posición menos
            */
            iterator &operator--();
            
            /**
             @brief Sobrecarga del operador *
             @return Punto apuntado por el iterador que llama al método.
            */
            Punto &operator*();

            /**
             @brief Sobrecarga del operador !=
             @param it: iterador con el que se va a comparar el objeto con el que se llama al método
             @return true si son distintos, false en caso contrario
            */
            bool operator!=(const iterator &it) const;

            /**
             @brief Sobrecarga del operador ==
             @param it: iterador con el que se va a comparar el objeto con el que se llama al método
             @return true si son iguales, false en caso contrario
            */
            bool operator==(const iterator &it) const;
        };

        /**
         @brief Consultor de un punto de la ruta
         @param it: iterador que apunta al punto que queremos consultar
         @return Devuelve el punto apuntado por it
        */
        Punto getPunto(Ruta::iterator it);
        
        /**
         @brief Iterador que apunta al principio de la ruta
         @return Iterador al comienzo de la ruta
        */
        iterator begin();

        /**
         @brief Iterador que apunta al final de la ruta
          @return Iterador al final de la ruta 
        */
        iterator end();
        
        /**
			@brief Escritura de la ruta
			@param os: flujo de salida. Es MODIFICADO
			@param ar: almacen de rutas que se escribe
			@return el flujo de salida
			*/
        friend ostream & operator<<(ostream & os, const Ruta &R);
        
        /**
			@brief Lectura de la ruta
			@param is: flujo de entrada. ES MODIFICADO
			@param ar: almacen de rutas. ES MODIFICADO
			@return el flujo de entrada
		*/
        friend istream & operator>>(istream & is, Ruta &R);
        
};