/*
 * Ordonnanceur.cpp
 *
 *  Created on: 2014-09-23
 *      Author: etudiant
 */

#include "Ordonnanceur.h"
#include <list>
#include "File.h"
#include <set>
#include<vector>
namespace tp1 {

//!
//!  \brief Constructeur de copie
//!  \pre Il faut qu'il y ait suffisamment de mémoire
//!  \exception bad_alloc s'il n'y a pas assez de mémoire
//!
Ordonnanceur::Ordonnanceur(const File<Processus> & p_tache) :
		m_tache(p_tache) {
}


Ordonnanceur::~Ordonnanceur() {

	m_tache.~File();

}


//!
//!\brief Accesseur du membre tache de l'ordonnanceur
//!\return p_pid

File<Processus>  Ordonnanceur::getTache() const{
	return this->m_tache;
}

//!brief Accesseur de la liste des priorité
list<int> Ordonnanceur::getlisteDePriorite()const{
	return this->listeDesPriorites;
}


//!brief cette fonction permet de recupere sans doublons les priorité
//!et  les triant par ordre croissant
//!return liste de priorités
list<int> Ordonnanceur::listerLesPriorites()  {

	std::list<int> listPritorite;

	for(int i= 1; i<m_tache.taille(); i++)
	{
		listPritorite.push_back(m_tache[i].getPriorite());
	}
	listPritorite.sort();
	listPritorite.unique();
	this->listeDesPriorites = listPritorite;
	return this->listeDesPriorites;
}

} /* namespace tp1_ordonanceur */
