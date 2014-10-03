/*
 * Ordonnanceur.h
 *
 *  Created on: 2014-09-23
 *      Author: etudiant
 */

#ifndef ORDONNANCEUR_H_
#define ORDONNANCEUR_H_
#include <iostream>
#include <stdexcept>
#include "File.h"
#include "Processus.h"
#include <list>
using namespace std;
namespace tp1 {

class Ordonnanceur {
public:
	Ordonnanceur();
	~Ordonnanceur();
	//!
	//!  \brief Constructeur de copie
	//!  \pre Il faut qu'il y ait suffisamment de mémoire
	//!  \exception bad_alloc s'il n'y a pas assez de mémoire
	//!
	Ordonnanceur(const File<Processus> &); //throw(std::bad_alloc);

	//!
	//!\brief Accesseur du membre tache de l'ordonnanceur
	//!\return p_pid

	File<Processus>  getTache() const;

	void  executeTache () const;

private:
	File<Processus> m_tache;// la tache de l'ordonanceur

	//!brief cette fonction permet de recupere sans doublons les priorité
	//!et  les triant par ordre croissant
	list<int> listeDesPriorites () ;

};

} /* namespace tp1_ordonanceur */

#endif /* ORDONNANCEUR_H_ */
