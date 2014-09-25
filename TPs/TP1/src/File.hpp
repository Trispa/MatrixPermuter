//! \file File.inl
//! \brief Le code des opérateurs de la file.
//! \author Patrice Diouf
//! \version 0.1
//! \date semptembre 2013
//! Implémentation de la classe générique File dans une liste chaénée
//!
//!

#ifndef _FILE_HPP
#define _FILE_HPP

#include <stdexcept>
using namespace std;

namespace tp1 {

//!
//! \fn File<T>::File()
//! \brief pour permettre la construction d'un objet File
//! \exception throw(std::bad_alloc:
//!
template<typename T>
File<T>::File() {
	tete = 0;
	queue = 0;
	cpt = 0;
}

//!
//! \fn File<T>::File(const File &p_source) throw(bad_alloc)
//! \breif Construir une file par copi d'une autre File p_source
//! \param[in] p_source La file p_source
//! \exception throw(std::bad_alloc)
template<class T>
File<T>::File(const File &p_source) {
	tete = p_source.tete;
	queue = p_source.queue;
	cpt = p_source.cpt;
	if (cpt != 0)
		_copier(p_source.tete);
}

//!
//! \fn File<T>::~File()
//! \brief dstruction d'une file
template<typename T>
File<T>::~File() {
	_detruire();
}

//!
//! \fn void File<T>::enfiler(const T& p_elementAEnfiler)throw (bad_alloc)
//! \brief ajouter une objet de type T dans la File
//! \param[in] p_elementAEnfiler élément é enfiler
//! \exception throw (std::bad_alloc)
template<class T>
void File<T>::enfiler(const T& p_elementAEnfiler) {	// enfiler un élément dans la File

	// créer un nouveau noeud
	elem nouveau = new Noeud(p_elementAEnfiler);
	nouveau->suivant = 0;
	if (cpt == 0) {
		tete = nouveau;
		queue = tete;
	} else {
		queue->suivant = nouveau;
		queue = nouveau;
	}
	cpt++;
}

//!
//! \fn T File<T>::defiler()throw(logic_error)
//! \breif enlever une element de la file
//! \return T - élément défilé
//! \exception throw(std::logic_error)
template<typename T>
T File<T>::defiler() {
	// défiler un élément de la File
	if (!estVide()) {
		T deFiler = tete->el;
		elem temp;
		temp = tete;
		tete = tete->suivant;
		delete temp;
		cpt--;
		if (cpt == 0) {
			queue = 0;
		}
		return (deFiler);
	}
	throw logic_error("Defiler: la File est vide!");
}

//!
//! \fn int File<T>::taille() const
//! \breif pour connaitre la taille de la File actuelle
//! \return La taille de la file
//!
template<typename T>
int File<T>::taille() const {
	return cpt;
}

//!
//! \fn bool File<T>:: estVide() const
//! \brief verifie si une File est vide  ou pas
//! \return true ou false
//!/
template<typename T>
bool File<T>::estVide() const {
	return cpt == 0;
}

//!
//! \fn const T& File<T>:: premier()const throw (logic_error)
//! \brief permet de connaitre le premier element de la File
//! \return Une copie de T, l'élément en téte de file
//! \exception throw (std::logic_error)
template<typename T>
const T& File<T>::premier() const {
	if (tete != 0) //file non vide
		return tete->el;
	throw logic_error("Premier: la file est vide!");
}

//!
//! \fn const T& File<T>:: dernier()const throw (logic_error)
//! \brief permet de connaitre le dernier element de la File
//! \return Une copie de T, l'élément en queue de file
//! \exception throw (std::logic_error)
template<typename T>
const T& File<T>::dernier() const {
	if (tete != 0) //file non vide
		return queue->el;
	throw logic_error("Dernier: la file est vide!");
}

//!
//! \fn const T& File<T>::operator [](int indice) const throw (out_of_range)
//! \param[in] indice L'indice de l'élément
//! \return T - Element recherche
//! \exception throw  throw (std::out_of_range)
template<typename T>
const T& File<T>::operator[](int indice) const
// retourne un élément de la file
		{
	elem temp = tete;
	if (indice >= 0 && indice < cpt) {
		for (int i = 0; i < indice; i++)
			temp = temp->suivant;
		return temp->el;
	} else
		throw out_of_range("Operator []: Debordement d'indice");
}

//!
//! \fn const File<T>& File<T>::operator = (const File<T>& f) throw(bad_alloc)
//! \param[in] f La file qu'on veut affecter
//! \return Une file, copie profonde de la p_source
//! \exception throw(std::bad_alloc)
template<typename T>
const File<T>& File<T>::operator =(const File<T>& f) {
	if (tete != 0){//nettoyer ...
		_detruire();
	}
	tete = f.tete;
	queue = f.queue;
	cpt = f.cpt;
	if (f.tete != 0) //si la file p_source n'est pas vide
		_copier(f.tete);

	return (*this);
}

//!
//! \fn std::ostream& operator << (std::ostream& f, const File<T>& q)
//! \param[in, out] f Le flux de sortie
//! \param[in] q Une file
//! \return Une référence sur le flux de sortie
//!
template<typename T>
std::ostream& operator <<(std::ostream& f, const File<T>& q) {
	typename File<T>::elem courant = q.tete;
	while (courant != 0) {
		f << courant->el << ", ";
		courant = courant->suivant;
	}
	return f;
}

//!
//! \fn void File<T>::_detruire()
//!
template<typename T>
void File<T>::_detruire() {
	elem courant = tete;

	while (tete != 0) {
		tete = courant->suivant;
		delete courant;
		courant = tete;
	}
	queue = 0;
	cpt = 0;
}

//!
//! \fn void File<T>:: _copier(Noeud //! sn) throw (std::bad_alloc)
//! \brief permet de faire la copie d'une Liste sous fore de File
//! \param[in] sn Le pointeur sur le début de la file p_source
//!
template<typename T>
void File<T>::_copier(Noeud *sn) {
	try {
		//copie le permier noeud
		tete = new Noeud(sn->el);
		// copie le reste de la liste
		queue = tete;
		for (elem temp = sn->suivant; temp != 0; temp = temp->suivant) {
			queue->suivant = new Noeud(temp->el);
			queue = queue->suivant;
		}
	} catch (exception&) {
		//Si on arrive ici c'est qu'il y a une erreur d'allocation
		//On doit donc libérer la mémoire déjé allouée
		_detruire();
		//On relance alors l'exception pour indiquer qu'une erreur est survenue
		throw;
	}

}
}			   // fin du namespace

#endif /* _FILE_HPP */
