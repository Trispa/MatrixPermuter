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
#include<iostream>
#include<fstream>
#include<string>
#include"Processus.h"
#include "Ordonnanceur.h"
#include"File.h"
#include<list>
using namespace std;
using namespace tp1;

int main(void) {

//TODO il reste a faire de sorte qu'on est un ordonnanceur pour chaque tache separé pas /*
	std::ifstream myfile("taches.txt");
	File<Processus> p_tache;
	std::string line;
	cout << line << endl;
	std::getline(myfile, line); //recupere le premier caractere de du fichier qui est "/*"
	try {
		while (!(myfile.eof())) // la boucle commence à patir de la deuxieme ligne
		{
			std::getline(myfile, line);


			std::istringstream iss(line);
			string pid;
			int duree, priorite;
			if (iss >> pid >> duree >> priorite) {
				Processus *p = new Processus(pid, duree, priorite);
				p_tache.enfiler(*p);


			} else {
				Ordonnanceur* unOrdonnanceur = new Ordonnanceur(p_tache);
				unOrdonnanceur->listerLesPriorites();
				cout<<"la taille de file est :" <<p_tache.taille()<<endl;
				unOrdonnanceur->afficherTache();
				int tp1;
				int tp2;
				unOrdonnanceur->executeTache(tp1, tp2);
				unOrdonnanceur->afficherResultats(tp1, tp2);

			}

		}
	} catch (...) {
		cout << "il y eut erreur !\n";
	}

}

