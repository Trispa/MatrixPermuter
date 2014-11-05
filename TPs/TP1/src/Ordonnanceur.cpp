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
Ordonnanceur::Ordonnanceur(File<Processus> & p_tache,
		list<Processus> & p_resultat, list<int> & p_priorite) :
		m_tache(p_tache), resultat(p_resultat), listeDesPriorites(p_priorite){
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
//!brief fonction permettant de retourner le membre resultat
list<Processus> Ordonnanceur::reqResultat() const {
	return this->resultat;
}
//!biref fonction permettant de mettre a jour le temp d'Attente des processus en attente
void Ordonnanceur::mettreAjourTempsAttente(File<Processus> & p_f, int tps) {

	//TODO on doit incrementé les temps d'Attente des processus qui ne sont ni en execution ni en terminé
	// une solution pourrait etre de mettre a jour juste les processus qui sont en attente.
	for (int i = 0; i < p_f.taille(); i++) {

		if (!(p_f[i].estEnExecution())) {
			p_f[i].asgAttente(p_f[i].reqAttente() + tps);
		}
	}
}

//!brief une fonction permettant de retourner une fille de Processus de meme priorité
const File<Processus> & Ordonnanceur::filePriorite(int p) {
	File<Processus> f;
	for (int i = 0; i < this->m_tache.taille(); ++i) {
		if (m_tache[i].reqPriorite() == p) {
			f.enfiler(m_tache[i]);
		}

	}

return f;
}
//!
//!\brief function permettant dexecuter une tâche
void Ordonnanceur::executeTache() {

	int tempConsommtiontal = 0;

	for (list<int>::iterator it = this->reqlisteDePriorite().begin();
			it != this->reqlisteDePriorite().end(); it++) {
		File<Processus> f;

		for (int i = 0; i < this->m_tache.taille(); i++) {
				if (m_tache[i].reqPriorite() == *it) {
					f.enfiler(m_tache[i]);
				}
		}

		cout <<"taile de f : "<<f.taille()<<endl;
		f = this->filePriorite((*it));
		while (!f.estVide()) {
			Processus p = f.defiler();
			p.elir();
			if (p.reqDuree() > QUANTUM) {
				p.asgTempsConsomme(p.reqTempsConsomme() + QUANTUM);
				p.asgDuree(p.reqDuree() - p.reqTempsConsomme());

				f.enfiler(p);


				mettreAjourTempsAttente(f, QUANTUM);

			} else if (p.reqDuree() < QUANTUM) {
				p.asgTempsConsomme(p.reqTempsConsomme() + p.reqDuree());
				mettreAjourTempsAttente(f, p.reqDuree());
				p.asgDuree(0);


			} else {
				this->resultat.push_back(p);
				p.terminer();

			}

			tempConsommtiontal = tempConsommtiontal + p.reqTempsConsomme();
		}
		mettreAjourTempsAttente(m_tache, tempConsommtiontal);
	}
}
//!brief Accesseur de la liste des priorité
list<int> Ordonnanceur::reqlisteDePriorite() {
	return this->listeDesPriorites;
}

//!\brief afficher les la tache à executer
void Ordonnanceur::afficherTache() const {

	cout << "------------------------------------------" << endl;
	cout << "TACHE À ACCOMPLIR:" << endl;
	for (int i = 0; i < m_tache.taille(); i++) {

		cout << m_tache[i].reqPid() << ": " << "durée    = "
				<< m_tache[i].reqDuree() << "   Priorité   = "
				<< m_tache[i].reqPriorite() << endl;
	}
}

//!\brief afficher le resultat de lasimulation
void Ordonnanceur::afficherResultats() {
	cout << endl << "taile de resultats = " << this->resultat.size() << endl;
	cout << "RESULTATS POUR CETTE TÂCHE" << endl;
	int tempsAttenteTotal = 0;
	int tempsAttenteMoyen;
	int tempsRequis;
	if (!this->resultat.empty()) {

		for (list<Processus>::iterator it = this->resultat.begin();
				it != this->resultat.end(); it++) {
			cout << (*it).reqPid() << ": " << "temps d'attente: "
					<< (*it).reqAttente() << endl;
			tempsAttenteTotal = tempsAttenteTotal + (*it).reqAttente();
			tempsRequis = tempsRequis + (*it).reqTempsConsomme();
		}
		tempsAttenteMoyen = tempsAttenteTotal / this->resultat.size();
		cout << "Temps moyen d’attente = " << tempsAttenteMoyen << endl;
		cout << "Temps requis pour l’exécution de cette tâche = " << tempsRequis
				<< endl;
		cout << endl;
		cout << endl;
	}
}

//!brief cette fonction permet de recupere sans doublons les priorité
//!et  les triant par ordre croissant
//!return liste de priorités
void Ordonnanceur::listerLesPriorites() {



	for (int i = 0; i < m_tache.taille(); i++) {
		this->listeDesPriorites.push_back(m_tache[i].reqPriorite());
	}
	this->listeDesPriorites.sort();
	this->listeDesPriorites.unique();


}

} /* namespace tp1_ordonanceur */
