#ifndef _GUIA_TLF_H
#define _GUIA_TLF_H
#include <map>
#include <iostream>
#include <string>
using namespace std;  


class Guia_Tlf{
	  private:
		    map<string,string> datos; //si admites que haya nombres repetidos tendr�as que usar un
					     //multimap
					     
	  public:
		//Guia_Tlf(){}
		//Guia_Tlf(const Guia_Tlf & gt);
		//~Guia_Tlf(){}
		//Guia_Tlf & operator=(const Guia_Tlf & gt);
		/**
			 @brief Acceso a un elemento
			@param nombre: nombre del elemento  elemento acceder
			@return devuelve el valor asociado a un nombre, es decir el teléfono
		*/
		string & operator[](const string &nombre);
		
		
		string  gettelefono(const string & nombre);
			
		/**
		 @brief Insert un nuevo telefono 
			@param nombre: nombre clave del nuevo telefono
			@param tlf: numero de telefono
			@return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o false en caso contrario
		*/
		pair<map<string,string>::iterator,bool>  insert(string nombre, string tlf);
		
		/**
		 @brief Insert un nuevo telefono 
			@param p: pair con el nombre y el telefono asociado
			
			@return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o false en caso contrario
		*/
		pair<map<string,string>::iterator,bool>  insert(pair<string,string> p);
		
		
		
		/**
			 @brief Borrar un telefono
			@param nombre: nombre que se quiere borrar
			@note: en caso de que fuese un multimap borraria todos con ese nombre
		*/
		void borrar(const string &nombre);
		
		/**
			 @brief Borrar un telefono
			@param nombre: nombre que se quiere borrar y telefono asociado
			@note: esta funcion nos permite borrar solamente aquel que coincida en nombre y tlf
		*/
		//con map siempre hay uno con multimap puede existir mas de uno
		void borrar(const string &nombre,const string &tlf);
		/**
			 @brief  Numero de telefonos 
			@return el numero de telefonos asociados
			*/
		int size()const;     
		/**
			 @brief Contabiliza cuantos telefonos tenemos asociados a un nombre
			@param nombre: nombre sobre el que queremos consultar
			@return numero de telefonos asociados a un nombre
			
			*/
		//al ser un map debe de ser 0 o 1. Si fuese un multimap podr�amos tener mas de uno
		unsigned int contabiliza(const string &nombre);
		
		/**
			 @brief Limpia la guia
			*/
		void clear();

		/**
			 @brief Union de guias de telefonos
			@param g: guia que se une
			@return: una nueva guia resultado de unir el objeto al que apunta this y g
		*/
		Guia_Tlf operator+(const Guia_Tlf & g);	   
					
		/**
			 @brief Diferencia de guias de telefonos
			@param g: guia que se une
			@return: una nueva guia resultado de la diferencia del objeto al que apunta this y g
		*/
		Guia_Tlf operator-(const Guia_Tlf & g);
		
		/**
			 @brief Escritura de la guia de telefonos
			@param os: flujo de salida. Es MODIFICADO
			@param g: guia de telefonos que se escribe
			@return el flujo de salida
			*/ 
			
		
		friend ostream & operator<<(ostream & os, Guia_Tlf & g);
		
		/**
			 @brief Lectura de  la guia de telefonos
			@param is: flujo de entrada. ES MODIFICADO
			@param g: guia de telefonos. ES MODIFICADO
			@return el flujo de entrada
		*/
		
		friend istream & operator>>(istream & is, Guia_Tlf & g);

	//CLASE ITERATOR
	class iterator
	{
	private:
		typename map<string, string>::iterator map_it;
		iterator(typename map<string, string>::iterator it);
		friend class Guia_Tlf;

	public:

 		iterator();

		iterator(const iterator &it);

		iterator &operator=(const iterator &it);

		iterator &operator++();

		iterator &operator--();

		pair<const string, string> &operator*();

		bool operator==(const iterator &it) const;

		bool operator!=(const iterator &it) const;
	};

	iterator begin();
	iterator end();


	//CLASE CONST ITERATOR
	class const_iterator
	{
	private:
		typename map<string, string>::const_iterator map_it;
		const_iterator(typename map<string, string>::const_iterator it);
		friend class Guia_Tlf;

	public:

 		const_iterator();

		const_iterator(const const_iterator &it);

		const_iterator &operator=(const const_iterator &it);

		const_iterator &operator++();

		const_iterator &operator--();

		const pair<const string, string> &operator*() const;

		bool operator==(const Guia_Tlf::const_iterator &it) const;

		bool operator!=(const Guia_Tlf::const_iterator &it) const;
	};

	const_iterator cbegin() const;
	const_iterator cend() const;
		    	    
/**
    @brief Método busca los contactos por debajo de un nombre dado (inclusive)
    @param n1: nombre de un contacto
    @return guia de teléfonos nueva
*/
	Guia_Tlf Buscar_contactos_por_debajo_nombre(string n1);

	/**
	@brief Método que devuelve una guia de teléfonos con los contactos que empiezan por la misma letra
	@param letra: primera letra del nombre
	@return guia de teléfonos nueva
	*/
	Guia_Tlf Buscar_contactos_por_letra(char letra);

	/**
	@brief Método que devuelve el nombre de un numero de tlf
	@param tlf: numero de tlf
	@return nombre asociado al tlf
	*/
	string  getNombre(const string & tlf);

	/**
	@brief Método que cuenta cuantos contactos hay con un nombre concreto en dos guias distintas
	@param nombre: nombre de un contacto
    @param guia: guia de tlf
	@return numero de nombres iguales
	*/
	int numeroNombresIguales(const string &nombre, const Guia_Tlf &guia2);
};
#endif

