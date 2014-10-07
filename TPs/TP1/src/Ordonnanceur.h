/*
 * Ordonnanceur.h
 *
 *  Created on: 2014-09-23
 *      Author: etudiant
 */

#ifndef ORDONNANCEUR_H_
#define ORDONNANCEUR_H_
#define QUANTUM 4
#include <iostream>
#include <stdexcept>
#include "File.h"
#include "Processus.h"
#include <list>
using namespace std;
namespace tp1 {

class Ordonnanceur {
public:

	//!
	//!  \brief Constructeur de copie
	//!  \pre Il faut qu'il y ait suffisamment de mémoire
	//!  \exception bad_alloc s'il n'y a pas assez de mémoire
	//!
	Ordonnanceur(File<Processus> &); //throw(std::bad_alloc);

	//!destructeur
	~Ordonnanceur();
	//!
	//!\brief Accesseur du membre tache de l'ordonnanceur
	File<Processus>  reqTache() const;

	//!brief MEttre a jour le temps d'Attente des processus
	void mettreAjourTempsAttente(int tps);
	//!
	//!\brief function permettant dexecuter une tâche
	void  executeTache (int &, int &) ;
	//!
	//!\brief Accesseur de la liste des priorité des pocessus
	list<int> reqlisteDePriorite() ;

	//!\brief afficher les infos de la tache
	void afficherTache()const;
	//!\brief afficher le resultat de lasimulation
	void afficherResultats(int &tempsAttenteMoyen , int &tempsRequis)const;
	//!brief cette fonction permet de recupere sans doublons les priorité
	void listerLesPriorites() ;
private:
	File<Processus> & m_tache;// la tache de l'ordonanceur

	//!brief cette fonction permet de recupere sans doublons les priorité
	//!et  les triant par ordre croissant
	list<int> listeDesPriorites;

};

} /* namespace tp1_ordonanceur */

#endif /* ORDONNANCEUR_H_ */
