/**
 * \file Metro.cpp
 * \brief Implémentation de la classe Metro.
 * \author Mon étudiant préféré
 * \version 0.1
 * \date ????
 *
 *  Travail pratique numéro 2
 *
 */

#include "Metro.h"

#include <algorithm>

using namespace std;

// ØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØ
//	Constructeur et destructeur
// _____________________________________________________________________________________________

/**
 * \fn			Metro::Metro(std::ifstream &f) throw(std::logic_error, std::bad_alloc)
 * \param[in]	f un flux sur un fichier d'entrÈe
 */
Metro::Metro(std::ifstream &f) {
	if (f == NULL)
		throw std::logic_error("Metro: fichier non ouvert\n");

	//Lecture Ligne Entete
	int nbStations, noStation, nbLiens;
	f >> nbStations >> nbLiens;

	//std::cout << nbStations << " " << nbLiens << std::endl;

	//Lecture du nom des stations
	std::vector<std::string> l; //Pour le nom des stations
	l.resize(nbStations);
	char buff[255];

	for (int i = 0; i < nbStations; i++) {

		f >> noStation;
		f.ignore();
		f.getline(buff, 100);
		std::string s(buff);
		l[i] = s;
	}

	//Lecture des coordonnées et placement des sommets en mémoire
	std::string ligne;
	if (getline(f, ligne)) {
		//std::cout << ligne << endl; //ignorer ce séparateur
	} else {
		throw logic_error("Metro::Metro : $ is expected");
	}
	for (int i = 0; i < nbStations; ++i) {
		if (getline(f, ligne)) {
			int aInt, x, y;
			std::stringstream ss(ligne);
			ss >> aInt >> x >> y;
			if (aInt != i) {
				throw logic_error("Metro::Metro : aInt==i expected");
			}
			//std::cout << i << " " << x << " " << y << std::endl;
			unGraphe.ajouterSommet(i, l[i], x, y);
		} else {
			throw logic_error("Metro::Metro : text line is expected");
		}
	}

	//Lecture des arc et placement des arcs dans le graphe en mémoire
	f.ignore();
	f.ignore();
	int s1, s2, l_cout;
	//std::cout << "$" << endl;
	for (int i = 0; i < nbLiens; i++) {
		f >> s1 >> s2 >> l_cout;
		unGraphe.ajouterArc(s1, s2, l_cout);
		//std::cout << s1 << " " << s2 << " " << l_cout << std::endl;
	}
}

/**
 * \fn		Metro::Metro(const Metro &source) throw (std::bad_alloc)
 *
 * \param[in]	source	La source du mÈtro ‡ copier
 */
Metro::Metro(const Metro &source) {
	this->unGraphe = source.unGraphe;
}

// ØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØ
//	Affichage
// _____________________________________________________________________________________________

/**
 * \fn			void Metro::afficherStations()
 */
void Metro::afficherStations() {
	std::vector<std::string> stations = this->unGraphe.listerNomsSommets();
	afficherStations(stations);
}

/**
 * \fn			void Metro::afficherStations(std::vector<std::string>&v)
 * \param[in]	v un vector de string
 */
void Metro::afficherStations(std::vector<std::string> & v) {
	if (v.size() == 0) {
		std::cout << "La liste est vide\n";
		return;
	}

	for (unsigned int i = v.size(); i > 0; i--) {
		std::cout << v[i - 1] << std::endl;
	}
}


//!\brief Initialiser les données pour le calcule du chemin le plus court par Dijkstra et bellmanford
//!\param[in] p_temp  un ensemble temporaire de sommets d’un graphe (pour ne pas modifier le vecteur de l'ensemlbe des sommets du graphe);
//!\param[in] p_predecesseurs le tableau des predecesseurs
//!\param[in] p_tableauCout  un tableau de coût de longueur |V| (le nombre de sommet du graphe);


void Metro::initForPathSearched(std::vector<int>& p_temp, std::vector<int> &p_predecesseurs, std::vector<int>& p_tableauCout,std::vector<bool>& etats
		) {
	std::vector<int> S = unGraphe.listerSommets(); // une copie de la liste des sommets

		for (size_t i  = 0; i <S.size() ;i++) {
			etats[i] = false;
			p_tableauCout[i] = INFINI;
			p_temp[i]= S[i];
			p_predecesseurs[i] = -1;
		}
}
//!
//!\fn int Metro::getIndiceSommetDeCoutMin(std::vector<int> &vect, std::vector<bool>& etats)
//!\param[in]vect le tableu des couts
//!\param[in] etats tableau des etats

int Metro::getIndiceSommetDeCoutMin(std::vector<int> &vect, std::vector<bool>& etats) {

	int min = INFINI ;
	int indiceMin ;
	for (size_t i=0; i < vect.size(); i++) {
		if (vect[i] < min) {
			if(etats[i] ==false)
			{
				min = vect[i] ;
				indiceMin = i;
			}

	}
	}
	return indiceMin;
}
//!\fn std::vector<std::string> Metro::cheminlePlusCourt(const std::vector<int>& predecesseurs,const int &source, const int &destination, int &nbSec)
//!\param[in]predecesseurs le tableau des predecesseurs
//!\param[in]source le numero de la station source
//!\param[in]destination le numero de la station de  destination
//!\param[in]nbSec le temps de parcour du chemin en second
//!\exception std::logic_error les sommets sources et destination doivent exister

