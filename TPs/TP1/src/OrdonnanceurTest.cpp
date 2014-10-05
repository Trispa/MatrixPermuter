/*
 * OrdonnanceurTest.cpp
 *
 *  Created on: 2014-10-04
 *      Author: etudiant
 */
#include <gtest/gtest.h>
#include "Ordonnanceur.h"
#include "File.h"
using namespace  tp1;


TEST(testOrdonnanceur, testDuconstructeur)
{
	Processus *p1 = new Processus("p3", 1 ,2);
	Processus *p2 = new Processus("p3", 1 ,2);
	Processus *p3 = new Processus("p3", 1 ,2);
	Processus *p4 = new Processus("p4", 2 ,6);
	Processus *p5 = new Processus("p5", 2 ,6);
	File<Processus> *p_tache;
	p_tache->enfiler(*p1);
	p_tache->enfiler(*p2);
	p_tache->enfiler(*p3);
	p_tache->enfiler(*p4);
	p_tache->enfiler(*p5);

	Ordonnanceur* unOrdonnanceur = new Ordonnanceur(*p_tache);

	ASSERT_TRUE(unOrdonnanceur->getTache().taille() == 5);
}
