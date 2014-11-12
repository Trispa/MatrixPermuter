/**
 * \file	Metro.h
 * \brief	Gestion d'un métro.
 * \author	LeProf
 * \version	1.0
 * \date	???
 */

#include "Graphe.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <limits>

//#pragma warning( disable : 4290 )//pour visual studio

#ifndef _METRO__H
#define _METRO__H

class Metro
{

	public:

	// 000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
	//	Constructeurs et destructeur
	// _________________________________________________________________________________________________

		/**
		 * \brief		Constructeur sans paramètre
		 * \post		Un métro vide est instancié.
		 */
		Metro() { };

		/**
		 * \brief		Constructeur é partir d'un fichier en entrée.
		 * \param[in]	fichierEntree, pointeur sur le fichier contenant la liste de stations é charger.
		 * \pre			Il y a assez de mémoire pour charger toute les stations de la liste.
		 * \pre			Le fichier \a fichierEntree est ouvert corectement.
		 * \post		Le fichier \a fichierEntree n'est pas fermé par la fonction.
		 * \post		Si les préconditions sont respectées, les données du métro contenu
		 *				dans le fichier en entrée sont organisées dans un graphe en mémoire.
		 * \exception	bad_alloc si pas assez de mémoire contenir toute la liste du fichier.
		 * \exception	logic_error si le fichier \a fichierEntree n'est pas ouvert correctement.
		 */
		Metro(std::ifstream &fichierEntree);

		/**
		 * \brief Constructeur de copie.
		 * \pre Il y a assez de mémoire.
		 * \exception bad_alloc S'il n'y a pas assez de mémoire.
		 */
		Metro(const Metro &source);

		/**
		 * \brief		Détruit et libére tout la mémoire allouée auparavant pour le métro.
		 * \post		Tout la mémoire allouée auparavant pour le Metro est libérée.
		 * \post		L'Objet Metro n'est plus valide.
		 */
		~Metro() { } ;





	// ééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééé
	//	Affichage
	// _________________________________________________________________________________________________

		/**
		 * \brief		Affiche une liste de stations de métro é l'écran.
		 * \param[in]	stations : Une liste de stations dans un vector.
		 * \post		Le contenu de la liste v est affiché.
		 */
		void afficherStations(std::vector<std::string>& stations);

		/**
		 * \brief		Affiche la liste de toutes les stations du métro é l'écran
		 * \post		La liste de toutes les stations du métro sont affichées.
		 */
		void afficherStations();

		//!
		//!\brief Initialiser les tableau utilisés pour la recherche du chemmin le plus court
		//!\param[in]temp  copie de la liste des sommets  pour ne pas modifier le graphe
		//!\param[in]predecesseurs le tableau des predecesseurs
		//!\param[in]tableauCout le tableau des coûts
		//!\param[in]etats tableau des etats

		void initForPathSearched(std::vector<int>& temp, std::vector<int>&predecesseurs,std::vector<int>&tableauCout, std::vector<bool>& etats);

		//!
		//!\brief retourner l'indice du sommet de coup minimal si le sommet n'a pas eté deja traité
		//!\param[in]vect le tableu des couts
		//!\param[in] etats tableau des etats

		int getIndiceSommetDeCoutMin(std::vector<int> &vect, std::vector<bool>&);

		//!\param[in]predecesseurs le tableau des predecesseurs
		//!\param[in]source le numero de la station source
		//!\param[in]destination le numero de la station de  destination
		//!\param[in]nbSec le temps de parcour du chemin en second
		//!\exception std::logic_error les sommets sources et destination doivent exister
		std::vector<std::string> cheminlePlusCourt(const std::vector<int>& predecesseurs,const int &source, const int &destunation, int& nbSec);
	// ééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééé
	//	Chemin le plus court, chemin le plus long...
	// _____________________________________________________________________________________________

		/**
		 * \brief		Trouve le plus court chemin entre deux points en utilisant l'algorithme de Dijsktra et le retourne
		 * \pre			Il y a assez de mémoire pour retourner les composantes du chemin
		 * \post		Le temps pris pour parcourir la distance est retournée, -1 s'il n'y a pas de chemin
		 * \post		Le graphe original reste inchangé
		 * \post		La liste des stations é parcourir est retournée
		 * \exception	bad_alloc		Il n'y a pas assez de mémoire pour retourner le chemin
		 * \exception	logic_error		Le sommet d'origine ou de destination n'existe pas
		 */
		std::vector<std::string> dijkstra(const int & origine, const int & destination, int & nbSec);

		/**
		 * \brief		Trouve le plus court chemin entre deux points en utilisant l'algorithme de Bellman-Ford et le retourne
		 * \pre			Il y a assez de mémoire pour retourner les composantes du chemin
		 * \post		Le temps pris pour parcourir la distance est retournée, -1 s'il n'y a pas de chemin
		 * \post		Le graphe original reste inchangé
		 * \post		La liste des stations é parcourir est retournée
		 * \exception	bad_alloc		Il n'y a pas assez de mémoire pour retourner le chemin
		 * \exception	logic_error		Le sommet d'origine ou de destination n'existe pas
		 */
		std::vector<std::string> bellManFord(const int & origine, const int & destination, int & nbSec);





	// ééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééé
	//	Surcharge d'opérateurs
	// _____________________________________________________________________________________________

		/**
		 * \brief		Surcharge de l'opérateur d'affectation.
		 * \pre			Il doit y avoir assez de mémoire.
		 * \post		Le Metro a un contenu identique é src.
		 * \exception	bad_alloc	S'il n'y a pas assez de mémoire.
		 */
		Metro& operator=(const Metro& src) throw(std::bad_alloc);

private:

	Graphe unGraphe;	/**< Le graphe du métro */

};

#endif
