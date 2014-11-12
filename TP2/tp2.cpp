/*
 * tp2.cpp
 *
 *  Created on: 2014-10-26
 *      Author: etudiant
 */

#include "Metro.h"
#include "Graphe.h"
#include <sstream>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(void) {

	std::ifstream myfile("Metro.txt");
	Metro * metroParis;
	metroParis = new Metro(myfile);

	int source ;
	int destination;

	int duree;
	cout<<"-----------------------------------------------------------------------------------"<<endl;
	cout << "Entrez le numéro de la station de départ" << endl;
	cin >> source;
	cout << "Entrez le numéro de la station d'arrivée" << endl;
	cin >> destination;
	vector<string> cheminDjkstra = metroParis->dijkstra(source, destination,
			duree);
	cout<<"-----------------------------------------------------------------------------------"<<endl;
	cout << "Le plus court chemin trouvé par Dijkstra est: " << endl;
	for (size_t i = 0; i < cheminDjkstra.size(); i++) {
		cout << cheminDjkstra[i] << endl;
	}
	cout << "avec un temps estimé de " << duree << " secondes" << endl;
	vector<string> cheminBellman_ford = metroParis->bellManFord(source,
			destination, duree);
	cout<<"-----------------------------------------------------------------------------------"<<endl;
	cout << "Le plus court chemin trouvé par Bellman-Ford est: " << endl;
	for (size_t i = 0; i < cheminBellman_ford.size(); i++) {
		cout << cheminBellman_ford[i] << endl;
	}
	cout << "avec un temps estimé de " << duree << " secondes" << endl;

	cout<<"-----------------------------------------------------------------------------------"<<endl;
	cout
			<< "Détermination du temps d'exécution de l'algorithme de Dijkstra pour toutes les paires origine/destination..."
			<< endl;
	cout << "Temps d'exécution de l'algorithme de Dijkstra = xx.xx secondes"
			<< endl;

	cout
			<< "Détermination du temps d'exécution de l'algorithme de Bellman-Ford pour toutes les paires origine/destination..."
			<< endl;
	cout << "Temps d'exécution de l'algorithme de Bellman-Ford = xx.xx secondes"
			<< endl;

}

