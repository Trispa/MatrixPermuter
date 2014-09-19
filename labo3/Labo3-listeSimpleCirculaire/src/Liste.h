/**
 * \file Liste.h
 * \brief Classe définissant le type abstrait Liste.
 * \author Ludovic Trottier
 * \author Mathieu Dumoulin
 * \version 0.3
 * \date Mai 2014
 *
 * Implémentation dans une liste simplement chaînée circulaire.
 */

#ifndef _LISTE__H
#define _LISTE__H

namespace lab03 {
/**
 * \class Liste
 *
 * \brief classe générique représentant une liste ordonnée
 *
 *  La classe gére une liste ordonnée générique. L'implémentation
 *  se fait dans une liste simplement chainée.
 */
template<typename T>
class Liste {
public:
	explicit Liste();
	explicit Liste(const Liste &);
	~Liste();

	const Liste<T> & operator =(const Liste<T> &);

	void ajouter(const T &, const int &);
	void enleverEl(const T &);
	void enleverPos(const int &);

	int taille() const;
	bool estVide() const;
	bool appartient(const T &) const;
	T element(const int &) const;
	int position(const T &) const;

	void verifieInvariant() const;

	template<class U> friend std::ostream& operator <<(std::ostream &,
			const Liste<U> &);
private:

	/**
	 * \class Noeud
	 *
	 * \brief Classe interne représentant un noeud (une position) dans la liste.
	 */
	class Noeud {
	public:
		T m_el; /*!<L'élément de base de la liste*/
		Noeud * m_suivant; /*!<Un pointeur vers le noeud suivant*/

		explicit Noeud(const T& data_item, Noeud * next_ptr = 0) :
				m_el(data_item), m_suivant(next_ptr) {
		}
	};

	/**
	 * \typedef typedef Noeud *elem
	 * \brief Définition d'un pointeur sur un Noeud
	 *
	 *  Pour abréger les écritures
	 */
	typedef Noeud * elem;
	elem m_dernier; /*!<Pointeur vers le dernier noeud de la liste*/
	int m_cardinalite; /*!< Cardinalité de la liste*/

	// Méthodes privées
    
    // À titre indicatif, voici les méthodes privées de la solution
    /*
	elem _pointeurSurNoeud(const int &) const;
	void _copier(elem);
	void _detruire();
	void _enlever(elem);
    */
};
}

#include "Liste.hpp"

#endif
