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

using namespace std;


// ØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØ
//	Constructeur et destructeur
// _____________________________________________________________________________________________

/**
 * \fn			Metro::Metro(std::ifstream &f) throw(std::logic_error, std::bad_alloc)
 * \param[in]	f un flux sur un fichier d'entrÈe
 */
Metro::Metro(std::ifstream &f)
{
	if (f  == NULL) throw std::logic_error("Metro: fichier non ouvert\n");

	//Lecture Ligne Entete
	int nbStations, noStation, nbLiens;
	f >> nbStations >> nbLiens;

	//std::cout << nbStations << " " << nbLiens << std::endl;

	//Lecture du nom des stations
	std:: vector<std::string> l; //Pour le nom des stations
	l.resize(nbStations);
	char buff[255];

	for(int i =0; i< nbStations ; i++)
	{

		f >> noStation;
		f.ignore();
		f.getline(buff, 100);
		std:: string s(buff);
		l[i] = s;
	}

	//Lecture des coordonnées et placement des sommets en mémoire
	std::string ligne;
	if(getline(f,ligne))
	{
		//std::cout << ligne << endl; //ignorer ce séparateur
	}
	else
	{
		throw logic_error("Metro::Metro : $ is expected");
	}
	for(int i=0; i <nbStations; ++i)
	{
		if(getline(f,ligne))
			{
				int aInt, x, y;
				std::stringstream ss(ligne);
				ss >> aInt >> x >> y;
				if (aInt!=i)
				{
					throw logic_error("Metro::Metro : aInt==i expected");
				}
				//std::cout << i << " " << x << " " << y << std::endl;
				unGraphe.ajouterSommet(i, l[i], x, y);
			}
			else
			{
				throw logic_error("Metro::Metro : text line is expected");
			}
	}

	//Lecture des arc et placement des arcs dans le graphe en mémoire
	f.ignore();f.ignore();
	int s1, s2, l_cout;
	//std::cout << "$" << endl;
	for (int i =0; i<nbLiens; i++)
	{
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
Metro::Metro(const Metro &source)
{
	this->unGraphe = source.unGraphe;
}




// ØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØØ
//	Affichage
// _____________________________________________________________________________________________

/**
 * \fn			void Metro::afficherStations()
 */
void Metro::afficherStations()
{
	std::vector<std::string> stations = this->unGraphe.listerNomsSommets();
	afficherStations(stations);
}

/**
 * \fn			void Metro::afficherStations(std::vector<std::string>&v)
 * \param[in]	v un vector de string
 */
void Metro::afficherStations(std::vector<std::string> & v)
{
	if (v.size() == 0)
	{
		std::cout << "La liste est vide\n";
		return;
	}

	for (unsigned int i=v.size(); i>0; i--)
 	{
	 	std::cout << v[i-1] << std::endl;
 	}
}

/**
 * \fn std::vector<std::string> Metro::dijkstra(const int & origine, const int & destination, int & nbSec)
 * \param[in] origin le sommet origine du chemin, un entier constant
 * \param[in] destination le sommet destination du chemin, un entier constant
 * \param[in] nbsec le temp de parcours du chemin
 * \return  vecteur de sommet composant le chemin le plus court dentre l'origine et la destination
 */

std::vector<std::string> Metro::dijkstra(const int & origine, const int & destination, int & nbSec)
{
	std::vector<int>  chemin;
	std::vector<string> cheminParNOM;
	this->unGraphe.dijkstra(origine, destination,chemin);

	for(std::vector<int>::iterator it =  chemin.begin(); it != chemin.end(); it++)
	{
		cheminParNOM.push_back(unGraphe.getNomSommet(*it));
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


std::vector<std::string>Metro::bellManFord(const int & origine, const int & destination, int & nbSec)
{
	std::vector<int>  chemin;
	std::vector<string> cheminParNOM;
	this->unGraphe.bellmanFord(origine, destination,chemin);

	for(std::vector<int>::iterator it =  chemin.begin(); it != chemin.end(); it++)
		{
			cheminParNOM.push_back(unGraphe.getNomSommet(*it));
		}
		return cheminParNOM;
}
