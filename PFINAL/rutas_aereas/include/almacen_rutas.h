#include "Ruta.h"
#include <map>

class Almacen_Rutas
{
private:
	map<string, Ruta> rutas;

public:
	/**
			@brief Acceso a un elemento
			@param codigo: codigo del elemento  elemento acceder
			@return devuelve el valor asociado a un codigo, es decir la ruta
		*/
	Ruta &operator[](const string &codigo);

	/**
			@brief Acceso a un elemento
			@param codigo: codigo del elemento  elemento acceder
			@return devuelve el valor asociado a un codigo, es decir la ruta
		*/
	Ruta GetRuta(const string &codigo);

	/**
		 	@brief Insert una nueva ruta 
			@param codigo: codigo clave de la nueva ruta
			@param ruta: numero de ruta
			@return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado la nuevo ruta o false en caso contrario
		*/
	pair<map<string, Ruta>::iterator, bool> insert(string codigo, const Ruta &ruta);

	/**
		 	@brief Insert una nueva ruta 
			@param p: pair con el codigo y la ruta asociado
			
			@return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado la nueva ruta o false en caso contrario
		*/
	pair<map<string, Ruta>::iterator, bool> insert(pair<string, Ruta> p);

	/**
			@brief Borrar una ruta
			@param codigo: codigo que se quiere borrar
			@note: en caso de que fuese un multimap borraria todos con ese codigo
		*/
	void borrar(const string &codigo);

	/**
			@brief Borrar una ruta
			@param codigo: codigo que se quiere borrar y ruta asociada
			@note: esta funcion nos permite borrar solamente aquel que coincida en codigo y ruta
		*/
	//con map siempre hay uno con multimap puede existir mas de uno
	void borrar(const string &codigo, const Ruta &ruta);

	/**
			@brief  Numero de rutas 
			@return el numero de rutas asociadas
			*/
	int size() const;

	/**
			 @brief Limpia el almacén
			*/
	void clear();

	/**
			@brief Escritura del almacen de rutas
			@param os: flujo de salida. Es MODIFICADO
			@param ar: almacen de rutas que se escribe
			@return el flujo de salida
			*/

	friend ostream &operator<<(ostream &os, Almacen_Rutas &ar);

	/**
			@brief Lectura del almacen de rutas
			@param is: flujo de entrada. ES MODIFICADO
			@param ar: almacen de rutas. ES MODIFICADO
			@return el flujo de entrada
		*/

	friend istream &operator>>(istream &is, Almacen_Rutas &ar);

	//CLASE ITERATOR
	class iterator
	{
	private:
		typename map<string, Ruta>::iterator map_it;

		/**
             @brief Constructor privado a partir de un iterador de vector
            */
		iterator(typename map<string, Ruta>::iterator it);
		friend class Almacen_Rutas;

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
             @brief Sobrecarga del operador=
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
             @return Ruta apuntada por el iterador que llama al método.
            */
		pair<const string, Ruta> &operator*();

		/**
             @brief Sobrecarga del operador ==
             @param it: iterador con el que se va a comparar el objeto con el que se llama al método
             @return true si son iguales, false en caso contrario
            */
		bool operator==(const iterator &it) const;

		/**
             @brief Sobrecarga del operador !=
             @param it: iterador con el que se va a comparar el objeto con el que se llama al método
             @return true si son distintos, false en caso contrario
            */
		bool operator!=(const iterator &it) const;
	};

	/**
	 @brief Iterador que apunta al comienzo del almacén de rutas
	 @return Iterador al comienzo del almacén
	*/
	iterator begin();

	/**
	 @brief Iterador que apunta al final del almacén de rutas
	 @return Iterador al final del almacén 
	*/
	iterator end();
};