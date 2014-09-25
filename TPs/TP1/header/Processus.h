/*
 * Processus.h
 *
 *  Created on: 2014-09-23
 *      Author: etudiant
 */

#ifndef PROCESSUS_H_
#define PROCESSUS_H_
#include<string>
using  namespace std;
namespace tp1 {

class Processus {
//!----------Partie publique accessible par les objets-------------*/
public:
	//!
	//! constructeurpar defaut

	Processus();
	//!
	//! constructeur avec parametres

	Processus(string  p_pid, int  p_duree, int  p_priorite);

	//!
	//! destructeur;

	virtual ~Processus();



	//!----------seters modificateurs----------------------*/

	//!
	//! modifcateur du membre temps d'Attente

	void setProcessId(const string &);
	//!
	//! modifcateur du membre buree

	void setDuree(const int &);
	//!
	//! modifcateur du membre Priorité

	void setPriorite(const int &);



	//!----------getters ou accesseurs----------------------*/

	//!
	//! Accesseur du membre Pid

	string getPid() const;

	//!
	//! Accesseur du membre duree
	//!
	int getDuree() const;

	//!
	//! Accesseur du membre temos de consommé

	int getTempsConsomme() const;

	//!
	//! Accesseur du membre  temps d'attente

	int getTempsAttente() const;

	//!
	//! Accesseur du membre priorité

	int getPriorite() const;

//!----------Partie privée non accessible par les objets-------------*/

private:
	std::string m_pid; //identifiant du processus pour l’affichage du résultat
	int m_duree; // durée du temps d’exécution que ce processus devra utiliser
	int m_tempsConsomme; //temps consommé jusqu’à maintenant
	int m_attente; // temps d’attente cumulé
	int m_priorite; // priorité du processus
};

} /* namespace tp1 */

#endif /* PROCESSUS_H_ */
