/*
 * test->cpp
 *
 *  Created on: 2014-11-01
 *      Author: etudiant
 */


#include <gtest/gtest.h>
#include "Graphe.h"
using namespace std;



class GrapheTesteur : public ::testing::Test
{
public:

	Graphe * g ;

};

TEST_F(GrapheTesteur , testPreparationGraphe)
{
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

   ASSERT_EQ(temp.size(), 6);
   ASSERT_EQ(tableauCout[source] , 0);
   ASSERT_EQ(tableauCout[1] , INFINI);
   ASSERT_EQ(tableauCout[2] , INFINI);
   ASSERT_EQ(tableauCout[3] , INFINI);
   ASSERT_EQ(tableauCout[4] , INFINI);
   ASSERT_EQ(tableauCout[5] , INFINI);
   for (size_t i = 0; i < tableauCout.size(); i++) {
   cout<<tableauCout[i]<<" " ;
   }
   cout<<endl;
   ASSERT_EQ(g->min(tableauCout)[0], 0);
   ASSERT_EQ(g->min(tableauCout)[1], 0);

   int coutPracour = g->dijkstra(source, destination, chemin);

   //cout<< coutPracour<<endl;



}
