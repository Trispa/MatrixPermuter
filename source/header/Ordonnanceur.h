/*
 * Ordonnanceur.h
 *
 *  Created on: 2014-09-23
 *      Author: etudiant
 */

#ifndef ORDONNANCEUR_H_
#define ORDONNANCEUR_H_
#include <iostream>
#include <stdexcept>
#include "File.h"
#include "Processus.h"
namespace tp1 {

class Ordonnanceur {
public:
	Ordonnanceur();
	//!
	//!  \brief Constructeur de copie
	//!  \pre Il faut qu'il y ait suffisamment de mémoire
	//!  \exception bad_alloc s'il n'y a pas assez de mémoire
	//!
	Ordonnanceur(const File<Processus> &); //throw(std::bad_alloc);

	void executeTache () const;

private:

};

} /* namespace tp1_ordonanceur */

#endif /* ORDONNANCEUR_H_ */
