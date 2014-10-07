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
#include<iostream>
#include<vector>
using namespace std;
namespace tp1 {

//!
//!  \brief Constructeur de copie
//!  \pre Il faut qu'il y ait suffisamment de mémoire
//!  \exception bad_alloc s'il n'y a pas assez de mémoire
//!
Ordonnanceur::Ordonnanceur(File<Processus> & p_tache) :
		m_tache(p_tache) {
}

Ordonnanceur::~Ordonnanceur() {

	m_tache.~File();

}

//!
//!\brief Accesseur du membre tache de l'ordonnanceur
//!\return p_pid

File<Processus> Ordonnanceur::reqTache() const {
	return this->m_tache;
}
//!biref fonction permettant de mettre a jour le temp d'Attente des processus en attente
void Ordonnanceur::mettreAjourTempsAttente(int tps) {

	//TODO on doit incrementé les temps d'Attente des processus qui ne sont ni en execution ni en terminé
	// une solution pourrait etre de mettre a jour juste les processus qui sont en attente.
	for (int i = 0; i < this->m_tache.taille(); i++) {

		if (!(this->m_tache[i].estEnExecution())) {
			this->m_tache[i].asgAttente(
					this->m_tache[i].reqAttente() + tps);
		}
	}
}

//!
//!\brief function permettant dexecuter une tâche
void Ordonnanceur::executeTache(int &tempsAttenteMoyen , int &tempsRequis ) {
	//TODO regler le probleme : quant une processu est terminé on le supprime directement ou on change juste  son etat
	tempsAttenteMoyen = 0;
	int tempsAttenteTotal = 0;
	tempsRequis = 0;
	int cpt = m_tache.taille(); //stocker la taille de la pile avant d'entammer les modification
	for (list<int>::iterator it = this->listeDesPriorites.begin();
			it != this->listeDesPriorites.end(); it++) {

		for (int i = 0; i < this->m_tache.taille(); ++i) {

			if ((*it) == this->m_tache[i].reqPriorite()) {

				m_tache[i].elir();
				if (m_tache[i].reqDuree() == 0) {
					m_tache[i].terminer();
					//m_tache.enleverPos(i);
				} else if (m_tache[i].reqDuree() < QUANTUM) {
					m_tache[i].asgTempsConsomme(
							m_tache[i].reqTempsConsomme()
									+ m_tache[i].reqDuree());
					mettreAjourTempsAttente(m_tache[i].reqDuree());
					m_tache[i].terminer();
					//m_tache.enleverPos(i);
				} else {

					m_tache[i].asgDuree(m_tache[i].reqDuree() - QUANTUM);
					m_tache[i].asgTempsConsomme(
							m_tache[i].reqTempsConsomme() + QUANTUM);

					mettreAjourTempsAttente(QUANTUM);
					m_tache[i].interrompre();
				}

			}
			tempsAttenteTotal= tempsAttenteTotal +  m_tache[i].reqAttente();
			tempsRequis = tempsRequis + m_tache[i].reqTempsConsomme();
		}
	}
	tempsAttenteMoyen = tempsAttenteTotal/cpt;
}
//!brief Accesseur de la liste des priorité
list<int> Ordonnanceur::reqlisteDePriorite() {
	return this->listeDesPriorites;
}

//!\brief afficher les la tache à executer
void Ordonnanceur::afficherTache() const {
	cout <<"------------------------------------------"<<endl;
	cout << "TACHE À ACCOMPLIR:" << endl;
	for (int i = 0; i < m_tache.taille(); i++) {

		cout << m_tache[i].reqPid() << ": " << "durée    = "
				<< m_tache[i].reqDuree() << "   Priorité   = "
				<< m_tache[i].reqPriorite() << endl;
	}
}

//!\brief afficher le resultat de lasimulation
void Ordonnanceur::afficherResultats(int &tempsAttenteMoyen , int &tempsRequis) const {
	cout << "RESULTATS POUR CETTE TÂCHE" << endl;
	for (int i = 0; i < m_tache.taille(); i++) {

		cout << m_tache[i].reqPid() << ": " << "temps d'attente: "
				<< m_tache[i].reqAttente() << endl;
	}
	cout << "Temps moyen d’attente = " <<tempsAttenteMoyen<< endl;
	cout <<"Temps requis pour l’exécution de cette tâche = "<<tempsRequis<< endl;

}

//!brief cette fonction permet de recupere sans doublons les priorité
//!et  les triant par ordre croissant
//!return liste de priorités
void Ordonnanceur::listerLesPriorites() {

	list<int> listPritorite;

	for (int i = 1; i < m_tache.taille(); i++) {
		listPritorite.push_back(m_tache[i].reqPriorite());
	}
	listPritorite.sort();
	listPritorite.unique();
	this->listeDesPriorites = listPritorite;

}

} /* namespace tp1_ordonanceur */
