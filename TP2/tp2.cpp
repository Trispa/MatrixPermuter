/*
 * tp2.cpp
 *
 *  Created on: 2014-10-26
 *      Author: etudiant
 */

#include "Graphe.h"
using namespace std;
int main(void)
{
	Graphe * g ;
	g = new Graphe();
	//ajouter les sommet


	g->ajouterSommet(0, "a", 0, 0);
	g->ajouterSommet(1, "b", 0, 0);
	g->ajouterSommet(2, "c", 0, 0);
	g->ajouterSommet(3, "d", 0, 0);
	g->ajouterSommet(4, "e", 0, 0);
	g->ajouterSommet(5, "f", 0, 0);

	// construire les arcs
	g->ajouterArc(0,1,4);
	g->ajouterArc(1,0,4);
	g->ajouterArc(0,2,2);
	g->ajouterArc(2,0,2);
	g->ajouterArc(1,2,1);
	g->ajouterArc(2,1,1);
	g->ajouterArc(2,3,8);
	g->ajouterArc(3,2,8);
	g->ajouterArc(1,3,5);
	g->ajouterArc(3,1,5);
	g->ajouterArc(2,4,10);
	g->ajouterArc(4,2,10);
	g->ajouterArc(4,3,2);
	g->ajouterArc(3,4,2);
	g->ajouterArc(5,4,3);
	g->ajouterArc(4,5,3);
	g->ajouterArc(3,5,6);
	g->ajouterArc(5,3,6);

	std::vector<int> temp;
	std::vector<int> sommetTraites;
	std::vector<int> tableauCout;
	std::vector<int> chemin ;
	int source = 0;
	int destination = 5;
	g->initGraphe(temp, sommetTraites, tableauCout, source);


   int coutPracour = g->dijkstra(source, destination, chemin);

   //cout<< coutPracour<<endl;
}

