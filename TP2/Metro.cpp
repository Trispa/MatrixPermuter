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
//!\brief relacher des arc pour mettre a jour le veceur des coups

//TODO a tester
void Metro::relacher(int numOrigine, int numDestination, int leurcout,
		std::vector<int> & p_chemin) {
	if (numDestination > (numOrigine + leurcout)) {
		numDestination = (numOrigine + leurcout);
		p_chemin[numDestination] = numOrigine;
	}
}
//!\brief cout minimul et sa position
//!\param[in] vecteur_cout
//!\param[out]vecteur de deux dimention contenent la valeur et sa position
//!\return une vecteur de deux dimention avec le premier element le mimimu et le second sa position dans le tableau
std::vector<int> Metro::min(std::vector<int> &vecteur_cout) {
	int valmin = *(vecteur_cout.begin()); //valeur minimale initialiser a la premier valeur du vecteur
	int positionMin = 0; // position de la valeur initiale
	std::vector<int> minInfo; // vecteur a retourner
	for (size_t i = 0; i < vecteur_cout.size(); i++) {
		if (valmin > vecteur_cout[i]) {
			valmin = vecteur_cout[i];
			positionMin = i; //Stockage de position initiale
		}
	}

	minInfo.push_back(valmin);
	minInfo.push_back(positionMin);

	return minInfo;
}
//!\brief Initialiser les données pour le calcule du chemin le plus court par Dijkstra et bellmanford
//!\param[in] p_temp  un ensemble temporaire de sommets d’un graphe (pour ne pas modifier le vecteur de l'ensemlbe des sommets du graphe);
//!\param[in] p_sommetTraites l’ensemble des sommets traités par l’algorithme (pour ne pas traiter 2 fois le même sommet);
//!\param[in] p_tableauCout  un tableau de coût de longueur |V| (le nombre de sommet du graphe);

void Metro::initGraphe(std::vector<int>& p_temp,
		std::vector<int>& p_sommetTraites, std::vector<int>& p_tableauCout,
		int & source) {
	std::vector<int> S = unGraphe.listerSommets(); // une copie de la liste des sommets

	for (std::vector<int>::iterator it = S.begin(); it != S.end(); it++) {
		p_temp.push_back(*it);
		unGraphe.setEtatSommet((*it), false);

		if (*it == source)
			p_tableauCout.push_back(0);
		else
			p_tableauCout.push_back(INFINI);
	}
	cout << "tableau des cout" << endl;
	for (std::vector<int>::iterator k = p_tableauCout.begin();
			k != p_tableauCout.end(); k++)
		cout << *k << endl;
}

int Metro::getIndiceSommet(std::vector<int> & dist, std::vector<bool> & etats ) {
	std::vector<int> S = unGraphe.listerSommets();
	int min = INFINI, min_index;
	 for (int v = 0; v < S.size(); v++)
	     if (etats[v] == false && dist[v] <= min)
	         min = dist[v], min_index = v;

	   return min_index;
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
	std::vector<int> S = unGraphe.listerSommets(); // une copie de la liste des sommets
	std::vector<int> T; // les sommets solutionnés
	std::vector<int> Q(S.size()); // fils d'Attente suivant le cout
	std::vector<int> D(S.size()); // tabelau des cout
	std::vector<int> P(S.size()); //tableau des sommet precedents
	std::vector<bool> etats; // tableau des etats

	//-----------INITIALISATION POUR DIJKSTRA----------------
	for( size_t  v = 0;v<S.size(); v++ )
		{
			Q[v] = S[v];
			etats[v] = false;
			D[v] = INFINI;
		}

	D[p_origine] = 0;
	cout << "tableau des cout" << endl;
	for (std::vector<int>::iterator k = D.begin(); k != D.end(); k++)
		cout << *k << endl;


	int trouve = 0;
	unsigned int itdebut =0; // indice pour le vecteur T

//	try {

		while (!Q.empty() && trouve == 0) {

//			int coutMin = *std::min_element(itdebut, D.end()); // coup minimal
//			cout << "le cout minimal est :" << coutMin << " " << endl;
			int u = this->getIndiceSommet(D, etats); //  la position du coup minimal
			cout << "la position du coup minimal est   :" << u << " " << endl;
			etats[u] = true;
			int numSommeCoutMin = Q[u];
			cout << "le sommet correspondant est :" << numSommeCoutMin << " "
					<< endl;
			//si on ateint la destination
			if (Q[u] == p_destination) {
				trouve = 1;
			}


			Q.erase(Q.begin() + u);
			T.push_back(numSommeCoutMin);


			std::vector<int> adj = unGraphe.listerSommetsAdjacents(numSommeCoutMin);
			cout << "les sommets adjacents à " << numSommeCoutMin << " sont"
					<< " " << endl;
			for(size_t v = 0;v<Q.size(); v++ )
			{
				if(unGraphe.arcExiste(u, Q[v]))
				{
					cout<< v <<",";
					int temp = D[u] + unGraphe.getCoutArc(numSommeCoutMin,Q[v]);
				if(!etats[u] && temp < D[Q[v]])
				{
					D[Q[v]] = temp;
					P[Q[v]] = u;

				}

				}
			}
//			for (std::vector<int>::iterator it = Q.begin(); it != Q.end();
//					it++) {
//				if (unGraphe.arcExiste(positionCoutMin + 1, *it) && etats[positionCoutMin]==false )
//				{
//					D[*it - 1] = std::min(D[*it - 1],
//							numSommeCoutMin
//									+ unGraphe.getCoutArc(positionCoutMin + 1,
//											*it));
//				cout<< Q[*it]<<",";
//				P.push_back(numSommeCoutMin);
//				}
//
//			}
//			for(std::vector<int>::iterator k =adj.begin();k!= adj.end(); k++) {
//				std::vector<int>::iterator it = find(Q.begin(),Q.end(), *k);
//				if(it != unGraphe.listerSommetsAdjacents(numSommeCoutMin).end()){
//
//					cout<< *k<<",";
//					int temp = D[positionCoutMin]+ unGraphe.getCoutArc(numSommeCoutMin, *k);
//					if(temp < D[*k-1] && etats[positionCoutMin]==false)
//					{
//						D[*k-1] = temp;
//						P.push_back(numSommeCoutMin);
//					}
//				}
//
//		}


			cout << endl;
			itdebut ++;

		}
//
//	} catch (std::bad_alloc & erreur) {
//
//		throw erreur;
//	}

	cout << "le chemin le plus court est :" << endl;
	for (std::vector<int>::iterator it = P.begin(); it != P.end(); it++) {

		if(std::find(cheminParNOM.begin(), cheminParNOM.end(),unGraphe.getNomSommet(*it))== cheminParNOM.end()){
			cheminParNOM.push_back(unGraphe.getNomSommet(*it)) ;

		cout << *it << endl;
		}
	}
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
