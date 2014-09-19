/**
 * \file Liste.h
 * \brief Classe définissant le type abstrait Liste.
 * \author Ludovic Trottier
 * \version 0.1
 * \date Mai 2014
 *
 * Implémentation dans un tableau dynamique.
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
 *  se fait dans un tableau dynamique.
 */
template<typename T>
class Liste {
public:
	explicit Liste(const int = MAX_LISTE);
	explicit Liste(const Liste &);
	~Liste();

	const Liste<T>& operator =(const Liste<T> &);

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

	int m_tailleMax; /*!< Taille maximum de la liste*/
	int m_cardinalite; /*!< Cardinalité de la liste*/
	T * m_tab; /*!< Pointeur pour définir un tableau dynamique*/
	static const int MAX_LISTE = 100; /*!< la taille maximum par défaut de la liste ordonnée*/

	//Méthodes privées

    // À titre indicatif, voici les méthodes privées de la solution
    /*
	void _copier(T *);
    */
};

}

#include "Liste.hpp"

#endif
