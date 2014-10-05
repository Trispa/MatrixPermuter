/*
 * Simulation.cpp
 *
 *  Created on: 2014-09-23
 *      Author: etudiant
 */

/**
 * programme principale pour l'Execution
 *
 */
#include <sstream>
#include<fstream>
#include<iostream>
#include<string>
#include <algorithm>
#include"Processus.h"
#include "Ordonnanceur.h"
#include"File.h"


using namespace tp1;

int main(void) {

//	ofstream myfile;
//	myfile.open ("taches.txt");
//	std::string line;
//	while (std::getlgetline(myfile, line))
//	{
//	    std::istringstream iss(line);
//	    string pid;
//	    int duree, priorite;
//	    if (!(iss >> pid>> duree >>priorite)) {
//	    	std::getline(myfile, line);
//	    }
//	    (iss >> pid>> duree >>priorite);
//
//	    // process pair (a,b)
//	}
//
	// tester les fonction de l'ordonnanceur
	Processus p1;
	Processus p2;
	Processus p3 ;
	Processus p4 ;
	Processus p5 ;
	File <Processus> p_tache;
	p_tache.enfiler(p1);
	p_tache.enfiler(p2);
	p_tache.enfiler( p3);
	p_tache.enfiler(p4);
	p_tache.enfiler(p5);

	Ordonnanceur* unOrdonnanceur = new Ordonnanceur(p_tache);

}

