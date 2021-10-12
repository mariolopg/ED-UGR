#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

/*Tipo elemento que define el diccionario. T es el tipo de dato asociado a una clave que
no se repite (DNI p.ej.) y list<U> es una lista de datos (string p.ej) asociados a la clave
de tipo T. El diccionario está ordenado de menor a mayor clave.
*/
template <class T, class U>
struct data
{
	T clave;
	list<U> info_asoci;
};

/*Comparador de datos. Ordena 2 registros de acuerdo a la clave de tipo T. Puede usarse como
 un funtor.
 */
template <class T, class U>
bool operator<(const data<T, U> &d1, const data<T, U> &d2)
{
	if (d1.clave < d2.clave)
		return true;
	return false;
}

/*Un diccionario es una lista de datos de los definidos anteriormente. Cuidado porque se
manejan listas de listas. Se añaden 2 funciones privadas que hacen más facil la implementación
de algunos operadores o funciones de la parte pública. Copiar copia un diccioario en
otro y borrar elimina todos los elementos de un diccionario. La implementación de copiar
puede hacerse usando iteradores o directamente usando la función assign.
*/
template <class T, class U>
class Diccionario{

private:
	list<data<T, U>> datos;

	void Borrar();

public:

	void Copiar(const Diccionario<T, U> &D);

	/* Constructor por defecto*/
	Diccionario();

	/* Constructor de copias*/
	Diccionario(const Diccionario &D);

	/* Desstructor*/
	~Diccionario();

	/* Operador de asignación*/
	Diccionario<T, U> &operator=(const Diccionario<T, U> &D);

	/* Busca la clave p en el diccionario. Si está devuelve un iterador a
		dónde está clave. Si no está, devuelve end() y deja el iterador de salida
		apuntando al sitio dónde debería estar la clave
		*/
	bool Esta_Clave(const T &p, typename list<data<T, U>>::iterator &it_out);

	/* Inserta un nuevo registro en el diccionario. Lo hace a través de la clave
		 e inserta la lista con toda la información asociada a esa clave. Si el 
		 diccionario no estuviera ordenado habría que usar la función sort() 
		 */
	void Insertar(const T &clave, const list<U> &info);

	/*Añade una nueva informacion asocida a una clave que está en el diccionario.
		 la nueva información se inserta al final de la lista de información.
                  Si no esta la clave la inserta y añade la informacion asociada. 
		 */
	void AddSignificado_Palabra(const U &s, const T &p);

	/* Devuelve la información (una lista) asociada a una clave p. Podrían 
		 haberse definido operator[] como
		 data<T,U> & operator[](int pos){ return datos.at(pos);}
		 const data<T,U> & operator[](int pos)const { return datos.at(pos);}
		  */
	list<U> getInfo_Asoc(const T &p);

	/*Devuelve el tamaño del diccionario*/
	int size() const;

	//CLASE ITERATOR
	class iterator
	{
	private:
		typename list<data<T, U>>::iterator list_it;
		iterator(typename list<data<T, U>>::iterator it);
		friend class Diccionario<T, U>;

	public:
		iterator();
		iterator(const iterator &it);

		iterator &operator=(const iterator &it);

		iterator &operator++();
		iterator &operator--();
		data<T, U> &operator*();

		bool operator!=(const iterator &it) const;
		bool operator==(const iterator &it) const;
	};

	iterator begin();
	iterator end();


	//CLASE CONST ITERATOR
	class const_iterator
	{
	private:
		typename list<data<T, U>>::const_iterator list_it;
		const_iterator(typename list<data<T, U>>::const_iterator it);
		friend class Diccionario<T, U>;

	public:
		const_iterator();
		const_iterator(const const_iterator &it);

		const_iterator &operator=(const const_iterator &it);

		const_iterator &operator++();
		const_iterator &operator--();
		const data<T, U> &operator*() const;

		bool operator!=(const const_iterator &it) const;
		bool operator==(const const_iterator &it) const;
	};

	const_iterator cbegin() const;
	const_iterator cend() const;

	/**
		@brief Consultor de la clave asociada a un iterador
		@param it: iterador 
		@return Devuelve una clave
	*/
	T getClave(Diccionario<T, U>::iterator it);

	/**
		@brief Sobrecarga del operador +
		@param D2: Diccionario que se va a sumar
		@return Suma de los dos diccionarios
	*/
	Diccionario<T, U> operator +(Diccionario<T, U> &D2);

	/**
		@brief Método para buscar claves comunes a dos diccionarios
		@param D2: Diccionario
		@return Diccionario con las claves comunes
	*/
	Diccionario<T, U> comunes(Diccionario<T,U> &D2);

	/**
		@brief Método para añadir un diccionario a otro
		@param D: Diccionario que se va a sumar
	*/
	void concatenar(Diccionario<T,U> &D);

};



#include "diccionario.cpp"

#endif
