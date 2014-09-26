/*
 * Processus.h
 *
 *  Created on: 2014-09-23
 *      Author: etudiant
 */

#ifndef PROCESSUS_H_
#define PROCESSUS_H_
#include<string>
using namespace std;
namespace tp1 {

class Processus {
//!----------Partie publique accessible par les objets-------------*/
public:
	//!
	//!\brief constructeurpar defaut

	Processus();
	//!
	//!\brief constructeur avec parametres

	Processus(string p_pid, int p_duree, int p_priorite);

	//!
	//!\brief destructeur;

	virtual ~Processus();

	//!----------seters modificateurs----------------------*/

	//!
	//!\brief modifcateur du membre temps d'Attente

	void setProcessId(const string &);
	//!
	//!\brief modifcateur du membre buree

	void setDuree(const int &);
	//!
	//!\brief modifcateur du membre Priorité

	void setPriorite(const int &);

	//!
	//!\brief modificateur du membre Etat

	void setEtat(const string &);

	//!----------getters ou accesseurs----------------------*/

	//!
	//!\brief Accesseur du membre Pid

	string getPid() const;

	//!
	//!\brief Accesseur du membre duree
	//!
	int getDuree() const;

	//!
	//!\brief Accesseur du membre temos de consommé

	int getTempsConsomme() const;

	//!
	//!\brief Accesseur du membre  temps d'attente

	int getTempsAttente() const;

	//!
	//! Accesseur du membre priorité

	int getPriorite() const;

	//!
	//!\brief Accesseur du membre etat

	string getEtat() const;

	//!brief fonction permettant d'elir une precuss
	//! ie: mettre a jour l'etat d' un processus une fois elu

	void elir();

	//!brief fonction permettant d'elir une precuss
	//! ie: mettre a jour l'etat d' un processus une fois elu

	void admettre();

	//!brief fonction permettant d'elir une precuss
	//! ie: mettre a jour l'etat d' un processus une fois elu

	void interrompre();

	//!brief fonction permettant d'elir une precuss
	//! ie: mettre a jour l'etat d' un processus une fois elu

	void terminer();
//!----------Partie privée non accessible par les objets-------------*/

private:
	std::string m_pid; //identifiant du processus pour l’affichage du résultat
	int m_duree; // durée du temps d’exécution que ce processus devra utiliser
	int m_tempsConsomme; //temps consommé jusqu’à maintenant
	int m_attente; // temps d’attente cumulé
	int m_priorite; // priorité du processus
	std::string m_etat; // l'etat du processus

	//!
	//!\brief _estElu permet de dire si le  processus est elu ou pas

	bool _estPret (const string & ) const;

	//!
	//!\brief _estAdmis permet de dire si le  processus est elu ou pas

	bool _estEnAttente( const string & )const;

	//!
	//!\brief _estInterrompu permet de dire si le  processus est elu ou pas

	bool _estEnExecution( const string & )const;

	//!
	//!\brief _esttermine permet de dire si le  processus est elu ou pas

	bool _estTermine( const string & )const;
};

} /* namespace tp1 */

#endif /* PROCESSUS_H_ */
