//! \file File.h
//! \brief Classe définissant le type abstrait file
//! \author Patrice Diouf
//! \version 0.1
//! \date semptembre 2014-09-24
//! Implémentation dans une liste simplement chaénée
//!

#ifndef _FILE_H
#define _FILE_H
#include <iostream>

#include <stdexcept>  //Gestion des exceptions
namespace tp1 {
//!
//! \class File
//!
//! \brief Classe générique représentant une file
//!
//!  La classe gére une file générique. L'implémentation
//!  se fait dans une liste chaénée.
//!
template<typename T>
class File {
public:
	//	constructeurs et destructeurs:

	//!
	//!  \brief Constructeur par défaut
	//!
	//!  \post Une instance de la classe File est initialisée
	//!
	File();

	//!
	//!  \brief Constructeur de copie
	//!  \pre Il faut qu'il y ait suffisamment de mémoire
	//!  \post une copie profonde la file source
	//!  \exception bad_alloc s'il n'y a pas assez de mémoire
	//!
	File(const File &); //throw(std::bad_alloc);

	//!
	//!  \brief Destructeur
	//!
	//!  \post l'instance de File est détruite
	//!
	~File();

	//	modificateur
	//brief modificateur de de la taille de la fille
	void asgTaille(int & p_cpt);

	//!
	//!  \brief Enfiler un nouvel élément dans la file
	//!
	//! \pre Il y a assez de mémoire
	//! \post La file comprend un élément de plus
	//! \exception bad_alloc si la mémoire n'est aps suffisante
	//!
	void enfiler(const T&);	//throw (std::bad_alloc);

	//!
	//!  \brief Défiler un élément
	//!
	//! \pre La file ne doit pas étre vide
	//! \post La file comprend un élément de moins
	//! \exception logic_error si la file est vide
	//!
	T defiler();	// throw(std::logic_error);
	//!
	//!  \brief Enlever un élément à une certaine position
	//! La position commence à partir de 1
	//!
	void enleverPos(int);

	// sélecteurs

	//!
	//! \brief Demander la taille de la file
	//!
	//! \post La file est inchangée
	//! \post La taille de la file
	//!
	int taille() const;

	//!
	//! \brief Vérifier si la file est vide
	//!
	//! \post La file est inchangée
	//! \post VRAI est retourné si la file est vide, FAUX sinon
	//!
	bool estVide() const;

	//!
	//! \brief Retourner l'élément au début de la file
	//!
	//! \pre La file ne doit pas étre vide
	//! \post Une copie de l'élément est retourné
	//! \post La file est inchangée
	//! \exception logic_error si la file est vide
	//!
	const T& premier() const;	//throw (std::logic_error);

	//!
	//! \brief Retourner l'élément au queue de la file
	//!
	//! \pre La file ne doit pas étre vide
	//! \post Une copie de l'élément est retourné
	//! \exception logic_error si la file est vide
	//!
	const T& dernier() const;	//throw (std::logic_error);

	// surcharges d'opérateurs

	//!
	//! \brief Surcharger l'opérateur []
	//!
	//! \pre L'indice doit étre compris entre 0 et la cardinalité de la pile - 1
	//! \post L'élément é la position voulue est retournée
	//! \exception out_of_range si l'indice n'est pas correcte
	//!
	T& operator [](int) const;	//throw (std::out_of_range);

	//!
	//! \brief Surcharger l'opérateur =
	//!
	//! \pre Il y a assez de mémoire pour l'opération
	//! \post Une copie d'une file est retournée
	//! \exception bad_alloc si la mémoire est insuffisante
	//!
	const File<T>& operator =(const File<T>&);	//throw (std::bad_alloc);

	//!
	//! \brief Surcharge de l'opérateur <<
	//!
	//! \post Un flot de sortie correspondant é la file est retournée
	//!
	template<class U> friend std::ostream& operator <<(std::ostream& f,
			const File<U>& q);

private:
	//!
	//! \class Noeud
	//!
	//! \brief classe interne représentant un noeud typique
	//!
	//!  La classe représente un noeud typique
	//!  pour implémenter une liste chaénée.
	//!
	class Noeud {
	public:
		T el;				//!<L'élément de base de la file//!/
		Noeud * suivant;	//!<Un pointeur vers le noeud suivant//!/

		//!
		//! \brief Constructeur de la classe Noeud
		//!
		//! \post un noeud typique est intialisé
		//!
		explicit Noeud(const T& data_item, Noeud * next_ptr = 0) :
				el(data_item), suivant(next_ptr) {
		}
	};

	//! \typedef typedef Noeud //!elem
	//!  \brief Définition d'un pointeur sur un Noeud
	//!
	//!  Pour abréger les écritures
	//!
	typedef Noeud * elem;

	elem tete;		//!< Pointeur vers le début de la File//!/
	elem queue;		//!< Pointeur vers la fin de la file//!/
	int cpt;		//!< Nombre d'éléments effectifs dans la file//!/

	//!
	//! \brief Détruire une file
	//!
	//! Méthode privée
	//!
	void _detruire();

	//!
	//!  \brief Copier une file
	//!
	//! Méthode privée
	//!
	//! \post Une copie profonde d'une file est créée
	//!
	void _copier(Noeud *);	//throw (std::bad_alloc);
};
}	//fin du namespace

#include "File.hpp"
#endif