std::vector<std::string> Metro::cheminlePlusCourt(const std::vector<int>& predecesseurs,const int &source, const int &destination, int &nbSec)
		{


			std::vector<std::string> chemin;
			chemin.push_back(unGraphe.getNomSommet(destination));
			int sommetActuel = destination;

			while(sommetActuel!= source)
			{
				chemin.insert(chemin.begin(),unGraphe.getNomSommet(predecesseurs[sommetActuel]));
				sommetActuel = predecesseurs[sommetActuel];
				nbSec +=20;
				if(sommetActuel == -1 || sommetActuel == destination)
				{
					nbSec = -1;
				}
			}

			return chemin;
		}
/**
 * \fn std::vector<std::string> Metro::dijkstra(const int & origine, const int & destination, int & nbSec)
 * \param[in] origin le sommet origine du chemin, un entier constant
 * \param[in] destination le sommet destination du chemin, un entier constant
 * \param[in] nbsec le temp de parcours du chemin
 * \return  vecteur de sommet composant le chemin le plus court dentre l'origine et la destination
 */

std::vector<std::string> Metro::dijkstra(const int & p_origine,
		const int & p_destination, int & nbSec) {
	std::vector<string> cheminParNOM;

	nbSec = 0;
	std::vector<int> tableau_suivant_cout(unGraphe.listerSommets().size()); // fils d'Attente suivant le cout
	std::vector<int> tableauDesCouts(unGraphe.listerSommets().size()); // tabelau des cout
	std::vector<int> predecesseurs(unGraphe.listerSommets().size()); //tableau des sommet precedents
	std::vector<bool> etats(unGraphe.listerSommets().size()); // tableau des etats

	//-----------INITIALISATION POUR DIJKSTRA----------------

	this->initForPathSearched(tableau_suivant_cout,predecesseurs,tableauDesCouts, etats);

	//initialiser le cout du sommet origine
	tableauDesCouts[p_origine]=0;

	cout << "tableau des cout" << endl;
	for (size_t i  = 0; i <tableauDesCouts.size() ;i++)
		cout << tableauDesCouts[i] << endl;


	int trouve = 0;

//	try{
		while (!tableau_suivant_cout.empty() && trouve == 0 ) {


			int positionCoutMin = this->getIndiceSommetDeCoutMin(tableauDesCouts,etats);//  la position du coup minimal
			int SommetCouMin = positionCoutMin;
			cout << "le sommet de cout minimal :" << SommetCouMin<< " "<< endl;
			int coutMin = tableauDesCouts[SommetCouMin]; // coup minimal
			cout << "son cout est  :" << coutMin << " " << endl;
			cout << "sa position est  :" << positionCoutMin << " " << endl;



			//si on ateint la destination
			if (SommetCouMin == p_destination) {
				trouve = 1;
			}

			cout<<"lelemenent a supprimer est :"<<SommetCouMin<<endl;
			tableau_suivant_cout.erase(std::find(tableau_suivant_cout.begin(),tableau_suivant_cout.end(),SommetCouMin));
			etats[positionCoutMin]= true;

			std::vector<int> adj = unGraphe.listerSommetsAdjacents(SommetCouMin);
			cout << "les sommets adjacents à " << SommetCouMin << " sont :" << endl;
			for (size_t k = 0 ; k<adj.size(); k++)
			{
				cout<<adj[k]<<endl;
				if(unGraphe.arcExiste(SommetCouMin, adj[k]))
				if(tableauDesCouts[adj[k]]> tableauDesCouts[SommetCouMin]+unGraphe.getCoutArc(SommetCouMin, adj[k]))
					{
						tableauDesCouts[adj[k]]= tableauDesCouts[SommetCouMin]+unGraphe.getCoutArc(SommetCouMin, adj[k]);
						predecesseurs[adj[k]] = SommetCouMin;

					}


			}

			cout << endl;

		}
//	}catch(std::bad_alloc & e)
//	{
//		throw e;
//	}
		nbSec += tableauDesCouts[p_destination];

		cheminParNOM = this->cheminlePlusCourt(predecesseurs, p_origine, p_destination, nbSec);
		cout << "le chemin le plus court est :" << endl;

		return cheminParNOM;
}

/**
 * \fn std::vector<std::string>Metro::bellManFord(const int & origine, const int & destination, int & nbSec)
 * \param[in] origin le sommet origine du chemin, un entier constant
 * \param[in] destination le sommet destination du chemin, un entier constant
 * \param[in] nbsec le temp de parcours du chemin
 * \return  vecteur de sommet composant le chemin le plus court entre l'origine et la destination
 */

std::vector<std::string> Metro::bellManFord(const int & origine,
		const int & destination, int & nbSec) {
	std::vector<int> chemin;
	std::vector<string> cheminParNOM;
	//this->unGraphe.bellmanFord(origine, destination,chemin);

	for (std::vector<int>::iterator it = chemin.begin(); it != chemin.end();
			it++) {
		cheminParNOM.push_back(unGraphe.getNomSommet(*it));
	}
	return cheminParNOM;
}
