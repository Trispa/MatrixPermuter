/*
 * Processus.cpp
 *
 *  Created on: 2014-09-23
 *      Author: etudiant
 */

#include "Processus.h"
#include<string>

namespace tp1 {
	//!\brief constructeur par defaut
	//!\exception std::bad_alloc
	Processus::Processus() :
			m_pid(NULL), m_duree(0), m_tempsConsomme(0), m_attente(0), m_priorite(0)

	{
	}
	;
	//!\brief constructeur par defaut
	//!\param[in]p_pid
	//!\param[in]p_duree
	//!\param[in]p_priorite
	//!\pre les paramtre d'entré doivent etre renseignés
	//!\post un objet de pocessus est crée
	//!\exception std::bad_alloc
	Processus::Processus(string p_pid, int p_duree, int p_priorite) :
			m_pid(p_pid), m_duree(p_duree), m_tempsConsomme(0), m_attente(0), m_priorite(
					p_priorite) {
	}
	;
	//!\brief destructeur du processus
	//!\post les resource alloués aux processus sont desallouées et le processus existe plus ne memoir
	Processus::~Processus() {
		// TODO Auto-generated destructor stub
	}

//!----------seters modificateurs----------------------*/

	//!
	//!\brief modifcateur du membre temps d'Attente
	//!\param[in] p_pid l'dentifiant du processus
	//!\pre p_pid doit etre un string
	//!\post l'identifiant du processus est renseigné

	void Processus::setProcessId(const string & p_pid){
		this->m_pid = p_pid;

	}
	//!
	//!\brief modifcateur du membre buree
	//!\param[in] p_ duree la durees du processus
	//!\pre p_duree doit etre une valeur entiere
	//!\post la durée du processu est renseignées

	void Processus::setDuree(const int & p_duree){
		this->m_duree = p_duree;
	}
	//!
	//!\brief modifcateur du membre Priorité
	//!\param[in] p_ duree la durees du processus
	//!\pre p_priorite doit etre une valeur entiere
	//!\post la priorité du processu est renseignées

	void Processus::setPriorite(const int & p_priorite){
		this->m_priorite = p_priorite;
	}



//!----------getters ou accesseurs----------------------*/

	//!
	//!\brief Accesseur du membre Pid
	//!\return p_pid
	string  Processus::getPid() const{
		return this->m_pid;
	}

	//!
	//!\brief Accesseur du membre duree
	//!\return m_duree
	int Processus::getDuree() const{
		return this->m_duree;
	}

	//!
	//!\brief Accesseur du membre temos de consommé
	//!\return m_tempsConsomme
	int Processus::getTempsConsomme() const{
		return this->m_tempsConsomme;
	}

	//!
	//!\brief Accesseur du membre  temps d'attente
	//!\return  p_attente
	int Processus::getTempsAttente() const{
		return this->m_attente;
	}

	//!
	//!\brief Accesseur du membre priorité
	//!\return m_priorite
	int Processus::getPriorite() const
	{
		return this->m_priorite;
	}
} /* namespace tp1 */
