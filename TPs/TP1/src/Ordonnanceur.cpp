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
Ordonnanceur::Ordonnanceur(const File<Processus> & p_tache) :
		m_tache(p_tache) {
}

Ordonnanceur::~Ordonnanceur() {

	m_tache.~File();

}

//!
//!\brief Accesseur du membre tache de l'ordonnanceur
//!\return p_pid

File<Processus> Ordonnanceur::getTache() const {
	return this->m_tache;
}

//!
//!\brief function permettant dexecuter une tâche
void  Ordonnanceur::executeTache () const
{
	for(list<int>::const_iterator it = this->listeDesPriorites.begin(); it != this->listeDesPriorites.end(); ++it)
	{

		for (int i = 1; i < this->m_tache.taille(); i++) {

					if((*it) == this->m_tache[i].getPriorite())
					{
						//m_tache[i].setDuree(m_tache[i].getDuree()-QUANTUM);
						this->m_tache[i].setPriorite(4);
					}
				}
	}
}
//!brief Accesseur de la liste des priorité
list<int> Ordonnanceur::getlisteDePriorite() const {
	return this->listeDesPriorites;
}

//!\brief afficher les la tache à executer
void Ordonnanceur::afficherTache() const {
	cout<<"Tâche à accomplir :"<<endl;
	for (int i = 1; i < m_tache.taille(); i++) {

		cout <<m_tache[i].getPid()<< ": " << "durée = " << m_tache[i].getDuree()
				<< "Priorité = " << m_tache[i].getPriorite() << endl;
	}
}

//!\brief afficher le resultat de lasimulation
void Ordonnanceur::afficherResultats() const {
	cout << "Résultats pour cette tâche" << endl;
	for (int i = 1; i < m_tache.taille(); i++) {

			cout <<m_tache[i].getPid()<< ": " << "temps d'attente: " << m_tache[i].getTempsAttente()<<endl;
		}
	cout<<"Temps moyen d’attente = " << "xxx"<<endl;
	cout<<"Temps requis pour l’exécution de cette tâche = "<<"abc"<<endl;

}

//!brief cette fonction permet de recupere sans doublons les priorité
//!et  les triant par ordre croissant
//!return liste de priorités
list<int> Ordonnanceur::listerLesPriorites() {

	list<int> listPritorite;

	for (int i = 1; i < m_tache.taille(); i++) {
		listPritorite.push_back(m_tache[i].getPriorite());
	}
	listPritorite.sort();
	listPritorite.unique();
	this->listeDesPriorites = listPritorite;
	return this->listeDesPriorites;
}

} /* namespace tp1_ordonanceur */
