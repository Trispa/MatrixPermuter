//!\File_listeChaineTesteur..cpp
//!\ Created on: 2014-09-30
//!\  Author: Patrice Diouf

#include <gtest/gtest.h>
#include "Processus.h"

using namespace  tp1;
/****************************FIXTURE******************************
 *
 */

class ProcessusTest: public ::testing::Test
{
public:
	Processus  *processusVide = new Processus(); //Processus vide


};



TEST_F(ProcessusTest, constructeurVide)
{

	ASSERT_EQ(processusVide->getPid(),"");
	ASSERT_EQ(processusVide->getEtat(),"nouveau");
	ASSERT_EQ(processusVide->getPriorite(),0);
	ASSERT_EQ(processusVide->getTempsAttente(),0);
	ASSERT_EQ(processusVide->getTempsConsomme(),0);
	ASSERT_EQ(processusVide->getDuree(),0);
}

TEST_F(ProcessusTest, constructeurAvecParametre)
{
	Processus * processus = new Processus("pe1", 5, 3);
	ASSERT_EQ(processus->getDuree(),5);
	ASSERT_EQ("pe1", processus->getPid());
	ASSERT_EQ(processus->getEtat(),"nouveau");
	ASSERT_EQ(processus->getPriorite(),3);
	ASSERT_EQ(processus->getTempsAttente(),0);
	ASSERT_EQ(processus->getTempsConsomme(),0);
}

TEST_F(ProcessusTest, TestOperateuregale)
{
	Processus *p1 = new Processus("p", 4, 6);
	Processus *p2 ;
	p2  = p1;

	ASSERT_EQ(p1->getDuree(),p2->getDuree());
	ASSERT_EQ(p1->getPid(), p2->getPid());
	ASSERT_EQ(p1->getEtat(),p2->getEtat());
	ASSERT_EQ(p1->getPriorite(),p2->getPriorite());
	ASSERT_EQ(p1->getTempsAttente(),p2->getTempsAttente());
	ASSERT_EQ(p1->getTempsConsomme(),p2->getTempsConsomme());
}

