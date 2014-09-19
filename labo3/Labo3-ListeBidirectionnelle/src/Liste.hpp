/**
 * \file Liste.hpp
 * \brief Le code des opérateurs de Liste.
 * \author Ludovic Trottier
 * \author Mathieu Dumoulin
 * \version 0.3
 * \date mai 2014
 *
 * Implémentation dans une liste doublement chaînée (bidirectionnelle).
 *
 */

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
//#include "ContratException.h""




namespace lab03 {
/**
 * \brief constructeur par defaut
 * \post Une instance de la classe Liste est initialisée
 */
template<typename T>
Liste<T>::Liste() :
		m_sommetG(0), m_sommetD(0), m_cardinalite(0) {
}
/**
*\briefConstructeur de copie.

*\Pre Il faut qu'il y ait suffisamment de mémoire
*\Post La liste passée en paramètre est copiée
*\Param[in]	p_source	La liste à copier
*\Exception bad_alloc	s'il n'y a pas assez de mémoire
*/

template<typename T>
Liste<T>::Liste(const Liste & p_source)throw (std::bad_alloc) {
	this->_copier(p_source->m_sommetG);
}
/**
 * \brief Destructeur.
 * \Post L'instance de Liste est détruite.
 */

template<typename T>
Liste<T>::~Liste() {
	this->_detruire();
}
/**\briefSurcharge de l'opérateur =.
*\Pre Il y a assez de mémoire pour l'opération
*\Post La liste passée en paramètre est copiée
*\Param[in]	p_source	La liste à copier
*\Exception bad_alloc	si la précondition n'est pas respectée
*/
template<typename T>
const Liste<T>::Liste<T> & operator =(const Liste<T> & p_source) throw (std::bad_alloc){
	if(this != p_source){
		this->_detruire();
		this->_copier(p_source->sommetG);
	}
}
/**\brief Ajouter un nouvel élément dans la liste.

*\Pre Il y a assez de mémoire pour ajouter l'élément x La position d'ajout, pos, est comprise entre 1 et |L|+1
*\Post La liste comprend un élément de plus La liste est inchangée sinon
*\Param[in]	p_element	L'élément à ajouter
*\param[in]	p_position	La position de l'élément à ajouter
*\Exception bad_alloc	si pas assez de mémoire
*/
template<typename T>
void Liste<T>::ajouter(const T & p_element , const int & p_position)  throw (std::bad_alloc) {

}

template<typename T>
void Liste<T>::enleverEl(const T & elem){
	this->_enlever(elem);
}
template<typename T>
void Liste<T>::enleverPos(const int &);

template<typename T>
int Liste<T>::taille() const;

template<typename T>
bool Liste<T>::estVide() const;

template<typename T>
bool Liste<T>::appartient(const T &) const;

template<typename T>
T Liste<T>::element(const int &) const;

template<typename T>
int Liste<T>::position(const T &) const;

template<typename T>
void Liste<T>::verifieInvariant() const;

} //fin namespace

