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

	explicit Processus();
	//!
	//!\brief constructeur avec parametres

	explicit Processus(string p_pid, int p_duree, int p_priorite);

	//!
	//!\brief destructeur;

	~Processus();

	//!
	//! \brief Surcharger l'opérateur =
	//!
	//! \pre Il y a assez de mémoire pour l'opération
	//! \post Une copie du Processus est retournée
	//! \exception bad_alloc si la mémoire est insuffisante
	//!
	const Processus& operator = (const Processus&) ;//throw (std::bad_alloc);


	//!----------modificatieur----------------------*/

	//!
	//!\brief modifcateur du membre temps d'Attente

	void asgProcessId(const string &);

		//!
	//!\brief modifcateur du membre buree

	void asgDuree(const int &);
	//!
	//!\brief modifcateur du membre Priorité

	void asgPriorite(const int &);

	//!
	//!\brief modificateur du membre Etat

	void asgEtat(const string &);
	//!
	//!\brief modificateur du membre temps consomme

		void asgTempsConsomme(const int &);

	//!
	//!\brief modificateur du membre temps d'Attente

	void asgAttente(const int &);

	//!----------getters ou accesseurs----------------------*/

	//!
	//!\brief Accesseur du membre Pid

	string reqPid() const;

	//!
	//!\brief Accesseur du membre duree
	//!
	int reqDuree() const;

	//!
	//!\brief Accesseur du membre temos de consommé

	int reqTempsConsomme() const;

	//!
	//!\brief Accesseur du membre  temps d'attente

	int reqAttente() const;

	//!
	//! Accesseur du membre priorité

	int reqPriorite() const;

	//!
	//!\brief Accesseur du membre etat

	string reqEtat() const;

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

	//!
	//!\brief _esttermine permet de dire si le  processus est elu ou pas

	bool estTermine()const;
	//!
	//!\brief _estInterrompu permet de dire si le  processus est elu ou pas

	bool estEnExecution();

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

	bool _estPret () const;

	//!
	//!\brief _estAdmis permet de dire si le  processus est elu ou pas

	bool _estEnAttente()const;


};

} /* namespace tp1 */

#endif /* PROCESSUS_H_ */
